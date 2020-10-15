#include "directX_Impl/include/Testing.h"

int main()
{
  const ErrorCode result = startWindowTest();
  EN_LOG_WITH_ERROR_CODE(result,"");
}