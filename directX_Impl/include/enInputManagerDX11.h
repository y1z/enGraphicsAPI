#pragma once
#include "core/include/enInputManagerCore.h"
#include "core/util/enModule.h"

// for removing unnecessary part of windows for the directX implementation
#define WIN32_LEAN_AND_MEAN 1
#define NOMINMAX 1 // really don't want the max and min macros from windows
#include <Windows.h>

/**
 * @brief the implementation of the inputManager for DirectX
 */
class enInputManagerDX11 : public enInputManagerCore ,public enModule< enInputManagerDX11 >
{
public:
  using windProcType = LRESULT(CALLBACK*)(HWND, UINT, WPARAM, LPARAM);
public:

  /** @returns the last key pressed*/
  [[nodiscard]] KeyInput
  getLastPressedKey() const override;

  /** @brife update the input */
  void
  updateInput() override;

  /** @brief for activating the module */
  bool
  internalActivateModule(void *descriptor) override;

  windProcType
  getProcPtr();

private:

  static LRESULT CALLBACK
  internalWindowProcedure(HWND handle, // procedure
                          UINT message,
                          WPARAM wparam,
                          LPARAM lparam);


private:
  inline static enInputData s_windProcData = enInputData(KeyInput::nullInput);
  inline static windProcType s_procPtr = nullptr;
};

