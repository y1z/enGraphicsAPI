#include <iostream>
#include "core/util/enDefines.h"
#include "core/util/enTypeTraits.h"
#include <type_traits>


int main()
{
  std::cout << std::boolalpha
    //<< tt::isTrue< (1 > 2) > << '\n'
    //<< tt::isTrue< (1 < 2) > << '\n'
    << "signed types "
    << tt::isUnsigned_v<const int> << '\n'
    << tt::isUnsigned_v<const char > << '\n'
    << tt::isUnsigned_v<const short> << '\n'
    << tt::isUnsigned_v<const bool > << "\n\n\n"
    << tt::isUnsigned_v<const long long> << "\n"
    << "unsigned types \n"
    << tt::isUnsigned_v<unsigned char> << '\n'
    << tt::isUnsigned_v<unsigned short> << '\n'
    << tt::isUnsigned_v<unsigned int> << '\n'
    << tt::isUnsigned_v<unsigned long> << "\n"
    << tt::isUnsigned_v<unsigned long long> << "\n\n"
    << tt::isUnsigned_v<const unsigned char><< '\n'
    << tt::isUnsigned_v<const unsigned short> << '\n'
    << tt::isUnsigned_v<const unsigned int> << '\n'
    << tt::isUnsigned_v<const unsigned long> << "\n"
    << tt::isUnsigned_v<const unsigned long long> << "\n\n"
    << tt::isUnsigned_v<volatile unsigned char> << '\n'
    << tt::isUnsigned_v<volatile unsigned short> << '\n'
    << tt::isUnsigned_v<volatile unsigned int> << '\n'
    << tt::isUnsigned_v<volatile unsigned long long> << "\n\n"
    << tt::isUnsigned_v<const volatile unsigned char> << '\n'
    << tt::isUnsigned_v<const volatile unsigned short> << '\n'
    << tt::isUnsigned_v<const volatile unsigned int> << '\n'
    << tt::isUnsigned_v<const volatile unsigned long long> << "\n\n";

  std::cout << std::boolalpha<< std::is_same_v<tt::RemoveCV_t<const int>, tt::RemoveCV_t<volatile int>>;
  //std::is_signed_v<>
  //std::remove_volatile_t<>

}