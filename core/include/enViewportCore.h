#pragma once
#include "core/util/enDefines.h"

class enViewPortCore 
{
public:
  virtual ErrorCode
  init(const sViewportData&) = 0;
  
};
