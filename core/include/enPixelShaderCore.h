#pragma once
#include "enShaderCore.h"


class enPixelShaderCore : public enShaderCore 
{
public:
  enPixelShaderCore(const enPixelShaderCore&) = default;
  enPixelShaderCore(enPixelShaderCore&&) noexcept = default;
  virtual ~enPixelShaderCore() noexcept = default;
public:
  enPixelShaderCore& operator=(const enPixelShaderCore&) = default;
  enPixelShaderCore& operator=(enPixelShaderCore&&) noexcept = default;

public:
  /**
   * @brief takes a file path to later use to compile the shader.
   * @para filePath : where the file is located.
   * @para shaderVersion : where the file is located.
   */
  virtual ErrorCode
  compileShaderFromFile(std::string_view filePath ,
                        std::string_view shaderVersion) override ;

protected:

/**
 * @brief is where the completions happens
 * @para filePath : where the file is located.
 * @para shaderVersion : where the file is located.
 */
  virtual ErrorCode
  compileShader(std::string_view shader,
                std::string_view shaderVersion) override ;

};

