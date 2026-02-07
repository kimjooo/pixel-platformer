#pragma once
#include <SDL3/SDL.h>

class Application {
public:
    Application();
    ~Application();
    void Run();

private:
    bool m_Running;

    SDL_Window*   m_Window;
    SDL_Renderer* m_Renderer; 
};
