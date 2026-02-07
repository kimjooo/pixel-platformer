#include "Application.h"
#include "Window.h"
#include <SDL3/SDL.h>

Application::Application()
    : m_Running(true)
{
    SDL_Init(SDL_INIT_VIDEO);
}

Application::~Application()
{
    SDL_Quit();
}

void Application::Run()
{
    Window window("Pixel Platformer", 1280, 720);

    while (m_Running && window.IsRunning())
    {
        window.PollEvents();
        window.Clear();
        window.Present();
    }
}
