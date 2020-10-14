#include <iostream>
#include <string>
#include <type_traits>

#include "core/util/enDefines.h"
#include "core/util/enTypeTraits.h"

int main()
{
  std::cout << std::boolalpha
    << "signed types "
    << tt::isUnsigned_v<bool> << "\n"
    << tt::isUnsigned_v<char> << '\n'
    << tt::isUnsigned_v<short> << '\n'
    << tt::isUnsigned_v<int> << '\n'
    << tt::isUnsigned_v<long> << "\n\n"
    << tt::isUnsigned_v<long long> << "\n\n"
    << tt::isUnsigned_v<const bool > << "\n"
    << tt::isUnsigned_v<const char > << '\n'
    << tt::isUnsigned_v<const short> << '\n'
    << tt::isUnsigned_v<const int> << '\n'
    << tt::isUnsigned_v<const long long> << "\n\n"
    << tt::isUnsigned_v<volatile bool > << "\n"
    << tt::isUnsigned_v<volatile char > << '\n'
    << tt::isUnsigned_v<volatile short> << '\n'
    << tt::isUnsigned_v<volatile int> << '\n'
    << tt::isUnsigned_v<volatile long long> << "\n\n"
    << tt::isUnsigned_v<const volatile bool > << "\n"
    << tt::isUnsigned_v<const volatile char > << '\n'
    << tt::isUnsigned_v<const volatile short> << '\n'
    << tt::isUnsigned_v<const volatile int> << '\n'
    << tt::isUnsigned_v<const volatile long long> << "\n\n"
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
    << tt::isUnsigned_v<const volatile unsigned long int> << '\n'
    << tt::isUnsigned_v<const volatile unsigned long long> << "\n\n";

  std::cout << std::is_integral_v<char16_t > << "\n "
    <<  std::is_integral_v<char16_t > << "\n "
    <<  std::is_integral_v<wchar_t> << "\n "
    << std::is_integral_v<char8_t> << "\n";

}