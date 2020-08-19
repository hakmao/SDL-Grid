//
// Created by Johannes Flieger on 11/05/2020.
//

#ifndef SDLGRID_PLAYER_H
#define SDLGRID_PLAYER_H

#include "SDL.h"

enum class Direction {
    Up, Down, Left, Right
};

class Player {
    bool is_alive{true};
    int grid_width_;
    int grid_height_;
    void SetInitialPosition();

public:
    int pos_x;
    int pos_y;

    Player(int grid_width, int grid_height)
            : grid_width_{grid_width},
              grid_height_{grid_height} { SetInitialPosition(); }

    bool IsPlayerCell(int x, int y) const;

    bool IsAlive() const;

    void TryToMove(Direction d);

    void Update();
};

#endif //SDLGRID_PLAYER_H
