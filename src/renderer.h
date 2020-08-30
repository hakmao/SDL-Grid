//
// Created by Johannes Flieger on 11/05/2020.
//

#ifndef SDLGRID_RENDERER_H
#define SDLGRID_RENDERER_H

#include "SDL.h"
#include "grid.h"

class Renderer {
    SDL_Window *sdl_window_;
    SDL_Renderer *sdl_renderer_;
    SDL_Color grid_background {22, 22, 22, 255}; // Barely Black
    SDL_Color grid_line_color {44, 44, 44, 255}; // Dark grey
    SDL_Color grid_obstacle_color {88, 88, 88, 255}; // Light grey
    SDL_Color grid_cursor_color {255, 255, 255, 255}; // White

    std::size_t window_width_;
    std::size_t window_height_;
    const std::size_t grid_cell_size_;
    const std::size_t grid_width_ ;
    const std::size_t grid_height_;
    void InitSDL();
    void InitWindow();
    std::size_t InitWindowDimension(const std::size_t cell_size, const std::size_t dimension);
public:
    SDL_bool sdl_quit;
    Renderer( const std::size_t grid_width, const std::size_t grid_height, const std::size_t grid_cell_size);
    Renderer( const Grid& g, const std::size_t grid_cell_size);
    ~Renderer();
    void Render(const Grid& grid);
    void RenderObstacle(SDL_Rect& block, std::size_t x, std::size_t y);
    void RenderPlayer(SDL_Rect& block, std::size_t x, std::size_t y);
};

#endif //SDLGRID_RENDERER_H
