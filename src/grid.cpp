//
// Created by Johannes Flieger on 23/08/2020.
//
#include "grid.h"
#include <iostream>
#include <sstream>
#include <fstream>


Grid::Grid(std::size_t width, std::size_t height)
        : width{width}, height{height}, num_rows{height}, num_cols{width}
{
    global_state.resize(num_rows, vector<Type>(num_cols, Type::Empty));
    random_point = std::make_unique<RandomPoint>(width, height);
//    PlaceTreasure();
//    PlacePlayer();
    PlaceEntities();
}

Grid::Grid() : Grid(grid_default_width, grid_default_height) {}

Grid::Grid(Grid2D grid) {
    global_state = grid;
    if (global_state.empty())
        std::cout << "WARNING [Grid Constructor]: Global state is empty." << std::endl;
    num_rows = global_state.size();
    num_cols = global_state[0].size();
    height = num_rows;
    width = num_cols;
    random_point = std::make_unique<RandomPoint>(width, height);
//    PlaceTreasure();
//    PlacePlayer();
    PlaceEntities();
}

Grid::Grid(string file_path) : Grid(ReadFile(file_path)) {}

int Grid::Size() const {
    return width * height;
}

bool Grid::ContainsCell(std::size_t x, std::size_t y) const {
    return (x < width) && (y < height);
}

bool Grid::AreNeighbours(std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2) {
    std::size_t diff1 = (x1 > x2) ? x1 - x2 : x2 - x1;
    std::size_t diff2 = (y1 > y2) ? y1 - y2 : y2 - y1;
    return (diff1 <= 1) && (diff2 <= 1);
}

bool Grid::CanMoveTo(std::size_t x, std::size_t y) const {
    if (!ContainsCell(x, y))
        return false;
    Type cell_state = global_state[y][x];
    switch (cell_state) {
        case Type::Obstacle:
            return false;
        case Type::Empty:
        case Type::Player:
        case Type::Treasure:
        default:
            return true;
    }
}

std::tuple<std::size_t, std::size_t> Grid::GetPlayerPosition() const {
    return std::make_tuple(player.pos_x, player.pos_y);
}

void Grid::SetPlayerPosition(std::size_t x, std::size_t y) {
    std::cout << "Setting position of player to [" << x  << "," << y << "]\n";
    player.pos_x = x;
    player.pos_y = y;
    SetCellState(Type::Player, x, y);
}

void Grid::SetTreasurePosition(std::size_t x, std::size_t y) {
    std::cout << "Setting position of treasure to [" << x  << "," << y << "]\n";
    treasure.pos_x = x;
    treasure.pos_y = y;
    SetCellState(Type::Treasure, x, y);
}

void Grid::PlacePlayer() {
    while (true) {
        auto[x, y] = random_point->Generate();
        if (CellIsEmpty(x, y)) {
            SetPlayerPosition(x, y);
            return;
        }
    }
}

void Grid::PlaceTreasure() {
    while (true) {
        auto[x, y] = random_point->Generate();
        if (CellIsEmpty(x, y)) {
            SetTreasurePosition(x, y);
            return;
        }
    }
}

void Grid::PlaceEntities(){
    PlaceTreasure();
    PlacePlayer();
}

std::tuple<bool, std::size_t, std::size_t> Grid::FindPlayerPosition() const {
    for (std::size_t row = 0; row < num_rows; ++row) {
        for (std::size_t col = 0; col < num_cols; ++col) {
            if (global_state[row][col] == Type::Player) {
                std::cout << "Player found at [" << col << ", " << row << "]\n";
                return std::make_tuple(true, col, row);
            }
        }
    }
    std::cout << "Player not found" << std::endl;
    return std::make_tuple(false, 0, 0);
}


