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
  auto tileSize1 = calculateTileSize1();
  auto numErrors1 = countErrors(tileSize1);
  if (numErrors1 > 0)
  {
    auto tileSize2 = calculateTileSize2();
    auto numErrors2 = countErrors(tileSize2);
    if (numErrors2 < numErrors1)
    {
      m_tileSize[0] = tileSize2[0];
      m_tileSize[1] = tileSize2[1];
    }
    else
    {
      m_tileSize[0] = tileSize1[0];
      m_tileSize[1] = tileSize1[1];
    }
  }
  else
  {
    m_tileSize[0] = tileSize1[0];
    m_tileSize[1] = tileSize1[1];
  }
}

std::vector<double> CPatPattern::calculateTileSize1()
{
  std::vector<double> res{ 0.f, 0.f };

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

std::vector<double> CPatPattern::calculateTileSize2()
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
  int res = 0;
  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : m_families)
  {
    auto alignedFamilySegments = f.generateSegments(tileSize);
    bool isOk = CTileChecker::checkFamilySegments(alignedFamilySegments, tileSize[0], tileSize[1], invalidSegmentIndices);
    res += 1 ? alignedFamilySegments.size() == 0 : 0;
    res += invalidSegmentIndices.size();
  }

  return res;
}