#pragma once

#ifdef OS_WINDOWS

#include "engine/renderer/GraphicsContext.h"

#include <gl/glcorearb.h>
#include <gl/glext.h>
#include <gl/wglext.h>

extern PFNGLCREATEPROGRAMPROC glCreateProgram;

namespace phantom {

	class WglContext : public GraphicsContext
	{
	private:
		HDC handle;
		HGLRC context;

	public:
		void initContext(void *handle);
		void uninitContext();
	};

}


#endif