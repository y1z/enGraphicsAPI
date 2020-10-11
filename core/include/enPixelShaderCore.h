#pragma once
#include "core/include/enShaderRequirements.h"


class enPixelShaderCore : public enShaderRequirementsCore 
{
public:
  enPixelShaderCore(const enPixelShaderCore&) = default;
  enPixelShaderCore(enPixelShaderCore&&) noexcept = default;
  virtual ~enPixelShaderCore() noexcept = default;
public:
  enPixelShaderCore& operator=(const enPixelShaderCore&) = default;
  enPixelShaderCore& operator=(enPixelShaderCore&&) noexcept = default;

};

