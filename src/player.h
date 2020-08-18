//
// Created by Johannes Flieger on 11/05/2020.
//

#ifndef SDLGRID_PLAYER_H
#define SDLGRID_PLAYER_H

#include "SDL.h"

enum class Direction { Up, Down, Left, Right };

class Player {
    bool alive;
    int grid_width_;
    int grid_height_;
    void UpdatePosition();

public:
    int pos_x;
    int pos_y;
    Player(int grid_width, int grid_height): grid_width_{grid_width}, grid_height_{grid_height} {}
    bool IsPlayerCell(int x, int y) const;
    bool IsAlive() const;
    void Move();
    void Update();
};

#endif //SDLGRID_PLAYER_H
