#include <iostream>
#include <thread>
#include <chrono>
#include <SDL.h>

using namespace std;
volatile bool end_flag;

void mouse_task()
{
    std::cout << "mouse task started" << std::endl;
    while(!end_flag) {
        int x, y;
        SDL_PumpEvents();
        SDL_GetMouseState(&x, &y);
        std::cout << "mouse [" << x << "," << y << "]" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "mouse task ended" << std::endl;
}

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "SDL2Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    auto mouse_thread = std::thread(mouse_task);
    SDL_Delay(10000);
    end_flag = true;
    std::cout << "Ending TestApp" << std::endl;
    mouse_thread.join();

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
