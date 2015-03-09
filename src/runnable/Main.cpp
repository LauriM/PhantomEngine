#include "engine/precompiled.h"

#include "Game/Phantom.h"

int main()
{
	PhantomInstance instance;

	instance.init();

	while (instance.running())
		instance.update();

	instance.uninit();

	return 0;
}