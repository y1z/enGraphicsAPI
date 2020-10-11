#pragma once
#include "core/util/enDefines.h"

/**
 * @class enViewportCore : a interface for all instances of viewport's.
 */
class enViewportCore
{
public:
  enViewportCore(const enViewportCore&) = default;
  enViewportCore(enViewportCore&&) noexcept = default;
  virtual ~enViewportCore() = default;

public:
  enViewportCore& operator=(const enViewportCore&) = default;
  enViewportCore& operator=(enViewportCore&&)noexcept = default;

public:

  virtual ErrorCode
  init(const sViewportData&data) = 0;
  
};
