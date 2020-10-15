#include "directX_Impl/include/enDeviceDX11.h"
#include "directX_Impl/include/enDeviceContextDX11.h"
#include "directX_Impl/include/enSwapChainDX11.h"

#include "core/include/enShaderProgramCore.h"
#include "core/include/enTextureCore.h"


#include <array>
#include <d3dcompiler.h>
#include <dxgi.h>

enDeviceDX11::enDeviceDX11()
:m_dx11Device(nullptr),
m_dx11Factory(nullptr)
{
}

enDeviceDX11::~enDeviceDX11() noexcept
{
  SAFE_DX_RELEASE(m_dx11Device)
  SAFE_DX_RELEASE(m_dx11Factory)
}

ErrorCode
enDeviceDX11::init(enDeviceContextCore& deviceContext)
{
  enDeviceContextDX11* directX11DeviceContext =
    dynamic_cast< enDeviceContextDX11* >(&deviceContext);

  if( nullptr == directX11DeviceContext )
  {
    EN_LOG_DEBUG_INFO("Using a wrong interface, would you kindly use the directX one.")
      return ErrorCode::badArgument;
  }

  ErrorCode result = initInternalFactory();
  if( ErrorCode::success != result )
  {
    EN_LOG_DEBUG_INFO("The Factory failed to be created.")
      return result;
  }

  IDXGIAdapter1* adapter = createAdapter();
  if( nullptr == adapter )
  {
    return ErrorCode::failedCreation;
  }

  DXGI_ADAPTER_DESC1 adapterDescriptor;
  HRESULT hr = adapter->GetDesc1(&adapterDescriptor);
  if( hr != S_OK )
  {
    EN_LOG_DEBUG_INFO("Passed a invalid parameter ")
    return ErrorCode::badArgument;
  }

  UINT deviceFlags = 0;
#if !NDEBUG
  deviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
  deviceFlags |= D3D11_CREATE_DEVICE_DEBUGGABLE;// requires DirectX feature level 11.1
#endif // !NDEBUG

  const std::array<const D3D_FEATURE_LEVEL ,3> featureLevels
  {
    D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_1,
    D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_0,
    D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_1,
  };

  D3D_FEATURE_LEVEL selectedFeatureLevel;

  HRESULT deviceCreationResult = D3D11CreateDevice(adapter,
                                                   D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_UNKNOWN,
                                                   NULL,
                                                   deviceFlags,
                                                   &featureLevels[0],
                                                   featureLevels.size(),
                                                   D3D11_SDK_VERSION,
                                                   &m_dx11Device,
                                                   &selectedFeatureLevel,
                                                   &directX11DeviceContext->m_dx11DeviceContext);

  if( S_OK == deviceCreationResult )
  {
    result = ErrorCode::success;
  }
  else
  {
    result = ErrorCode::badArgument;
  }
  
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
enDeviceDX11::createSwapChain(const uint32 screenWidth,
                              const uint32 screenHeight,
                              int format)
{
  DXGI_SWAP_CHAIN_DESC swapDescriptor;
  std::memset(&swapDescriptor ,0,sizeof(swapDescriptor));
  swapDescriptor.BufferDesc.Format = static_cast< DXGI_FORMAT > (format);
  swapDescriptor.BufferCount = 1;
  swapDescriptor.BufferDesc.Width = screenWidth;
  swapDescriptor.BufferDesc.Height = screenHeight;
  swapDescriptor.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  swapDescriptor.BufferDesc.RefreshRate.Numerator = 60;
  swapDescriptor.BufferDesc.RefreshRate.Denominator = 1;
  swapDescriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
  //swapDescriptor.OutputWindow = g_hWnd;
  swapDescriptor.SampleDesc.Count = 1;
  swapDescriptor.SampleDesc.Quality = 0;
  swapDescriptor.Windowed = TRUE;


  IDXGISwapChain* dx11SwapChain;
  const HRESULT swapChainCreationResult =
    m_dx11Factory->CreateSwapChain(m_dx11Device,
                                   &swapDescriptor,
                                   &dx11SwapChain);

  if( S_OK == swapChainCreationResult )
  {
    return new enSwapChainDX11(dx11SwapChain);
  }

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

