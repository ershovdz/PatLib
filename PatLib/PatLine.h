﻿#pragma once

#include "patglobal.h"
#include <vector>

class CPatLine
{
public:
  CPatLine() = default;
  CPatLine(double angle, const std::pair<double, double>& origin, const std::pair<double, double>& delta, const std::vector<double>& intervals, int index, const std::vector<double>& maxLength);
  ~CPatLine() = default;

  std::pair<double, double> func(double arg) const;
  double funcMinusOneX(double x) const;
  double funcMinusOneY(double y) const;

  double length();
  std::vector<int> CPatLine::getIntervalNumbers(double arg);
private:
  void init(const std::vector<double>& maxLength);
public:
  double m_angle;
  std::pair<double, double> m_origin;
  std::pair<double, double> m_delta;
  std::vector<double> m_intervals;
  int m_index;
  std::vector<std::tuple<int, double, double> > m_definitions;
  double m_t0;
  double m_t1;
  bool m_initialized{ false };
};
