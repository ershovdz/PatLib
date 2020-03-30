#include "PatUtils.h"

#include <tuple>
#include <algorithm>

namespace
{
  static double cEpsilon = 0.0001;
  static double cDelta = 0.015;

  struct Line
  {
    double a, b, c;

    Line() {}
    Line(Point p, Point q)
    {
      a = p.y - q.y;
      b = q.x - p.x;
      c = -a * p.x - b * p.y;
      norm();
    }

    void norm()
    {
      double z = sqrt(a * a + b * b);
      if (abs(z) > cEpsilon)
        a /= z, b /= z, c /= z;
    }

    double dist(Point p) const { return a * p.x + b * p.y + c; }
  };

  double det(double a, double b, double c, double d)
  {
    return a * d - b * c;
  }

  inline bool betw(double l, double r, double x)
  {
    return std::min(l, r) <= x + cEpsilon && x <= std::max(l, r) + cEpsilon;
  }

  inline bool intersect_1d(double a, double b, double c, double d)
  {
    if (a > b)
      std::swap(a, b);
    if (c > d)
      std::swap(c, d);
    return std::max(a, c) <= std::min(b, d) + cEpsilon;
  }

  bool intersect(Point a, Point b, Point c, Point d, Point& left, Point& right)
  {
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
      return false;
    Line m(a, b);
    Line n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < cEpsilon)
    {
      if (abs(m.dist(c)) > cEpsilon || abs(n.dist(a)) > cEpsilon)
        return false;
      if (b < a)
        std::swap(a, b);
      if (d < c)
        std::swap(c, d);
      left = std::max(a, c);
      right = std::min(b, d);
      return true;
    }
    else
    {
      left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
      left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
      return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
        betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
  }
}

double Point::distanceTo(const Point& other) const
{
  return ::_hypot(x - other.x, y - other.y);
}

bool Point::operator<(const Point& p) const
{
  return x < p.x - cEpsilon || (std::abs(x - p.x) < cEpsilon && y < p.y - cEpsilon);
}

bool CTileChecker::checkFamilySegments(const std::vector<std::tuple<int, Point, Point>>& familySegments, double tileWidth, double tileHeight, std::unordered_set<int>& invalidSegmentIndices)
{
  auto segmentsForLeftSide = filterSegmentsBySideIntersection(familySegments, Point{ 0,0 }, Point{ 0,tileHeight });
  auto segmentsForRightSide = filterSegmentsBySideIntersection(familySegments, Point{ tileWidth, 0 }, Point{ tileWidth ,tileHeight });

  auto segmentsForTopSide = filterSegmentsBySideIntersection(familySegments, Point{ 0,0 }, Point{ tileWidth,0 });
  auto segmentsForBottomSide = filterSegmentsBySideIntersection(familySegments, Point{ 0, tileHeight }, Point{ tileWidth ,tileHeight });

  return
    checkSegmentsForOppositeSides(segmentsForLeftSide, segmentsForRightSide, tileWidth, invalidSegmentIndices) &&
    checkSegmentsForOppositeSides(segmentsForTopSide, segmentsForBottomSide, tileHeight, invalidSegmentIndices);
}

std::vector<std::tuple<int, Point, Point, Point, Point, int>> CTileChecker::filterSegmentsBySideIntersection(const std::vector<std::tuple<int, Point, Point>>& familySegments, Point sideStart, Point sideEnd)
{
  std::vector<std::tuple<int, Point, Point, Point, Point, int>> result;

  for (int i = 0; i < familySegments.size(); ++i)
  {
    auto&& segment = familySegments[i];
    Point firstIntersectPoint, secondIntersectPoint;

    if (intersect(std::get<1>(segment), std::get<2>(segment), sideStart, sideEnd, firstIntersectPoint, secondIntersectPoint))
      result.push_back(std::make_tuple(std::get<0>(segment), std::get<1>(segment), std::get<2>(segment), firstIntersectPoint, secondIntersectPoint, i));
  }

  return result;
}

