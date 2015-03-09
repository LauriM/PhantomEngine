#include "engine/precompiled.h"
#include "Debug.h"

namespace phantom {

	void debugPrint(const String &p_msg)
	{
		OutputDebugString(p_msg.c_str());
		OutputDebugString("\n");
	}

	void debugBreakpoint()
	{
		__debugbreak();
	}

}
