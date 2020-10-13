#pragma once
#include "core/util/enDefines.h"
#include <cstddef>

/**
 * @class enVertexBufferCore : represents a interface for the vertex buffer.
 */
class enVertexBufferCore 
{
public: 
  /** @brief this type def exist so it becomes easier to switch out
   * the underlying container.
   */
  using vertexContainer = std::vector<enVertexType>;
public: //constructors

  enVertexBufferCore(const enVertexBufferCore&) = default;

  enVertexBufferCore(enVertexBufferCore&&) noexcept = default;

  virtual ~enVertexBufferCore() = default;

public: //operator
  enVertexBufferCore& 
  operator=(const enVertexBufferCore&) = default;

  enVertexBufferCore& 
  operator=(enVertexBufferCore&&) noexcept = default;

public:

  /**
   * @brief initializes the vertex buffer.
   */
  virtual ErrorCode 
  init(const std::vector<enVertexType>& vertexContainer ) = 0;


  /** @returns a pointer to the START of the container*/
  [[nodiscard]] vertexContainer::iterator
  begin()
  {
    return m_vertexes.begin(); 
  }

  /** @returns a iterator to the end of the container*/
  [[nodiscard]] vertexContainer::iterator
  end()
  {
    return m_vertexes.end();
  }

  /** @returns a iterator to the start of a container*/
  [[nodiscard]] vertexContainer::const_iterator
  cbegin() const
  {
    return m_vertexes.begin(); 
  }

  /** @returns a iterator to the end of the container*/
  [[nodiscard]] vertexContainer::const_iterator
  cend() const
  {
    return m_vertexes.end();
  }

  vertexContainer m_vertexes;
};



