#include "engine/precompiled.h"

#include "engine/Sys/GameWindow.h"
#include "Game/Phantom.h"

#include "DebugLogger.h"

int main()
{
	phantom::GameWindow window("Phantom", 800, 600);

	HWND handle = window.getWindowHandle();

	phantom::g_logger = new DebugLogger();

	PhantomInstance instance;

	LOG_INFO("Initting PhantomInstance");

	instance.initInstance((void*)handle);

	LOG_INFO("Entering the main loop");

	while (instance.running())
		instance.updateInstance();

	instance.uninit();

	return 0;
}