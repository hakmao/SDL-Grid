//
// Created by Johannes Flieger on 11/05/2020.
//

#include "game.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
: player(grid_width, grid_height){}

void Game::Run(const Controller& controller, const Renderer& renderer)
{
    ;
}

void Game::Update()
{
/*
    if (!player.alive) return;

    player.Update();
*/
;
}

int Game::GetScore()
{
    return 0;
}
