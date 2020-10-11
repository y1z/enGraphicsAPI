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
  enRenderTargetCore(enRenderTargetCore&&) noexcept = default;
  virtual ~enRenderTargetCore() noexcept = default;

public:
  enRenderTargetCore& operator=(const enRenderTargetCore&) = default;
  enRenderTargetCore& operator=(enRenderTargetCore&&)noexcept = default;
public:

  /**
   * @brief : initializes a render target.
   */
  virtual ErrorCode
  initRenderTarget(const uint32 width,const uint32 height, int format) = 0;


  /**
   * @brief : creates a render-target from a 2D Texture.
   */
  virtual ErrorCode
  initFromTexture(const enTexture2DCore& texture) = 0;

  /**
   * @returns The height of the render target
   */
  [[nodiscard]] uint32
  getHeight()const
  {
    return m_height;
  }

  /**
   * @returns The height of the render target
   */
  [[nodiscard]] uint32
  getWidth()const
  {
    return m_width;
  }

protected:
  /**@brief The width of the render target*/
  uint32 m_width;

  /**@brief The height of the render target*/
  uint32 m_height;
};


