#pragma once

namespace tt 
{
  template <class Type>
  struct Identity
  {
    using type = Type;
  };

  /** 
   * @brief Choses a type Depending on the result of the condition
   */
  template<class firstType, class secondType, bool conditional = true>
  struct ConditionalType
  {
    using type = firstType;
  };

  template<class firstType, class secondType>
  struct ConditionalType< firstType, secondType, false>
  {
    using type = secondType;
  };

  template <class firstType, class secondType, bool condition>
  using ConditionalType_t = typename ConditionalType<firstType, secondType, condition>::type;

  template <class Type, Type firstValue, Type secondValue , bool condition = true>
  struct ConditionalValue {
    static inline Type value = firstValue;  
  };

  template <class Type, Type firstValue, Type secondValue> 
  struct ConditionalValue<Type, firstValue, secondValue, false>
  {
    static inline Type value = secondValue;  
  };

  template<bool condition>
  struct ConditionalValueBool {
    static inline bool value = ConditionalValue<bool,true,false,condition>::value;
  };

  template<bool condition>
  constexpr bool isTrue = false;

  template<>
  constexpr bool isTrue<true> = true;

  template<class Type, class otherType>
  constexpr bool isSame = false;

  template<class Type>
  constexpr bool isSame<Type, Type> = true;


  template<class Type>
  constexpr bool isFloatType = false;

  template<>
  constexpr bool isFloatType<float> = true;

  template<>
  constexpr bool isFloatType<double> = true;

  template<>
  constexpr bool isFloatType<long double> = true;


  template<class Type>
  constexpr bool isIntegerType = false;

  template<class Type>
  constexpr bool isIntegerType<volatile Type> = isIntegerType<Type>;

  template<class Type>
  constexpr bool isIntegerType<const Type> = isIntegerType<Type>;

  template<class Type>
  constexpr bool isIntegerType<const volatile Type> = isIntegerType<Type>;

  template<>
  constexpr bool isIntegerType<short> = true;

  template<>
  constexpr bool isIntegerType<int> = true;

  template<>
  constexpr bool isIntegerType<long> = true;

  template<>
  constexpr bool isIntegerType<long long> = true;


  /**
   * @brief : A helper template used to distinguish which type is a primitive
   */
  template<class Type>
  constexpr bool isPrimitiveType = false;

  template<class Type>
  constexpr bool isPrimitiveType<volatile Type> = isPrimitiveType<Type>;

  template<class Type>
  constexpr bool isPrimitiveType<const Type> = isPrimitiveType<Type>;

  template<class Type>
  constexpr bool isPrimitiveType<const volatile Type> = isPrimitiveType<Type>;

  template<>
  constexpr bool isPrimitiveType<char> = true;

  template<>
  constexpr bool isPrimitiveType<char8_t> = true;

  template<>
  constexpr bool isPrimitiveType<char16_t> = true;

  template<>
  constexpr bool isPrimitiveType<char32_t> = true;

  template<>
  constexpr bool isPrimitiveType<wchar_t> = true;

  template<>
  constexpr bool isPrimitiveType<short> = true;

  template<>
  constexpr bool isPrimitiveType<int> = true;

  template<>
  constexpr bool isPrimitiveType<long> = true;

  template<>
  constexpr bool isPrimitiveType<long long> = true;

  template<>
  constexpr bool isPrimitiveType<float> = true;

  template<>
  constexpr bool isPrimitiveType<double> = true;

  template<>
  constexpr bool isPrimitiveType<long double> = true;

  template<class typeWithoutVolatile>
  struct RemoveVolatile
  {
    using type = typeWithoutVolatile;
  };

  template<class typeWithVolatile>
  struct RemoveVolatile<volatile typeWithVolatile>
  {
    using type = typeWithVolatile;
  };

  template<class typeWithVolatile>
  using RemoveVolatile_t = typename RemoveVolatile<typeWithVolatile>::type;


  template<class typeWithoutConst>
  struct RemoveConst
  {
    using type = typeWithoutConst;
  };

  template<class typeWithConst>
  struct RemoveConst<const typeWithConst>
  {
    using type = typeWithConst;
  };

  template<class typeWithConst>
  using RemoveConst_t = typename RemoveConst<typeWithConst>::type;


  template <class removeVolatileAndConst>
  struct RemoveCV
  {
    using type = RemoveVolatile_t<RemoveConst_t<removeVolatileAndConst>>;
  };

  template<class removeVolatileAndConst>
  using RemoveCV_t = typename RemoveCV<removeVolatileAndConst>::type;

  template<class typeWithVolatile>
  constexpr bool isVolatile = false;

  template<class typeWithVolatile>
  constexpr bool isVolatile<volatile typeWithVolatile> = true;

  template<class typeWithConst>
  constexpr bool isConst = false;

  template<class typeWithConst>
  constexpr bool isConst<const typeWithConst> = true;

  template<class typeWithConstOrVolatile>
  constexpr bool isConstOrVolatile = isConst<typeWithConstOrVolatile> || isVolatile<typeWithConstOrVolatile>;

  template<class Type>
  struct isUnsigned
  {
    constexpr static bool value = false;
  };

  template<class Type>
  struct isUnsigned<volatile Type>
  {
    constexpr static bool value = isUnsigned<Type>::value;
  };

  template<class Type>
  struct isUnsigned<const Type>
  {
    static constexpr bool value = isUnsigned<Type>::value;
  };

  template<class Type>
  struct isUnsigned<const volatile Type>
  {
    static constexpr bool value = isUnsigned<Type>::value;
  };

  template<>
  struct isUnsigned<unsigned char>
  {
    static constexpr bool value = true;
  };

  template<>
  struct isUnsigned<unsigned short>
  {
    static constexpr bool value = true;
  };

  template<>
  struct isUnsigned <unsigned int>
  {
    static constexpr bool value = true;
  };

  template<>
  struct isUnsigned<unsigned long>
  {
    static constexpr bool value = true;
  };


  template<>
  struct isUnsigned<unsigned long long>
  {
    static constexpr bool value = true;
  };

  template<class unsignedType>
  struct makeUnsigned {
    using type = unsignedType;
  };

  template<>
  struct makeUnsigned<char> {
    using type = unsigned char;
  };

  template<>
  struct makeUnsigned<short> {
    using type = unsigned short;
  };

  template<>
  struct makeUnsigned<int> {
    using type = unsigned int;
  };

  template<>
  struct makeUnsigned<long> {
    using type = unsigned long;
  };

  template<>
  struct makeUnsigned<long long> {
    using type = unsigned long long;
  };

  template<class Type>
  constexpr bool isUnsigned_v = isUnsigned<Type>::value;

  template <class SignedType>
  constexpr bool isSigned = isPrimitiveType<SignedType> && !(isUnsigned<SignedType>::value);

}
