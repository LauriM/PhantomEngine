#include "engine/precompiled.h"

#include "engine/Sys/GameWindow.h"
#include "Game/Phantom.h"

#include "DebugLogger.h"

int main()
{
	phantom::GameWindow window("Phantom", 800, 600);

	phantom::g_logger = new DebugLogger();

	PhantomInstance instance;

	LOG_INFO("Initting PhantomInstance");

	instance.init();

	LOG_INFO("Entering the main loop");

	while (instance.running())
		instance.update();

	instance.uninit();

	return 0;
}