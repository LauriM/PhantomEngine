#pragma once

#include <string>
#include <cstdio>
#include <sstream>

typedef std::string String;

#include "Preprocessor/platform.h"
#include "engine/sys/Logger.h"

#ifdef OS_WINDOWS

#include <Windows.h>
#include <WinBase.h>

#endif