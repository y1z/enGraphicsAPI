#pragma once
#include "core/util/enDefines.h"
#include "core/include/enVertexShaderCore.h"
#include "core/include/enPixelShaderCore.h"

/**
 * @class enShaderProgramCore : an interface for the shader program
 */
class enShaderProgramCore 
{
public://constructors 

  enShaderProgramCore()
    :m_vertexShader(nullptr),m_pixelShader(nullptr)
  {}

  enShaderProgramCore(const enShaderProgramCore&) = delete;
  enShaderProgramCore(enShaderProgramCore&& other) noexcept
    :m_vertexShader(std::move(other.m_vertexShader)), m_pixelShader(std::move(other.m_pixelShader))
  {
    other.m_vertexShader = nullptr;
    other.m_pixelShader = nullptr;
  } 
  virtual ~enShaderProgramCore() noexcept = default;

public:// operators
  enShaderProgramCore& 
  operator=(const enShaderProgramCore&) = delete;

  enShaderProgramCore& 
  operator=(enShaderProgramCore&& other) noexcept
  {
    m_vertexShader = std::move(other.m_vertexShader);
    m_pixelShader = std::move(other.m_pixelShader);
    return *this;
  }

public:// functions

  /**
  * @brief initializes the shader program
  * @returns 
  */
  virtual ErrorCode
  init(std::unique_ptr<enVertexShaderCore>&& pixelShader,
       std::unique_ptr<enVertexShaderCore>&& vertexShader) = 0;


  enVertexShaderCore*
  getVertexShader()
  {
    return m_vertexShader.get();
  }

  enPixelShaderCore*
  getPixelShader()
  {
    return m_pixelShader.get();  
  }

  virtual bool
  linkShaders() = 0;

  virtual bool
  detachShaders() = 0;

protected:
  std::unique_ptr<enVertexShaderCore> m_vertexShader;
  std::unique_ptr<enPixelShaderCore>  m_pixelShader;

};
