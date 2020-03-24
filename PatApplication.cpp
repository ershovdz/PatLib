// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved


#include "PatApplication.h"
#include "PatFileParser.h"
#include "PatUtils.h"
#include <tuple>
#include <algorithm>

const double EPS = 1E-5;

//struct Point
//{
//  double x, y;
//
//  double distanceTo(const Point& other) const
//  {
//    return ::_hypot(x - other.x, y - other.y);
//  }
//
//  bool operator<(const Point& p) const
//  {
//    return x < p.x - EPS || (std::abs(x - p.x) < EPS && y < p.y - EPS);
//  }
//};

#undef min
#undef max

//namespace
//{
//  struct Line 
//  {
//    double a, b, c;
//
//    Line() {}
//    Line(Point p, Point q)
//    {
//      a = p.y - q.y;
//      b = q.x - p.x;
//      c = -a * p.x - b * p.y;
//      norm();
//    }
//
//    void norm()
//    {
//      double z = sqrt(a * a + b * b);
//      if (abs(z) > EPS)
//        a /= z, b /= z, c /= z;
//    }
//
//    double dist(Point p) const { return a * p.x + b * p.y + c; }
//  };
//
//  double det(double a, double b, double c, double d)
//  {
//    return a * d - b * c;
//  }
//
//  inline bool betw(double l, double r, double x)
//  {
//    return std::min(l, r) <= x + EPS && x <= std::max(l, r) + EPS;
//  }
//
//  inline bool intersect_1d(double a, double b, double c, double d)
//  {
//    if (a > b)
//      std::swap(a, b);
//    if (c > d)
//      std::swap(c, d);
//    return std::max(a, c) <= std::min(b, d) + EPS;
//  }
//
//  bool intersect(Point a, Point b, Point c, Point d, Point& left, Point& right)
//  {
//    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
//      return false;
//    Line m(a, b);
//    Line n(c, d);
//    double zn = det(m.a, m.b, n.a, n.b);
//    if (abs(zn) < EPS) 
//    {
//      if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS)
//        return false;
//      if (b < a)
//        std::swap(a, b);
//      if (d < c)
//        std::swap(c, d);
//      left = std::max(a, c);
//      right = std::min(b, d);
//      return true;
//    }
//    else 
//    {
//      left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
//      left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
//      return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
//        betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
//    }
//  }  
//}