bool CTileChecker::checkSegmentsForOppositeSides(const std::vector<std::tuple<int, Point, Point, Point, Point, int>>& firstSideSegments, const std::vector<std::tuple<int, Point, Point, Point, Point, int>>& secondSideSegments, double sidesDistance, std::unordered_set<int>& invalidSegmentIndices)
{
  if (firstSideSegments.size() != secondSideSegments.size())
  {
    for(auto& segment : firstSideSegments)
      invalidSegmentIndices.insert(std::get<5>(segment));

    for (auto& segment : secondSideSegments)
      invalidSegmentIndices.insert(std::get<5>(segment));

    return false;
  }    

  bool isOk = true;

  for (int i = 0; i < firstSideSegments.size(); ++i)
  {
    bool hasOppositeSegment = false;

    auto&& segmentForFirstSide = firstSideSegments[i];
    double firstSegmentLength = std::get<1>(segmentForFirstSide).distanceTo(std::get<2>(segmentForFirstSide));

    for (int j = 0; j < secondSideSegments.size(); ++j)
    {
      auto&& segmentForSecondSide = secondSideSegments[j];
      double secondSegmentLength = std::get<1>(segmentForSecondSide).distanceTo(std::get<2>(segmentForSecondSide));

      if (std::get<0>(segmentForFirstSide) == std::get<0>(segmentForSecondSide))
      {
        // single-interval segments
        if (firstSegmentLength > sidesDistance && secondSegmentLength > sidesDistance)
        {
          auto&& sideIntersectPointForFirstSegment = std::get<3>(segmentForFirstSide);
          auto&& sideIntersectPointForSecondSegment = std::get<3>(segmentForSecondSide);

          auto distanceBetweenIntersectPointsByX = abs(sideIntersectPointForFirstSegment.x - sideIntersectPointForSecondSegment.x);
          auto distanceBetweenIntersectPointsByY = abs(sideIntersectPointForFirstSegment.y - sideIntersectPointForSecondSegment.y);

          if (distanceBetweenIntersectPointsByX < cEpsilon || abs(distanceBetweenIntersectPointsByX - sidesDistance) < cEpsilon)
          {
            if (distanceBetweenIntersectPointsByY < cEpsilon || abs(distanceBetweenIntersectPointsByY - sidesDistance) < cEpsilon)
            {
              hasOppositeSegment = true;
              break;
            }
          }
        }
        else
        {
          auto&& firstSegmentStartPoint = std::get<1>(segmentForFirstSide);
          auto&& secondSegmentStartPoint = std::get<1>(segmentForSecondSide);

          auto distanceBetweenSegmentsByX = abs(firstSegmentStartPoint.x - secondSegmentStartPoint.x);
          auto distanceBetweenSegmentsByY = abs(firstSegmentStartPoint.y - secondSegmentStartPoint.y);

          if (distanceBetweenSegmentsByX < cEpsilon || abs(distanceBetweenSegmentsByX - sidesDistance) < cEpsilon)
          {
            if (distanceBetweenSegmentsByY < cEpsilon || abs(distanceBetweenSegmentsByY - sidesDistance) < cEpsilon)
            {
              hasOppositeSegment = true;
              break;
            }
          }
        }
      }
    }

    if (!hasOppositeSegment)
    {
      invalidSegmentIndices.insert(std::get<5>(segmentForFirstSide));
      isOk = false;
    }      
  }

  return isOk;
}

std::vector<std::tuple<int, Point, Point>> CTileLineAligner::getAligned(const std::vector<CPatLine>& lines, double tileWidth, double tileHeight)
{
  alignData.clear();
  std::vector<std::tuple<int, Point, Point>> result;

  if (lines.empty())
    return result;

  
  alignEps = std::min(lines[0].m_delta.first / 12., lines[0].m_delta.second / 12.);
  if (alignEps < 0.00001)
    alignEps = std::max(lines[0].m_delta.first / 12., lines[0].m_delta.second / 12.);

  for (auto& line : lines)
  {
    if (line.m_index == 0)
    {
      addAlignedLineSegments(line, tileWidth, tileHeight, result);
    }
  }

  for (auto& line : lines)
  {
    if (line.m_index != 0)
    {
      addAlignedLineSegments(line, tileWidth, tileHeight, result);
    }
  }

  return result;
}

