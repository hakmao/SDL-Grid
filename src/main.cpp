//#include "main.h"
#include <iostream>
//#include "SDL.h"
#include "player.h"
#include "renderer.h"
#include "controller.h"
#include "game.h"

constexpr std::size_t kgrid_cell_size = 36;
constexpr std::size_t kgrid_width = 29;
constexpr std::size_t kgrid_height = 23;


int main()
{
//    Grid game_grid(kgrid_width, kgrid_height);
    Grid game_grid("../src/example_grid_1.grid");
    Renderer renderer(game_grid.width, game_grid.height, kgrid_cell_size);
    Controller controller;
    Game game;
    game.Run(game_grid, controller, renderer);
    // Goodbye message
    std::cout << "Game Over!\n";
    std::cout << "Score: " << game.GetScore() << std::endl;

    return EXIT_SUCCESS;
}
