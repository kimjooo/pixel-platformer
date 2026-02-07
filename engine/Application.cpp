#include "Application.h"
#include "Window.h"
#include <SDL3/SDL.h>

Application::Application()
    : m_Running(true), m_Window(nullptr), m_Renderer(nullptr)
{
    SDL_Init(SDL_INIT_VIDEO);

    m_Window = SDL_CreateWindow(
        "Pixel Platformer",
        800, 600,
        SDL_WINDOW_RESIZABLE
    );

    m_Renderer = SDL_CreateRenderer(m_Window, nullptr);
}


Application::~Application()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

void Application::Run()
{
    SDL_FRect player = { 100, 100, 32, 32 };
    float playerSpeed = 200.0f; // 픽셀/초 단위 속도

    Uint64 lastTime = SDL_GetTicks();

    while (m_Running) {
        // ⏱ deltaTime 계산 (FPS 독립적 이동)
        Uint64 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f; // 초 단위
        lastTime = currentTime;

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT)
                m_Running = false;
        }

        int key_count = 0;
        const bool* keys = SDL_GetKeyboardState(&key_count);

        // 방향키 이동
        if (keys[SDL_SCANCODE_LEFT])  player.x -= playerSpeed * deltaTime;
        if (keys[SDL_SCANCODE_RIGHT]) player.x += playerSpeed * deltaTime;
        if (keys[SDL_SCANCODE_UP])    player.y -= playerSpeed * deltaTime;
        if (keys[SDL_SCANCODE_DOWN])  player.y += playerSpeed * deltaTime;

        // 화면 경계 제한
        if (player.x < 0) player.x = 0;
        if (player.y < 0) player.y = 0;
        if (player.x + player.w > 800) player.x = 800 - player.w;
        if (player.y + player.h > 600) player.y = 600 - player.h;

        // 🎨 화면 그리기
        SDL_SetRenderDrawColor(m_Renderer, 30, 30, 40, 255);
        SDL_RenderClear(m_Renderer);

        SDL_SetRenderDrawColor(m_Renderer, 200, 50, 50, 255);
        SDL_RenderFillRect(m_Renderer, &player); // SDL3는 FillRectF 사용

        SDL_RenderPresent(m_Renderer);

        SDL_Delay(1); // CPU 과부하 방지
    }
}

