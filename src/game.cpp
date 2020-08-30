//
// Created by Johannes Flieger on 11/05/2020.
//

#include "game.h"

void Game::Run(Grid& g, const Controller& controller, Renderer& renderer)
{
    bool is_running = true;

    while (is_running)
    {
        renderer.Render( g);
        controller.HandleInput(g, is_running);
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
