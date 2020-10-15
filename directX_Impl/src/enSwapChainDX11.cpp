#include "directX_Impl/include/enSwapChainDX11.h"

enSwapChainDX11::enSwapChainDX11()
:m_dx11SwapChain(nullptr)
{}

enSwapChainDX11::enSwapChainDX11(IDXGISwapChain * ptrSwapChain)
:m_dx11SwapChain(ptrSwapChain)
{
  ptrSwapChain = nullptr;
}

enSwapChainDX11::enSwapChainDX11(enSwapChainDX11 && swapChain) noexcept
  :m_dx11SwapChain(swapChain.m_dx11SwapChain)
{
  swapChain.m_dx11SwapChain = nullptr;
}

enSwapChainDX11::~enSwapChainDX11() noexcept
{
  SAFE_DX_RELEASE(m_dx11SwapChain)
}

enSwapChainDX11& 
enSwapChainDX11::operator=(enSwapChainDX11&& swapChain) noexcept
{
  SAFE_DX_RELEASE(m_dx11SwapChain);
  m_dx11SwapChain = swapChain.m_dx11SwapChain;
  swapChain.m_dx11SwapChain = nullptr;
  return *this;
}


// TODO : Implement function
ErrorCode
enSwapChainDX11::setRenderTarget(enRenderTargetCore& rt)
{
    return ErrorCode();
}

// TODO : Implement function
ErrorCode 
enSwapChainDX11::present([[maybe_unused]] int options)
{
  return ErrorCode();
}

ErrorCode 
enSwapChainDX11::resizeSwapChain(uint32 width,
                                 uint32 height,
                                 enRenderTargetCore& rt)
{
  return ErrorCode();
}

IDXGISwapChain* 
enSwapChainDX11::getDX11SwapChain() const
{
  return m_dx11SwapChain;
}

IDXGISwapChain** 
enSwapChainDX11::getDX11SwapChainRef()
{
  return &m_dx11SwapChain;
}