//class CTileChecker
//{
//public:
//  static bool checkFamilySegments(const std::vector<std::tuple<int, Point, Point>>& familySegments, double tileWidth, double tileHeight)
//  {
//    auto segmentsForLeftSide = filterSegmentsBySideIntersection(familySegments, Point{ 0,0 }, Point{ 0,tileHeight });
//    auto segmentsForRightSide = filterSegmentsBySideIntersection(familySegments, Point{ tileWidth, 0 }, Point{ tileWidth ,tileHeight });
//
//    auto segmentsForTopSide = filterSegmentsBySideIntersection(familySegments, Point{ 0,0 }, Point{ tileWidth,0 });
//    auto segmentsForBottomSide = filterSegmentsBySideIntersection(familySegments, Point{ 0, tileHeight }, Point{ tileWidth ,tileHeight });
//
//    return
//      checkSegmentsForOppositeSides(segmentsForLeftSide, segmentsForRightSide, tileWidth) &&
//      checkSegmentsForOppositeSides(segmentsForTopSide, segmentsForBottomSide, tileHeight);
//  }
//
//private:
//  static std::vector<std::tuple<int, Point, Point, Point, Point>> filterSegmentsBySideIntersection(const std::vector<std::tuple<int, Point, Point>>& familySegments, Point sideStart, Point sideEnd)
//  {
//    std::vector<std::tuple<int, Point, Point, Point, Point>> result;
//
//    for (auto& segment : familySegments)
//    {
//      Point firstIntersectPoint, secondIntersectPoint;
//
//      if (intersect(std::get<1>(segment), std::get<2>(segment), sideStart, sideEnd, firstIntersectPoint, secondIntersectPoint))
//        result.push_back(std::make_tuple(std::get<0>(segment), std::get<1>(segment), std::get<2>(segment), firstIntersectPoint, secondIntersectPoint));
//    }
//
//    return result;
//  }
//
//  static bool checkSegmentsForOppositeSides(const std::vector<std::tuple<int, Point, Point, Point, Point>>& firstSideSegments, const std::vector<std::tuple<int, Point, Point, Point, Point>>& secondSideSegments, double sidesDistance)
//  {
//    if (firstSideSegments.size() != secondSideSegments.size())
//      return false;
//
//    for (int i = 0; i < firstSideSegments.size(); ++i)
//    {
//      bool hasOppositeSegment = false;
//
//      auto&& segmentForFirstSide = firstSideSegments[i];
//      double firstSegmentLength = std::get<1>(segmentForFirstSide).distanceTo(std::get<2>(segmentForFirstSide));
//
//      for (int j = 0; j < secondSideSegments.size(); ++j)
//      {
//        auto&& segmentForSecondSide = secondSideSegments[j];
//        double secondSegmentLength = std::get<1>(segmentForSecondSide).distanceTo(std::get<2>(segmentForSecondSide));
//
//        if (std::get<0>(segmentForFirstSide) == std::get<0>(segmentForSecondSide))
//        {
//          // single-interval segments
//          if (firstSegmentLength > sidesDistance && secondSegmentLength > sidesDistance)
//          {
//            auto&& sideIntersectPointForFirstSegment = std::get<3>(segmentForFirstSide);
//            auto&& sideIntersectPointForSecondSegment = std::get<3>(segmentForSecondSide);
//
//            auto distanceBetweenIntersectPointsByX = abs(sideIntersectPointForFirstSegment.x - sideIntersectPointForSecondSegment.x);
//            auto distanceBetweenIntersectPointsByY = abs(sideIntersectPointForFirstSegment.y - sideIntersectPointForSecondSegment.y);
//
//            if (distanceBetweenIntersectPointsByX < EPS || abs(distanceBetweenIntersectPointsByX - sidesDistance) < EPS)
//            {
//              if (distanceBetweenIntersectPointsByY < EPS || abs(distanceBetweenIntersectPointsByY - sidesDistance) < EPS)
//              {
//                hasOppositeSegment = true;
//                break;
//              }
//            }
//          }
//          else
//          {
//            auto&& firstSegmentStartPoint = std::get<1>(segmentForFirstSide);
//            auto&& secondSegmentStartPoint = std::get<1>(segmentForSecondSide);
//
//            auto distanceBetweenSegmentsByX = abs(firstSegmentStartPoint.x - secondSegmentStartPoint.x);
//            auto distanceBetweenSegmentsByY = abs(firstSegmentStartPoint.y - secondSegmentStartPoint.y);
//
//            if (distanceBetweenSegmentsByX < EPS || abs(distanceBetweenSegmentsByX - sidesDistance) < EPS)
//            {
//              if (distanceBetweenSegmentsByY < EPS || abs(distanceBetweenSegmentsByY - sidesDistance) < EPS)
//              {
//                hasOppositeSegment = true;
//                break;
//              }
//            }
//          }
//        }
//      }
//
//      if (!hasOppositeSegment)
//        return false;
//    }
//
//    return true;
//  }
//};



//
// Provides the entry point to the application.
//
int WINAPI WinMain(
  HINSTANCE /* hInstance */,
  HINSTANCE /* hPrevInstance */,
  LPSTR /* lpCmdLine */,
  int /* nCmdShow */
)
{
  // Ignore the return value because we want to continue running even in the
  // unlikely event that HeapSetInformation fails.
  HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

  if (SUCCEEDED(CoInitialize(NULL)))
  {
    {
      DemoApp app;

      if (SUCCEEDED(app.Initialize()))
      {
        app.RunMessageLoop();
      }
    }
    CoUninitialize();
  }

  return 0;
}


//
// Initialize members.
//
DemoApp::DemoApp() :
  m_hwnd(NULL),
  m_pD2DFactory(NULL),
  m_pWICFactory(NULL),
  m_pDWriteFactory(NULL),
  m_pRenderTarget(NULL),
  m_pTextFormat(NULL),
  m_pPathGeometry(NULL),
  //    m_pLinearGradientBrush(NULL),
  m_pBlackBrush(NULL),
  m_pWhiteBrush(NULL),
  m_pGridPatternBitmapBrush(NULL)
  //    m_pBitmap(NULL),
  //    m_pAnotherBitmap(NULL)
{
}

//
// Release resources.
//
DemoApp::~DemoApp()
{
  SafeRelease(&m_pD2DFactory);
  SafeRelease(&m_pWICFactory);
  SafeRelease(&m_pDWriteFactory);
  SafeRelease(&m_pRenderTarget);
  SafeRelease(&m_pTextFormat);
  SafeRelease(&m_pPathGeometry);
  //    SafeRelease(&m_pLinearGradientBrush);
  SafeRelease(&m_pBlackBrush);
  SafeRelease(&m_pWhiteBrush);
  SafeRelease(&m_pGridPatternBitmapBrush);
//    SafeRelease(&m_pBitmap);
//    SafeRelease(&m_pAnotherBitmap);
}

