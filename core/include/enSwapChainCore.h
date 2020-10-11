#pragma once
#include "core/include/enRenderTargetCore.h"

/**
 * @class enSwapChainCore : interface for implementation of a swap chain.
 */
class enSwapChainCore 
{
public://constructors
  enSwapChainCore() = default;
  enSwapChainCore(const enSwapChainCore&) = default;
  enSwapChainCore(enSwapChainCore&&) noexcept = default;
  virtual ~enSwapChainCore() noexcept = default;
public:// operators

  enSwapChainCore& operator= (const enSwapChainCore&) = default;
  enSwapChainCore& operator= (enSwapChainCore&&) noexcept = default;

public:// functions

  /**
   * @brief sets the RenderTarget the swap chain will use.
   */
  virtual ErrorCode
  setRenderTarget(enRenderTargetCore& rt) = 0;


  /**
   * @brief presents all the data draw on to the renderTarget.
   * @param options : used for when the implementation has additional options also
   */
  virtual ErrorCode
  present([[maybe_unused]]int options = 0) = 0;
  
};
