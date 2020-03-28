#include "common.h"
#include "PatLine.h"

#include <sstream>
#include <algorithm>
#include <tuple>

namespace
{
  static double cEpsilon = 0.0001;
}

CPatLine::CPatLine(double angle, const std::pair<double, double>& origin, const std::pair<double, double>& delta, const std::vector<double>& intervals, int index, const std::vector<double>& maxLength) :
  m_angle(angle),
  m_origin(origin),
  m_delta(delta),
  m_intervals(intervals),
  m_index(index),
  m_lineEps(std::numeric_limits<double>::max())
{
  init(maxLength);
}

void CPatLine::initLineEps()
{
  for (auto& interval : m_intervals)
  {
    if (abs(interval) > cEpsilon)
      m_lineEps = std::min(m_lineEps, abs(interval));
  }

  if (abs(m_delta.first) > cEpsilon)
    m_lineEps = std::min(m_lineEps, std::abs(m_delta.first));
  if (abs(m_delta.second) > cEpsilon)
    m_lineEps = std::min(m_lineEps, std::abs(m_delta.second));

  m_lineEps /= 10.;  
}

void CPatLine::init(const std::vector<double>& maxLength)
{
  initLineEps();

  const double pi = std::acos(-1);
  auto angleRad = ((double)m_angle*pi) / 180.;
  double t0Y = 0, t0X = 0, t1Y = 0, t1X = 0;

  if (abs(cos(angleRad)) < cEpsilon) // cos is 0 
  {
    m_t0 = funcMinusOneY(0);
    m_t1 = funcMinusOneY(maxLength[1]);
  }
  else if (abs(sin(angleRad)) < cEpsilon) // sin is 0
  {
    m_t0 = funcMinusOneX(0);
    m_t1 = funcMinusOneX(maxLength[0]);
  }
  else
  {
    t0Y = funcMinusOneY(0);
    t0X = funcMinusOneX(0);

    t1Y = funcMinusOneY(maxLength[1]);
    t1X = funcMinusOneX(maxLength[0]);

    if (cos(angleRad) > 0 && sin(angleRad) > 0)
    {
      m_t0 = std::max(t0X, t0Y);
      m_t1 = std::min(t1X, t1Y);
    }
    else if (cos(angleRad) < 0 && sin(angleRad) < 0)
    {
      m_t0 = std::min(t0X, t0Y);
      m_t1 = std::max(t1X, t1Y);
    }
    else if (cos(angleRad) > 0 && sin(angleRad) < 0)
    {
      m_t0 = std::max(t0X, t1Y);
      m_t1 = std::min(t0Y, t1X);
    }
    else
    {
      m_t0 = std::max(t0Y, t1X);
      m_t1 = std::min(t0X, t1Y);
    }
  }

  if (m_t0 > m_t1)
  {
    auto tmp = m_t1;
    m_t1 = m_t0;
    m_t0 = tmp;
  }

  if (m_intervals.size() < 2)
  {
    m_definitions.push_back(std::make_tuple(m_t0 - std::max(maxLength[0], maxLength[1]), m_t1 + std::max(maxLength[0], maxLength[1]), 0));
  }
  else
  {
    double originLeft = 0.f, originRight = 0.f;
    while (originRight <= m_t1 + 2.*cEpsilon)
    {
      for (size_t intervalIndex = 0; intervalIndex < m_intervals.size(); ++intervalIndex)
      {
        auto interval = m_intervals[intervalIndex];
        if (interval >= 0 && (abs(originRight + interval - m_t0) < cEpsilon || (originRight + interval - m_t0) > cEpsilon))
        {
          auto point1 = originRight;//std::max(originRight, m_t0);
          auto point2 = originRight + interval;// std::min(originRight + interval, m_t1);
          m_definitions.push_back(std::make_tuple(std::min(point1, point2), std::max(point1, point2), intervalIndex));
        }
        originRight += abs(interval);
        if (originRight > m_t1 + 2.*cEpsilon)
        {
          break;
        }
      }
    }

    while (originLeft >= m_t0)
    {
      for (int intervalIndex = (int)m_intervals.size() - 1; intervalIndex >= 0; --intervalIndex)
      {
        auto interval = m_intervals[intervalIndex];

        if (interval >= 0 && (abs(m_t1 - originLeft + interval) < cEpsilon || (m_t1 - originLeft + interval) > cEpsilon))
        {
          auto point1 = originLeft;
          auto point2 = originLeft - interval;// std::max(originLeft - interval, m_t0);
          m_definitions.push_back(std::make_tuple(std::min(point1, point2), std::max(point1, point2), intervalIndex));
        }
        originLeft -= abs(interval);
        if (originLeft < m_t0 - 2.*cEpsilon)
        {
          break;
        }
      }
    }
  }

  std::sort(m_definitions.begin(), m_definitions.end());
  m_initialized = true;
}

