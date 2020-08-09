//
// Created by Johannes Flieger on 11/05/2020.
//
#include "renderer.h"


std::size_t Renderer::init_window_dimension(const std::size_t cell_size, const std::size_t dimension) {
    // +1 to window width & height so that the border grid lines fit in the screen.
    return (dimension * cell_size) + 1;
}
Renderer::Renderer(const std::size_t grid_cell_size, const std::size_t grid_width, const std::size_t grid_height):
grid_cell_size_ {grid_cell_size}, grid_width_ {grid_width}, grid_height_ {grid_height}
{
    window_width_ = init_window_dimension(grid_cell_size, grid_width);
    window_height_ = init_window_dimension(grid_cell_size, grid_height);
    init_SDL();
    init_window();
    init_cursor();
    sdl_quit = SDL_FALSE;
}
Renderer::~Renderer()
{
    SDL_DestroyRenderer(sdl_renderer_);
    SDL_DestroyWindow(sdl_window_);
    SDL_Quit();
}

void Renderer::init_cursor() {
    // Place the cursor in the middle of the grid
    grid_cursor_->x = (grid_width_ - 1) / 2 * grid_cell_size_;
    grid_cursor_->y = (grid_height_ - 1) / 2 * grid_cell_size_;
    grid_cursor_->w = grid_cell_size_;
    grid_cursor_->h = grid_cell_size_;
}

void Renderer::init_SDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialize SDL: %s",
                     SDL_GetError());
        exit(EXIT_FAILURE);
    }
}
void Renderer::init_window()
{
    if (SDL_CreateWindowAndRenderer(window_width_, window_height_, 0, &sdl_window_,
                                    &sdl_renderer_) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Create window and renderer: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_SetWindowTitle(sdl_window_, "SDL Grid");
}

void Renderer::render()
{
// Draw grid background.
    SDL_SetRenderDrawColor(sdl_renderer_, grid_background.r, grid_background.g,
                           grid_background.b, grid_background.a);
    SDL_RenderClear(sdl_renderer_);

    // Draw grid lines.
    SDL_SetRenderDrawColor(sdl_renderer_, grid_line_color.r, grid_line_color.g,
                           grid_line_color.b, grid_line_color.a);

    for (std::size_t x = 0; x < 1 + grid_width_ * grid_cell_size_;
         x += grid_cell_size_)
    {
        SDL_RenderDrawLine(sdl_renderer_, x, 0, x, window_height_);
    }

    for (std::size_t y = 0; y < 1 + grid_height_ * grid_cell_size_;
         y += grid_cell_size_)
    {
        SDL_RenderDrawLine(sdl_renderer_, 0, y, window_width_, y);
    }

    // Draw grid cursor.
    SDL_SetRenderDrawColor(sdl_renderer_, grid_cursor_color.r,
                           grid_cursor_color.g, grid_cursor_color.b,
                           grid_cursor_color.a);
    SDL_RenderFillRect(sdl_renderer_, grid_cursor_);

    SDL_RenderPresent(sdl_renderer_);
}

void Renderer::input_loop() {
    // Input loop
    while (!sdl_quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_w:
                        case SDLK_UP:
                            grid_cursor_->y -= grid_cell_size_;
                            break;
                        case SDLK_s:
                        case SDLK_DOWN:
                            grid_cursor_->y += grid_cell_size_;
                            break;
                        case SDLK_a:
                        case SDLK_LEFT:
                            grid_cursor_->x -= grid_cell_size_;
                            break;
                        case SDLK_d:
                        case SDLK_RIGHT:
                            grid_cursor_->x += grid_cell_size_;
                            break;
                    }
                    break;
                case SDL_QUIT:
                    sdl_quit = SDL_TRUE;
                    break;
            }
        }
        render();
    }
}
