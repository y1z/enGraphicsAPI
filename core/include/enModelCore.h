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
   * @brief : creates a model from a file to a 3D model.
   * @param filePath : The path to the file where the model is.
   */
  [[nodiscard]] ErrorCode
  init(std::string_view filePath);

  /** @brief : draws all the meshes of the model. */
  void
  drawMeshes();

  /**
   * @returns : a pointer to a individual mesh or nullptr.
   * @param index : let u select a individual mesh
   */
  [[nodiscard]] enMeshCore*
  getMesh(const size_t index);

  /** @returns : the amount of meshes the model contains. */
  [[nodiscard]] size_t
  getMeshCount()const;

  /** @returns : a iterator to beginning of the container*/
  [[nodiscard]] meshContainer::iterator
  begin();

  /** @returns : a iterator to end of the container*/
  [[nodiscard]] meshContainer::iterator
  end();

  /** @returns : a iterator to beginning of the container*/
  [[nodiscard]] meshContainer::const_iterator
  cbegin() const;

  /** @returns : a iterator to end of the container*/
  [[nodiscard]] meshContainer::const_iterator
  cend() const;

protected:
  /** @brief contains the mesh */
  meshContainer m_meshes;
};
