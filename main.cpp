#include "engine/Window.h"

int main(int argc, char* argv[])
{
    Window window("Pixel Platformer", 800, 600);

    while (window.IsRunning())
    {
        window.PollEvents();
        window.Clear();
        window.Present();
    }

    return 0;
}
