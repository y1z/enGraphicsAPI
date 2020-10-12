#pragma once
#include <string_view>

#include "core/util/enDefines.h"


/**
 * @class enShaderRequirementsCore : imposes the requirements that every type of shader 
 * must have.
 */
class enShaderRequirementsCore 
{
public://constructor
  enShaderRequirementsCore() = default;
  enShaderRequirementsCore(const enShaderRequirementsCore&) = default;
  enShaderRequirementsCore(enShaderRequirementsCore&&) noexcept = default;
  virtual ~enShaderRequirementsCore() noexcept = default;
public:// operators
  enShaderRequirementsCore& operator=(const enShaderRequirementsCore&) = default;
  enShaderRequirementsCore& operator=(enShaderRequirementsCore&&) noexcept = default;

  /**
   * @brief initializes a shader
   * @param shaderFilePath : A path to the file that contains the shader.
   * @param shaderVersion : A .
   */
  virtual ErrorCode 
  init(std::string_view shaderFilePath,
       std::string_view shaderVersion) = 0;

protected:
  /**
   * @brief where the shader gets complied
   */
  virtual ErrorCode
  compileShader() = 0;

};
