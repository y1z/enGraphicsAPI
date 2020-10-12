#pragma once
#include "core/util/enDefines.h"

class enRenderTargetCore;


/**
 * @class enDrawDeviceCore : takes care of drawing any object that can be drawn.
 */
class enDrawDeviceCore 
{
public://constructors
  enDrawDeviceCore() = default;
  enDrawDeviceCore(const enDrawDeviceCore&) = default;
  enDrawDeviceCore(enDrawDeviceCore&&) = default;
  virtual ~enDrawDeviceCore() = default;
public:// operators
  enDrawDeviceCore& operator=(const enDrawDeviceCore&) = default;
  enDrawDeviceCore& operator=(enDrawDeviceCore&&) = default;
public:

  virtual ErrorCode
  draw(enRenderTargetCore& rt) = 0;
};

