#pragma once
#include "core/include/enShaderCore.h"

/**
 * @class enVertexShaderCore : a interface for vertex shaders.
 */
class enVertexShaderCore :public enShaderCore
{
public:
  enVertexShaderCore(const enVertexShaderCore&) = default;
  enVertexShaderCore(enVertexShaderCore&&) noexcept = default;
  virtual ~enVertexShaderCore() noexcept = default;
public:
  enVertexShaderCore& operator=(const enVertexShaderCore&) = default;

  enVertexShaderCore& operator=(enVertexShaderCore&&) noexcept = default;

  /**
   * @brief takes a file path to later use to compile the shader.
   * @para filePath : where the file is located.
   * @para shaderVersion : where the file is located.
   */
  virtual ErrorCode
  compileShaderFromFile(std::string_view filePath ,
                        std::string_view shaderVersion) = 0 ;

protected:

/**
 * @brief is where the completions happens
 * @para filePath : where the file is located.
 * @para shaderVersion : where the file is located.
 */
  virtual ErrorCode
  compileShader(std::string_view shader,
                std::string_view shaderVersion) = 0;

};