//
// Creates the application window and initializes
// device-independent resources.
//
HRESULT DemoApp::Initialize()
{
  HRESULT hr;

  // Initialize device-indpendent resources, such
  // as the Direct2D factory.
  hr = CreateDeviceIndependentResources();
  if (SUCCEEDED(hr))
  {
    // Register the window class.
    WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = DemoApp::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = sizeof(LONG_PTR);
    wcex.hInstance = HINST_THISCOMPONENT;
    wcex.hbrBackground = NULL;
    wcex.lpszMenuName = NULL;
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.lpszClassName = L"D2DDemoApp";

    RegisterClassEx(&wcex);

    // Create the application window.
    //
    // Because the CreateWindow function takes its size in pixels, we
    // obtain the system DPI and use it to scale the window size.
    FLOAT dpiX, dpiY;
    m_pD2DFactory->GetDesktopDpi(&dpiX, &dpiY);

    // Create the application window.
    m_hwnd = CreateWindow(
      L"D2DDemoApp",
      L"Direct2D Demo Application",
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT,
      CW_USEDEFAULT,
      static_cast<UINT>(ceil(480.f * dpiX / 96.f)),
      static_cast<UINT>(ceil(480.f * dpiY / 96.f)),
      NULL,
      NULL,
      HINST_THISCOMPONENT,
      this
    );
    hr = m_hwnd ? S_OK : E_FAIL;
    if (SUCCEEDED(hr))
    {
      ShowWindow(m_hwnd, SW_SHOWNORMAL);
      UpdateWindow(m_hwnd);
    }
  }

  return hr;
}


//
// Create resources which are not bound
// to any device. Their lifetime effectively extends for the
// duration of the app. These resources include the Direct2D,
// DirectWrite, and WIC factories; and a DirectWrite Text Format object
// (used for identifying particular font characteristics) and
// a Direct2D geometry.
//
HRESULT DemoApp::CreateDeviceIndependentResources()
{
  static const WCHAR msc_fontName[] = L"Verdana";
  static const FLOAT msc_fontSize = 20;
  HRESULT hr;
  ID2D1GeometrySink *pSink = NULL;

  // Create a Direct2D factory.
  hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2DFactory);
  if (SUCCEEDED(hr))
  {
    // Create WIC factory.
    hr = CoCreateInstance(
      CLSID_WICImagingFactory,
      NULL,
      CLSCTX_INPROC_SERVER,
      IID_IWICImagingFactory,
      reinterpret_cast<void **>(&m_pWICFactory)
    );
  }
  if (SUCCEEDED(hr))
  {
    // Create a DirectWrite factory.
    hr = DWriteCreateFactory(
      DWRITE_FACTORY_TYPE_SHARED,
      __uuidof(m_pDWriteFactory),
      reinterpret_cast<IUnknown **>(&m_pDWriteFactory)
    );
  }
  if (SUCCEEDED(hr))
  {
    // Create a DirectWrite text format object.
    hr = m_pDWriteFactory->CreateTextFormat(
      msc_fontName,
      NULL,
      DWRITE_FONT_WEIGHT_THIN,
      DWRITE_FONT_STYLE_NORMAL,
      DWRITE_FONT_STRETCH_NORMAL,
      msc_fontSize,
      L"", //locale
      &m_pTextFormat
    );
  }
  if (SUCCEEDED(hr))
  {
    // Center the text horizontally and vertically.
    m_pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);

    m_pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

    // Create a path geometry.
    hr = m_pD2DFactory->CreatePathGeometry(&m_pPathGeometry);
  }
  if (SUCCEEDED(hr))
  {
    // Use the geometry sink to write to the path geometry.
    hr = m_pPathGeometry->Open(&pSink);
  }
  if (SUCCEEDED(hr))
  {
    pSink->SetFillMode(D2D1_FILL_MODE_ALTERNATE);

    pSink->BeginFigure(
      D2D1::Point2F(0, 0),
      D2D1_FIGURE_BEGIN_FILLED
    );

    pSink->AddLine(D2D1::Point2F(200, 0));

    pSink->AddBezier(
      D2D1::BezierSegment(
        D2D1::Point2F(150, 50),
        D2D1::Point2F(150, 150),
        D2D1::Point2F(200, 200))
    );

    pSink->AddLine(D2D1::Point2F(0, 200));

    pSink->AddBezier(
      D2D1::BezierSegment(
        D2D1::Point2F(50, 150),
        D2D1::Point2F(50, 50),
        D2D1::Point2F(0, 0))
    );

    pSink->EndFigure(D2D1_FIGURE_END_CLOSED);

    hr = pSink->Close();
  }

  SafeRelease(&pSink);

  return hr;
}

