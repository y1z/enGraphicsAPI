#pragma once
#include <cassert>
#include <cstdint>
#include <iostream>

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
 * @brief : an enum used to represent the errors that can occur.
 */
enum class ErrorCode : int32

{
  success = 1,/*!< means no error has occurred */
  failedCreation = -1, /*!< means that the creation of a resource has failed */
  shaderCompileError = -2, /*!< means that a shader has failed to compile*/
  badArgument = -3, /*!< means that one of the arguments passed to a function is ill-formed */
  unpreparedForOperation = -4, /*!< means that the function requires something else to happen before it works*/
};


/**
 * functions for the management of error codes
 */
namespace error_handle 
{
  constexpr void 
  logErrorCode(const ::ErrorCode error)
  {
    switch( error )
    {
      case ErrorCode::badArgument:
      std::cerr << "one of the arguments passed is ill-formed\n";
      break;

      case ErrorCode::failedCreation:
      std::cerr << "the creation of a object has failed \n";
      break;

      case ErrorCode::shaderCompileError:
      std::cerr << "the shader has failed to compile \n";
      break;

      case ErrorCode::unpreparedForOperation:
      std::cerr << "the operation cannot happen because something else must happen first\n";
      break;

      case ErrorCode::success:
      std::cerr << "no error occurred\n";
      break;

      default:
      std::cerr << "un-handled Error please add the case\n";
      break;
    }
  }

  /**
   * @brief logs and error
   */
  static void
  logErrorWithMessage(const ::ErrorCode error,
                      const char* message)
  {
    logErrorCode(error);

    std::cerr << "\n==========================( message )============================\n"
      << message << "\n==========================(         )============================\n";
    
  }

  static void
  logDebugData(const uint32_t line,
               const char* functionName,
               const char* fileName,
               const char* errorDesc)
  {
    std::clog << "\n================================================================\n"
      << "description of Error {" << errorDesc << "}\n\n"
      << "file of Error : " << fileName << "\n"
      << "function of error : " << functionName << "\n"
      << "line where error was reported [ " << line << "\n\n";
  }

  /** Used to know if a function has committed and error.
    * @returns false when NO error has occurred, true when and error has occurred.
   */
  constexpr bool
  hasError(const ErrorCode error)
  {
    return error != ErrorCode::success;
  }

}


/**
 * Debug Macros
 */
#if !NDEBUG
  #define EN_LOG_WITH_ERROR_CODE(errorCode, message) error_handle::logErrorWithMessage(errorCode ,#message);
  #define EN_LOG_DEBUG_INFO(errorDesc) error_handle::logDebugData(__LINE__ ,__func__ ,__FILE__ ,#errorDesc);
#else
  #define EN_LOG_WITH_ERROR_CODE(errorCode, message)
  #define EN_LOG_DEBUG_INFO(errorDesc)
#endif



struct enInputLayoutData 
{
  std::string Name{ "" };
  uint32 Index{ 0 };
  uint32 Format{ 0 };
  uint32 Slot{ 0 };
  uint32 Alignment{ 0 };
  uint32 SlotClass{ 0 };
  uint32 InstanceData{ 0 };
};


struct sViewportData
{
  uint32 width{ 1u };
  uint32 height{ 1u };
  float minDepth{ 0.0f };
  float maxDepth{ 0.0f };
  float TopLeftX{ 0.0f };
  float TopLeftY{ 0.0f };
};




