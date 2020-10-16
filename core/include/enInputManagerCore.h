#pragma once
#include "core/util/enDefines.h"


/**
 * @brife takes care of all user input operations
 */
class enInputManagerCore 
{
public:
  enInputManagerCore() = default;
  virtual ~enInputManagerCore() = default;
public:

  virtual ErrorCode
  init( ) = 0;

  enInputData
  getInputLastInputData()const
  {
    return m_lastInput;
  }

  virtual KeyInput
  getLastPressedKey() const = 0;


private:
  enInputData m_lastInput; 

};
