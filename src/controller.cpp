//
// Created by Johannes Flieger on 20/08/2020.
//

#include "controller.h"
#include "SDL.h"

// Handle user keyboard input.
// Change player position using WASD or arrow keys.
void Controller::HandleInput(Grid &grid, bool &running) const {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_w:
                case SDLK_UP:
                    grid.TryToMovePlayer(Direction::Up);
                    break;
                case SDLK_s:
                case SDLK_DOWN:
                    grid.TryToMovePlayer(Direction::Down);
                    break;
                case SDLK_a:
                case SDLK_LEFT:
                    grid.TryToMovePlayer(Direction::Left);
                    break;
                case SDLK_d:
                case SDLK_RIGHT:
                    grid.TryToMovePlayer(Direction::Right);
                    break;
            }
        }
    }
}

