#include "directX_Impl/include/Demo.h"
#include "directX_Impl/include/enDeviceDX11.h"
#include "directX_Impl/include/enDeviceContextDX11.h"
#include "directX_Impl/include/enSwapChainDX11.h"
#include <utility>

using std::make_unique;
using std::unique_ptr;

ErrorCode
startDeviceTest()
{
  unique_ptr<enDeviceCore> device = make_unique<enDeviceDX11>();
  unique_ptr<enDeviceContextCore> deviceContext = make_unique<enDeviceContextDX11>();

  ErrorCode currentErrorCode = device->init(*deviceContext);
  
  enSwapChainCore* swapChain = device->createSwapChain(1280,
                                                       700,
                                                       DXGI_FORMAT_R8G8B8A8_UNORM);

  if( nullptr == swapChain )
  {
    currentErrorCode = ErrorCode::failedCreation;

  }

  SAFE_DELETE(swapChain)

  return currentErrorCode;
}
