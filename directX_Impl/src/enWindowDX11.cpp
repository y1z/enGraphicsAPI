#include "directX_Impl/include/enWindowDX11.h"
#include "directX_Impl/include/enInputManagerDX11.h"
#include "core/util/stringConversions.h"

enWindowDX11::enWindowDX11()
  :enWindowCore()
{}

enWindowDX11::enWindowDX11(enWindowDX11 && other) noexcept
  :m_handle(other.m_handle),
  m_module(other.m_module)
{
  other.m_handle = nullptr;
  other.m_module = nullptr;
}

ErrorCode
enWindowDX11::init(void* windowHandle,
                   const char* windowName,
                   enInputManagerCore* inputManPtr,
                   const int32 windowWidth,
                   const int32 windowHeight)

{
  const HMODULE modInstance = reinterpret_cast< HMODULE > (windowHandle);

  auto* dx11InputMan = dynamic_cast<enInputManagerDX11*>(inputManPtr);
  if( nullptr == dx11InputMan )
  {
    EN_LOG_DEBUG_INFO("Requires that you use directX implementation of the input-manager");
    return ErrorCode::wrongImplementation;
  }

  if( nullptr == dx11InputMan->getProcPtr() )
  {
    EN_LOG_DEBUG_INFO("Requires that the Input manager module be activated ");
    return ErrorCode::unpreparedForOperation;
  }

#if UNICODE || _UNICODE
  const std::wstring activeWindowName = convertStringToWString(windowName);
#else
  const std::string activeWindowName{windowName};
#endif // UNICODE || _UNICODE
  WNDCLASSEX windowDescriptor;
  windowDescriptor.cbSize = sizeof(WNDCLASSEX);
  windowDescriptor.style = CS_HREDRAW | CS_VREDRAW;
  windowDescriptor.lpfnWndProc = dx11InputMan->getProcPtr();
  windowDescriptor.cbClsExtra = 0;
  windowDescriptor.cbWndExtra = 0;
  windowDescriptor.hInstance = modInstance;
  windowDescriptor.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  windowDescriptor.hCursor = LoadCursor(NULL, IDC_CROSS);
  windowDescriptor.hbrBackground = ( HBRUSH )(COLOR_WINDOW + 1);
  windowDescriptor.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  windowDescriptor.lpszClassName = activeWindowName.c_str();
  windowDescriptor.lpszMenuName = NULL;
  windowDescriptor.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


  if( !RegisterClassEx(&windowDescriptor) )
  {
    EN_LOG_DEBUG_INFO("something failed in the Registration of the window");
    return ErrorCode::failedCreation;
  }

  // Create window
  m_width = windowWidth;
  m_height = windowHeight;
  RECT rc = { 0, 0,  m_width , m_height };
  AdjustWindowRect(&rc,
                   WS_OVERLAPPEDWINDOW,
                   FALSE);

  m_handle = CreateWindow(activeWindowName.c_str(),
                          activeWindowName.c_str(),
                          WS_OVERLAPPEDWINDOW,
                          CW_DEFAULT,
                          CW_DEFAULT,
                          rc.right - rc.left,
                          rc.bottom - rc.top,
                          NULL,
                          NULL,
                          modInstance,
                          NULL);

  if( !m_handle )
  {

    EN_LOG_DEBUG_INFO("something failed in the creation of the window");
    return ErrorCode::failedCreation;
  }

  ShowWindow(m_handle, SW_SHOW);
  UpdateWindow(m_handle);

  return ErrorCode::success;
}


ErrorCode
enWindowDX11::resizeWindow(const int32 windowWidth,
                           const int32 windowHeight)
{
  return ErrorCode();
}

void*
enWindowDX11::getWindowHandle()
{
  return m_handle;
}

bool
enWindowDX11::isPointInsideWindow(const enMath::enVec2& point)
{
  return false;
}
