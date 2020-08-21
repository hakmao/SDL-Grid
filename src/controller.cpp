//
// Created by Johannes Flieger on 20/08/2020.
//

#include "controller.h"
#include "SDL.h"

// Handle user keyboard input.
// Change player position using WASD or arrow keys.
void Controller::HandleInput(bool &running, Player &player) const {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_w:
                case SDLK_UP:
                    player.TryToMove(Direction::Up);
                    break;
                case SDLK_s:
                case SDLK_DOWN:
                    player.TryToMove(Direction::Down);
                    break;
                case SDLK_a:
                case SDLK_LEFT:
                    player.TryToMove(Direction::Left);
                    break;
                case SDLK_d:
                case SDLK_RIGHT:
                    player.TryToMove(Direction::Right);
                    break;
            }
        }
    }
}