//
//  This method creates resources which are bound to a particular
//  Direct3D device. It's all centralized here, in case the resources
//  need to be recreated in case of Direct3D device loss (eg. display
//  change, remoting, removal of video card, etc).
//
HRESULT DemoApp::CreateDeviceResources()
{
  HRESULT hr = S_OK;

  if (!m_pRenderTarget)
  {
    RECT rc;
    GetClientRect(m_hwnd, &rc);

    D2D1_SIZE_U size = D2D1::SizeU(
      rc.right - rc.left,
      rc.bottom - rc.top
    );

    // Create a Direct2D render target.
    hr = m_pD2DFactory->CreateHwndRenderTarget(
      D2D1::RenderTargetProperties(),
      D2D1::HwndRenderTargetProperties(m_hwnd, size),
      &m_pRenderTarget
    );
    if (SUCCEEDED(hr))
    {
      // Create a black brush.
      hr = m_pRenderTarget->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::Red),
        &m_pBlackBrush
      );

      hr = m_pRenderTarget->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::White),
        &m_pWhiteBrush
      );
    }
    if (SUCCEEDED(hr))
    {
      ID2D1GradientStopCollection *pGradientStops = NULL;
      // Create a linear gradient.
      static const D2D1_GRADIENT_STOP stops[] =
      {
          {   0.f,  { 0.f, 1.f, 1.f, 0.25f }  },
          {   1.f,  { 0.f, 0.f, 1.f, 1.f }  },
      };

      hr = m_pRenderTarget->CreateGradientStopCollection(
        stops,
        ARRAYSIZE(stops),
        &pGradientStops
      );
    }
    std::wstring path(L"ansi36.pat");
    m_patterns = CPatFileParser::loadPatterns(path);

    if (SUCCEEDED(hr))
    {
      hr = CreateGridPatternBrush(m_pRenderTarget, &m_pGridPatternBitmapBrush);
    }
  }

  return hr;
}

//
// Creates a pattern brush.
//
HRESULT DemoApp::CreateGridPatternBrush(
  ID2D1RenderTarget *pRenderTarget,
  ID2D1BitmapBrush **ppBitmapBrush
)
{
  HRESULT hr = S_OK;

  // Create a compatible render target.

  D2D1_STROKE_STYLE_PROPERTIES style = D2D1::StrokeStyleProperties(
    D2D1_CAP_STYLE_ROUND,
    D2D1_CAP_STYLE_ROUND,
    D2D1_CAP_STYLE_FLAT,
    D2D1_LINE_JOIN_MITER_OR_BEVEL, 1.0f,
    D2D1_DASH_STYLE_SOLID, 0);

  D2D1_STROKE_STYLE_PROPERTIES desc;
  desc.dashCap = style.dashCap;
  desc.dashOffset = style.dashOffset;
  desc.dashStyle = style.dashStyle;
  desc.endCap = style.endCap;
  desc.lineJoin = style.lineJoin;
  desc.miterLimit = style.miterLimit;
  desc.startCap = style.startCap;

  ID2D1StrokeStyle* pStrokeStyle;
  m_pD2DFactory->CreateStrokeStyle(&desc, nullptr, 0, &pStrokeStyle);

  ID2D1BitmapRenderTarget *pCompatibleRenderTarget = NULL;
  auto pattern = m_patterns[m_patterns.size() > m_currentIndex ? m_currentIndex : 0];
  int index = 0;
  MaxRect = pattern.length();
  std::vector<double> MaxRectE = { MaxRect[0] + m_eps, MaxRect[1] + m_eps };
  auto aspectE = MaxRectE[0] / MaxRectE[1];

  double tileWidth = 400.0f;
  double tileHeight = tileWidth/aspectE;
  hr = pRenderTarget->CreateCompatibleRenderTarget(
    D2D1::SizeF((float)tileWidth, (float)tileHeight),
    &pCompatibleRenderTarget
  );
  if (SUCCEEDED(hr))
  {
    // Draw a pattern.
    ID2D1SolidColorBrush *pGridBrush = NULL;
    hr = pCompatibleRenderTarget->CreateSolidColorBrush(
      D2D1::ColorF(D2D1::ColorF::Black),
      &pGridBrush
    );
    ID2D1SolidColorBrush *pWhiteGridBrush = NULL;
    hr = pCompatibleRenderTarget->CreateSolidColorBrush(
      D2D1::ColorF(D2D1::ColorF::White),
      &pWhiteGridBrush
    );
    if (SUCCEEDED(hr))
    {
      pCompatibleRenderTarget->BeginDraw();
      pCompatibleRenderTarget->Clear();
      wchar_t msg[80];
      swprintf_s(msg, L"Length: %d %f %f\n", m_currentIndex, MaxRect[0], MaxRect[1]);
      OutputDebugString(msg);

      auto minW = tileWidth / MaxRectE[0];
      auto minH = tileHeight / MaxRectE[1];
      auto families = pattern.families();
      double pointAddition = 0;
      index++;
      double l = 6.f;

      for (auto& f : families)
      {
        auto alignedFamilySegments = f.generateSegments(MaxRectE);

        bool isOk = CTileChecker::checkFamilySegments(alignedFamilySegments, MaxRectE[0], MaxRectE[1]);

        for (int i = 0; i < alignedFamilySegments.size(); ++i)
        {
          auto&& line = alignedFamilySegments[i];

          auto start = std::get<1>(line);
          auto end = std::get<2>(line);

          pointAddition = (start.distanceTo(end) <= 0.001f) ? 1.f : 0.f;

          pCompatibleRenderTarget->DrawLine(
            D2D1::Point2F(static_cast<float>(minW*(start.x - m_deltaX) - pointAddition), static_cast<float>(minH*(start.y - m_deltaY) - pointAddition)),
            D2D1::Point2F(static_cast<float>(minW*(end.x - m_deltaX) + pointAddition), static_cast<float>(minH*(end.y - m_deltaY) + pointAddition)),
            pGridBrush,
            (float)l/*,
            pStrokeStyle*/);
        }
      }

      pCompatibleRenderTarget->EndDraw();

      // Retrieve the bitmap from the render target.
      ID2D1Bitmap *pGridBitmap = NULL;
      hr = pCompatibleRenderTarget->GetBitmap(&pGridBitmap);
      if (SUCCEEDED(hr))
      {
        // Choose the tiling mode for the bitmap brush.
        D2D1_BITMAP_BRUSH_PROPERTIES brushProperties =
          D2D1::BitmapBrushProperties(D2D1_EXTEND_MODE_WRAP, D2D1_EXTEND_MODE_WRAP);

        // Create the bitmap brush.
        hr = m_pRenderTarget->CreateBitmapBrush(pGridBitmap, brushProperties, ppBitmapBrush);

        pGridBitmap->Release();
      }

      pGridBrush->Release();
      pWhiteGridBrush->Release();
    }

    pCompatibleRenderTarget->Release();
  }

  return hr;
}

