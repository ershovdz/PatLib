#pragma once

#include "patglobal.h"
#include "PatFamily.h"

#include <vector>
#include <string>

  class CPatPattern
  {
  public:
    CPatPattern() = default;
    ~CPatPattern() = default;

    void addFamily(const std::wstring& family);

    std::wstring name() const { return m_name; }
    void setName(const std::wstring& name) { m_name = name; }
    void setDescription(const std::wstring& desc) { m_description = desc; }
    std::wstring description() const { return m_description; }

    std::vector<CPatFamily>& families() { return m_families; }
    std::vector<double>& length();
    void recalculate(double unitKoef);
    void calculateTileSize();

  private:
    int countErrors(const std::vector<double>& tileSize);
    std::vector<double> calculateTileSize1();
    std::vector<double> calculateTileSize2();
  private:
    std::wstring m_name;
    std::wstring m_description;
    std::vector<CPatFamily> m_families;
		std::vector<double> m_tileSize{0.f, 0.f};
  };


