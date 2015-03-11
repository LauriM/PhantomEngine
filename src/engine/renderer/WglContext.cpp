#include "engine/precompiled.h"

#include "engine/renderer/WglContext.h"

PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;

namespace phantom {

	void WglContext::initContext(void *handle)
	{
		wglCreateContext((HDC)handle);
		glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	}

	void WglContext::uninitContext()
	{
	}

}