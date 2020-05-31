#pragma once

#include "patglobal.h"
#include "PatLine.h"
#include "PatUtils.h"

#include <memory>
#include <string>
#include <vector>

class CPatFamily
{
public:
  CPatFamily();
  ~CPatFamily() = default;
  bool operator==(const CPatFamily& other) const;
  bool operator!=(const CPatFamily& other) const;
  bool operator<(const CPatFamily& other) const;

  void parse(const std::wstring& family);
  void recalculateLength();
  void recalculate(double unitKoef);
  std::vector<double> length();
  std::vector<double> clippedLength();

  std::vector<CPatLine> lines(const std::vector<double>& tileSize);
  std::vector<std::tuple<int, Point, Point>> generateSegments(const std::vector<double>& tileSize);

  bool isOrnamentBroken(double periodX, double periodY);
  CPatLine getDual(CPatLine& line, const std::vector<CPatLine>& linesForPeriod, double periodX, double periodY);
public:
  double m_angle;
  std::pair<double, double> m_origin;
  std::pair<double, double> m_delta;
  std::vector<double> m_intervals;
  std::vector<double> m_length{ -1.f,-1.f };
  std::vector<double> m_clippedLength{ -1.f,-1.f };
  std::vector<double> m_minPeriod{ 0.f, 0.f };
};
