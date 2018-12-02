#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <shellapi.h> // For CommandLineToArgvW

// In order to define a function called CreateWindow, the Windows macro needs to
// be undefined.
#if defined(CreateWindow)
#undef CreateWindow
#endif

// STL Headers
#include <algorithm>
#include <string>
#include <cassert>
#include <map>
#include <memory>

// Macros
#include "HANmacros.h"

// KeyCodes
#include "KeyCodes.h"
