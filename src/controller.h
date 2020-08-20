//
// Created by Johannes Flieger on 20/08/2020.
//

#ifndef SDLGRID_CONTROLLER_H
#define SDLGRID_CONTROLLER_H

#include "player.h"

class Controller {
public:
    void HandleInput(bool &running, Player &player) const;
};

#endif //SDLGRID_CONTROLLER_H
