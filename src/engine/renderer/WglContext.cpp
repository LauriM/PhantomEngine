#include "engine/precompiled.h"

#include "engine/renderer/WglContext.h"

PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;

namespace phantom {

	void WglContext::initContext(void *h)
	{
		handle = GetDC((HWND)h);

		PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
			PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
			32,                        //Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                        //Number of bits for the depthbuffer
			8,                        //Number of bits for the stencilbuffer
			0,                        //Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		int pixelFormatID;
		pixelFormatID = ChoosePixelFormat(handle, &pfd);
		SetPixelFormat(handle, pixelFormatID, &pfd);

		context = wglCreateContext(handle);
		DWORD error = GetLastError();

		bool state = wglMakeCurrent(handle, context);

		glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	}

	void WglContext::uninitContext()
	{
	}

}