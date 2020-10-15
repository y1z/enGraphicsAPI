#pragma once
#include "core/include/enDeviceCore.h"
#include "directX_Impl/dx11_utility/dx11Headers.h"

class enDeviceDX11 : public enDeviceCore 
{
public:
  friend class enDeviceContextDX11;
public:
  enDeviceDX11();
  enDeviceDX11(const enDeviceDX11&) = delete;
  enDeviceDX11(enDeviceDX11&&) noexcept = delete;

  ~enDeviceDX11() noexcept;
public:
  enDeviceDX11& 
  operator=(const enDeviceDX11&) = delete;

  enDeviceDX11& 
  operator=(enDeviceDX11&&) noexcept = delete;
public:

  /** @brief initializes the device along with the device-context */
  [[nodiscard]] ErrorCode
  init(enDeviceContextCore& deviceContext)override;

  /** @returns a pointer to a instance of enTextureCore used to manipulate derived classes*/
  [[nodiscard]] enTextureCore*
  createTexture(std::string_view filePath)override;

  /** @returns a pointer to a instance of enSamplerCore used to manipulate derived classes*/
  [[nodiscard]] enSamplerCore*
  createSampler(const enSamplerData& data )override;

  /** @returns a pointer to a instance of enRenderTargetCore used to manipulate derived classes*/
  [[nodiscard]] enRenderTargetCore*
  createRenderTarget(const uint32 width,
                     const uint32 height)override;

  /** @returns a pointer to a instance of enSwapChainCore used to manipulate derived classes*/
  [[nodiscard]] enSwapChainCore*
  createSwapChain()override;

  /** @returns a pointer to a instance of enInputLayoutCore used to manipulate derived classes*/
  [[nodiscard]] enInputLayoutCore*
  createInputLayout(const enInputLayoutData& data)override;

  /** @returns a pointer to a instance of enVertexShaderCore used to manipulate derived classes*/
  [[nodiscard]] std::unique_ptr<enVertexShaderCore>
  createVertexShader(std::string_view shaderFilePath)override;

  /** @returns a pointer to a instance of enPixelShaderCore used to manipulate derived classes*/
  [[nodiscard]] std::unique_ptr<enPixelShaderCore>
  createPixelShader(std::string_view shaderFilePath)override;

  /** @returns a pointer to a instance of enShaderProgramCore used to manipulate derived classes*/
  [[nodiscard]] std::unique_ptr<enShaderProgramCore>
  createShaderProgram(const enShaderProgramData&data)override;

  /** @returns a pointer to a instance of unsigned32IndexBuffer used to manipulate derived classes*/
  [[nodiscard]] enModelCore*
  createModel(std::string_view filePath)override;

  /** @returns a pointer to a instance of enSceneCore used to manipulate derived classes
   * @brief this class is used to manipulate a group of 3d models.
   */
  [[nodiscard]] enSceneCore*
  createScene(const std::vector<std::string>& filePaths)override;

protected:
  /** @returns a pointer to a instance of enMeshCore to create enModules */
  [[nodiscard]] enMeshCore*
  createMesh(std::unique_ptr<enVertexBufferCore>&& vertexBuffer,
             std::unique_ptr<unsigned32IndexBuffer>&& indexBuffer)override;

  /** @returns a pointer to a instance of a enVertexBufferCore used to manipulate derived classes*/
  [[nodiscard]] enVertexBufferCore*
  createVertexBuffer(const std::vector<enVertexType>& vertexes )override;

  /** @returns a pointer to a instance of a unsigned32IndexBuffer used to manipulate derived classes*/
  [[nodiscard]] unsigned32IndexBuffer*
  createIndexBuffer(const std::vector<uint32>& indexes)override;
private: //functions

  /** @brief initializes the factory internally. */
  [[nodiscard]] ErrorCode
  initInternalFactory();


  /** 
   * @brief creates a adapter .
   * @return a pointer to a adapter.
   */
  [[nodiscard]] IDXGIAdapter1*  
  createAdapter() const;



private: //variables 

  /** @brief will be used to create directX objects */
  ID3D11Device* m_dx11Device;

  /** @brief will be used to create a device and swap chain*/
  IDXGIFactory1* m_dx11Factory;

};

