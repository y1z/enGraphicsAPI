#include "core/include/enPixelShaderCore.h"
#include <cassert>

ErrorCode 
enPixelShaderCore::compileShaderFromFile(std::string_view filePath,
                                         std::string_view shaderVersion)
{
  compileShader(filePath, shaderVersion);
  return ErrorCode::shaderCompileError;
}

ErrorCode 
enPixelShaderCore::compileShader(std::string_view shader,
                                 std::string_view shaderVersion)
{
  assert(false && "inherit from this class to implement");
  return ErrorCode::shaderCompileError;
}
