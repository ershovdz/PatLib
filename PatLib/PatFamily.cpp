#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include "common.h"
#include "PatLine.h"
#include "PatFamily.h"
#include "PatUtils.h"
#include <tuple>


namespace
{
  static double cEpsilon = 0.0001;
  static double cDelta = 0.1f;
}

CPatFamily::CPatFamily()
{
}

void CPatFamily::parse(const std::wstring& family)
{
  std::wistringstream iss(family);

  std::wstring token;
  std::vector<std::wstring> strs;

  std::getline(iss, token, L',');
  m_angle = std::stod(token);

  std::getline(iss, token, L',');
  m_origin.first = std::stod(token);

  std::getline(iss, token, L',');
  m_origin.second = std::stod(token);

  std::getline(iss, token, L',');
  m_delta.first = std::stod(token);

  std::getline(iss, token, L',');
  m_delta.second = std::stod(token);

  while (std::getline(iss, token, L','))
  {
    auto len = std::stod(token);
    m_intervals.push_back(len);
  }

  recalculateLength();
}

void CPatFamily::recalculateLength()
{
  const double pi = std::acos(-1);
  auto angleRad = (m_angle*pi) / 180;

  CPatLine line0(m_angle, m_origin, m_delta, m_intervals, 0, { 1.f,1.f });
  auto x0 = line0.func(line0.funcMinusOneY(0)).first;
  auto y0 = line0.func(line0.funcMinusOneX(0)).second;

  auto i = 0;
  double fragmentLength = -1.f;
  if (m_intervals.size() > 0)
  {
    fragmentLength = abs(m_intervals[0]);
    for (auto j = 1; j < m_intervals.size(); j++)
    {
      fragmentLength += abs(m_intervals[j]);
    }
  }

  if (abs(sin(angleRad)) < cEpsilon)
  {
    m_length[0] = fragmentLength;
    m_length[1] = abs(2 * m_delta.second);
  }
  else if (abs(cos(angleRad)) < cEpsilon)
  {
    m_length[0] = abs(2 * m_delta.second);
    m_length[1] = fragmentLength;
  }
  else if (abs(sin(angleRad)) > cEpsilon)
  {
    double periodX = 0.f, periodY = 0.f;
    double maxLenX = 0.f, maxLenY = 0.f;
    bool ornamentBroken = false;
    do
    {
      CPatLine lineI(m_angle, m_origin, m_delta, m_intervals, ++i, { 1.f, 1.f });
      auto xi = lineI.func(lineI.funcMinusOneY(0)).first;
      double yi = lineI.func(lineI.funcMinusOneX(0)).second;
      auto periodYI = (xi - x0)*tan(angleRad);
      double periodXI = (yi - y0)*cos(angleRad) / sin(angleRad);
      periodY = abs(periodYI);
      periodX = abs(periodXI);
      if (m_minPeriod[0] == 0.f && m_minPeriod[1] == 0.f)
      {
        m_minPeriod[0] = periodX;
        m_minPeriod[1] = periodY;
      }

      maxLenX = abs(periodX / cos(angleRad)) / fragmentLength;
      maxLenY = abs(periodY / sin(angleRad)) / fragmentLength;

      ornamentBroken = isOrnamentBroken(periodX, periodY);

    } while (abs(maxLenX - std::round(maxLenX)) > cDelta ||
      abs(maxLenY - std::round(maxLenY)) > cDelta ||
      ornamentBroken);

    m_length[0] = periodX;
    m_length[1] = periodY;    
  }
}