void CTileLineAligner::addAlignedLineSegments(const CPatLine& line, double tileWidth, double tileHeight, std::vector<std::tuple<int, Point, Point>>& alignedSegments)
{
  for (auto& definition : line.m_definitions)
  {
    auto start = line.func(std::get<0>(definition));
    auto end = line.func(std::get<1>(definition));
    auto intervalIndex = std::get<2>(definition);

    double xOffset = 0;
    double yOffset = 0;
    if (getAlignVectorIfTargetLineExist(Point{ start.first, start.second }, Point{ end.first, end.second }, intervalIndex, tileWidth, tileHeight, xOffset, yOffset))
    {
      start.first += xOffset;
      start.second += yOffset;

      end.first += xOffset;
      end.second += yOffset;
            
      /*start.first = std::round(start.first * 10000.0) / 10000.0;
      start.second = std::round(start.second * 10000.0) / 10000.0;
      
      end.first = std::round(end.first * 10000.0) / 10000.0;
      end.second = std::round(end.second * 10000.0) / 10000.0;*/

      alignedSegments.push_back(std::make_tuple(intervalIndex, Point{ start.first, start.second }, Point{ end.first, end.second }));
    }
    else
    {
      /*start.first = std::round(start.first * 10000.0) / 10000.0;
      start.second = std::round(start.second * 10000.0) / 10000.0;

      end.first = std::round(end.first * 10000.0) / 10000.0;
      end.second = std::round(end.second * 10000.0) / 10000.0;*/

      alignedSegments.push_back(std::make_tuple(intervalIndex, Point{ start.first, start.second }, Point{ end.first, end.second }));
    }
  }
}

//bool CTileLineAligner::getAlignVectorIfTargetLineExist(const Point& start, const Point& end, int intervalIndex, double tileWidth, double tileHeight, double& xOffset, double& yOffset)
//{
//  xOffset = 0;
//  yOffset = 0;
//
//  for (auto& existedSegment : alignData)
//  {
//    bool lineAlreadyExist = false;
//
//    auto existedIntervalIndex = std::get<0>(existedSegment);
//    auto existedLineStartPoint = std::get<1>(existedSegment);
//
//    if (intervalIndex == existedIntervalIndex)
//    {
//      auto distanceX = abs(existedLineStartPoint.x - start.x);
//      auto distanceY = abs(existedLineStartPoint.y - start.y);
//            
//      if (abs(tileWidth - distanceX) < alignEps && distanceY < alignEps)
//      {
//        lineAlreadyExist = true;
//        if (existedLineStartPoint.x > start.x)
//          xOffset = existedLineStartPoint.x - tileWidth - start.x;
//        else
//          xOffset = existedLineStartPoint.x + tileWidth - start.x;
//
//        yOffset = existedLineStartPoint.y - start.y;
//      }
//
//      /*else if (distanceX < alignEps)
//      {
//        lineAlreadyExist = true;
//        xOffset = existedLineStartPoint.x - start.x;
//      }*/
//
//      if (abs(tileHeight - distanceY) < alignEps && distanceX < alignEps)
//      {
//        lineAlreadyExist = true;
//        if (existedLineStartPoint.y > start.y)
//          yOffset = existedLineStartPoint.y - tileHeight - start.y;// -abs(tileHeight - distanceY);
//        else
//          yOffset = existedLineStartPoint.y + tileHeight - start.y;// abs(tileHeight - distanceY);
//
//        xOffset = existedLineStartPoint.x - start.x;
//      }
//      /*else if (distanceY < alignEps)
//      {
//        lineAlreadyExist = true;
//        yOffset = existedLineStartPoint.y - start.y;
//      }*/
//    }
//
//    if (lineAlreadyExist)
//      return true;
//  }
//
//
//  Point firstIntersectPoint, secondIntersectPoint;
//  bool intersectSide = intersect(start, end, Point{ 0,0 }, Point{ 0,tileHeight }, firstIntersectPoint, secondIntersectPoint) ||
//    intersect(start, end, Point{ tileWidth, 0 }, Point{ tileWidth ,tileHeight }, firstIntersectPoint, secondIntersectPoint) ||
//    intersect(start, end, Point{ 0,0 }, Point{ tileWidth,0 }, firstIntersectPoint, secondIntersectPoint) ||
//    intersect(start, end, Point{ 0, tileHeight }, Point{ tileWidth ,tileHeight }, firstIntersectPoint, secondIntersectPoint);
//  
//  if(intersectSide)
//    alignData.push_back(std::make_tuple(intervalIndex, Point{ start.x, start.y }, Point{ end.x, end.y }));
//
//  return false;
//}

