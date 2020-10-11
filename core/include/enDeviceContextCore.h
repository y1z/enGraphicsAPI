#pragma once
class enTextureCore;
class enRenderTargetCore;

class enInputLayoutCore;

class enVertexShaderCore;
class enPixelShaderCore;

class enDeviceContextCore;
class enSwapChainCore;
class enShaderProgramCore;


class enDeviceContextCore 
{
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
   * @brief prepares render target to be used.
   */
  virtual void
  setRenderTarget(const enRenderTargetCore& rt) = 0;


  /**
   * @brief sets up the input layout.
   */
  virtual void
  setInputLayout(const enInputLayoutCore& inputLayout) = 0;

  /**
   * @brief sets up the input layout.
   */
  virtual void
  setShaderProgram(const enShaderProgramCore& shaderProgram) = 0;
  
};
