//#include "main.h"
#include <iostream>
//#include "SDL.h"
#include "game_objects.h"
#include "renderer.h"
#include "controller.h"
#include "game.h"

constexpr std::size_t GRID_CELL_SIZE = 36;
constexpr std::size_t GRID_WIDTH = 29;
constexpr std::size_t GRID_HEIGHT = 23;

constexpr Uint32 FRAMES_PER_SECOND{60};
constexpr Uint32 MS_PER_FRAME{1000/FRAMES_PER_SECOND};


int main()
{
//    Grid game_grid(kgrid_width, kgrid_height);
    Grid game_grid("../src/example_grid_1.grid");
    Renderer renderer(game_grid.width, game_grid.height, GRID_CELL_SIZE);
    Controller controller;
    Game game;
    game.Run(game_grid, controller, renderer, MS_PER_FRAME);
    // Goodbye message
    std::cout << "Game Over!\n";
    std::cout << "Score: " << game.GetScore() << std::endl;

    return EXIT_SUCCESS;
}
