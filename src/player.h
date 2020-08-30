//
// Created by Johannes Flieger on 11/05/2020.
//

#ifndef SDLGRID_PLAYER_H
#define SDLGRID_PLAYER_H

#include "SDL.h"

class Player {

public:
    std::size_t pos_x{0};
    std::size_t pos_y{0};
    bool is_alive{true};

//    Player(std::size_t x, std::size_t y) : pos_x{x}, pos_y{y} {}
};

#endif //SDLGRID_PLAYER_H
