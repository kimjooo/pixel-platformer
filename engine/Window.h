#pragma once
#include <SDL3/SDL.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    void PollEvents();
    void Clear();
    void Present();
    bool IsRunning() const;

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool running = true;
};