//
//  Discard device-specific resources which need to be recreated
//  when a Direct3D device is lost
//
void DemoApp::DiscardDeviceResources()
{
  SafeRelease(&m_pRenderTarget);
  SafeRelease(&m_pBlackBrush);
  SafeRelease(&m_pWhiteBrush);
}

//
// The main window message loop.
//
void DemoApp::RunMessageLoop()
{
  MSG msg;

  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
}


//
//  Called whenever the application needs to display the client
//  window. This method draws a bitmap a couple times, draws some
//  geometries, and writes "Hello, World"
//
//  Note that this function will not render anything if the window
//  is occluded (e.g. when the screen is locked).
//  Also, this function will automatically discard device-specific
//  resources if the Direct3D device disappears during function
//  invocation, and will recreate the resources the next time it's
//  invoked.
//

HRESULT DemoApp::OnRender()
{
  HRESULT hr;

  hr = CreateDeviceResources();

  if (SUCCEEDED(hr) && !(m_pRenderTarget->CheckWindowState() & D2D1_WINDOW_STATE_OCCLUDED))
  {
    static const WCHAR sc_helloWorld[] = L"Hello, World!";
    // Retrieve the size of the render target.
    D2D1_SIZE_F renderTargetSize = m_pRenderTarget->GetSize();

    m_pRenderTarget->BeginDraw();

    m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

    m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

    // Draw a grid background.
    int width = static_cast<int>(renderTargetSize.width);
    int height = static_cast<int>(renderTargetSize.height);

    auto pattern = m_patterns[m_patterns.size() > m_currentIndex ? m_currentIndex : 0];

    m_pRenderTarget->DrawText(
      pattern.name().c_str(),
      ARRAYSIZE(sc_helloWorld) - 1,
      m_pTextFormat,
      D2D1::RectF(0, 0, 200, 20),
      m_pBlackBrush
    );

    hr = CreateGridPatternBrush(m_pRenderTarget, &m_pGridPatternBitmapBrush);
    std::vector<double> MaxRectE = { MaxRect[0] + m_eps, MaxRect[1] + m_eps };
    auto aspectE = MaxRectE[0] / MaxRectE[1];
    double tileWidth = 400.0f;
    double tileHeight = tileWidth/aspectE;



    //auto rect = D2D1::RectF(0 /*- m_delta* hor*/, 0/* - m_delta * vert*/, (float)(tileWidth) /*- m_delta * hor*/, (float)(tileHeight) /*- m_delta * vert*/);

  //  m_pRenderTarget->FillRectangle(
  //    rect,
  //    m_pGridPatternBitmapBrush
  //  );    
    
    int vert = 0, hor = 0;
    
    for (vert = 0; tileHeight * vert < height; vert++)
    {
      for (hor = 0; tileWidth * hor < width; hor++)
      {
        /*if (vert == 0 && hor == 0)
          continue;*/

        //m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(m_deltaX * (hor > 0 ? hor : 1), -m_deltaY * (vert > 0 ? vert : 1)));

        auto rect = D2D1::RectF((float)(tileWidth * hor) /*- m_delta* hor*/, (float)(tileHeight*vert)/* - m_delta * vert*/, (float)(tileWidth * (hor + 1)) /*- m_delta * hor*/, (float)(tileHeight*(vert + 1)) /*- m_delta * vert*/);
        
        m_pRenderTarget->FillRectangle(
          rect,
          m_pGridPatternBitmapBrush
        );
      }
    }

    hr = m_pRenderTarget->EndDraw();

    if (hr == D2DERR_RECREATE_TARGET)
    {
      hr = S_OK;
      DiscardDeviceResources();
    }

    SafeRelease(&m_pGridPatternBitmapBrush);
  }

  return hr;
}

