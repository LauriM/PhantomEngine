#pragma once

namespace phantom {

	// Rendering device
	class Device
	{
	private:
		HDC handle;

	public:
		Device(HDC handle);

		void swapBuffers();
		void clearScreen();
	};

}