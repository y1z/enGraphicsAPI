#pragma once
#include <memory>

#include "core/include/enVertexBufferCore.h"
#include "core/include/enIndexBufferCore.h"

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
  virtual ~enMeshCore() noexcept = default;
public:
  enMeshCore& operator=(const enMeshCore&) = delete;
  enMeshCore& operator=(enMeshCore&&) noexcept = default;
public:

  /**
   * @brief : initializes the mesh.
   */
  virtual ErrorCode
  init(std::unique_ptr<enVertexBufferCore> && vertexBuffer,
       std::unique_ptr<unsigned32IndexBuffer> && indexBuffer) = 0;

  

public:
  /**
   * @brief contains all vertex data of the mesh.
   */
  std::unique_ptr<enVertexBufferCore> m_vertexData; 

  /**
   * @brief contains all the index buffer data of the mesh.
   */
  std::unique_ptr<unsigned32IndexBuffer> m_indexData;
};
