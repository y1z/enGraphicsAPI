#pragma once
#include "core/include/enDeviceContextCore.h"
#include "directX_Impl/dx11_utility/dx11Headers.h"


/**
 * @brief DirectX implementation of the device context.
 */
class enDeviceContextDX11 : public enDeviceContextCore 
{
public:
  friend class enDeviceDX11;
public:
  enDeviceContextDX11();
  enDeviceContextDX11(const enDeviceContextDX11&) = delete;
  enDeviceContextDX11(enDeviceContextDX11&&) = delete;
  ~enDeviceContextDX11()noexcept ;
public:
  enDeviceContextDX11& operator=(const enDeviceContextDX11&) = delete;
  enDeviceContextDX11& operator=(enDeviceContextDX11&&)noexcept = delete;
public:

  /**
   * @brief prepares the texture to be used.
   */
  void
  setTexture(const enTextureCore& texture)override;

  /**
   * @brief prepares render-target to be used.
   */
  void
  setRenderTarget(const enRenderTargetCore& rt)override;


  /**
   * @brief prepares the input layout to be used.
   */
  void
  setInputLayout(const enInputLayoutCore& inputLayout)override;

  /**
   * @brief prepares the input layout to be used.
   */
  void
  setShaderProgram(const enShaderProgramCore& shaderProgram)override;

  /**
   * @brief prepares the vertexShader to be used.
   */
  void
  setVertexShader(const enVertexShaderCore& vertexShader)override;

  /**
   * @brief prepares the vertexShader to be used.
   */
  void
  setPixelShader(const enPixelShaderCore& pixelShader)override;

  /**
   * @brief prepares the vertex buffer to be used .
   */
  void
  setVertexBuffer(const enVertexBufferCore& vertexBuffer)override;
  
  /**
   * @brief prepares the vertexShader to be used.
   */
  void
  setIndexBuffer(const unsigned32IndexBuffer& indexBuffer)override;

  /** @brief prepares the swap-chain to be used. */
  void
  setSwapChain(const enSwapChainCore& swapChain)override;

  /** @brief prepares a sampler with a texture to be used. */
  void
  setSampler(const enSamplerCore& sampler ,
             const enTextureCore& texture)override;


  /** @brief prepares a mesh for rendering. */
  void
  setMesh(const enMeshCore& mesh)override;
private:

  ID3D11DeviceContext* m_dx11DeviceContext;

};