bool CTileLineAligner::getAlignVectorIfTargetLineExist(const Point& start, const Point& end, int intervalIndex, double tileWidth, double tileHeight, double& xOffset, double& yOffset)
{
  xOffset = 0;
  yOffset = 0;

  for (auto& existedSegment : alignData)
  {
    bool lineAlreadyExist = false;

    auto existedIntervalIndex = std::get<0>(existedSegment);
    auto existedLineStartPoint = std::get<1>(existedSegment);

    if (intervalIndex == existedIntervalIndex)
    {
      auto distanceX = abs(existedLineStartPoint.x - start.x);
      auto distanceY = abs(existedLineStartPoint.y - start.y);

      if (distanceX < alignEps)
      {
        lineAlreadyExist = true;
        xOffset = existedLineStartPoint.x - start.x;
      }
      else if (abs(tileWidth - distanceX) < alignEps)
      {
        lineAlreadyExist = true;
        if (existedLineStartPoint.x > start.x)
          xOffset = -abs(tileWidth - distanceX);
        else
          xOffset = abs(tileWidth - distanceX);
      }

      if (distanceY < alignEps)
      {
        lineAlreadyExist = true;
        yOffset = existedLineStartPoint.y - start.y;
      }
      else if (abs(tileHeight - distanceY) < alignEps)
      {
        lineAlreadyExist = true;
        if (existedLineStartPoint.y > start.y)
          yOffset = -abs(tileHeight - distanceY);
        else
          yOffset = abs(tileHeight - distanceY);
      }
    }

    if (lineAlreadyExist)
      return true;
  }

  Point firstIntersectPoint, secondIntersectPoint;
  bool intersectSide = intersect(start, end, Point{ 0,0 }, Point{ 0,tileHeight }, firstIntersectPoint, secondIntersectPoint) ||
    intersect(start, end, Point{ tileWidth, 0 }, Point{ tileWidth ,tileHeight }, firstIntersectPoint, secondIntersectPoint) ||
    intersect(start, end, Point{ 0,0 }, Point{ tileWidth,0 }, firstIntersectPoint, secondIntersectPoint) ||
    intersect(start, end, Point{ 0, tileHeight }, Point{ tileWidth ,tileHeight }, firstIntersectPoint, secondIntersectPoint);

  if (intersectSide)
    alignData.push_back(std::make_tuple(intervalIndex, Point{ start.x, start.y }, Point{ end.x, end.y }));

  return false;
}

std::pair<double, double> CPatUtils::getApproximation(double r, int iteration)
{
  double a0;
  modf(r, &a0);
  std::vector<double> a;
  a.push_back(a0);
  std::vector<double> x;
  x.push_back(r - a[0]);
  if (x.back() > cDelta)
  {
    for (int i = 0; i < iteration; i++)
    {
      modf((1 / x.back()), &a0);
      a.push_back(a0);
      x.push_back(1 / (x.back()) - a.back());
    }
  }

  return getPQ(a, iteration);
}

std::pair<double, double> CPatUtils::getPQ(std::vector<double>& a, int iteration)
{
  if (iteration == -1)
  {
    return std::pair<double, double>(1, 0);
  }
  else if (iteration == 0 || a.size() <= iteration)
  {
    return std::pair<double, double>(a[0], 1);
  }
  else
  {
    auto pair1 = getPQ(a, iteration - 1);
    auto pair2 = getPQ(a, iteration - 2);
    return std::pair<double, double>(a[iteration] * pair1.first + pair2.first, a[iteration] * pair1.second + pair2.second);
  }
}

double CPatUtils::byMod(double x, double mod)
{
  double res = x;
  if (x >= mod || abs(x - mod) <= 0.001f)
  {
    auto roundedX = std::round(x * 10000.0) / 10000.0;
    auto roundedMod = std::round(mod * 10000.0) / 10000.0;
    res = (roundedX / roundedMod) - std::ceil(roundedX / roundedMod);
  }

  return res;
}
