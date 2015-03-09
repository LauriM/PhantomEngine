#pragma once

namespace phantom {

	class GameWindow
	{
	private:
	#if defined OS_WINDOWS
		WNDCLASS windowClass;
		HWND windowHandle;
		HINSTANCE instance;
	#endif

		bool windowClosed;
		String windowClassString;
	public:

	#if defined OS_WINDOWS
		static LRESULT CALLBACK staticProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
		LRESULT CALLBACK proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

		const HWND getWindowHandle() const { return windowHandle; }
	#endif

		GameWindow(const String &title, const int &width, const int &height);
		~GameWindow();

		void close() { windowClosed = true; }
		const bool isClosed() const { return windowClosed; }
	};

}