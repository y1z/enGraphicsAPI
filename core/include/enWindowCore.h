#pragma once
#include "core/util/enDefines.h"

class enWindowCore 
{
public:
  enWindowCore() = default;
  enWindowCore(const enWindowCore&) = default;
  enWindowCore(enWindowCore&&)noexcept = default;
  virtual ~enWindowCore() noexcept = default;
public:
  enWindowCore& operator=(const enWindowCore&) = default;
  enWindowCore& operator=(enWindowCore&&) noexcept = default;
public:

  /** 
   * @brief initializes the window
   * @param windowHandle : a implementation defined pointer to a handle used to control
   * the window 
   * @param windowWidth : how wide the window is going to be.
   * @param windowHeight : how tall the window is going to be.
   */
  virtual ErrorCode
  init(void* windowHandle,
       const uint16 windowWidth,
       const uint16 windowHeight) = 0;

  /**
  * @brief Resizes the window.
  * @param windowWidth : the new width of the window.
  * @param windowHeight : the new height of the window.
  */
  virtual ErrorCode 
  resizeWindow(const uint16 windowWidth,
               const uint16 windowHeight) = 0;

  /** @returns a pointer to the window handle. */
  virtual void *
  getWindowHandle() = 0;

  /** @returns the width of the window*/
  [[nodiscard]] uint16
  getWindowWidth()const
  {
    return m_width;
  }

  /** @returns the height of the window*/
  [[nodiscard]] uint16
  getWindowHeight()const
  {
    return m_height;
  }

  /**
   * @returns a pointer to the window handle.
   * @param point : the point on the screen.
   */
  virtual bool
  isPointInsideWindow(const enMath::enVec2& point) = 0;

protected:
  /** @brief is the width of the window*/
  uint16 m_width;
  /** @brief is the height of the window*/
  uint16 m_height;
  
};
