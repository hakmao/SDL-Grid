//
// Created by Johannes Flieger on 20/08/2020.
//

#ifndef SDLGRID_CONTROLLER_H
#define SDLGRID_CONTROLLER_H

#include "grid.h"

class Controller {
public:
    void HandleInput(Grid &grid, bool &running) const;
};

#endif //SDLGRID_CONTROLLER_H
