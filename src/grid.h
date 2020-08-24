//
// Created by Johannes Flieger on 23/08/2020.
//

#ifndef SDLGRID_GRID_H
#define SDLGRID_GRID_H

#include <vector>

using std::vector;
using std::string;

enum class State
{
    Empty,
    Obstacle,
    Player,
    Treasure
};

using GridRow = vector<State>;
using Grid2D = vector < GridRow>;

class Grid
{
    Grid2D global_state;
    GridRow ParseLine(string line);
    Grid2D ReadFile(string file_path);

public:
    std::size_t num_rows;
    std::size_t num_cols;
    Grid(std::size_t rows, std::size_t cols);
    Grid(Grid2D);
    Grid(string file_path);
    int Size() const;
    bool CellIsOnGrid(std::size_t x, std::size_t y) const;
    bool CellsAreNeighbours(std::size_t  x1, std::size_t y1, std::size_t x2, std::size_t y2);
    State CellState(std::size_t  x, std::size_t y) const;
    bool CanMove(std::size_t x, std::size_t y) const;
    const Grid2D &GlobalState() const;
    // Convert to string representation
    string ToString() const;
    bool FromFile(string file_path);
    bool ToFile(string file_path);
    friend std::ostream& operator<<(std::ostream& out, const Grid& grid);
    // Equality
    friend bool operator==(const Grid& g1, const Grid & g2);
    friend bool operator!=(const Grid& g1, const Grid & g2);
};


#endif //SDLGRID_GRID_H
