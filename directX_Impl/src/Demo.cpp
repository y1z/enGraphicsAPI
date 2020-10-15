#include "directX_Impl/include/Demo.h"
#include "directX_Impl/include/enDeviceDX11.h"
#include "directX_Impl/include/enDeviceContextDX11.h"
#include <utility>

using std::make_unique;
using std::unique_ptr;

ErrorCode
startDeviceTest()
{
  unique_ptr<enDeviceCore> device = make_unique<enDeviceDX11>();
  unique_ptr<enDeviceContextCore> deviceContext = make_unique<enDeviceContextDX11>();

  ErrorCode currentErrorCode = device->init(*deviceContext);
  

  return currentErrorCode;
}
