//
// Created by Johannes Flieger on 11/05/2020.
//

#include "player.h"

void Player::Update() {
    SDL_Point prev_cell{ // Player cell before update
            pos_x,
            pos_y
    };
    // TODO: update
    SDL_Point current_cell{ // Player cell after update
            pos_x,
            pos_y
    };
}

void Player::TryToMove(Direction d) {
    int old_x = pos_x;
    int old_y = pos_y;
    switch (d) {
        case Direction::Up:
            pos_y -= 1;
            break;
        case Direction::Down:
            pos_y += 1;
            break;
        case Direction::Left:
            pos_x -= 1;
            break;
        case Direction::Right:
            pos_x += 1;
            break;
    }
}

void Player::SetInitialPosition() {
    pos_x = (grid_width_ - 1) / 2;
    pos_y = (grid_height_ - 1) / 2;
}

