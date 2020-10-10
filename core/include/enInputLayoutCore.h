#pragma once
#include "core/util/enDefines.h"
#include <vector>

/**
 * @class enInputLayout : interface for controlling how are data is formated to the Graphics card.
 */
class enInputLayoutCore {
public:
  enInputLayoutCore (const enInputLayoutCore& )= default;
  enInputLayoutCore (enInputLayoutCore&& )= default;
  virtual ~enInputLayoutCore() = default;
public:

  virtual ErrorCode
  init(const std::vector<enInputLayoutData>& inputFormat) = 0;

protected:
  std::vector<enInputLayoutData> m_data;
};
