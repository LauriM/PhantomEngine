#include "engine/precompiled.h"

#include "engine/renderer/WglContext.h"

PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;

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

		int attribs[] =
		{
			WGL_CONTEXT_MAJOR_VERSION_ARB, 2,
			WGL_CONTEXT_MINOR_VERSION_ARB, 1,
			WGL_CONTEXT_FLAGS_ARB, 0,
			0
		};

		int pixelFormatID;
		pixelFormatID = ChoosePixelFormat(handle, &pfd);
		SetPixelFormat(handle, pixelFormatID, &pfd);

		HGLRC tempContext = wglCreateContext(handle);
		DWORD error = GetLastError();

		BOOL state = wglMakeCurrent(handle, tempContext);

		if (state == false)
		{
			LOG_ERROR("Failed to create context!");
			return;
		}

		// temp state created, find the proc addresses!
		wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC )wglGetProcAddress("wglCreateContextAttribsARB");

		context = wglCreateContextAttribsARB(handle, 0, attribs);

		// Make the new context active!
		state = wglMakeCurrent(handle, context);

		if (state == false)
		{
			LOG_ERROR("Failed to create context!");
			return;
		}

		// find the correct ptrs for the functions!
		glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");

	}

	void WglContext::uninitContext()
	{
	}

}