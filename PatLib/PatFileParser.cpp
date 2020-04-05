#include "PatFileParser.h"

#include <fstream>
#include <codecvt>

#define _UNICODE 1
#define WIN32_LEAN_AND_MEAN 1


namespace
{
  std::wstring nameFrom(std::wstring line)
  {
    std::wstring name;

    size_t asteriskPos = line.find(L"*");
    size_t firstCommaPos = line.find(L",");
    size_t semicolonPos = line.find(L";");

    if (asteriskPos == 0)
    {
      if (firstCommaPos != std::string::npos)
      {
        if (semicolonPos != std::string::npos)
        {
          if (firstCommaPos < semicolonPos)
            name = line.substr(1, firstCommaPos - 1);
          else
            name = line.substr(1, semicolonPos - 1);
        }
        else
        {
          name = line.substr(1, firstCommaPos - 1);
        }
      }
      else
      {
        if (semicolonPos != std::string::npos)
          name = line.substr(1, semicolonPos - 1);
        else
          name = line.substr(1);
      }
    }

    return name;
  }  

  std::wstring descriptionFrom(std::wstring line)
  {
    std::wstring description;

    size_t asteriskPos = line.find(L"*");
    size_t firstCommaPos = line.find(L",");
    size_t semicolonPos = line.find(L";");

    if (asteriskPos == 0)
    {
      if (firstCommaPos != std::string::npos)
      {
        if (semicolonPos != std::string::npos)
        {
          if (firstCommaPos < semicolonPos)
            description = line.substr(firstCommaPos + 1, semicolonPos - firstCommaPos - 1);
        }
        else
          description = line.substr(firstCommaPos + 1);
      }      
    }

    return description;
  }

  std::vector<CPatPattern> parsePatterns(std::wifstream& infile)
  {
    std::vector<CPatPattern> patternCollection;

    std::wstring line;
    while (std::getline(infile, line))
    {
      size_t asteriskPos = line.find(L"*");

      if (asteriskPos == 0)
      {
        CPatPattern pattern;

        pattern.setName(nameFrom(line));
        pattern.setDescription(descriptionFrom(line));
        patternCollection.push_back(pattern);
      }
      else if (line.find(L";") == std::string::npos && line.length() > 0)
      {
        if (!patternCollection.empty())
          patternCollection.back().addFamily(line);
      }
    }

		for (auto& pattern : patternCollection)
		{
			pattern.calculateTileSize();
			
		}

    return patternCollection;
  }
}



std::vector<CPatPattern> CPatFileParser::loadPatterns(const std::wstring& filename)
{
  std::vector<CPatPattern> patternCollection;

  const std::locale utf16_locale_in = std::locale(std::locale::empty(),
    new std::codecvt_utf8_utf16<wchar_t>());

  std::wifstream infile(filename);
  infile.imbue(utf16_locale_in);
  patternCollection = parsePatterns(infile);

  if (patternCollection.empty())
  {
    std::wifstream newInfile(filename);

    patternCollection = parsePatterns(newInfile);
  }

  return patternCollection;
}

