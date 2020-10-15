#pragma once

// for removing unnecessary part of windows for the directX implementation
#define WIN32_LEAN_AND_MEAN 1
#define NOMINMAX 1 // really don't want the max and min macros from windows

#include <d3d11.h>


#define SAFE_DX_RELEASE(ptr) if(nullptr != ptr){ptr->Release(); ptr = nullptr;};
