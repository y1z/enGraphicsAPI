#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>

/**
* @brief converts a wstring/const wchar_t* to it's string equivalent assuming it has any.
*/
static std::string
convertWStringToString(std::wstring_view wideString)
{
  std::string result(wideString.length() + 1, '\0');

  size_t index = wideString.length() - 1;

  for( const auto& element : wideString )
  {
    int status;
    wctomb_s(&status, &result[index], sizeof(char), element);
    --index;
    assert(status != -1 && "conversion is not possible give the current local");
  }

  return result;
}

/**
* @brief converts a string/const char* to it's wstring equivalent
*/
static std::wstring
convertStringToWString(std::string_view String)
{
  std::wstring Result(String.length() + 1, L'\0');

  size_t numCharConverted = 0;
  wchar_t* ptrToBuffer = &Result[0];
  const errno_t checkForError = mbstowcs_s(&numCharConverted,
                                           ptrToBuffer,
                                           String.length(),
                                           String.data(),
                                           String.length());

  assert(checkForError == 0 && "invalid string conversion ");

  return Result;
}


/**
 * @brief load the contents of a file on to a std::string.
*/
static std::string
loadFileToString(std::string_view filePath)
{
  std::string Result{ "Error" };
  std::ifstream File(filePath.data());

  if( File.is_open() )
  {
    std::stringstream SStream;
    SStream << File.rdbuf();
    Result = SStream.str();
    File.close();
    return Result;
  }
  else
  {
    std::cerr << "Error with path {" << filePath << "}\n";
  }
  return Result;
}

/**
 * @brief load the contents of a file on to a std::wstring.
*/
static std::string
loadFileToString(std::wstring_view filePath)
{
  std::string Result{ "Error" };
  std::wifstream File(filePath.data());
  if( File.is_open() )
  {
    std::stringstream SStream;
    SStream << File.rdbuf();
    Result = SStream.str();

    File.close();
    return Result;
  }
  else
  {
    std::wcerr << "error with path { " << filePath << " }\n";
  }
  return Result;
}

