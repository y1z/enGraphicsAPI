#include "directX_Impl/include/Demo.h"

int main()
{
  const ErrorCode result = startDeviceTest();
  EN_LOG_WITH_ERROR_CODE(result, " testing the device init function");
}