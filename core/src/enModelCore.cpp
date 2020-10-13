#include "core/include/enModelCore.h"

// TODO : implement model init function.
ErrorCode 
enModelCore::init(std::string_view filePath)
{
  


  return ErrorCode();
}

void 
enModelCore::drawMeshes()
{
  for( auto& mesh : m_meshes )
  {
    mesh->draw();
  }
}

enMeshCore* 
enModelCore::getMesh(const size_t index)
{
  if( m_meshes.empty() || m_meshes.size() > index )
  {
    return nullptr;
  }
  return m_meshes[index].get();
}

size_t 
enModelCore::getMeshCount() const
{
  return m_meshes.size();
}

enModelCore::meshContainer::iterator 
enModelCore::begin()
{
  return m_meshes.begin();
}

enModelCore::meshContainer::iterator
enModelCore::end()
{
  return m_meshes.end();
}

enModelCore::meshContainer::const_iterator
enModelCore::cbegin() const
{
  return m_meshes.cbegin();
}

enModelCore::meshContainer::const_iterator
enModelCore::cend() const
{
  return m_meshes.cend();
}
