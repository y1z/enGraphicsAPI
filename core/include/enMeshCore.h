#pragma once
#include <memory>

#include "core/include/enVertexBufferCore.h"
#include "core/include/enDrawRequirements.h"


/**
 * @brief is the interface for using individual meshes.
 */
class enMeshCore : public enDrawRequirements 
{
public:
  enMeshCore() = default;
  enMeshCore(const enMeshCore&) = delete;
  enMeshCore(enMeshCore&&) noexcept = default;
  virtual ~enMeshCore() = default;
public:
  enMeshCore& operator=(const enMeshCore&) = delete;
  enMeshCore& operator=(enMeshCore&&) noexcept = default;
public:

  

public:
  std::unique_ptr<enVertexBufferCore> m_meshData; 
};
