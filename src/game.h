//
// Created by Johannes Flieger on 11/05/2020.
//

#ifndef SDLGRID_GAME_H
#define SDLGRID_GAME_H

#include <random>
#include "grid.h"
#include "renderer.h"
#include "controller.h"

class Game {
    void Update();
    int score{0};
    Uint32 target_frame_duration;
public:
//    Game( );
    void Run(Grid& g, const Controller &controller, Renderer &renderer, const Uint32 target_frame_duration);
    int GetScore();
};

#endif //SDLGRID_GAME_H
