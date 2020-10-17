#pragma once
#include <iostream>
#include "enDefines.h"



/**
 * @brief create a module, in other word a instance of a class that's only created once
 * and can be called globally
 */
template<class Type>
class enModule 
{
public:

  enModule() = default;
  enModule(const enModule&) = delete;
  enModule(enModule&&) noexcept = delete;
  virtual ~enModule()
  {
    if( s_isActive  )
    {
      EN_LOG_DEBUG_INFO("Do not forget to end the module with \'modleEnd\'");
    }
  }

public:
   enModule& operator= (const enModule&) = delete;
   enModule& operator= (enModule&&)noexcept = delete;

public:

  /**
   * @brief initializes the Module
   * @param descriptor This parameter exist for type that requires a descriptor
   * possibly goes unused.
   * @returns boolean value that indicates if everything when correct
   */
  virtual bool
  internalActivateModule(void *descriptor) = 0;

  /**
   * @brief prepares the module so it can be used.
   * @param descriptor : Is a pointer to some descriptor type object in case 
   * the behavior of the underling instance requires it.
   */
  static bool 
  activateModule(void* descriptor)
  {
    Type*& ptrToInstance = instanceInternal();
    setInternalPtr(ptrToInstance);
    s_isActive = true;
    if( nullptr == ptrToInstance )
    {
      std::cerr << " failed to activate the module \n";
      return false;
    }
    
    return (ptrToInstance)->internalActivateModule(descriptor);
  }

  /**
   * @brief frees resource related with the module.
   * @returns 'true' when the instance if the instance get's deleted,'false'
   * When it was never initialized or already deleted .
   */
  static bool
  deactivateModule()
  {
    if( nullptr != instanceInternal() )
    {
      s_isActive = false;
      delete instanceInternal();
      instanceInternal() = nullptr;
      setInternalPtr(nullptr);
      return true;
    }
    return false;
  }


  /**
   * @returns a pointer to the instance
   */
  static Type*
  getInstancePtr()
  {
    if( nullptr == s_ptrToInstance )
    {
      EN_LOG_DEBUG_INFO("Trying to access a module instance that was freed ");
      return nullptr ;
    }
    return s_ptrToInstance;
  }


  /**
   * @returns a reference to the instance.
   */
  static Type&
  getInstanceRef()
  {
    if( nullptr == s_ptrToInstance)
    {
      EN_LOG_DEBUG_INFO("Trying to access a instance that was deleted or not initialized");
      assert(nullptr != s_ptrToInstance);
    }

    return *s_ptrToInstance;
  }



private:

  /**
   * @returns a pointer to the instance.
   */
  static Type*
  getInternalPtr()
  {
    return s_ptrToInstance;
  }

  /**
   * @brief set the pointer to the underlying instance.
   */
  static void
  setInternalPtr(Type*const ptrToInstance)
  {
    s_ptrToInstance = ptrToInstance;
  }


private:
  /**
   * @brief Takes care of create the instance for the module.
   */
  static Type*&
  instanceInternal()
  {
    static Type* instance = new Type();
    
    return instance;
  }

private:
  inline static Type* s_ptrToInstance = nullptr;
  inline static bool s_isActive = false;
};
