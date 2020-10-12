#pragma once
#include <vector>
#include <string_view>

#include "core/include/enMeshCore.h"

/**
 * @class enModelCore : is a class that takes care of all meshes of a individual model.
 */
class enModelCore 
{
public:
  using meshContainer = std::vector<std::unique_ptr<enMeshCore>>;
public:
  enModelCore() = default;
  enModelCore(const enModelCore &) = delete;
  enModelCore(enModelCore &&)noexcept = default;
  ~enModelCore() noexcept = default;
public:
  enModelCore& operator=(const enModelCore &) = delete;
  enModelCore& operator=(enModelCore &&)noexcept = default;
public:

  /**
   * @brief : path to the file of the model.
   */
  [[nodiscard]] ErrorCode
  init(std::string_view filePath);

  /**
   * @brief : path to the file of the model.
   */
  void
  drawMeshes();

  [[nodiscard]] enMeshCore*

protected:
  meshContainer m_meshes;
};
