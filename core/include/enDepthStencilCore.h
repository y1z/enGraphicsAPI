#pragma once
#include "core/util/enDefines.h"
#include "core/include/enRenderTargetCore.h"

class enDepthStencilCore 
{
public:
  enDepthStencilCore(const enDepthStencilCore&) = default;
  enDepthStencilCore(enDepthStencilCore&&) noexcept = default;
  virtual ~enDepthStencilCore() = default;
public:
enDepthStencilCore& operator=(const enDepthStencilCore&) = default;
enDepthStencilCore& operator=(enDepthStencilCore&&) noexcept = default;

public:

  virtual ErrorCode  
  init(const enRenderTargetCore& rt, int format) = 0;


  int m_format;
};
