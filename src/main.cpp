#include "main.h"

constexpr std::size_t kgrid_cell_size = 36;
constexpr std::size_t kgrid_width = 29;
constexpr std::size_t kgrid_height = 23;


int main()
{
    bool game_is_running = true;
    Player player( kgrid_width, kgrid_height);
    Renderer renderer(kgrid_cell_size, kgrid_width, kgrid_height);
    while (game_is_running)
    {
        renderer.Render(player);
        renderer.HandleInput(game_is_running, player);
    }
    // Goodbye message
    std::cout << "Game Over!\n";

    return EXIT_SUCCESS;
}