//
//  If the application receives a WM_SIZE message, this method
//  resize the render target appropriately.
//
void DemoApp::OnResize(UINT width, UINT height)
{
  if (m_pRenderTarget)
  {
    D2D1_SIZE_U size;
    size.width = width;
    size.height = height;

    // Note: This method can fail, but it's okay to ignore the
    // error here -- it will be repeated on the next call to
    // EndDraw.
    m_pRenderTarget->Resize(size);
  }
}


//
// The window message handler.
//
LRESULT CALLBACK DemoApp::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  LRESULT result = 0;

  if (message == WM_CREATE)
  {
    LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
    DemoApp *pDemoApp = (DemoApp *)pcs->lpCreateParams;

    ::SetWindowLongPtrW(
      hwnd,
      GWLP_USERDATA,
      PtrToUlong(pDemoApp)
    );

    result = 1;
  }
  else
  {
    DemoApp *pDemoApp = reinterpret_cast<DemoApp *>(static_cast<LONG_PTR>(
      ::GetWindowLongPtrW(
        hwnd,
        GWLP_USERDATA
      )));

    bool wasHandled = false;

    if (pDemoApp)
    {
      switch (message)
      {
      case WM_SIZE:
      {
        UINT width = LOWORD(lParam);
        UINT height = HIWORD(lParam);
        pDemoApp->OnResize(width, height);
      }
      result = 0;
      wasHandled = true;
      break;

      case WM_PAINT:
      case WM_DISPLAYCHANGE:
      {
        PAINTSTRUCT ps;
        BeginPaint(hwnd, &ps);
        pDemoApp->OnRender();
        EndPaint(hwnd, &ps);
      }
      result = 0;
      wasHandled = true;
      break;

      case WM_DESTROY:
      {
        PostQuitMessage(0);
      }
      result = 1;
      wasHandled = true;
      break;
      case WM_KEYDOWN:
        if (wParam == 39)
        {
          pDemoApp->m_currentIndex++;
        }
        else if (wParam == 37)
        {
          pDemoApp->m_currentIndex--;
        }
        else if (wParam == 38)
        {
          auto pattern = pDemoApp->m_patterns[pDemoApp->m_patterns.size() > pDemoApp->m_currentIndex ? pDemoApp->m_currentIndex : 0];
          auto tile = pattern.length();
          auto aspect = tile[0] / tile[1];

          pDemoApp->MaxRect[0] += 0.01;
          pDemoApp->MaxRect[1] += (0.01/aspect);
//					pDemoApp->m_eps += 0.1;
        }
        else if (wParam == 40)
        {
          auto pattern = pDemoApp->m_patterns[pDemoApp->m_patterns.size() > pDemoApp->m_currentIndex ? pDemoApp->m_currentIndex : 0];
          auto tile = pattern.length();
          auto aspect = tile[0] / tile[1];

          pDemoApp->MaxRect[0] -= 0.01;
          pDemoApp->MaxRect[1] -= (0.01/aspect);
//					pDemoApp->m_eps -= 0.1;
        }
        else if (wParam == 100)
        {
          pDemoApp->m_deltaX -= 0.1;
        }
        else if (wParam == 102)
        {
          pDemoApp->m_deltaX += 0.1;
        }
        else if (wParam == 104)
        {
          pDemoApp->m_deltaY += 0.1;
        }
        else if (wParam == 98)
        {
          pDemoApp->m_deltaY -= 0.1;
        }

        if (pDemoApp->m_currentIndex >= pDemoApp->m_patterns.size() || pDemoApp->m_currentIndex < 0)
        {
          pDemoApp->m_currentIndex = 0;
        }

        InvalidateRect(hwnd, NULL, TRUE);
//				wchar_t msg[32];
//				swprintf_s(msg, L"Index: %d, MaxRect: %f\n", pDemoApp->m_currentIndex, pDemoApp->MaxRect);
//				OutputDebugString(msg);
        break;

      case WM_MOUSEWHEEL:
        //auto pattern = pDemoApp->m_patterns[pDemoApp->m_patterns.size() > pDemoApp->m_currentIndex ? pDemoApp->m_currentIndex : 0];
        auto mousewheel = GET_WHEEL_DELTA_WPARAM(wParam);
        if (mousewheel > 0)
        {
          pDemoApp->m_eps += 0.01f;
        }
        else if (mousewheel < 0)
        {
          pDemoApp->m_eps -= 0.01f;
        }

        InvalidateRect(hwnd, NULL, TRUE);
//				swprintf_s(msg, L"Index: %d, MaxRect: %f\n", pDemoApp->m_currentIndex, pDemoApp->MaxRect);
//				OutputDebugString(msg);
        break;
      }
    }

    if (!wasHandled)
    {
      result = DefWindowProc(hwnd, message, wParam, lParam);
    }
  }

  return result;
}

