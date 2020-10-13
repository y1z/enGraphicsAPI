#pragma once
#include <vector>
#include <string_view>
#include "core/util/enDefines.h"
#include "core/include/enModelCore.h"

/**
 * @class enSceneCore : contains an entire scene composed of 1 or more 3D models.
 */
class enSceneCore 
{
public:
  /**
   * @brief : typedef is the container of models 
   * @note : the reason it's a typedef is so I can change the underling container
   * in the future.
   */
  using modelContainer = std::vector<enModelCore>;
public://constructor
  enSceneCore() = default;
  enSceneCore(const enSceneCore&) = delete;
  enSceneCore(enSceneCore&&) noexcept = default;
  ~enSceneCore() noexcept = default;
public://operator
  enSceneCore& operator= (const enSceneCore&) = delete;
  enSceneCore& operator= (enSceneCore&&) noexcept = default;
public:

  /**
   * @brief : initializes the scene
   * @filesPaths : contains 1 or more files path.
   */
  ErrorCode
  init(const std::vector<std::string_view>& filePaths);

  /** @brief : draws all the meshes of the model. */
  void
  drawScene();

  /**
   * @returns : a reference to a individual model.
   * @param index : let u select a individual mesh.
   */
  [[nodiscard]] enModelCore&
  getModel(const size_t index);

  /** @returns : the amount of models the scene contains. */
  [[nodiscard]] size_t
  getModelCount()const;

  /** @returns : a iterator to beginning of the container*/
  [[nodiscard]] modelContainer::iterator
  begin();

  /** @returns : a iterator to end of the container*/
  [[nodiscard]] modelContainer::iterator
  end();

  /** @returns : a iterator to beginning of the container*/
  [[nodiscard]] modelContainer::const_iterator
  cbegin() const;

  /** @returns : a iterator to end of the container*/
  [[nodiscard]] modelContainer::const_iterator
  cend() const;

protected:

  /** @brief contains all the models of the scene*/
  modelContainer m_models;
};

