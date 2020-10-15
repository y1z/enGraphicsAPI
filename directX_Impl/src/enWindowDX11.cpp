#include "directX_Impl/include/enWindowDX11.h"

ErrorCode
enWindowDX11::init(void* windowHandle,
                   const char* windowName,
                   const int32 windowWidth,
                   const int32 windowHeight)
{
  const HMODULE modInstance = reinterpret_cast< HMODULE > (windowHandle);

  WNDCLASSEX windowDescriptor;
  windowDescriptor.cbSize = sizeof(WNDCLASSEX);
  windowDescriptor.style = CS_HREDRAW | CS_VREDRAW;
  windowDescriptor.lpfnWndProc = DefWindowProc;
  windowDescriptor.cbClsExtra = 0;
  windowDescriptor.cbWndExtra = 0;
  windowDescriptor.hInstance = modInstance;
  windowDescriptor.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  windowDescriptor.hCursor = LoadCursor(NULL, IDC_CROSS);
  windowDescriptor.hbrBackground = ( HBRUSH )(COLOR_WINDOW + 1);
  windowDescriptor.lpszMenuName = NULL;
  windowDescriptor.lpszMenuName = NULL;


  return ErrorCode::failedCreation;
}

ErrorCode
enWindowDX11::resizeWindow(const int32 windowWidth, const int32 windowHeight)
{
  return ErrorCode();
}

void*
enWindowDX11::getWindowHandle()
{
  return nullptr;
}

bool
enWindowDX11::isPointInsideWindow(const enMath::enVec2& point)
{
  return false;
}
