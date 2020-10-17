#pragma once
#include "core/util/enDefines.h"
#include "core/util/enModule.h"


/**
 * @brife takes care of all user input operations
 */
class enInputManagerCore : public enModule< enInputManagerCore >
{
public:
  enInputManagerCore()
    :m_inputTimeDelta(0.0f),
    m_lastInput(KeyInput::nullInput)
  {};
public:

  /** @returns a copy of the last cached input. */
  [[nodiscard]] enInputData
  getInputLastInputData()const
  {
    return m_lastInput;
  }

  /** @returns the last key pressed*/
  [[nodiscard]] virtual KeyInput
  getLastPressedKey() const = 0;

  /** @brife update the input */
  virtual void
  updateInput() = 0;

private:

  /**
   * @brief controls how much time the input should wait before returning 
   * a the last pressed key.
   */
  float m_inputTimeDelta;


  /**
   * @brief contains the last cached input from the user.
   */
  enInputData m_lastInput; 

};


