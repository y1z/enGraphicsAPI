#pragma once
#include "core/include/enSwapChainCore.h"
#include "directX_Impl/dx11_utility/dx11Headers.h"

class enSwapChainDX11 : public enSwapChainCore
{
public:
  enSwapChainDX11();
  explicit enSwapChainDX11(IDXGISwapChain* ptrSwapChain);
  enSwapChainDX11(const enSwapChainDX11& ) = delete;
  enSwapChainDX11(enSwapChainDX11&& swapChain) noexcept;
  ~enSwapChainDX11() noexcept;
public:
  enSwapChainDX11& operator =(const enSwapChainDX11&) = delete;
  enSwapChainDX11& operator =(enSwapChainDX11&& swapChain ) noexcept;

public:

  /**
   * @brief sets the RenderTarget the swap chain will use.
   */
  ErrorCode
  setRenderTarget(enRenderTargetCore& rt) override;


  /**
   * @brief presents all the data draw on to the renderTarget.  
   * @param options : used for when the implementation has additional options also 
   */
  ErrorCode
  present(int options = 0) override;

  /**
   * @brief changes the size of the swap-chain buffer.
   */
  ErrorCode
  resizeSwapChain(uint32 width,
                  uint32 height,
                  enRenderTargetCore& rt) override;



  /**
   * @returns a pointer the implementation (DirectX in this case) SwapChain.
   */
  [[nodiscard]] IDXGISwapChain*
  getDX11SwapChain()const;

  /**
   * @returns a reference to a pointer 
   * of the implementations (DirectX in this case) SwapChain.
   */
  [[nodiscard]] IDXGISwapChain**
  getDX11SwapChainRef();

private:
  IDXGISwapChain* m_dx11SwapChain; 

};

