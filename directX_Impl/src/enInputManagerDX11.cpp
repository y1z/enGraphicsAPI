#include "directX_Impl/include/enInputManagerDX11.h"
#include <cctype>

auto isLetterChar = [](const WPARAM possibleLetter) 
{
  return ((possibleLetter >= 'a' && possibleLetter <= 'z')
          || (possibleLetter >= 'A' && possibleLetter <= 'Z'));
};

KeyInput 
enInputManagerDX11::getLastPressedKey() const
{
  return m_lastInput.keyPressed;
}

void 
enInputManagerDX11::updateInput()
{
  m_lastInput = s_windProcData;

  MSG message;
  while(PeekMessage(&message, NULL, 0, 0,PM_REMOVE) )
  {
    TranslateMessage(&message);
    DispatchMessage(&message);
  }

}

bool 
enInputManagerDX11::internalActivateModule(void* descriptor)
{
  enInputManagerDX11::s_procPtr = enInputManagerDX11::internalWindowProcedure;

  return true;
}

enInputManagerDX11::windProcType
enInputManagerDX11::getProcPtr()
{
  return s_procPtr;
}

// TODO : this implementation does not KNOW if you press the shift , alt , ctrl and numpad keys

LRESULT
enInputManagerDX11::internalWindowProcedure(HWND handle,
                                            UINT message,
                                            WPARAM inputedKey,
                                            LPARAM lparam)
{
  PAINTSTRUCT ps;
  HDC hdc;

  switch( message )
  {
    case WM_PAINT:
    hdc = BeginPaint(handle, &ps);
    EndPaint(handle, &ps);
    break;

    case WM_DESTROY:
    PostQuitMessage(0);
    break;

    case WM_KEYDOWN:
    {
      if( isLetterChar(inputedKey) )
      {
        const uint32 lowerCaseValue = std::tolower(static_cast< unsigned char >(inputedKey));
        s_windProcData.keyPressed = static_cast< KeyInput >(lowerCaseValue);

      }

    }
    break;

    default:
    return  DefWindowProc(handle, message, inputedKey, lparam);
  }
  return 0;
}



