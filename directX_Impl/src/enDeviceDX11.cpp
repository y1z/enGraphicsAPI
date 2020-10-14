#include "directX_Impl/include/enDeviceDX11.h"
#include "core/include/enShaderProgramCore.h"
#include "core/include/enTextureCore.h"

#include <d3dcompiler.h>
#include <dxgi.h>

enDeviceDX11::enDeviceDX11()
:m_dx11Device(nullptr),
m_dx11Factory(nullptr)
{
}

enDeviceDX11::~enDeviceDX11() noexcept
{
  if( nullptr != m_dx11Device )
  {
    m_dx11Device->Release();
    m_dx11Device = nullptr;
  }
  if( nullptr != m_dx11Factory )
  {
    m_dx11Factory->Release();
    m_dx11Factory = nullptr;
  }
}

ErrorCode
enDeviceDX11::init(enDeviceContextCore& deviceContext)
{

  ErrorCode result = initInternalFactory();
  if( ErrorCode::success != result )
  {
    EN_LOG_DEBUG_INFO("The Factory failed to be created.")
    return result;
  }

  IDXGIAdapter1* adapter = createAdapter();


  
  return result;
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

ErrorCode
enDeviceDX11::initInternalFactory()
{
  const HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIFactory1),
                                        reinterpret_cast< void** >(&m_dx11Factory));

  if( hr != S_OK)
  {
    return ErrorCode::failedCreation;
  }

  return ErrorCode::success;
}

IDXGIAdapter1*
enDeviceDX11::createAdapter() const
{
  UINT adapterIndex = 0u;
  IDXGIAdapter1* adapter;
  const HRESULT adpatersResult = m_dx11Factory->EnumAdapters1(adapterIndex ,&adapter);

  if( adpatersResult != S_OK )
  {
    EN_LOG_DEBUG_INFO("The Factory failed to be created.")

    return nullptr;
  }

  return adapter;
}
