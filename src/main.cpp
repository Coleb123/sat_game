#include <SDL.h>
#include "SatelliteManager.h"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr float PI = 3.14159265359f;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window =
        SDL_CreateWindow(
            "Satellite Ops",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            1280,
            720,
            SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SatelliteManager satelliteManager;
    satelliteManager.Initialize();

    bool running = true;
    Uint32 last = SDL_GetTicks();

    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = false;
        }

        Uint32 now = SDL_GetTicks();
        float dt = (now - last) / 1000.0f;
        last = now;

        satelliteManager.Update(dt);

        // ======================
        // RENDER
        // ======================

        SDL_SetRenderDrawColor(renderer, 0, 0, 20, 255);
        SDL_RenderClear(renderer);

        int cx = WINDOW_WIDTH / 2;
        int cy = WINDOW_HEIGHT / 2;
        float radius = 250.0f;

        // Draw Earth
        SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
        SDL_Rect earth{ cx - 30, cy - 30, 60, 60 };
        SDL_RenderFillRect(renderer, &earth);

        // Draw orbit ring
        SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
        for (int i = 0; i < 360; i++)
        {
            float r = i * PI / 180.0f;
            int x = cx + (int)(cos(r) * radius);
            int y = cy + (int)(sin(r) * radius);
            SDL_RenderDrawPoint(renderer, x, y);
        }

        // Draw satellites
        for (const auto& sat : satelliteManager.GetSatellites())
        {
            float a = sat.GetAngle() * PI / 180.0f;

            int x = cx + (int)(cos(a) * radius);
            int y = cy + (int)(sin(a) * radius);

            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_Rect r{ x - 4, y - 4, 8, 8 };
            SDL_RenderFillRect(renderer, &r);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}