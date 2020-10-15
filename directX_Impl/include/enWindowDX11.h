#pragma once
#include "core/include/enWindowCore.h"

// for removing unnecessary part of windows for the directX implementation
#define WIN32_LEAN_AND_MEAN 1
#define NOMINMAX 1 // really don't want the max and min macros from windows
#include <Windows.h>


/**
 * @brief DirectX implementation of the window.
 */
class enWindowDX11 : public enWindowCore 
{
public:
  using windProcType = LRESULT(CALLBACK*)(HWND, UINT, WPARAM, LPARAM);
public:
public:

  /**
  * @brief initializes the window
  * @param windowHandle : a implementation defined pointer to a handle used to control
  * the window
  * @param windowWidth : how wide the window is going to be.
  * @param windowHeight : how tall the window is going to be.
  * @param windowName : the name of the window.
  */
  ErrorCode
  init(void* windowHandle,
       const char* windowName,
       const int32 windowWidth,
       const int32 windowHeight) override;

  /**
  * @brief Resizes the window.
  * @param windowWidth : the new width of the window.
  * @param windowHeight : the new height of the window.
  */
  ErrorCode 
  resizeWindow(const int32 windowWidth,
               const int32 windowHeight)override;

  /** @returns a pointer to the window handle. */
  [[nodiscard]] void *
  getWindowHandle()override;

  /**
   * @returns a pointer to the window handle.
   * @param point : the point on the screen.
   */
  bool
  isPointInsideWindow(const enMath::enVec2& point)override;

private:

  HWND m_handle;
};

