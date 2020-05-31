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
  auto tileSizeWithClippedLength = calculateTileSizeUsingClippedLength();
  auto numErrorsWithClippedLength = countErrors(tileSizeWithClippedLength);
  if (numErrorsWithClippedLength > 0)
  {
    auto tileSizeWithLength = calculateTileSizeUsingLength();
    auto numErrorsWithLength = countErrors(tileSizeWithLength);
    if (numErrorsWithLength < numErrorsWithClippedLength)
    {
      m_tileSize[0] = tileSizeWithLength[0];
      m_tileSize[1] = tileSizeWithLength[1];
    }
    else
    {
      m_tileSize[0] = tileSizeWithClippedLength[0];
      m_tileSize[1] = tileSizeWithClippedLength[1];
    }
  }
  else
  {
    m_tileSize[0] = tileSizeWithClippedLength[0];
    m_tileSize[1] = tileSizeWithClippedLength[1];
  }
}

std::vector<double> CPatPattern::calculateTileSizeUsingClippedLength()
{
  std::vector<double> res{ 0.f, 0.f };

  for (int i = 0; i < 2; i++)
  {
    std::map<double, int> allLengths;
    if (m_families.size() == 1)
    {
      allLengths[m_families[0].clippedLength()[i]] = 1;
    }
    else
    {
      for (auto& family : m_families)
      {
        if (family.clippedLength()[i] > 0)
        {
          bool found = false;
          for (auto& len : allLengths)
          {
            if (abs(len.first - family.clippedLength()[i]) < cDelta)
            {
              found = true;
              allLengths[len.first]++;
              break;
            }
          }
          if (!found)
          {
            allLengths[family.clippedLength()[i]]++;
          }
        }
      }
    }

    // Fill minLengths
    std::map<double, int> minLengths;
    for (auto& family : m_families)
    {
      if (family.m_minPeriod[i] > 0)
      {
        bool found = false;
        for (auto& len : minLengths)
        {
          if (abs(len.first - family.m_minPeriod[i]) < cDelta)
          {
            found = true;
            minLengths[len.first]++;
            break;
          }
        }
        if (!found)
        {
          minLengths[family.m_minPeriod[i]]++;
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

    res[i] = lenCand;
  }

  if (res[0] <= 0.01)
  {
    res[0] = res[1];
  }

  if (res[1] <= 0.01)
  {
    res[1] = res[0];
  }

  return res;
}

std::vector<double> CPatPattern::calculateTileSizeUsingLength()
{
  std::vector<double> res{ 0.f, 0.f };

	for (int i = 0; i < 2; i++)
	{
		std::vector<double> lengths;
		if (m_families.size() == 1)
		{
			lengths.push_back(m_families[0].length()[i]);
		}
		else
		{
			for (auto& fam : m_families)
			{
				if (fam.length()[i] > 0)
				{
					bool found = false;
					for (auto& len : lengths)
					{
						if (abs(len - fam.length()[i]) < cDelta)
						{
							found = true;
							break;
						}
					}
					if (!found)
					{
						lengths.push_back(fam.length()[i]);
					}
				}
			}
		}

		std::pair<double, double> q;
		if (res[i] == 0.f && lengths.size() > 0)
		{
			res[i] = lengths[0];
		}

		for (auto& len : lengths)
		{
			if (abs(res[i] - len) > cDelta)
			{
				auto diff = res[i] / len;
				for (int k = 1; k <= 10; k++)
				{
					q = CPatUtils::getApproximation(diff, k);
					auto M = q.second*res[i] * cDelta;
					if (abs(q.second*res[i] - q.first*len) <= M) break;
				}
			}
			else
			{
				q = std::pair<double, double>(1.f, 1.f);
			}

			res[i] = abs(q.second*res[i] + q.first*len) / 2;
			if (res[i] > 50.f)
			{
				res[i] = *std::min_element(lengths.begin(), lengths.end());// lengths[0];
			}
		}
	}

  if (res[0] <= 0.5)
  {
    res[0] = res[1];
  }

  if (res[1] <= 0.5)
  {
    res[1] = res[0];
  }

  return res;
}

void CPatPattern::recalculate(double unitKoef)
{
  for (auto& family : m_families)
  {
    family.recalculate(unitKoef);
  }
}

int CPatPattern::countErrors(const std::vector<double>& tileSize)
{
  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : m_families)
  {
    auto alignedFamilySegments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(alignedFamilySegments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  return invalidSegmentIndices.size();
}