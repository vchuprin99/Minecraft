#include "window.h"

#include <GLFW/glfw3.h>

#include <log.h>

Minecraft::Window::Window()
	: _winProps({0, 0, false, false, false}), 
	_window_imp(nullptr), _monitor(nullptr), _mode(nullptr)
{
}

int Minecraft::Window::Construct(const WindowDesc& desc)
{
	_winProps.width = desc.width;
	_winProps.height = desc.height;
	_winProps.fullScreen = desc.fullScreen;
	_winProps.vSync = desc.vSync;

	if (!glfwInit()) {
		log_err("GLFW initialization failed");
		return -1;
	}
	_window_imp = glfwCreateWindow(_winProps.width, _winProps.height, desc.title, 
			nullptr, nullptr);
	if (!_window_imp) {
		log_err("Window creation failed");
		return -2;
	}
	glfwMakeContextCurrent(_window_imp);
	glfwSetWindowUserPointer(_window_imp, &_winProps);

	_monitor = glfwGetPrimaryMonitor();
	_mode = glfwGetVideoMode(_monitor);
	if (_winProps.fullScreen) glfwSetWindowMonitor(_window_imp, _monitor, 0, 0,
		_winProps.width, _winProps.height, _mode->refreshRate);	

	glfwSwapInterval(_winProps.vSync);

	glfwSetErrorCallback([](int error_code, const char* description) {
		log_err("GLFW error {0}: {1}", error_code, description);
	});
	glfwSetWindowCloseCallback(_window_imp, [](GLFWwindow* window) {
		WinProps* winProps = reinterpret_cast<WinProps*>(glfwGetWindowUserPointer(window));
		winProps->isOpened = false;
	});
	glfwSetWindowSizeCallback(_window_imp, [](GLFWwindow* window, int width, int height) {
		WinProps* winProps = reinterpret_cast<WinProps*>(glfwGetWindowUserPointer(window));
		winProps->width = width;
		winProps->height = height;
	});

	_winProps.isOpened = true;

	return 0;
}

void Minecraft::Window::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(_window_imp);
}
