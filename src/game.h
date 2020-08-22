//
// Created by Johannes Flieger on 11/05/2020.
//

#ifndef SDLGRID_GAME_H
#define SDLGRID_GAME_H

#include "player.h"
#include "renderer.h"
#include "controller.h"

class Game {
    Player player;
    void Update();
public:
    Game( const std::size_t grid_width, const std::size_t grid_height);
    void Run(const Controller &controller, Renderer &renderer);
    int GetScore();
};

#endif //SDLGRID_GAME_H
