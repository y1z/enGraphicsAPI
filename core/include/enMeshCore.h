#pragma once
#include "core/include/enVertexBufferCore.h"
#include <memory>

class enMeshCore {
public:
  enMeshCore() = default;
  enMeshCore(const enMeshCore&) = delete;
  enMeshCore(enMeshCore&&) noexcept = default;
  virtual ~enMeshCore() = default;
public:


public:
  enMeshCore& operator=(const enMeshCore&) = delete;
  enMeshCore& operator=(enMeshCore&&) noexcept = default;
public:
  std::unique_ptr<enVertexBufferCore> m_meshData; 
};
