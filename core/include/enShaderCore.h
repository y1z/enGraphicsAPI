#pragma once
#include "core/util/enDefines.h"
#include <string>

  /**
 * @class enShaderCore : The interface for all shader types.
 */
class enShaderCore 
{
public:// constructors

  enShaderCore(const enShaderCore&) = default;
  enShaderCore(enShaderCore&&) noexcept = default;

  enShaderCore& operator= (const enShaderCore&) = default;
  enShaderCore& operator= (enShaderCore&&) noexcept = default;

  virtual
  ~enShaderCore() = default;

  /**
   * @brief takes a file path to later use to compile the shader.
   * @para filePath : where the file is located.
   * @para shaderVersion : where the file is located.
   */
  virtual ErrorCode
  compileShaderFromFile(std::string_view filePath ,
                        std::string_view shaderVersion) = 0;

protected:

/**
 * @brief is where the completions happens
 * @para filePath : where the file is located.
 * @para shaderVersion : where the file is located.
 */
  virtual ErrorCode
  compileShader(std::string_view filePath,
                std::string_view shaderVersion) = 0;

public:
  /** The variable that contains the shader*/
  std::string m_shader;
  /** The variable that contains which version of the shader we use.*/
  std::string m_shaderVersion;
};

