#pragma once
#include "core/util/enDefines.h"
#include <string_view>

class enTextureCore;
class enRenderTargetCore;
class enInputLayoutCore;
class enVertexShaderCore;

/**
 * @brief : create all the interfaces
 */
class enDeviceCore 
{
public:

  virtual enTextureCore*
  createTexture(std::string_view filePath) = 0;

  virtual enRenderTargetCore*
  createRenderTarget(const uint32 width, const uint32 height) = 0;

  virtual enInputLayoutCore*
  createInputLayout(const enInputLayoutData& data) = 0;

  virtual enVertexShaderCore*
  createVertexShader() = 0;
  
  
};
