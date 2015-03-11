#include "engine/precompiled.h"

#include "engine/renderer/RendererSystem.h"

#include "engine/renderer/WglContext.h"

namespace phantom {

	RendererSystem::RendererSystem(void *handle)
	{
#ifdef OS_WINDOWS
		context = new WglContext();
#endif

		context->initContext(handle);

		device = new Device();

		LOG_INFO("TODO: device creation");
	}
}