void Grid::TryToMovePlayer(Direction d) {
    int new_x = player.pos_x;
    int new_y = player.pos_y;
    switch (d) {
        case Direction::Up:
            new_y -= 1;
            break;
        case Direction::Down:
            new_y += 1;
            break;
        case Direction::Left:
            new_x -= 1;
            break;
        case Direction::Right:
            new_x += 1;
            break;
    }
    if (CanMoveTo(new_x, new_y)) {
        Move(player.pos_x, player.pos_y, new_x, new_y);
        player.pos_x = new_x;
        player.pos_y = new_y;
        Update();
    }
}

void Grid::Update()
{
    if (!player.is_alive) return;

    // Check if player has found treasure
    std::size_t new_x = player.pos_x;
    std::size_t new_y = player.pos_y;
    if (treasure.pos_x == new_x && treasure.pos_y == new_y)
    {
        PlaceTreasure();
    }
}

void Grid::Move(std::size_t old_x, std::size_t old_y, std::size_t new_x, std::size_t new_y) {
    Type state = GetCellState(old_x, old_y);
    SetCellState(state, new_x, new_y);
    SetCellState(Type::Empty, old_x, old_y);
}

Type Grid::GetCellState(std::size_t x, std::size_t y) const {
    return global_state[y][x];
}
void Grid::SetCellState(Type new_state, std::size_t x, std::size_t y) {
    global_state[y][x] = new_state;
}
bool Grid::CellIsEmpty(std::size_t x, std::size_t y) const {
    Type cell_state = GetCellState(x, y);
    return (cell_state == Type::Empty);
}

const Grid2D &Grid::GlobalState() const {
    return global_state;
}

GridRow Grid::ParseLine(string line) {
    std::istringstream str_line(line);
    int n;
    char c;
    GridRow row;
    while (str_line >> n >> c && c == ',') {
        row.push_back(static_cast<Type>(n));
    }
    return row;
}

Grid2D Grid::ReadFile(string path) {
    Grid2D new_grid{};
    std::ifstream file_path(path);
    if (file_path) {
        string line;
        while (getline(file_path, line)) {
            GridRow row = ParseLine(line);
            new_grid.push_back(row);
        }
    } else {
        std::cerr << "Could not open file for reading." << std::endl;
    }
    return new_grid;
}

string Grid::ToString() const {
    if (global_state.empty()) {
        std::cerr << "WARNING [Grid::ToString]: Grid is empty, nothing to write." << std::endl;
        return "";
    } else {
        std::ostringstream oss;
        for (auto &row: global_state) {
            for (auto it = row.begin(); it != row.end(); ++it)
                oss << static_cast<int>(*it) << ",";
            oss << "\n";
        }
        return oss.str();
    }
}

std::ostream &operator<<(std::ostream &out, const Grid &grid) {
    return (out << grid.ToString());
}

bool Grid::FromFile(string file_path) {
    if (!global_state.empty())
        global_state.clear();
    global_state = ReadFile(file_path);
    if (global_state.empty()) {
        std::cerr << "Warning [Grid::FromFile]: Grid is empty." << std::endl;
        return false;
    } else
        return true;
}

bool Grid::ToFile(string file_path) {
    if (global_state.empty()) {
        std::cerr << "WARNING [Grid::ToFile]: Grid is empty, nothing to write." << std::endl;
        return false;
    } else {
        std::ofstream outfile(file_path);
        if (outfile) {
            for (auto &row: global_state) {
                for (auto it = row.begin(); it != row.end(); ++it) {
                    outfile << static_cast<int>(*it) << ",";
                }
                outfile << std::endl;
            }
            return true;
        } else {
            std::cerr << "WARNING [Grid::ToFile]: Could not open file for reading." << std::endl;
            return false;
        }
    }
}

// Equality
bool operator==(const Grid &g1, const Grid &g2) {
    return (g1.global_state == g2.global_state);
}

bool operator!=(const Grid &g1, const Grid &g2) {
    return (g1.global_state != g2.global_state);
}

