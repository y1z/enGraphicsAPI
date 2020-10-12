#pragma once
#include <cstddef>

/**
 * @class enVertexBufferCore : represents a interface for the vertex buffer.
 */
class enVertexBufferCore 
{
public: //constructors

  enVertexBufferCore(const enVertexBufferCore&) = default;

  enVertexBufferCore(enVertexBufferCore&&) noexcept = default;

  virtual 
  ~enVertexBufferCore() = default;

public: //operator
  enVertexBufferCore& 
  operator=(const enVertexBufferCore&) = default;

  enVertexBufferCore& 
  operator=(enVertexBufferCore&&) noexcept = default;

public:

  /** @returns the size of a individual element*/
  [[nodiscard]] virtual size_t
  getSizeOfVertex()const = 0;

  /** @returns how many elements does the vector have */
  [[nodiscard]] virtual size_t
  getCountOfVertex()const = 0;

  /** @returns a pointer to the START of the container*/
  [[nodiscard]] virtual void *
  getStartOfVertexContainer()const =0;

  /** @returns a pointer to the END of the container*/
  [[nodiscard]] virtual void*
  getEndOfVertexContainer()const =0;

};