bool CPatFamily::isOrnamentBroken(double periodX, double periodY)
{
  bool res = false;
  if (m_intervals.size() <= 1)
  {
    return res;
  }

  auto linesForPeriod = lines({ periodX, periodY });


  //bool hasGeometry = false;
  
  CPatLine lPlus, lMinus;
  for (auto& line : linesForPeriod)
  {
    auto point = line.func(line.m_t0);

    if ((abs(point.first) > cEpsilon || abs(point.second) > cEpsilon) &&
      abs(line.m_t1 - line.m_t0) > cDelta &&
      line.m_definitions.size() > 0)
    {
      //hasGeometry = true;

      auto dual = getDual(line, periodX, periodY);
      if (dual.m_initialized)
      {
        lMinus = line;
        lPlus = dual;
        break;
      }
    }
  }

  //if (!hasGeometry)
  //  return true;

  if (!lMinus.m_initialized || !lPlus.m_initialized)
  {
    return res;
  }

  if (lMinus.m_definitions.size() > 0 && lPlus.m_definitions.size() > 0)
  {
    auto intervalsMinus = lMinus.getIntervalNumbers(lMinus.m_t1);
    auto intervalsPlus = lPlus.getIntervalNumbers(lPlus.m_t0);

    if (intervalsMinus.size() == intervalsPlus.size() && intervalsMinus.size() > 1)
    {
      for (int i = 0; i < intervalsMinus.size(); ++i)
      {
        if (intervalsMinus[i] != intervalsPlus[i])
          return true;
      }
      
      res = false;
    }
    else
    {
      double gluedLength = 0.f;
      if (intervalsMinus[0] == intervalsPlus[0])
      {
        auto lMinusLength = 0.f;
        if ((lMinus.m_t1 - std::get<1>(lMinus.m_definitions.back())) > lMinus.lineEps())
        {
          lMinusLength = (float)(lMinus.m_t1 - std::get<1>(lMinus.m_definitions.back()));
        }
        else
        {
          lMinusLength = (float)(lMinus.m_t1 - std::get<0>(lMinus.m_definitions.back()));
        }

        auto lPlusLength = 0.f;
        if (lPlus.m_t0 < std::get<0>(lPlus.m_definitions.front()))
        {
          lPlusLength = (float)(std::get<0>(lPlus.m_definitions.front()) - lPlus.m_t0);
        }
        else
        {
          lPlusLength = (float)(std::get<1>(lPlus.m_definitions.front()) - lPlus.m_t0);
        }

        gluedLength = lMinusLength + lPlusLength;
      }

      res = (abs(gluedLength - abs(m_intervals[intervalsMinus[0]])) >= abs(m_intervals[intervalsMinus[0]])*cDelta);
    }
  }

  return res;
}

CPatLine CPatFamily::getDual(CPatLine& line, double periodX, double periodY)
{
  CPatLine res;
  auto linesForPeriod = lines({ periodX, periodY });

  auto lMX = line.func(line.m_t0);
  auto lMXMod1 = CPatUtils::byMod(lMX.first, periodX);
  auto lMXMod2 = CPatUtils::byMod(lMX.second, periodY);
  auto lMY = line.func(line.m_t1);
  auto lMYMod1 = CPatUtils::byMod(lMY.first, periodX);
  auto lMYMod2 = CPatUtils::byMod(lMY.second, periodY);

  for (auto& l : linesForPeriod)
  {
    auto lX = l.func(l.m_t0);
    auto lXMod1 = CPatUtils::byMod(lX.first, periodX);
    auto lXMod2 = CPatUtils::byMod(lX.second, periodY);
    auto lY = l.func(l.m_t1);
    auto lYMod1 = CPatUtils::byMod(lY.first, periodX);
    auto lYMod2 = CPatUtils::byMod(lY.second, periodY);
    
    if (l.m_index != line.m_index &&
      abs(l.m_t1 - l.m_t0) > cDelta &&
      l.m_definitions.size() > 0 &&
      ((abs(lXMod1 - lMYMod1) < cEpsilon && abs(lXMod2 - lMYMod2) < cEpsilon) ||
      (abs(lYMod1 - lMXMod1) < cEpsilon && abs(lYMod2 - lMXMod2) < cEpsilon)))
    {
      res = l;
      break;
    }
  }
  return res;
}

namespace
{
  int roundIndex(double num)
  {
    if (num >= 0)
      return  (int)std::ceil(num);
    else
      return (int)std::round(num);
  }
}

