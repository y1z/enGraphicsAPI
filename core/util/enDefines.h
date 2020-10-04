#pragma once
#include <cstdint>

/**
 * Integer TYPE DEFS
 */

using int8 = std::int8_t;  /*!< a signed integer of 8-bits*/
using int16 = std::int16_t;/*!< a signed integer of 16-bits*/
using int32 = std::int32_t;/*!< a signed integer of 32-bits*/
using int64 = std::int64_t;/*!< a signed integer of 64-bits*/

using uint8 = std::uint8_t;  /*!< a unsigned integer of 8-bits*/
using uint16 = std::uint16_t;/*!< a unsigned integer of 16-bits*/
using uint32 = std::uint32_t;/*!< a unsigned integer of 32-bits*/
using uint64 = std::uint64_t;/*!< a unsigned integer of 64-bits*/

/**
 * @brief : an enum used to represent the errors that 
 */
enum class ErrorCode : int32

{
  success = 1,/*!< means no error has occurred */
  failedCreation = -1, /*!< means that the creation of a resource has failed */
  shaderCompileError = -2, /*!< means that a shader has failed to compile*/
  badArgument = -3, /*!< means that one of the arguments passed to a function is ill-formed */
};






