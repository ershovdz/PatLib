#include <algorithm>
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
		if (m_tileSize[i] == 0.f && lengths.size() > 0)
		{
			m_tileSize[i] = lengths[0];
		}

		for (auto& len : lengths)
		{
			if (abs(m_tileSize[i] - len) > cDelta)
			{
				auto diff = m_tileSize[i] / len;
				for (int k = 1; k <= 10; k++)
				{
					q = CPatUtils::getApproximation(diff, k);
					auto M = q.second*m_tileSize[i] * cDelta;
					if (abs(q.second*m_tileSize[i] - q.first*len) <= M) break;
				}
			}
			else
			{
				q = std::pair<double, double>(1.f, 1.f);
			}

			m_tileSize[i] = abs(q.second*m_tileSize[i] + q.first*len) / 2;
			if (m_tileSize[i] > 50.f)
			{
				m_tileSize[i] = *std::min_element(lengths.begin(), lengths.end());// lengths[0];
			}
		}
	}

  if (m_tileSize[0] <= 0.1)
  {
    m_tileSize[0] = length()[1];
  }

  if (m_tileSize[1] <= 0.1)
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

