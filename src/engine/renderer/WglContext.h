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
	public:
		void initContext(void *handle);
		void uninitContext();
	};

}


#endif