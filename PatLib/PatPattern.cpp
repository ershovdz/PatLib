#include <algorithm>
#include <map>
#include "PatFamily.h"
#include "PatPattern.h"
#include "PatUtils.h"

static double cDelta = 0.015;

void CPatPattern::addFamily(const std::wstring& subLine)
{
	CPatFamily patFamily;
	patFamily.parse(subLine);
	m_families.push_back(patFamily);
}

std::vector<double>& CPatPattern::length()
{
	return m_tileSize;
}

void CPatPattern::calculateTileSize()
{
  for (int i = 0; i < 2; i++)
  {
    std::map<double, int> allLengths;
    if (m_families.size() == 1)
    {
      allLengths[m_families[0].length()[i]] = 1;
    }
    else
    {
      for (auto& fam : m_families)
      {
        if (fam.length()[i] > 0)
        {
          bool found = false;
          for (auto& len : allLengths)
          {
            if (abs(len.first - fam.length()[i]) < cDelta)
            {
              found = true;
              allLengths[len.first]++;
              break;
            }
          }
          if (!found)
          {
            allLengths[fam.length()[i]]++;
          }
        }
      }
    }

    // Fill minLengths
    std::map<double, int> minLengths;
    for (auto& fam : m_families)
    {
      if (fam.m_minPeriod[i] > 0)
      {
        bool found = false;
        for (auto& len : minLengths)
        {
          if (abs(len.first - fam.m_minPeriod[i]) < cDelta)
          {
            found = true;
            minLengths[len.first]++;
            break;
          }
        }
        if (!found)
        {
          minLengths[fam.m_minPeriod[i]]++;
        }
      }
    }

    int maxOccurence = 1;
    double maxOccursLength = 0.f;
    for (auto& len : minLengths)
    {
      if (len.second >= maxOccurence)
      {
        maxOccursLength = len.first;
        maxOccurence = len.second;
      }
    }

    if (maxOccursLength == 0.f)
    {
      maxOccursLength = m_families[0].m_minPeriod[i];
    }

    double lenCand = 0.f;
    int occurence = 1;
    int count = 0;
    int midOccurence = 1.f;
    double sum = 0.f;
    for (auto& len : allLengths)
    {
      sum += len.second;
      count++;
      auto q = len.first / maxOccursLength;
      midOccurence = sum / count;
      if (abs(q - std::round(q)) < 0.01f && len.first > lenCand)
      {
        if (len.second >= midOccurence)
        {
          lenCand = len.first;
          occurence = len.second;
        }
      }
    }

    m_tileSize[i] = lenCand;
  }

  if (m_tileSize[0] <= 0.01)
  {
    m_tileSize[0] = m_tileSize[1];
  }

  if (m_tileSize[1] <= 0.01)
  {
    m_tileSize[1] = m_tileSize[0];
  }
}

void CPatPattern::recalculate(double unitKoef)
{
  for (auto& family : m_families)
  {
    family.recalculate(unitKoef);
  }
}

