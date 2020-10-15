#pragma once
#include <string_view>
#include <memory>
#include <vector>

#include "core/util/enDefines.h"

class enTextureCore;// check
class enRenderTargetCore;// check

class enInputLayoutCore;// check

class enVertexBufferCore;//check
class unsigned32IndexBuffer;// check

class enVertexShaderCore;// check
class enPixelShaderCore;// check
class enShaderProgramCore;// check

class enDeviceContextCore; // check
class enSwapChainCore;

class enSamplerCore;

class enMeshCore;
class enModelCore;
class enSceneCore;

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

  /** @brief initializes the device along with the device-context */
  virtual ErrorCode
  init(enDeviceContextCore& deviceContext) = 0;

  /** @returns a pointer to a instance of enTextureCore used to manipulate derived classes*/
  virtual enTextureCore*
  createTexture(std::string_view filePath) = 0;

  /** @returns a pointer to a instance of enSamplerCore used to manipulate derived classes*/
  virtual enSamplerCore*
  createSampler(const enSamplerData& data ) = 0;

  /** @returns a pointer to a instance of enRenderTargetCore used to manipulate derived classes*/
  virtual enRenderTargetCore*
  createRenderTarget(const uint32 width,
                     const uint32 height) = 0;

  /** @returns a pointer to a instance of enSwapChainCore used to manipulate derived classes*/
  virtual enSwapChainCore*
  createSwapChain(const uint32 screenWidth,
                  const uint32 screenHeight,
                  int format) = 0;

  /** @returns a pointer to a instance of enInputLayoutCore used to manipulate derived classes*/
  virtual enInputLayoutCore*
  createInputLayout(const enInputLayoutData& data) = 0;

  /** @returns a pointer to a instance of enVertexShaderCore used to manipulate derived classes*/
  virtual std::unique_ptr<enVertexShaderCore>
  createVertexShader(std::string_view shaderFilePath) = 0;

  /** @returns a pointer to a instance of enPixelShaderCore used to manipulate derived classes*/
  virtual std::unique_ptr<enPixelShaderCore>
  createPixelShader(std::string_view shaderFilePath) = 0;

  /** @returns a pointer to a instance of enShaderProgramCore used to manipulate derived classes*/
  virtual std::unique_ptr<enShaderProgramCore>
  createShaderProgram(const enShaderProgramData&data) = 0;

  /** @returns a pointer to a instance of unsigned32IndexBuffer used to manipulate derived classes*/
  virtual enModelCore*
  createModel(std::string_view filePath) = 0;

  /** @returns a pointer to a instance of enSceneCore used to manipulate derived classes
   * @brief this class is used to manipulate a group of 3d models.
   */
  virtual enSceneCore*
  createScene(const std::vector<std::string>& filePaths) = 0;

protected:
  /** @returns a pointer to a instance of enMeshCore to create enModules */
  virtual enMeshCore*
  createMesh(std::unique_ptr<enVertexBufferCore>&& vertexBuffer,
             std::unique_ptr<unsigned32IndexBuffer>&& indexBuffer) = 0;

  /** @returns a pointer to a instance of a enVertexBufferCore used to manipulate derived classes*/
  virtual enVertexBufferCore*
  createVertexBuffer(const std::vector<enVertexType>& vertexes ) = 0;

  /** @returns a pointer to a instance of a unsigned32IndexBuffer used to manipulate derived classes*/
  virtual unsigned32IndexBuffer*
  createIndexBuffer(const std::vector<uint32>& indexes) = 0;

};
