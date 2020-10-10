#pragma once
#include "core/include/enRenderTargetCore.h"

class enSwapChainCore 
{
public:

  virtual ErrorCode
  setRenderTarget(enRenderTargetCore& rt) = 0;


  virtual ErrorCode
  present(int options) = 0;
  
};
