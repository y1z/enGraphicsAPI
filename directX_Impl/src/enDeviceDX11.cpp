#include "directX/include/enDeviceDX11.h"
#include "core/include/enShaderProgramCore.h"
#include"core/include/enTextureCore.h"

#include <d3d11.h>
#include <d3dcompiler.h>

ErrorCode 
enDeviceDX11::init(enDeviceContextCore& deviceContext)
{
  return ErrorCode::failedCreation;
}

enTextureCore* 
enDeviceDX11::createTexture(std::string_view filePath)
{
  return nullptr;
}

enSamplerCore*
enDeviceDX11::createSampler(const enSamplerData& data)
{
  return nullptr;
}

enRenderTargetCore*
enDeviceDX11::createRenderTarget(const uint32 width, const uint32 height)
{
  return nullptr;
}

enSwapChainCore*
enDeviceDX11::createSwapChain()
{
  return nullptr;
}

enInputLayoutCore*
enDeviceDX11::createInputLayout(const enInputLayoutData& data)
{
  return nullptr;
}

std::unique_ptr<enVertexShaderCore>
enDeviceDX11::createVertexShader(std::string_view shaderFilePath)
{
  return std::unique_ptr<enVertexShaderCore>();
}

std::unique_ptr<enPixelShaderCore>
enDeviceDX11::createPixelShader(std::string_view shaderFilePath)
{
  return std::unique_ptr<enPixelShaderCore>();
}

std::unique_ptr<enShaderProgramCore>
enDeviceDX11::createShaderProgram(const enShaderProgramData& data)
{
  return std::unique_ptr<enShaderProgramCore>();
}

enModelCore*
enDeviceDX11::createModel(std::string_view filePath)
{
  return nullptr;
}

enSceneCore*
enDeviceDX11::createScene(const std::vector<std::string>& filePaths)
{
  return nullptr;
}

enMeshCore*
enDeviceDX11::createMesh(std::unique_ptr<enVertexBufferCore>&& vertexBuffer,
                         std::unique_ptr<unsigned32IndexBuffer>&& indexBuffer)
{
  return nullptr;
}

enVertexBufferCore*
enDeviceDX11::createVertexBuffer(const std::vector<enVertexType>& vertexes)
{
  return nullptr;
}

unsigned32IndexBuffer*
enDeviceDX11::createIndexBuffer(const std::vector<uint32>& indexes)
{
  return nullptr;
}
