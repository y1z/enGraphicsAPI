#include "directX_Impl/include/Testing.h"
#include "directX_Impl/include/enDeviceDX11.h"
#include "directX_Impl/include/enDeviceContextDX11.h"
#include "directX_Impl/include/enSwapChainDX11.h"
#include "directX_Impl/include/enWindowDX11.h"
#include "directX_Impl/include/enInputManagerDX11.h"

#include <memory>

using std::make_unique;
using std::unique_ptr;

ErrorCode
startDeviceTest()
{
  unique_ptr<enDeviceCore> device = make_unique<enDeviceDX11>();
  unique_ptr<enDeviceContextCore> deviceContext = make_unique<enDeviceContextDX11>();

  ErrorCode currentErrorCode = device->init(*deviceContext);
  
  //enSwapChainCore* swapChain = device->createSwapChain(1280,
  //                                                     700,
  //                                                     DXGI_FORMAT_R8G8B8A8_UNORM);

  //if( nullptr == swapChain )
  //{
  //  currentErrorCode = ErrorCode::failedCreation;

  //}

  //SAFE_DELETE(swapChain)

  return currentErrorCode;
}

ErrorCode 
startWindowTest()
{
  enInputManagerDX11::activateModule(nullptr);
  unique_ptr<enWindowCore> window = make_unique<enWindowDX11>();

  HMODULE modHandle = GetModuleHandle(nullptr);

  const ErrorCode result = window->init(&modHandle,
                                        "test window",
                                        enInputManagerDX11::getInstancePtr(),
                                        1280,
                                        700);

  enInputManagerCore* input = enInputManagerDX11::getInstancePtr();


  std::cout << R"(press 'i' to close this window or press every other English letter for fun)";
  KeyInput currentKeyInput = KeyInput::nullInput;
  KeyInput lastInput = KeyInput::nullInput;

  while( true )
  {
    input->updateInput();
    currentKeyInput = input->getLastPressedKey();
    if( KeyInput::i == input->getLastPressedKey() )
    {
      break;
    }
    else if(currentKeyInput !=  lastInput)
    {
      std::cout <<
      "{ " << static_cast< unsigned char >(input->getLastPressedKey()) << " } " << '\n';
      lastInput = currentKeyInput;
    }
  }

  enInputManagerDX11::deactivateModule();
  return result ;
}

#include <Windows.h>

static LRESULT CALLBACK 
windowProc (HWND handel, UINT message , WPARAM wparam, LPARAM lparam)
{
  PAINTSTRUCT ps;
  HDC hdc;
  switch( message )
  {
   case WM_PAINT:
   hdc = BeginPaint(handel, &ps);
   EndPaint(handel, &ps);
   break;

    case WM_DESTROY:
    PostQuitMessage(0);
    break;
    default:
    return DefWindowProc(handel, message, wparam, lparam);
  }


  return DefWindowProc(handel, message, wparam, lparam);
}
