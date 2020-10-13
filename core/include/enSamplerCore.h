#pragma once
#include "core/util/enDefines.h"

class enTextureCore;



class enSamplerCore 
{
public:
  enSamplerCore() = default;
  enSamplerCore(const enSamplerCore&) = default;
  enSamplerCore(enSamplerCore&&) noexcept = default;

  virtual ~enSamplerCore() = default;
public:
  enSamplerCore& operator=(const enSamplerCore&) = default;
  enSamplerCore& operator=(enSamplerCore&&) noexcept = default;

public:
  /**
   * @brief initializes the Sampler.
   * @param data : determines what the sampler will do.
   */
  virtual ErrorCode
  init(const enSamplerData& data) = 0;

  /**
   * @brief attaches a texture to the sampler.
   * @param texture : the texture to be attached to.
   */
  virtual ErrorCode
  attachToTexture(enTextureCore* texture) = 0;

  
};
