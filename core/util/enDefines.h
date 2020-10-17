#pragma once
#include <cstdint>
#include <iostream>
#include "core/math/enMathTypes.h"

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
  needsImplementation = -5,
  wrongImplementation = -6,
};

enum class MeshType : uint32 
{
  triangleMesh, 
  quadMesh,
  lineMesh,
  pointMesh,
};

/**
 * @brief every value represents a key on the keyboard
 */
enum class KeyInput : uint32 
{
  nullInput = 0u,

  leftShift,
  leftAlt,
  leftCtrl,

  rightShift,
  rightAlt,
  rightCtrl,

  shift,
  alt,
  tab,
  tilde,

  upArrow,
  downArrow,
  leftArrow,
  rightArrow,

  enter,
  backSpace,
  escape,
  a = 'a',
  b = 'b',
  c = 'c',
  d = 'd',
  e = 'e',
  f = 'f',
  g = 'g',
  h = 'h',
  i = 'i',
  j = 'j',
  k = 'k',
  l = 'l',
  m = 'm',
  n = 'n',
  o = 'o',
  p = 'p',
  q = 'q',
  r = 'r',
  s = 's',
  t = 't',
  u = 'u',
  v = 'v',
  w = 'w',
  x = 'x',
  y = 'y',
  z = 'z',
  num0 = '0',
  num1 = '1',
  num2 = '2',
  num3 = '3',
  num4 = '4',
  num5 = '5',
  num6 = '6',
  num7 = '7',
  num8 = '8',
  num9 = '9',
  plus = '+',
  minus = '-',
  asterisk = '*',
  forwardSlash = '/',
  backSlash = '\\',
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
      std::cerr << "---> " << "[One of the arguments passed is ill-formed]\n";
      break;

      case ErrorCode::failedCreation:
      std::cerr << "---> " << "[The creation of a object has failed] \n";
      break;

      case ErrorCode::shaderCompileError:
      std::cerr << "---> " << "[The shader has failed to compile] \n";
      break;

      case ErrorCode::unpreparedForOperation:
      std::cerr << "---> " << "[The operation cannot happen because something else must happen first]\n";
      break;

      case ErrorCode::success:
      std::cerr << "---> " << "[No error occurred]\n";
      break;

      case ErrorCode::needsImplementation:
      std::cerr << "---> " << "operation does NOT have a implementation\n";
      break;

      case ErrorCode::wrongImplementation:
      std::cerr << "---> " << "trying to use the wrong implementation\n";
      break;
      default:
      std::cerr << "---> " << "un-handled Error please add the case\n";
      break;
    }
  }

  /**
   * @brief logs and error
   */
  inline static void
  logErrorWithMessage(const ::ErrorCode error,
                      const char* message)
  {
    logErrorCode(error);

    std::cerr << "\n==========================( additional info )============================\n\n"
      << '\t' << message;
    
  }

  inline static void
  logDebugData(const uint32_t line,
               const char* functionName,
               const char* fileName,
               const char* errorDesc)
  {
    std::cerr << "\n================================================================\n"
      << "description of Error {" << errorDesc << "}\n\n"
      << "file of Error : " << fileName << "\n"
      << "function of error : " << functionName << "\n"
      << "line where error was reported [ " << line << "]\n\n";
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

/**
 * Utility Macros
 */
#define SAFE_DELETE(ptr) if(nullptr != ptr){ delete ptr; ptr = nullptr;}
#define SAFE_DELETE_ARRAY(ptrArray) if(nullptr != ptrArray) {delete[] ptrArray; ptrArray= nullptr;}

#define CHAR_TEXT(someText) #someText;
#define WCHAR_TEXT(someText) L#someText;
#define CHAR16_TEXT(someText) u#someText;
#define CHAR32_TEXT(someText) U#someText;

#ifdef __cpp_char8_t
  #define CHAR8_TEXT(someText) u8#someText;

#endif //__cpp_char8_t

#if UNICODE || _UNICODE
  #define TEXT_T(someText) WCHAR_TEXT(someText)
#else
  #define TEXT_T(someText) CHAR_TEXT(someText)
#endif


/**
 * Data Structures
 */


/**
 * @brief Used to know the input layout is formatted.
 */
struct enInputLayoutData 
{
  std::string Name{ "\0" };
  uint32 Index{ 0 };
  uint32 Format{ 0 };
  uint32 Slot{ 0 };
  uint32 Alignment{ 0 };
  uint32 SlotClass{ 0 };
  uint32 InstanceData{ 0 };
};


/**
 * @brief Controls how the view port will work.
 */
struct enViewportData
{
  uint32 width{ 1u };
  uint32 height{ 1u };
  float minDepth{ 0.0f };
  float maxDepth{ 0.0f };
  float topLeftX{ 0.0f };
  float topLeftY{ 0.0f };
};

/**
 * @brief A type that contains all the necessary arguments to initialize a 
 * shader program.
 */
struct enShaderProgramData
{
  /**@brief a file path to a vertex shader*/
  std::string_view filePathToVertexShader;
  /**@brief a string that describes which version of the shader is being used. */
  std::string_view vertexShaderVersion;

  /**@brief a file path to a pixel shader*/
  std::string_view filePathToPixelShader;
  /**@brief a string that describes which version of the shader is being used. */
  std::string_view pixelShaderVersion;

};

/**
 * @brief Controls what the sampler will do.
 */
struct enSamplerData
{
  uint32 filter{ 0 };/*!< how to filter the data */ 
  uint32 addressU{ 0 };/*<! how to address the x axis */
  uint32 addressV{ 0 }; /*<! how to address the y axis */

  uint32 AnisotropicLevel{ 1 };//<! controls the how anisotropic the texture is 

  int32 comparingFunc{ 0 };//<! how to compare 

  float minLod = { 0.0f };//<! lowest level of detail 
  float maxLod = { 0.0f };//<! highest level of detail
};


struct enInputData 
{
  enInputData(const KeyInput _keyPressed,
              const KeyInput _modifier = KeyInput::nullInput,
              bool _holding = false)
    :keyPressed(_keyPressed),
    modifier(_modifier),
    holding(_holding)
  {}
  KeyInput keyPressed;
  KeyInput modifier;
  bool holding;
};

/**
 * Utility TYPE DEFS
 */

/** @brief this type def exist to make it easier to switch out the underlying
 * type which is use in the vertex shaders.
 */
using enVertexType = enMath::enVec4;




