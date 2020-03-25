#pragma once

#include "PatLine.h"
#include <vector>
#include <unordered_set>

class CPatUtils
{
public:
  static std::pair<double, double> getPQ(std::vector<double>& a, int iteration);
  static std::pair<double, double> getApproximation(double r, int iteration);
  static double byMod(double x, double mod);
};

struct Point
{
  double x, y;

  double distanceTo(const Point& other) const;
  bool operator<(const Point& p) const;
};

class CTileChecker
{
public:
  static bool checkFamilySegments(const std::vector<std::tuple<int, Point, Point>>& familySegments, double tileWidth, double tileHeight, std::unordered_set<int>& invalidSegmentIndices);

private:
  static std::vector<std::tuple<int, Point, Point, Point, Point, int>> filterSegmentsBySideIntersection(const std::vector<std::tuple<int, Point, Point>>& familySegments, Point sideStart, Point sideEnd);
  static bool checkSegmentsForOppositeSides(const std::vector<std::tuple<int, Point, Point, Point, Point, int>>& firstSideSegments, const std::vector<std::tuple<int, Point, Point, Point, Point, int>>& secondSideSegments, double sidesDistance, std::unordered_set<int>& invalidSegmentIndices);
};

class CTileLineAligner
{
public:
  std::vector<std::tuple<int, Point, Point>> getAligned(const std::vector<CPatLine>& lines, double tileWidth, double tileHeight);

private:
  void addAlignedLineSegments(const CPatLine& line, double tileWidth, double tileHeight, std::vector<std::tuple<int, Point, Point>>& alignedSegments);
  bool getAlignVectorIfTargetLineExist(const Point& start, const Point& end, int intervalIndex, double tileWidth, double tileHeight, double& xOffset, double& yOffset);

private:
  double alignEps = 0.08;
  std::vector<std::tuple<int, Point, Point>> alignData;
};

