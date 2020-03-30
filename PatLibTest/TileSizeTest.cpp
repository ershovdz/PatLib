#include <gmock/gmock.h>

#include <PatFileParser.h>

TEST(TileSizeTest, RENGA_DASH)
{
  std::wstring path(L"../data/renga_dash.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();
  
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, RENGA_DASHDOT)
{
  std::wstring path(L"../data/renga_dashdot.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, RENGA_DASHDOTLINE)
{
  std::wstring path(L"../data/renga_dashdotline.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, RENGA_DASH2)
{
  std::wstring path(L"../data/renga_dash2.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, RENGA_LINE)
{
  std::wstring path(L"../data/renga_line.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, RENGA_BILINE)
{
  std::wstring path(L"../data/renga_biline.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, RENGA_TRILINE)
{
  std::wstring path(L"../data/renga_triline.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, RENGA_DOTS)
{
  std::wstring path(L"../data/renga_dots.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  std::unordered_set<int> invalidSegmentIndices;

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 3);
}

TEST(TileSizeTest, ANSI31)
{
  std::wstring path(L"../data/ansi31.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ANSI32)
{
  std::wstring path(L"../data/ansi32.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ANSI33)
{
  std::wstring path(L"../data/ansi33.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ANSI34)
{
  std::wstring path(L"../data/ansi34.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ANSI35)
{
  std::wstring path(L"../data/ansi35.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ANSI36)
{
  std::wstring path(L"../data/ansi36.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ANSI37)
{
  std::wstring path(L"../data/ansi37.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ANSI38)
{
  std::wstring path(L"../data/ansi38.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, STARS)
{
  std::wstring path(L"../data/stars.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, GRAVEL)
{
  std::wstring path(L"../data/gravel1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
    if (!invalidSegmentIndices.empty())
      return;
  }
}

TEST(TileSizeTest, ANGLESTEEL)
{
  std::wstring path(L"../data/angle_steel.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, CROSS)
{
  std::wstring path(L"../data/cross.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ARB816)
{
  std::wstring path(L"../data/arb816.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ARB816C)
{
  std::wstring path(L"../data/arb816c.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ARB88)
{
  std::wstring path(L"../data/arb88.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ARBRELM)
{
  std::wstring path(L"../data/arbrelm.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ARBRSTD)
{
  std::wstring path(L"../data/arbrstd.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, ARHBONE)
{
  std::wstring path(L"../data/arhbone.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, ARPARQ1)
{
  std::wstring path(L"../data/arparq1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ARROOF)
{
  std::wstring path(L"../data/arroof.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ARSHKE)
{
  std::wstring path(L"../data/arshke.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, BOX)
{
  std::wstring path(L"../data/box.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    std::unordered_set<int> invalidSegmentIndices;
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}
