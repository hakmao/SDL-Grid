//
// Created by Johannes Flieger on 11/05/2020.
//

#include "game.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
: player(grid_width, grid_height){}

void Game::Run(const Controller& controller, Renderer& renderer)
{
    bool is_running = true;

    while (is_running)
    {
        renderer.Render(player);
        controller.HandleInput(is_running, player);
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
    return 1000;
}
