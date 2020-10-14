#pragma once
class enTextureCore; // check
class enRenderTargetCore;// check

class enInputLayoutCore;// check

class enVertexBufferCore;// check 
class unsigned32IndexBuffer; // check

class enVertexShaderCore; // check
class enPixelShaderCore;// check
class enShaderProgramCore; // check

class enSwapChainCore; // check

class enSamplerCore;// check

class enMeshCore;// check
class enModelCore;// check
class enSceneCore;// check


/**
 * @class enDeviceContextCore : a interface for preparing other interface to be used.
 */
class enDeviceContextCore 
{
  friend class enDeviceContextDX11;
public:// functions
  enDeviceContextCore() = default;
  enDeviceContextCore(const enDeviceContextCore &) = delete;
  enDeviceContextCore(enDeviceContextCore &&) noexcept = delete;
  virtual ~enDeviceContextCore() noexcept = default;

public:
  enDeviceContextCore& operator=(const enDeviceContextCore&) = delete;
  enDeviceContextCore& operator=(enDeviceContextCore &&) = delete;
public:

  /**
   * @brief prepares the texture to be used.
   */
  virtual void
  setTexture(const enTextureCore& texture) = 0;

  /**
   * @brief prepares render-target to be used.
   */
  virtual void
  setRenderTarget(const enRenderTargetCore& rt) = 0;


  /**
   * @brief prepares the input layout to be used.
   */
  virtual void
  setInputLayout(const enInputLayoutCore& inputLayout) = 0;

  /**
   * @brief prepares the input layout to be used.
   */
  virtual void
  setShaderProgram(const enShaderProgramCore& shaderProgram) = 0;

  /**
   * @brief prepares the vertexShader to be used.
   */
  virtual void
  setVertexShader(const enVertexShaderCore& vertexShader) = 0;

  /**
   * @brief prepares the vertexShader to be used.
   */
  virtual void
  setPixelShader(const enPixelShaderCore& pixelShader) = 0;

  /**
   * @brief prepares the vertex buffer to be used .
   */
  virtual void
  setVertexBuffer(const enVertexBufferCore& vertexBuffer) = 0;
  
  /**
   * @brief prepares the vertexShader to be used.
   */
  virtual void
  setIndexBuffer(const unsigned32IndexBuffer& indexBuffer) = 0;

  /** @brief prepares the swap-chain to be used. */
  virtual void
  setSwapChain(const enSwapChainCore& swapChain) = 0;

  /** @brief prepares a sampler with a texture to be used. */
  virtual void
  setSampler(const enSamplerCore& sampler ,
             const enTextureCore& texture) = 0;


  /** @brief prepares a mesh for rendering. */
  virtual void
  setMesh(const enMeshCore& mesh) = 0;


};



