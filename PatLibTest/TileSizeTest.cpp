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

  EXPECT_TRUE(invalidSegmentIndices.size() == 0);
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

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 13);
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

TEST(TileSizeTest, BRASS)
{
  std::wstring path(L"../data/brass.pat");
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

TEST(TileSizeTest, BRICK)
{
  std::wstring path(L"../data/brick.pat");
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

TEST(TileSizeTest, BRSTONE)
{
  std::wstring path(L"../data/brstone.pat");
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


TEST(TileSizeTest, CLAY)
{
  std::wstring path(L"../data/clay.pat");
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

TEST(TileSizeTest, CORK)
{
  std::wstring path(L"../data/cork.pat");
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

TEST(TileSizeTest, DOLMIT)
{
  std::wstring path(L"../data/dolmit.pat");
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

TEST(TileSizeTest, DOTS)
{
  std::wstring path(L"../data/dots.pat");
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

TEST(TileSizeTest, EARTH)
{
  std::wstring path(L"../data/earth.pat");
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

TEST(TileSizeTest, ESCHER)
{
  std::wstring path(L"../data/escher.pat");
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


TEST(TileSizeTest, Wood1)
{
  std::wstring path(L"../data/Wood_1.pat");
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

TEST(TileSizeTest, Wood2)
{
  std::wstring path(L"../data/Wood_2.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;

  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 0);
}

TEST(TileSizeTest, Wood3)
{
  std::wstring path(L"../data/Wood_3.pat");
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

TEST(TileSizeTest, Wood4)
{
  std::wstring path(L"../data/Wood_4.pat");
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

TEST(TileSizeTest, Wood5)
{
  std::wstring path(L"../data/Wood_5.pat");
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

TEST(TileSizeTest, FLEX)
{
  std::wstring path(L"../data/flex.pat");
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

TEST(TileSizeTest, GOSTGLASS)
{
  std::wstring path(L"../data/gostglass.pat");
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

TEST(TileSizeTest, GOSTWOOD)
{
  std::wstring path(L"../data/gostwood.pat");
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

TEST(TileSizeTest, GOSTGROUND)
{
  std::wstring path(L"../data/gostground.pat");
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

TEST(TileSizeTest, HEX)
{
  std::wstring path(L"../data/hex.pat");
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

TEST(TileSizeTest, INSUL)
{
  std::wstring path(L"../data/insul.pat");
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

TEST(TileSizeTest, GRATE)
{
  std::wstring path(L"../data/grate.pat");
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

TEST(TileSizeTest, GRASS)
{
  std::wstring path(L"../data/grass.pat");
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

TEST(TileSizeTest, HONEY)
{
  std::wstring path(L"../data/honey.pat");
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

TEST(TileSizeTest, HOUND)
{
  std::wstring path(L"../data/hound.pat");
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

TEST(TileSizeTest, ZIGZAG)
{
  std::wstring path(L"../data/zigzag.pat");
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



TEST(TileSizeTest, ACADISO02)
{
  std::wstring path(L"../data/acadiso02.pat");
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

TEST(TileSizeTest, ACADISO03)
{
  std::wstring path(L"../data/acadiso03.pat");
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

TEST(TileSizeTest, ACADISO04)
{
  std::wstring path(L"../data/acadiso04.pat");
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

TEST(TileSizeTest, ACADISO05)
{
  std::wstring path(L"../data/acadiso05.pat");
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

TEST(TileSizeTest, ACADISO06)
{
  std::wstring path(L"../data/acadiso06.pat");
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

TEST(TileSizeTest, ACADISO07)
{
  std::wstring path(L"../data/acadiso07.pat");
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

TEST(TileSizeTest, ACADISO08)
{
  std::wstring path(L"../data/acadiso08.pat");
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

TEST(TileSizeTest, ACADISO09)
{
  std::wstring path(L"../data/acadiso09.pat");
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

TEST(TileSizeTest, ACADISO10)
{
  std::wstring path(L"../data/acadiso10.pat");
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

TEST(TileSizeTest, ACADISO11)
{
  std::wstring path(L"../data/acadiso11.pat");
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

TEST(TileSizeTest, ACADISO12)
{
  std::wstring path(L"../data/acadiso12.pat");
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

TEST(TileSizeTest, ACADISO13)
{
  std::wstring path(L"../data/acadiso13.pat");
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

TEST(TileSizeTest, ACADISO14)
{
  std::wstring path(L"../data/acadiso14.pat");
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

TEST(TileSizeTest, ACADISO15)
{
  std::wstring path(L"../data/acadiso15.pat");
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

TEST(TileSizeTest, MUDST)
{
  std::wstring path(L"../data/mudst.pat");
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

TEST(TileSizeTest, NET)
{
  std::wstring path(L"../data/net.pat");
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

TEST(TileSizeTest, NET3)
{
  std::wstring path(L"../data/NET3.pat");
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

TEST(TileSizeTest, PLAST)
{
  std::wstring path(L"../data/plast.pat");
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

TEST(TileSizeTest, PLASTI)
{
  std::wstring path(L"../data/plasti.pat");
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

TEST(TileSizeTest, SACNCR)
{
  std::wstring path(L"../data/sacncr.pat");
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

TEST(TileSizeTest, SQUARE)
{
  std::wstring path(L"../data/square.pat");
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

TEST(TileSizeTest, STEEL)
{
  std::wstring path(L"../data/steel.pat");
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

TEST(TileSizeTest, SWAMP)
{
  std::wstring path(L"../data/swamp.pat");
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

TEST(TileSizeTest, TRANS)
{
  std::wstring path(L"../data/trans.pat");
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

TEST(TileSizeTest, TRIANG)
{
  std::wstring path(L"../data/triang.pat");
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

TEST(TileSizeTest, ALUMINUM)
{
  std::wstring path(L"../data/aluminum.pat");
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

TEST(TileSizeTest, CEILING24)
{
  std::wstring path(L"../data/ceiling24.pat");
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

TEST(TileSizeTest, CEILING48)
{
  std::wstring path(L"../data/ceiling48.pat");
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

TEST(TileSizeTest, CONCRETEPAVER)
{
  std::wstring path(L"../data/concrete_paver.pat");
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

TEST(TileSizeTest, PARQUET)
{
  std::wstring path(L"../data/parquet.pat");
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

TEST(TileSizeTest, PARTICLE)
{
  std::wstring path(L"../data/particle.pat");
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


TEST(TileSizeTest, SHAKE)
{
  std::wstring path(L"../data/shake.pat");
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

TEST(TileSizeTest, WOODBOARD)
{
  std::wstring path(L"../data/wood_board.pat");
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

TEST(TileSizeTest, WOODCORK)
{
  std::wstring path(L"../data/wood_cork.pat");
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

TEST(TileSizeTest, HERRINGBONE)
{
  std::wstring path(L"../data/herring_bone.pat");
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

TEST(TileSizeTest, SAND)
{
  std::wstring path(L"../data/sand.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);    
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 3);
}

TEST(TileSizeTest, Brick_Modular_Common_C)
{
  std::wstring path(L"../data/Brick_Modular_Common_C.pat");
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

TEST(TileSizeTest, Brick_Modular_FlemishDiagonal_C)
{
  std::wstring path(L"../data/Brick_Modular_FlemishDiagonal_C.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 2);
}

TEST(TileSizeTest, Brick_Modular_Garden_C)
{
  std::wstring path(L"../data/Brick_Modular_Garden_C.pat");
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

TEST(TileSizeTest, Brick_Running_C)
{
  std::wstring path(L"../data/Brick_Running_C.pat");
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

TEST(TileSizeTest, Brick_Stack_C)
{
  std::wstring path(L"../data/Brick_Stack_C.pat");
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

TEST(TileSizeTest, CMU_SplitFace_Running_C)
{
  std::wstring path(L"../data/CMU_SplitFace_Running_C.pat");
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

TEST(TileSizeTest, HWOD10E1)
{
  std::wstring path(L"../data/HWOD10E1.pat");
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

TEST(TileSizeTest, HWOD20E1)
{
  std::wstring path(L"../data/HWOD20E1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 2);
}

TEST(TileSizeTest, HWOD30E1)
{
  std::wstring path(L"../data/HWOD30E1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 2);
}

TEST(TileSizeTest, HWOD40E1)
{
  std::wstring path(L"../data/HWOD40E1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 2);
}

TEST(TileSizeTest, HWEND1N0)
{
  std::wstring path(L"../data/HWEND1N0.pat");
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

TEST(TileSizeTest, HWEND2N0)
{
  std::wstring path(L"../data/HWEND2N0.pat");
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

TEST(TileSizeTest, HWEND3N0)
{
  std::wstring path(L"../data/HWEND3N0.pat");
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

TEST(TileSizeTest, HWEND4N0)
{
  std::wstring path(L"../data/HWEND4N0.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 3);
}


TEST(TileSizeTest, HWEND5N0)
{
  std::wstring path(L"../data/HWEND5N0.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 1);
}

TEST(TileSizeTest, HWOOD1E1)
{
  std::wstring path(L"../data/HWOOD1E1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 1);
}

TEST(TileSizeTest, HWOOD4E1)
{
  std::wstring path(L"../data/HWOOD4E1.pat");
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

TEST(TileSizeTest, HWOOD5E1)
{
  std::wstring path(L"../data/HWOOD5E1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 2);
}

TEST(TileSizeTest, HWOOD6E1)
{
  std::wstring path(L"../data/HWOOD6E1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 2);
}

TEST(TileSizeTest, Batt_Insulation)
{
  std::wstring path(L"../data/Batt_Insulation.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }  
}

TEST(TileSizeTest, Batt_Insulation_Loose)
{
  std::wstring path(L"../data/Batt_ins.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, CMU_SCREEN)
{
  std::wstring path(L"../data/cmu_screen.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 0);
}

TEST(TileSizeTest, CONCRETE)
{
  std::wstring path(L"../data/concrete.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 28);
}

TEST(TileSizeTest, Roofing_Shingles)
{
  std::wstring path(L"../data/Roof_shingles.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, CastInplace_Panels_Reveal1_C)
{
  std::wstring path(L"../data/Cast-in-place_Panels_Reveal1_C.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Pavers_SuperDecor)
{
  std::wstring path(L"../data/Pavers_SuperDecor.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 0);
}

TEST(TileSizeTest, RoofingSiding_Metal_Ribbed)
{
  std::wstring path(L"../data/Roofing-Siding_Metal_Ribbed.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, RoofingSiding_Metal_Standing)
{
  std::wstring path(L"../data/Roofing-Siding_Metal_Standing.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, GENERAL_TEXTURE)
{
  std::wstring path(L"../data/general_texture.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, HSBDR1E1)
{
  std::wstring path(L"../data/HSBDR1E1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, CS01)
{
  std::wstring path(L"../data/cs01.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, CS03)
{
  std::wstring path(L"../data/cs03.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, CS04)
{
  std::wstring path(L"../data/cs04.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 0);
}


TEST(TileSizeTest, CS06)
{
  std::wstring path(L"../data/cs06.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, crssbd_s)
{
  std::wstring path(L"../data/crssbd_s.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Concret1)
{
  std::wstring path(L"../data/Concret1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 0);
}

TEST(TileSizeTest, Concret4)
{
  std::wstring path(L"../data/Concret4.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Concret5)
{
  std::wstring path(L"../data/Concret5.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar1)
{
  std::wstring path(L"../data/Ar1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar2)
{
  std::wstring path(L"../data/Ar2.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar3)
{
  std::wstring path(L"../data/Ar3.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar4)
{
  std::wstring path(L"../data/Ar4.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

//TEST(TileSizeTest, Ar5)
//{
//  std::wstring path(L"../data/Ar5.pat");
//  auto patterns = CPatFileParser::loadPatterns(path);
//
//  EXPECT_TRUE(patterns.size() == 1);
//
//  auto&& pattern = patterns[0];
//  auto families = pattern.families();
//  auto tileSize = pattern.length();
//
//  EXPECT_TRUE(!families.empty());
//
//  std::unordered_set<int> invalidSegmentIndices;
//  for (auto& f : families)
//  {
//    auto tileSgments = f.generateSegments(tileSize);
//    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
//  }
//}

TEST(TileSizeTest, Ar6)
{
  std::wstring path(L"../data/Ar6.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar7)
{
  std::wstring path(L"../data/Ar7.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar8)
{
  std::wstring path(L"../data/Ar8.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar9)
{
  std::wstring path(L"../data/Ar9.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar10)
{
  std::wstring path(L"../data/Ar10.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar11)
{
  std::wstring path(L"../data/Ar11.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar12)
{
  std::wstring path(L"../data/Ar12.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar13)
{
  std::wstring path(L"../data/Ar13.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

//TEST(TileSizeTest, Ar14)
//{
//  std::wstring path(L"../data/Ar14.pat");
//  auto patterns = CPatFileParser::loadPatterns(path);
//
//  EXPECT_TRUE(patterns.size() == 1);
//
//  auto&& pattern = patterns[0];
//  auto families = pattern.families();
//  auto tileSize = pattern.length();
//
//  EXPECT_TRUE(!families.empty());
//
//  std::unordered_set<int> invalidSegmentIndices;
//  for (auto& f : families)
//  {
//    auto tileSgments = f.generateSegments(tileSize);
//    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
//  }
//}

TEST(TileSizeTest, Ar15)
{
  std::wstring path(L"../data/Ar15.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar16)
{
  std::wstring path(L"../data/Ar16.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar17)
{
  std::wstring path(L"../data/Ar17.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar18)
{
  std::wstring path(L"../data/Ar18.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar19)
{
  std::wstring path(L"../data/Ar19.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar20)
{
  std::wstring path(L"../data/Ar20.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar21)
{
  std::wstring path(L"../data/Ar21.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar22)
{
  std::wstring path(L"../data/Ar22.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar23)
{
  std::wstring path(L"../data/Ar23.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar24)
{
  std::wstring path(L"../data/Ar24.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar25)
{
  std::wstring path(L"../data/Ar25.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar26)
{
  std::wstring path(L"../data/Ar26.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar27)
{
  std::wstring path(L"../data/Ar27.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar28)
{
  std::wstring path(L"../data/Ar28.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar29)
{
  std::wstring path(L"../data/Ar29.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Ar30)
{
  std::wstring path(L"../data/Ar30.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, ArTile01)
{
  std::wstring path(L"../data/AR-Tile01.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile02)
{
  std::wstring path(L"../data/AR-Tile02.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile03)
{
  std::wstring path(L"../data/AR-Tile03.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile04)
{
  std::wstring path(L"../data/AR-Tile04.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile05)
{
  std::wstring path(L"../data/AR-Tile05.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile06)
{
  std::wstring path(L"../data/AR-Tile06.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile07)
{
  std::wstring path(L"../data/AR-Tile07.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile08)
{
  std::wstring path(L"../data/AR-Tile08.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile09)
{
  std::wstring path(L"../data/AR-Tile09.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile10)
{
  std::wstring path(L"../data/AR-Tile10.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile11)
{
  std::wstring path(L"../data/AR-Tile11.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile12)
{
  std::wstring path(L"../data/AR-Tile12.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 3);
}

TEST(TileSizeTest, ArTile13)
{
  std::wstring path(L"../data/AR-Tile13.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 0);
}

TEST(TileSizeTest, ArTile14)
{
  std::wstring path(L"../data/AR-Tile14.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 0);
}

TEST(TileSizeTest, ArTile15)
{
  std::wstring path(L"../data/AR-Tile15.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile16)
{
  std::wstring path(L"../data/AR-Tile16.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile17)
{
  std::wstring path(L"../data/AR-Tile17.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile18)
{
  std::wstring path(L"../data/AR-Tile18.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 1);
}

TEST(TileSizeTest, ArTile19)
{
  std::wstring path(L"../data/AR-Tile19.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile20)
{
  std::wstring path(L"../data/AR-Tile20.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile21)
{
  std::wstring path(L"../data/AR-Tile21.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile22)
{
  std::wstring path(L"../data/AR-Tile22.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile23)
{
  std::wstring path(L"../data/AR-Tile23.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile24)
{
  std::wstring path(L"../data/AR-Tile24.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile25)
{
  std::wstring path(L"../data/AR-Tile25.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile26)
{
  std::wstring path(L"../data/AR-Tile26.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ArTile27)
{
  std::wstring path(L"../data/AR-Tile27.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, ArTile28)
{
  std::wstring path(L"../data/AR-Tile28.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, ArTile29)
{
  std::wstring path(L"../data/AR-Tile29.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, ArTile30)
{
  std::wstring path(L"../data/AR-Tile30.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Aecinsul)
{
  std::wstring path(L"../data/Aecinsul.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, APPIAN2)
{
  std::wstring path(L"../data/APPIAN2.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, Ankh3)
{
  std::wstring path(L"../data/Ankh3.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, 3TAB)
{
  std::wstring path(L"../data/3TAB.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, 4hStone)
{
  std::wstring path(L"../data/4h-stone.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, Aecline)
{
  std::wstring path(L"../data/Aecline.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, Bang2)
{
  std::wstring path(L"../data/Bang2.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, BATT)
{
  std::wstring path(L"../data/BATT.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, GEOL4)
{
  std::wstring path(L"../data/GEOL4.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, GNDCOVER)
{
  std::wstring path(L"../data/gndcover.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, GLASBLOC)
{
  std::wstring path(L"../data/GLASBLOC.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


//TEST(TileSizeTest, GLASS3)
//{
//  std::wstring path(L"../data/GLASS3.pat");
//  auto patterns = CPatFileParser::loadPatterns(path);
//
//  EXPECT_TRUE(patterns.size() == 1);
//
//  auto&& pattern = patterns[0];
//  auto families = pattern.families();
//  auto tileSize = pattern.length();
//
//  EXPECT_TRUE(!families.empty());
//
//  std::unordered_set<int> invalidSegmentIndices;
//  for (auto& f : families)
//  {
//    auto tileSgments = f.generateSegments(tileSize);
//    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
//  }
//}

TEST(TileSizeTest, GRTSTONE)
{
  std::wstring path(L"../data/grtstone.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, SPANISH)
{
  std::wstring path(L"../data/SPANISH.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, SPANISH1)
{
  std::wstring path(L"../data/SPANISH1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, SPANISH2)
{
  std::wstring path(L"../data/SPANISH2.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, SPANISH3)
{
  std::wstring path(L"../data/SPANISH3.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 2);
}

TEST(TileSizeTest, SPANTIL1)
{
  std::wstring path(L"../data/SPANTIL1.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, SPANTIL2)
{
  std::wstring path(L"../data/SPANTIL2.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, LEGNO2)
{
  std::wstring path(L"../data/legno2.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, TRONCO)
{
  std::wstring path(L"../data/TRONCO.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, SM)
{
  std::wstring path(L"../data/SM.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, STONE)
{
  std::wstring path(L"../data/STONE.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}


TEST(TileSizeTest, RIPPLE3)
{
  std::wstring path(L"../data/RIPPLE3.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, GW)
{
  std::wstring path(L"../data/GW.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);
    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
  }
}

TEST(TileSizeTest, ARCONC)
{
  std::wstring path(L"../data/ar-conc.pat");
  auto patterns = CPatFileParser::loadPatterns(path);

  EXPECT_TRUE(patterns.size() == 1);

  auto&& pattern = patterns[0];
  auto families = pattern.families();
  auto tileSize = pattern.length();

  EXPECT_TRUE(!families.empty());

  std::unordered_set<int> invalidSegmentIndices;
  for (auto& f : families)
  {
    auto tileSgments = f.generateSegments(tileSize);

    
    CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices);
  }

  EXPECT_TRUE(invalidSegmentIndices.size() == 6);
}

//TEST(TileSizeTest, RUBBLE)
//{
//  std::wstring path(L"../data/RUBBLE.pat");
//  auto patterns = CPatFileParser::loadPatterns(path);
//
//  EXPECT_TRUE(patterns.size() == 1);
//
//  auto&& pattern = patterns[0];
//  auto families = pattern.families();
//  auto tileSize = pattern.length();
//
//  EXPECT_TRUE(!families.empty());
//
//  std::unordered_set<int> invalidSegmentIndices;
//  for (auto& f : families)
//  {
//    auto tileSgments = f.generateSegments(tileSize);
//    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
//  }
//}

//TEST(TileSizeTest, Concret3)
//{
//  std::wstring path(L"../data/Concret3.pat");
//  auto patterns = CPatFileParser::loadPatterns(path);
//
//  EXPECT_TRUE(patterns.size() == 1);
//
//  auto&& pattern = patterns[0];
//  auto families = pattern.families();
//  auto tileSize = pattern.length();
//
//  EXPECT_TRUE(!families.empty());
//
//  std::unordered_set<int> invalidSegmentIndices;
//  for (auto& f : families)
//  {
//    auto tileSgments = f.generateSegments(tileSize);
//    EXPECT_TRUE(CTileChecker::checkFamilySegments(tileSgments, tileSize[0], tileSize[1], invalidSegmentIndices));
//  }
//}