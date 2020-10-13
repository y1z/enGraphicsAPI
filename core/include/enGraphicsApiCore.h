#pragma once
#include "core/util/enDefines.h"
#include "core/include/enDeviceCore.h"
#include "core/include/enDeviceContextCore.h"
#include "core/include/enSwapChainCore.h"

/**
 * @brief Is a interface for controlling all Graphics related operations.
 */
class enGraphicsApiCore 
{
public:
  enGraphicsApiCore()
    :m_device(nullptr),
    m_deviceContext(nullptr),
    m_swapChain(nullptr)
  {}

  enGraphicsApiCore(const enGraphicsApiCore&) = delete;
  enGraphicsApiCore(enGraphicsApiCore&&) noexcept = delete;
  virtual ~enGraphicsApiCore()
  {
    SAFE_DELETE(m_device) 
    SAFE_DELETE(m_deviceContext) 
    SAFE_DELETE(m_swapChain) 
  }
public:
  enGraphicsApiCore& operator= (const enGraphicsApiCore&) = delete;
  enGraphicsApiCore& operator= (enGraphicsApiCore&&) noexcept = delete;
public:

  /**
   * @brief : initializes the api.
   */
  virtual ErrorCode
  init( ) = 0;


    

  enDeviceCore * m_device;
  enDeviceContextCore *m_deviceContext;
  enSwapChainCore * m_swapChain;
};

