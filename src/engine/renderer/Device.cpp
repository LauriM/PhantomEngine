#include "engine/precompiled.h"

#include "engine/renderer/Device.h"
#include "engine/renderer/WglContext.h"
#include <gl/GL.h>

namespace phantom {

	Device::Device(HDC handle)
		: handle(handle)
	{
	}

	void Device::swapBuffers()
	{
		SwapBuffers(handle);
	}

	void Device::clearScreen()
	{
		glClearColor(1.0f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

}
