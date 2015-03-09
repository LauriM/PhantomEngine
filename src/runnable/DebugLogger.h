#include "engine/sys/Logger.h"
#include "engine/debug/Debug.h"

class DebugLogger : public phantom::Logger
{
public:
	void error(const String &msg)
	{
		DEBUG_PRINT("[ERROR] " << msg);
	}

	void warning(const String &msg)
	{
		DEBUG_PRINT("[WARNING] " << msg);
	}

	void info(const String &msg)
	{
		DEBUG_PRINT("[INFO] " << msg);
	}

};