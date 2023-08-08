#pragma once

#include <memory>

struct GLFWwindow;
struct GLFWmonitor;
struct GLFWvidmode;
namespace Minecraft {
	class Window {
	public:
		struct WindowDesc
		{
			unsigned int width;
			unsigned int height;
			const char* title;

			bool fullScreen;
			bool vSync;
		};

		Window();
		~Window() {}

		int Construct(const WindowDesc& desc);
		void Update();

		inline bool IsOpened() const { return _winProps.isOpened; }
	private:
		struct WinProps {
			unsigned int width;
			unsigned int height;

			bool fullScreen;
			bool vSync;

			bool isOpened;
		} _winProps;
		GLFWwindow* _window_imp;
		GLFWmonitor* _monitor;
		const GLFWvidmode* _mode;
	};
}