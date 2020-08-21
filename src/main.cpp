//#include "main.h"
#include <iostream>
//#include "SDL.h"
#include "player.h"
#include "renderer.h"
#include "controller.h"

constexpr std::size_t kgrid_cell_size = 36;
constexpr std::size_t kgrid_width = 29;
constexpr std::size_t kgrid_height = 23;


int main()
{
    bool game_is_running = true;
    Player player( kgrid_width, kgrid_height);
    Renderer renderer(kgrid_cell_size, kgrid_width, kgrid_height);
    Controller controller;
    while (game_is_running)
    {
        renderer.Render(player);
        controller.HandleInput(game_is_running, player);
    }
    // Goodbye message
    std::cout << "Game Over!\n";

    return EXIT_SUCCESS;
}
