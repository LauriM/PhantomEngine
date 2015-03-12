#include "engine/precompiled.h"

#include "engine/renderer/RendererSystem.h"

#include "engine/renderer/WglContext.h"

namespace phantom {

	RendererSystem::RendererSystem(void *handle)
	{
#ifdef OS_WINDOWS
		context = new WglContext();

		context->initContext(handle);

		device = new Device(((WglContext*)context)->getHandle());
#endif


		LOG_INFO("TODO: device creation");
	}

	void RendererSystem::draw()
	{
		device->clearScreen();
		device->swapBuffers();
	}

}
