#pragma once
#include "core/util/enDefines.h"
#include "core/include/enTextureCore.h"


/**
 * @class  enRenderTargetCore : a interface to a render target.
 */
class enRenderTargetCore 
{
public:
  enRenderTargetCore(const enRenderTargetCore&) = default;
  enRenderTargetCore(enRenderTargetCore&&) = default;
  virtual ~enRenderTargetCore() =default;
public:

  virtual ErrorCode
  initRenderTarget(const uint32 width,const uint32 height, int format) = 0;


  virtual ErrorCode
  initFromTexture(const enTexture2DCore& texture) =0;


protected:
  uint32 m_width;
  uint32 m_height;
};


