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
    Renderer renderer(kgrid_cell_size, kgrid_width, kgrid_height);
    Controller controller;
    Game game( kgrid_width, kgrid_height);
    game.Run(controller, renderer);
    // Goodbye message
    std::cout << "Game Over!\n";
    std::cout << "Score: " << game.GetScore() << std::endl;

    return EXIT_SUCCESS;
}
