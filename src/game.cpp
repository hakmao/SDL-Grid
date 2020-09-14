//
// Created by Johannes Flieger on 11/05/2020.
//

#include "game.h"
//#include "SDL.h"

void Game::Run(Grid& g, const Controller& controller, Renderer& renderer, Uint32 target_frame_duration)
{
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;

    bool is_running = true;

    while (is_running)
    {
        frame_start = SDL_GetTicks();

        renderer.Render( g);
        controller.HandleInput(g, is_running);
        frame_end = SDL_GetTicks();

        frame_count++;
        frame_duration = frame_end - frame_start;

        // Update the window title every second
        if (frame_end - title_timestamp >= 1000)
        {
            renderer.UpdateWindowTitle(score);
            frame_count = 0;
            title_timestamp = frame_end;
        }
        // Even out frame rate
        if (frame_duration < target_frame_duration)
        {
            SDL_Delay(target_frame_duration - frame_duration);
        }

    }
}

void Game::Update()
{
/*
    if (!player.IsAlive()) return;

    player.Update();
*/
;
}

int Game::GetScore()
{
    return score;
}
