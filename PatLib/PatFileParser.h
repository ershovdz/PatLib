#pragma once

#include "patglobal.h"
#include "PatPattern.h"

  class CPatFileParser
  {
  public:
    static std::vector<CPatPattern> loadPatterns(const std::wstring& filename);
  };

