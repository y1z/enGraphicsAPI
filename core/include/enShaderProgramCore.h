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
  * @returns ErrorCode::success when the operation succeeds if the operation
  * did not succeed it returns something else.
  */
  virtual ErrorCode
  init(std::unique_ptr<enVertexShaderCore>&& pixelShader,
       std::unique_ptr<enVertexShaderCore>&& vertexShader) = 0;

  /**
  * @brief initializes the shader program
  * @returns ErrorCode::success when the operation succeeds if the operation
  * did not succeed it returns something else.
  */
  virtual ErrorCode
  init(const enShaderProgramCore& data) = 0;



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


  [[nodiscard]] enVertexShaderCore*
  getVertexShader() const
  {
    return m_vertexShader.get();
  }

  [[nodiscard]] enPixelShaderCore*
  getPixelShader() const
  {
    return m_pixelShader.get();  
  }

  /**
   * @brief makes the shader's know of each-others existence.
   */
  virtual bool
  linkShaders() = 0;

  /**
   * @brief makes the shader .
   */
  virtual bool
  detachShaders() = 0;

protected:
  std::unique_ptr<enVertexShaderCore> m_vertexShader;
  std::unique_ptr<enPixelShaderCore>  m_pixelShader;

};
