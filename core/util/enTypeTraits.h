#pragma once

namespace tt 
{
  template<bool condition>
  constexpr bool isTrue = false;

  template<>
  constexpr bool isTrue<true> = true;


  template<class Type, class otherType>
  constexpr bool isSame = false;

  template<class Type>
  constexpr bool isSame<Type, Type> = true;

  template <class Type>
  struct Identity
  {
    using type = Type;
  };

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
  using ConditionalType_t = ConditionalType<firstType, secondType, condition>;

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

  template<class Type>
  constexpr bool isUnsigned_v = isUnsigned<Type>::value;

  template <class SignedType>
  constexpr bool isSigned = !(isUnsigned<SignedType>::value);

}
