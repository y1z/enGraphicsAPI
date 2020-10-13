#pragma once
#include <memory>

#include "core/include/enVertexBufferCore.h"
#include "core/include/enIndexBufferCore.h"

#include "core/include/enDrawRequirements.h"


/**
 * @brief Is the interface for using individual meshes.
 */
class enMeshCore : public enDrawRequirements 
{
public:
  enMeshCore()
    :m_transform(enMath::identityMat4x4){}
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
   * @brief represents the transform of the current mesh.
   */
  enMath::enMat4x4 m_transform; 

  /**
   * @brief contains all vertex data of the mesh.
   */
  std::unique_ptr<enVertexBufferCore> m_vertexData; 

  /**
   * @brief contains all the index buffer data of the mesh.
   */
  std::unique_ptr<unsigned32IndexBuffer> m_indexData;
};


