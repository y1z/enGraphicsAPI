#include <cassert>
#include "core/include/enSceneCore.h"

// TODO : implement Scene Init function
ErrorCode 
enSceneCore::init(const std::vector<std::string_view>& filePaths)
{
  return ErrorCode::unpreparedForOperation;
}

void 
enSceneCore::drawScene()
{
  for(auto& model : m_models )
  {
    model.drawMeshes(); 
  }
}

enModelCore&
enSceneCore::getModel(const size_t index) 
{
  assert( (!m_models.empty() && m_models.size() > index ), "accessing empty vector or invalid index");
  return m_models[index];
}

size_t 
enSceneCore::getModelCount() const
{
  return  m_models.size() ;
}

enSceneCore::modelContainer::iterator
enSceneCore::begin()
{
  return m_models.begin();
}

enSceneCore::modelContainer::iterator
enSceneCore::end()
{
  return m_models.end();
}

enSceneCore::modelContainer::const_iterator
enSceneCore::cbegin() const
{
  return m_models.cbegin();
}

enSceneCore::modelContainer::const_iterator
enSceneCore::cend() const
{
  return m_models.cend();
}
