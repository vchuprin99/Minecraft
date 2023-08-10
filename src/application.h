#pragma once

#include "window.h"

namespace Minecraft {
	class Application {
	public:
		Application();
		virtual ~Application() {}

		int Construct(const Window::WindowDesc& desc);
		void Start();
	protected:
		virtual void OnUserStart() = 0;
		virtual void OnUserUpdate() = 0;
	private:
		std::unique_ptr<Window> _window;
	};
}