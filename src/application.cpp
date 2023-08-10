#include "application.h"

Minecraft::Application::Application()
    : _window(nullptr)
{
}

int Minecraft::Application::Construct(const Window::WindowDesc& desc)
{
    _window = std::make_unique<Window>();
    int ret = _window->Construct(desc);

    return ret;
}

void Minecraft::Application::Start()
{
    OnUserStart();
    while (_window->IsOpened())
    {
        OnUserUpdate();
        _window->Update();
    }
}
