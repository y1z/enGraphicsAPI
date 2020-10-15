#include "directX_Impl/include/enDeviceContextDX11.h"

enDeviceContextDX11::enDeviceContextDX11()
  :m_dx11DeviceContext(nullptr)
{}

enDeviceContextDX11::~enDeviceContextDX11() noexcept 
{
  SAFE_DX_RELEASE(m_dx11DeviceContext);
}

void enDeviceContextDX11::setTexture(const enTextureCore& texture)
{}

void enDeviceContextDX11::setRenderTarget(const enRenderTargetCore & rt)
{}

void enDeviceContextDX11::setInputLayout(const enInputLayoutCore & inputLayout)
{}

void enDeviceContextDX11::setShaderProgram(const enShaderProgramCore & shaderProgram)
{}

void enDeviceContextDX11::setVertexShader(const enVertexShaderCore & vertexShader)
{}

void enDeviceContextDX11::setPixelShader(const enPixelShaderCore & pixelShader)
{}

void enDeviceContextDX11::setVertexBuffer(const enVertexBufferCore & vertexBuffer)
{}

void enDeviceContextDX11::setIndexBuffer(const unsigned32IndexBuffer & indexBuffer)
{}

void enDeviceContextDX11::setSwapChain(const enSwapChainCore & swapChain)
{}

void enDeviceContextDX11::setSampler(const enSamplerCore & sampler, const enTextureCore & texture)
{}

void enDeviceContextDX11::setMesh(const enMeshCore & mesh)
{}
