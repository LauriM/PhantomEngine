#include "engine/precompiled.h"

#include "engine/Sys/GameWindow.h"
#include "Game/Phantom.h"

int main()
{
	phantom::GameWindow window("Phantom", 800, 600);

	PhantomInstance instance;

	instance.init();

	while (instance.running())
		instance.update();

	instance.uninit();

	return 0;
}