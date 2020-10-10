#pragma once
#include "core/util/enDefines.h"
#include <string>

/**
 * @class enTexture2DCore : a int3erface to the texture of the api
 */
class enTexture2DCore 
{
public:
  enTexture2DCore(const enTexture2DCore&) = default;
  enTexture2DCore(enTexture2DCore&&) = default;
  virtual~enTexture2DCore() = default;

public:
  enTexture2DCore& operator =(const enTexture2DCore&) = default;
  enTexture2DCore& operator =(enTexture2DCore&&) = default;
public:
  virtual ErrorCode
  initTexture(std::string_view pathToTexture) = 0;

  virtual ErrorCode
  generateMipMaps() = 0;

  uint32 
  getWidth()const
  {
   return m_width; 
  }

  uint32 
  getHeight()const
  {
   return m_height; 
  }




protected:
  std::string m_source;
  uint32 m_width;
  uint32 m_height;
};