std::vector<CPatLine> CPatFamily::lines(const std::vector<double>& tileSize)
{
  std::vector<CPatLine> res;
  const double pi = std::acos(-1);
  auto angleRad = (m_angle*pi) / 180;
  int indexMin = 0, indexMax = 0;
  if (abs(cos(angleRad)) < cEpsilon) // cos is 0
  {
    if (abs(m_delta.second) < cEpsilon)
    {
      indexMin = 0;
      indexMax = 0;
    }
    else
    {
      indexMin = roundIndex(m_origin.first / (m_delta.second*sin(angleRad)));
      indexMax = roundIndex((m_origin.first - tileSize[0]) / (m_delta.second*sin(angleRad)));
    }
  }
  else if (abs(sin(angleRad)) < cEpsilon) // sin is 0
  {
    if (abs(m_delta.second) < cEpsilon)
    {
      indexMin = 0;
      indexMax = 0;
    }
    else
    {
      indexMin = roundIndex(-m_origin.second / (m_delta.second*cos(angleRad)));
      indexMax = roundIndex((tileSize[1] - m_origin.second) / (m_delta.second*cos(angleRad)));
    }
  }
  else if (cos(angleRad)*sin(angleRad) > 0)
  {
    if (abs(m_delta.second) < cEpsilon)
    {
      indexMin = 0;
      indexMax = 0;
    }
    else
    {
      indexMin = (int)std::round(((m_origin.first - tileSize[0])*sin(angleRad) - cos(angleRad)*m_origin.second) / m_delta.second);
      indexMax = (int)std::round(((tileSize[1] - m_origin.second)*cos(angleRad) + sin(angleRad)*m_origin.first) / m_delta.second);
    }
  }
  else if (cos(angleRad)*sin(angleRad) < 0)
  {
    if (abs(m_delta.second) < cEpsilon)
    {
      indexMin = 0;
      indexMax = 0;
    }
    else
    {
      indexMin = (int)std::round((m_origin.first*sin(angleRad) - m_origin.second*cos(angleRad)) / m_delta.second);
      indexMax = (int)std::round(((tileSize[1] - m_origin.second)*cos(angleRad) - (tileSize[0] - m_origin.first)*sin(angleRad)) / m_delta.second);
    }
  }

  // generate family line instances
  int start = std::min(indexMin, indexMax);
  int end = std::max(indexMin, indexMax);

  for (auto i = start; i <= end; i++)
  {
    res.emplace_back(m_angle, m_origin, m_delta, m_intervals, i, std::vector<double>{ tileSize[0] /*+ 0.01*/, tileSize[1] /*+ 0.01*/ });
  }
  
  return res;
}

std::vector<std::tuple<int, Point, Point>> CPatFamily::generateSegments(const std::vector<double>& tileSize)
{
  std::vector<CPatLine> patLines = lines(std::vector<double>{ tileSize[0], tileSize[1] });

  return CTileLineAligner().getAligned(patLines, tileSize[0], tileSize[1]);
}

void CPatFamily::recalculate(double unitKoef)
{
  m_origin.first *= unitKoef;
  m_origin.second *= unitKoef;

  m_delta.first *= unitKoef;
  m_delta.second *= unitKoef;

  for (auto& interval : m_intervals)
  {
    interval *= unitKoef;
  }

  recalculateLength();
}

std::vector<double> CPatFamily::length()
{
  return m_length;
}

bool CPatFamily::operator==(const CPatFamily& other) const
{
  bool intervalsAreEqual = std::equal(m_intervals.begin(), m_intervals.end(), other.m_intervals.begin(),
    [](double left, double right)
  {
    return std::abs(left - right) < cEpsilon;
  });

  return std::abs(m_angle - other.m_angle) < cEpsilon
    && std::abs(m_origin.first - other.m_origin.first) < cEpsilon
    && std::abs(m_origin.second - other.m_origin.second) < cEpsilon
    && std::abs(m_delta.first - other.m_delta.first) < cEpsilon
    && std::abs(m_delta.second - other.m_delta.second) < cEpsilon
    && intervalsAreEqual;
}

bool CPatFamily::operator!=(const CPatFamily& other) const
{
  return !operator==(other);
}

bool CPatFamily::operator<(const CPatFamily& other) const
{
  if (m_angle != other.m_angle)
    return (m_angle < other.m_angle);
  if (std::abs(m_origin.first - other.m_origin.first) >= cEpsilon)
    return (m_origin.first < other.m_origin.first);
  if (std::abs(m_origin.second - other.m_origin.second) >= cEpsilon)
    return (m_origin.second < other.m_origin.second);
  if (std::abs(m_delta.first - other.m_delta.first) >= cEpsilon)
    return (m_delta.first < other.m_delta.first);
  if (std::abs(m_delta.second - other.m_delta.second) >= cEpsilon)
    return (m_delta.second < other.m_delta.second);
  if (m_intervals.size() != other.m_intervals.size())
    return m_intervals.size() < other.m_intervals.size();

  for (size_t i = 0; i < m_intervals.size(); ++i)
  {
    if (std::abs(m_intervals[i] - other.m_intervals[i]) >= cEpsilon)
      return (m_intervals[i] < other.m_intervals[i]);
  }

  return false;
}

