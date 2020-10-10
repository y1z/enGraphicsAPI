#pragma once
#include <cstddef>
#include <vector>
#include "enTypeTraits.h"

/** @class enIndexBufferCore : Interface for a index buffer*/
template<class IndexType>
class enIndexBufferCore 
{
public://constructors and destructor
  enIndexBufferCore(const enIndexBufferCore&) = default;
  enIndexBufferCore(enIndexBufferCore&&) noexcept = default;

  virtual  
  ~enIndexBufferCore() noexcept = default;
public: // operators
  enIndexBufferCore&
  operator=(const enIndexBufferCore&) = default;

  enIndexBufferCore&
  operator=(enIndexBufferCore&&)noexcept = default;

public:

  [[nodiscard]] virtual size_t
  getIndexCount() = 0;
  
  [[nodiscard]] virtual size_t
  getIndexSize() = 0;


  std::vector<IndexType> m_indexes;

};
