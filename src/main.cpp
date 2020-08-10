#include "main.h"

constexpr std::size_t kgrid_cell_size = 36;
constexpr std::size_t kgrid_width = 29;
constexpr std::size_t kgrid_height = 23;


int main()
{
    Renderer renderer(kgrid_cell_size, kgrid_width, kgrid_height);
    renderer.input_loop();

    std::cout << "Game Over!\n";

    return EXIT_SUCCESS;
}