//
// Created by Johannes Flieger on 11/05/2020.
//

#include "player.h"

void Player::Update()
{
    SDL_Point prev_cell{ // Player cell before update
            pos_x,
            pos_y
    };
    // TODO: update
    UpdatePosition();
    SDL_Point current_cell{ // Player cell after update
            pos_x,
            pos_y
    };
}

void Player::Move() {

}