//
// Creates a Direct2D bitmap from a resource in the
// application resource file.
//
HRESULT DemoApp::LoadResourceBitmap(
  ID2D1RenderTarget *pRenderTarget,
  IWICImagingFactory *pIWICFactory,
  PCWSTR resourceName,
  PCWSTR resourceType,
  UINT destinationWidth,
  UINT destinationHeight,
  ID2D1Bitmap **ppBitmap
)
{
  HRESULT hr = S_OK;
  IWICBitmapDecoder *pDecoder = NULL;
  IWICBitmapFrameDecode *pSource = NULL;
  IWICStream *pStream = NULL;
  IWICFormatConverter *pConverter = NULL;
  IWICBitmapScaler *pScaler = NULL;

  HRSRC imageResHandle = NULL;
  HGLOBAL imageResDataHandle = NULL;
  void *pImageFile = NULL;
  DWORD imageFileSize = 0;

  // Locate the resource.
  imageResHandle = FindResourceW(HINST_THISCOMPONENT, resourceName, resourceType);

  hr = imageResHandle ? S_OK : E_FAIL;
  if (SUCCEEDED(hr))
  {
    // Load the resource.
    imageResDataHandle = LoadResource(HINST_THISCOMPONENT, imageResHandle);

    hr = imageResDataHandle ? S_OK : E_FAIL;
  }
  if (SUCCEEDED(hr))
  {
    // Lock it to get a system memory pointer.
    pImageFile = LockResource(imageResDataHandle);

    hr = pImageFile ? S_OK : E_FAIL;
  }
  if (SUCCEEDED(hr))
  {
    // Calculate the size.
    imageFileSize = SizeofResource(HINST_THISCOMPONENT, imageResHandle);

    hr = imageFileSize ? S_OK : E_FAIL;
  }
  if (SUCCEEDED(hr))
  {
    // Create a WIC stream to map onto the memory.
    hr = pIWICFactory->CreateStream(&pStream);
  }
  if (SUCCEEDED(hr))
  {
    // Initialize the stream with the memory pointer and size.
    hr = pStream->InitializeFromMemory(
      reinterpret_cast<BYTE*>(pImageFile),
      imageFileSize
    );
  }
  if (SUCCEEDED(hr))
  {
    // Create a decoder for the stream.
    hr = pIWICFactory->CreateDecoderFromStream(
      pStream,
      NULL,
      WICDecodeMetadataCacheOnLoad,
      &pDecoder
    );
  }
  if (SUCCEEDED(hr))
  {
    // Create the initial frame.
    hr = pDecoder->GetFrame(0, &pSource);
  }
  if (SUCCEEDED(hr))
  {
    // Convert the image format to 32bppPBGRA
    // (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
    hr = pIWICFactory->CreateFormatConverter(&pConverter);
  }
  if (SUCCEEDED(hr))
  {
    // If a new width or height was specified, create an
    // IWICBitmapScaler and use it to resize the image.
    if (destinationWidth != 0 || destinationHeight != 0)
    {
      UINT originalWidth, originalHeight;
      hr = pSource->GetSize(&originalWidth, &originalHeight);
      if (SUCCEEDED(hr))
      {
        if (destinationWidth == 0)
        {
          FLOAT scalar = static_cast<FLOAT>(destinationHeight) / static_cast<FLOAT>(originalHeight);
          destinationWidth = static_cast<UINT>(scalar * static_cast<FLOAT>(originalWidth));
        }
        else if (destinationHeight == 0)
        {
          FLOAT scalar = static_cast<FLOAT>(destinationWidth) / static_cast<FLOAT>(originalWidth);
          destinationHeight = static_cast<UINT>(scalar * static_cast<FLOAT>(originalHeight));
        }

        hr = pIWICFactory->CreateBitmapScaler(&pScaler);
        if (SUCCEEDED(hr))
        {
          hr = pScaler->Initialize(
            pSource,
            destinationWidth,
            destinationHeight,
            WICBitmapInterpolationModeCubic
          );
          if (SUCCEEDED(hr))
          {
            hr = pConverter->Initialize(
              pScaler,
              GUID_WICPixelFormat32bppPBGRA,
              WICBitmapDitherTypeNone,
              NULL,
              0.f,
              WICBitmapPaletteTypeMedianCut
            );
          }
        }
      }
    }
    else
    {
      hr = pConverter->Initialize(
        pSource,
        GUID_WICPixelFormat32bppPBGRA,
        WICBitmapDitherTypeNone,
        NULL,
        0.f,
        WICBitmapPaletteTypeMedianCut
      );
    }
  }
  if (SUCCEEDED(hr))
  {
    //create a Direct2D bitmap from the WIC bitmap.
    hr = pRenderTarget->CreateBitmapFromWicBitmap(
      pConverter,
      NULL,
      ppBitmap
    );
  }

  SafeRelease(&pDecoder);
  SafeRelease(&pSource);
  SafeRelease(&pStream);
  SafeRelease(&pConverter);
  SafeRelease(&pScaler);

  return hr;
}

