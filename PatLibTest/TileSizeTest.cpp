#include <gmock/gmock.h>

#include <PatFileParser.h>

TEST(TileSizeTest, RENGA_DASH)
{
  std::wstring path(L"renga_dash.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();
  
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1]));
  }
}

TEST(TileSizeTest, ANSI35)
{
  std::wstring path(L"ansi35.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1]));
  }
}

TEST(TileSizeTest, ANSI36)
{
  std::wstring path(L"ansi36.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1]));
  }
}