std::pair<double, double> CPatLine::func(double arg) const
{
  const double pi = std::acos(-1);
  auto angleRad = (m_angle*pi) / 180;
  auto xDeltaPos = m_delta.first*cos(angleRad) - m_delta.second*sin(angleRad);
  auto yDeltaPos = m_delta.first*sin(angleRad) + m_delta.second*cos(angleRad);
  auto res = std::pair<double, double>(m_origin.first + arg*std::cos(angleRad) + (m_index)*xDeltaPos, m_origin.second + arg*std::sin(angleRad) + (m_index)*yDeltaPos);
  return res;
}

double CPatLine::funcMinusOneX(double x) const
{
  const double pi = std::acos(-1);
  auto angleRad = (m_angle*pi) / 180;
  auto xDeltaPos = m_delta.first*cos(angleRad) - m_delta.second*sin(angleRad);
  auto res = (x - m_origin.first - m_index*xDeltaPos) / cos(angleRad);
  return res;
}

double CPatLine::funcMinusOneY(double y) const
{
  const double pi = std::acos(-1);
  auto angleRad = (m_angle*pi) / 180;
  auto yDeltaPos = m_delta.first*sin(angleRad) + m_delta.second*cos(angleRad);
  auto res = (y - m_origin.second - m_index*yDeltaPos) / sin(angleRad);
  return res;
}

double CPatLine::length()
{
  double res = 0.f;
  res = abs(m_t1 - m_t0);
  return res;
}

std::vector<int> CPatLine::getIntervalNumbers(double arg)
{
  std::vector<int> res;
  auto fragmentLen = 0.;
  for (auto& interval : m_intervals)
  {
    fragmentLen += abs(interval);
  }

  int fragNum = (int)(abs(arg) / fragmentLen);
  auto startPoint = fragNum*fragmentLen;
  if (arg >= 0)
  {
    auto currentPoint = startPoint;
    if (abs(arg - currentPoint) < 0.001f)
    {
      res.push_back(0);
      res.push_back((int)m_intervals.size() - 1);
    }
    for (int i = 0; i < m_intervals.size(); i++)
    {
      currentPoint += abs(m_intervals[i]);
      if (arg < currentPoint || abs(arg - currentPoint) < m_lineEps)
      {
        res.push_back(i);
        break;
      }
    }

    if (abs(arg - currentPoint) < 0.001f)
    {
      res.push_back(0);
    }
  }
  else
  {
    auto currentPoint = -startPoint;
    if (abs(arg - currentPoint) < 0.001f)
    {
      res.push_back(0);
    }
    for (int i = (int)m_intervals.size() - 1; i >= 0; i--)
    {
      currentPoint -= abs(m_intervals[i]);
      if (arg > currentPoint)
      {
        res.push_back(i);
        break;
      }
    }
    if (abs(arg - currentPoint) < 0.001f)
    {
      res.push_back(1);
    }
  }

  return res;
}
