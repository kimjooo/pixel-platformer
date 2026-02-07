#include "Window.h"

Window::Window(const std::string& title, int width, int height)
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        title.c_str(),
        width,
        height,
        SDL_WINDOW_RESIZABLE
    );

    renderer = SDL_CreateRenderer(window, nullptr);
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::PollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
            running = false;
    }
}

void Window::Clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Window::Present()
{
    SDL_RenderPresent(renderer);
}

bool Window::IsRunning() const
{
    return running;
}
