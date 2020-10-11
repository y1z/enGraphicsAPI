#pragma once
#include "core/include/enShaderRequirements.h"

/**
 * @class enVertexShaderCore : a interface for vertex shader's.
 */
class enVertexShaderCore : public enShaderRequirementsCore
{
public:
  enVertexShaderCore(const enVertexShaderCore&) = default;
  enVertexShaderCore(enVertexShaderCore&&) noexcept = default;
  virtual ~enVertexShaderCore() noexcept = default;
public:
  enVertexShaderCore& operator=(const enVertexShaderCore&) = default;

  enVertexShaderCore& operator=(enVertexShaderCore&&) noexcept = default;

};

