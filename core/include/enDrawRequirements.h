#pragma once
#include "core/util/enDefines.h"

class enDeviceContextCore;

/**
 * @class enDrawRequirements : are the requirements for being drawn.
 */
class enDrawRequirements 
{
public://constructors
  enDrawRequirements() = default;
  enDrawRequirements(const enDrawRequirements&) = default;
  enDrawRequirements(enDrawRequirements&&) = default;
  virtual ~enDrawRequirements() = default;
public:// operators
  enDrawRequirements& operator=(const enDrawRequirements&) = default;
  enDrawRequirements& operator=(enDrawRequirements&&) = default;
public:
  /**
   * @brief used to prepare the object to be drawn.
   */
  virtual ErrorCode
  setSelfToDrawTarget(enDeviceContextCore& deviceContext) = 0;

  /**
   * @brief does the actual drawing.
   */
  virtual ErrorCode
  draw() = 0;
};
