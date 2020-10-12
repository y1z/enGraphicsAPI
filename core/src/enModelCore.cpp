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
