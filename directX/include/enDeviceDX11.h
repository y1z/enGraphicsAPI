#pragma once
#include "core/include/enDeviceCore.h"

class enDeviceDX11 :
    public enDeviceCore 
{
  /** @brief initializes the device context*/
  ErrorCode
  init(enDeviceContextCore& deviceContext)override;

  /** @returns a pointer to a instance of enTextureCore used to manipulate derived classes*/
  enTextureCore*
  createTexture(std::string_view filePath)override;

  /** @returns a pointer to a instance of enSamplerCore used to manipulate derived classes*/
  enSamplerCore*
  createSampler(const enSamplerData& data )override;

  /** @returns a pointer to a instance of enRenderTargetCore used to manipulate derived classes*/
  enRenderTargetCore*
  createRenderTarget(const uint32 width,
                     const uint32 height)override;

  /** @returns a pointer to a instance of enSwapChainCore used to manipulate derived classes*/
  enSwapChainCore*
  createSwapChain()override;

  /** @returns a pointer to a instance of enInputLayoutCore used to manipulate derived classes*/
  enInputLayoutCore*
  createInputLayout(const enInputLayoutData& data)override;

  /** @returns a pointer to a instance of enVertexShaderCore used to manipulate derived classes*/
  std::unique_ptr<enVertexShaderCore>
  createVertexShader(std::string_view shaderFilePath)override;

  /** @returns a pointer to a instance of enPixelShaderCore used to manipulate derived classes*/
  std::unique_ptr<enPixelShaderCore>
  createPixelShader(std::string_view shaderFilePath)override;

  /** @returns a pointer to a instance of enShaderProgramCore used to manipulate derived classes*/
  std::unique_ptr<enShaderProgramCore>
  createShaderProgram(const enShaderProgramData&data)override;

  /** @returns a pointer to a instance of unsigned32IndexBuffer used to manipulate derived classes*/
  enModelCore*
  createModel(std::string_view filePath)override;

  /** @returns a pointer to a instance of enSceneCore used to manipulate derived classes
   * @brief this class is used to manipulate a group of 3d models.
   */
  enSceneCore*
  createScene(const std::vector<std::string>& filePaths)override;

protected:
  /** @returns a pointer to a instance of enMeshCore to create enModules */
  enMeshCore*
  createMesh(std::unique_ptr<enVertexBufferCore>&& vertexBuffer,
             std::unique_ptr<unsigned32IndexBuffer>&& indexBuffer)override;

  /** @returns a pointer to a instance of a enVertexBufferCore used to manipulate derived classes*/
  enVertexBufferCore*
  createVertexBuffer(const std::vector<enVertexType>& vertexes )override;

  /** @returns a pointer to a instance of a unsigned32IndexBuffer used to manipulate derived classes*/
  unsigned32IndexBuffer*
  createIndexBuffer(const std::vector<uint32>& indexes)override;

};

