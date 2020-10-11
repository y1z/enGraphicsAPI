#pragma once
/**
 * FORWARD DECORATIONS
 */
class enVertexShaderCore;
class enPixelShaderCore;

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
    :m_vertexShader(other.m_vertexShader), m_pixelShader(other.m_pixelShader)
  {
    other.m_vertexShader = nullptr;
    other.m_pixelShader = nullptr;
  } 
  virtual ~enShaderProgramCore() = default;

public:// operators
  enShaderProgramCore& 
  operator=(const enShaderProgramCore&) = delete;

  enShaderProgramCore& 
  operator=(enShaderProgramCore&& other) noexcept
  {
    m_vertexShader = other.m_vertexShader;
    m_pixelShader = other.m_pixelShader;
    
    other.m_vertexShader = nullptr;
    other.m_pixelShader = nullptr;
    return *this;
  }

public:// functions

  void
  setPixelShader(enPixelShaderCore& newPixelShader)
  {
    m_pixelShader = &newPixelShader;
  }

  void
  setVertexShader(enVertexShaderCore& newVertexShader)
  {
    m_vertexShader = &newVertexShader; 
  }

  enVertexShaderCore*
  getVertexShader()
  {
    return m_vertexShader;  
  }

  enPixelShaderCore*
  getPixelShader()
  {
    return m_pixelShader;  
  }

  virtual bool
  linkShaders() = 0;

  virtual bool
  detachShaders() = 0;

protected:
  enVertexShaderCore* m_vertexShader;
  enPixelShaderCore* m_pixelShader;

};
