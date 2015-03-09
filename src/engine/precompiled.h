#pragma once

#include "Preprocessor/platform.h"

#include <string>
#include <cstdio>

typedef std::string String;

#ifdef OS_WINDOWS

#include <Windows.h>
#include <WinBase.h>

#endif