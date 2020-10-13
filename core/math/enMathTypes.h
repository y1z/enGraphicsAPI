#pragma once
#include "glm/matrix.hpp"

#define USING_ENTROPY_MATH 0

#if USING_ENTROPY_MATH == 1

#else 

namespace enMath 
{
  using enVec2 = glm::vec2;  
  using enVec3 = glm::vec3;  
  using enVec4 = glm::vec4;  

  using enMat3x3 = glm::mat3x3;
  using enMat4x4 = glm::mat4x4;
  inline static const enMat4x4 identityMat4x4 = glm::mat4x4(1.0f);
  inline static const enMat3x3 identityMat3x3 = glm::mat3x3(1.0f);

}

#endif // USING_ENTROPY_MATH




