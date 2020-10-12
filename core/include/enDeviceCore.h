#pragma once
#include <string_view>
#include <memory>

#include "core/util/enDefines.h"

class enTextureCore;
class enRenderTargetCore;

class enInputLayoutCore;

class enVertexShaderCore;
class enPixelShaderCore;
class enShaderProgramCore;

class enDeviceContextCore;
class enSwapChainCore;

/**
 * @class enDeviceCore : takes care of creating every single object in the game
 */
class enDeviceCore 
{
public:
  enDeviceCore() = default;
  enDeviceCore(const enDeviceCore&) = delete;
  enDeviceCore(enDeviceCore&&) noexcept = delete;
  virtual ~enDeviceCore() noexcept = default;

public:
  enDeviceCore& operator=(const enDeviceCore&) = delete;
  enDeviceCore& operator=(enDeviceCore&&) = delete;
public:

  /** @brief initializes the device context*/
  virtual ErrorCode
  init(enDeviceContextCore& deviceContext) = 0;

  /** @returns a pointer to a instance of a enTextureCore used to manipulate derived classes*/
  virtual enTextureCore*
  createTexture(std::string_view filePath) = 0;

  /** @returns a pointer to a instance of a enRenderTargetCore used to manipulate derived classes*/
  virtual enRenderTargetCore*
  createRenderTarget(const uint32 width, const uint32 height) = 0;

  /** @returns a pointer to a instance of a enInputLayoutCore used to manipulate derived classes*/
  virtual enInputLayoutCore*
  createInputLayout(const enInputLayoutData& data) = 0;

  /** @returns a pointer to a instance of a enVertexShaderCore used to manipulate derived classes*/
  virtual std::unique_ptr<enVertexShaderCore>
  createVertexShader(std::string_view shaderFilePath) = 0;

  /** @returns a pointer to a instance of a enPixelShaderCore used to manipulate derived classes*/
  virtual std::unique_ptr<enPixelShaderCore>
  createPixelShader(std::string_view shaderFilePath) = 0;

  /** @returns a pointer to a instance of a enShaderProgramCore used to manipulate derived classes*/
  virtual std::unique_ptr<enShaderProgramCore>
  createShaderProgram(const enShaderProgramData&data) = 0;


};
