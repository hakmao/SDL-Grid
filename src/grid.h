//
// Created by Johannes Flieger on 23/08/2020.
//

#ifndef SDLGRID_GRID_H
#define SDLGRID_GRID_H

#include <vector>
#include <tuple>
#include "entity.h"
#include "random_point.h"

constexpr std::size_t grid_default_width = 29;
constexpr std::size_t grid_default_height = 23;

using std::vector;
using std::string;

enum class State
{
    Empty,
    Obstacle,
    Player,
    Treasure
};

enum class Direction {
    Up, Down, Left, Right
};

using GridRow = vector<State>;
using Grid2D = vector <GridRow>;

class Grid
{
    std::size_t num_rows;
    std::size_t num_cols;
    Grid2D global_state;
    std::unique_ptr<RandomPoint> random_point;
    GridRow ParseLine(string line);
    Grid2D ReadFile(string file_path);
    void PlacePlayer();
    void PlaceEntity(Entity& e);
    State EntityToState(Entity& e);
    void SetEntityPosition(Entity& e, std::size_t x, std::size_t y);

public:
    std::size_t height;
    std::size_t width;
    Player player;
    Treasure treasure;
    Grid();
    Grid(std::size_t width, std::size_t height);
    Grid(Grid2D);
    Grid(string file_path);
    int Size() const;
    bool ContainsCell(std::size_t x, std::size_t y) const;
    bool AreNeighbours(std::size_t  x1, std::size_t y1, std::size_t x2, std::size_t y2);
    bool CellIsEmpty(std::size_t x, std::size_t y) const;
    State GetCellState(std::size_t  x, std::size_t y) const;
    void SetCellState(State new_state, std::size_t  x, std::size_t y);
    std::tuple<std::size_t, std::size_t> GetPlayerPosition() const;
    std::tuple< bool, std::size_t, std::size_t> FindPlayerPosition() const;
    void SetPlayerPosition(std::size_t x, std::size_t y);
    void TryToMovePlayer(Direction d);
    bool CanMoveTo(std::size_t x, std::size_t y) const;
    void Move(std::size_t old_x, std::size_t old_y, std::size_t new_x, std::size_t new_y);
    const Grid2D &GlobalState() const;
    // Import & export grid representation from/to file
    string ToString() const;
    bool FromFile(string file_path);
    bool ToFile(string file_path);
    friend std::ostream& operator<<(std::ostream& out, const Grid& grid);
    // Equality
    friend bool operator==(const Grid& g1, const Grid & g2);
    friend bool operator!=(const Grid& g1, const Grid & g2);
};


#endif //SDLGRID_GRID_H
