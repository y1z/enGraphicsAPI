#pragma once
class enTextureCore;
class enRenderTargetCore;
class enInputLayoutCore;
class enVertexShaderCore;

class enDeviceContextCore {
public:

  virtual void
  setTexture(const enTextureCore& texture) = 0;

  virtual void
  setRenderTarget(const enRenderTargetCore& rt) = 0;


  virtual void
  setInputLayout(const enInputLayoutCore& inputLayout) = 0;

  virtual void
  enVertexShader(const enVertexShaderCore& texture) = 0;
  
};
