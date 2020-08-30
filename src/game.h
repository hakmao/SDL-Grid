//
// Created by Johannes Flieger on 11/05/2020.
//

#ifndef SDLGRID_GAME_H
#define SDLGRID_GAME_H

#include "grid.h"
#include "renderer.h"
#include "controller.h"

class Game {
    void Update();
    int score{0};
public:
//    Game( );
    void Run(Grid& g, const Controller &controller, Renderer &renderer);
    int GetScore();
};

#endif //SDLGRID_GAME_H
