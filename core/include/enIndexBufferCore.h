#pragma once
#include <cstddef>
#include <vector>

/** @class enIndexBufferCore : Interface for a index buffer*/
template<class IndexType>
class enIndexBufferCore 
{
public://constructors and destructor
  enIndexBufferCore(const enIndexBufferCore&) = default;
  enIndexBufferCore(enIndexBufferCore&&) noexcept = default;

  virtual ~enIndexBufferCore() noexcept = default;
public: // operators
  enIndexBufferCore&
  operator=(const enIndexBufferCore&) = default;

  enIndexBufferCore&
  operator=(enIndexBufferCore&&)noexcept = default;

public:

  /** @brief container for the indexes of the index buffer*/
  std::vector<IndexType> m_indexes;
};

using unsigned16IndexBuffer = enIndexBufferCore<uint16_t>;
using unsigned32IndexBuffer = enIndexBufferCore<uint32_t>;
