#include "directX_Impl/include/Testing.h"
#include "core/util/enModule.h"

class SomeData : public enModule< SomeData >
{
public:
  SomeData() = default;
  ~SomeData() = default;
public:
  int d = 0; 

  /**
   * @brief initializes the Module
   * @param descriptor This parameter exist for type that requires a descriptor
   * possibly goes unused.
   * @returns boolean value that indicates if everything when correct
   */
  bool
  internalActivateModule(void *descriptor)override
  {
    return true;
  } ;

  int getD()const
  {
    return d;
  }

};

int main()
{
  SomeData::activateModule(nullptr);
  SomeData* dPtr = SomeData::getInstancePtr();
  std::cout << "the value of D " << '\t' << dPtr->getD() << "\n\n";
  SomeData& dRef = SomeData::getInstanceRef();
  std::cout << "the value of D " << '\t' << dPtr->d << "\n\n";

  //const ErrorCode result = startWindowTest();
  //EN_LOG_WITH_ERROR_CODE(result,"");
  SomeData::deactivateModule();
}