//
// Creates a Direct2D bitmap from the specified
// file name.
//
HRESULT DemoApp::LoadBitmapFromFile(
  ID2D1RenderTarget *pRenderTarget,
  IWICImagingFactory *pIWICFactory,
  PCWSTR uri,
  UINT destinationWidth,
  UINT destinationHeight,
  ID2D1Bitmap **ppBitmap
)
{
  HRESULT hr = S_OK;

  IWICBitmapDecoder *pDecoder = NULL;
  IWICBitmapFrameDecode *pSource = NULL;
  IWICStream *pStream = NULL;
  IWICFormatConverter *pConverter = NULL;
  IWICBitmapScaler *pScaler = NULL;

  hr = pIWICFactory->CreateDecoderFromFilename(
    uri,
    NULL,
    GENERIC_READ,
    WICDecodeMetadataCacheOnLoad,
    &pDecoder
  );
  if (SUCCEEDED(hr))
  {

    // Create the initial frame.
    hr = pDecoder->GetFrame(0, &pSource);
  }

  if (SUCCEEDED(hr))
  {
    // Convert the image format to 32bppPBGRA
    // (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
    hr = pIWICFactory->CreateFormatConverter(&pConverter);
  }
  if (SUCCEEDED(hr))
  {
    // If a new width or height was specified, create an
    // IWICBitmapScaler and use it to resize the image.
    if (destinationWidth != 0 || destinationHeight != 0)
    {
      UINT originalWidth, originalHeight;
      hr = pSource->GetSize(&originalWidth, &originalHeight);
      if (SUCCEEDED(hr))
      {
        if (destinationWidth == 0)
        {
          FLOAT scalar = static_cast<FLOAT>(destinationHeight) / static_cast<FLOAT>(originalHeight);
          destinationWidth = static_cast<UINT>(scalar * static_cast<FLOAT>(originalWidth));
        }
        else if (destinationHeight == 0)
        {
          FLOAT scalar = static_cast<FLOAT>(destinationWidth) / static_cast<FLOAT>(originalWidth);
          destinationHeight = static_cast<UINT>(scalar * static_cast<FLOAT>(originalHeight));
        }

        hr = pIWICFactory->CreateBitmapScaler(&pScaler);
        if (SUCCEEDED(hr))
        {
          hr = pScaler->Initialize(
            pSource,
            destinationWidth,
            destinationHeight,
            WICBitmapInterpolationModeCubic
          );
        }
        if (SUCCEEDED(hr))
        {
          hr = pConverter->Initialize(
            pScaler,
            GUID_WICPixelFormat32bppPBGRA,
            WICBitmapDitherTypeNone,
            NULL,
            0.f,
            WICBitmapPaletteTypeMedianCut
          );
        }
      }
    }
    else // Don't scale the image.
    {
      hr = pConverter->Initialize(
        pSource,
        GUID_WICPixelFormat32bppPBGRA,
        WICBitmapDitherTypeNone,
        NULL,
        0.f,
        WICBitmapPaletteTypeMedianCut
      );
    }
  }
  if (SUCCEEDED(hr))
  {
    // Create a Direct2D bitmap from the WIC bitmap.
    hr = pRenderTarget->CreateBitmapFromWicBitmap(
      pConverter,
      NULL,
      ppBitmap
    );
  }

  SafeRelease(&pDecoder);
  SafeRelease(&pSource);
  SafeRelease(&pStream);
  SafeRelease(&pConverter);
  SafeRelease(&pScaler);

  return hr;
}
