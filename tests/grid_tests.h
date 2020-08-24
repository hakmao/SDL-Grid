//
// Created by Johannes Flieger on 19/01/2020.
//

#ifndef GRID_TESTS_H
#define GRID_TESTS_H

#include "grid.h"

namespace grid_tests
{
    // Sample grids
    std::size_t const sample_grid_1_rows = 5;
    std::size_t const sample_grid_1_cols = 6;
    std::size_t const sample_grid_1_size = 5 * 6;
    vector<vector<State>> const sample_grid_1 = {
            { State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle },
            { State::Obstacle, State::Player,   State::Obstacle, State::Empty,    State::Empty,   State::Obstacle },
            { State::Obstacle, State::Empty,    State::Obstacle, State::Empty,    State::Obstacle, State::Obstacle },
            { State::Obstacle, State::Empty,    State::Empty,    State::Treasure,     State::Empty,    State::Obstacle },
            { State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle }};

    vector<vector<State>> const sample_grid_2 = {
            { State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle },
            { State::Obstacle, State::Treasure,     State::Obstacle, State::Empty,  State::Empty,   State::Obstacle },
            { State::Obstacle, State::Empty,    State::Obstacle, State::Empty,    State::Empty,    State::Obstacle },
            { State::Obstacle, State::Player,   State::Empty,    State::Empty,    State::Empty,    State::Obstacle },
            { State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle, State::Obstacle }};

    // Test file name
    std::string const testfile( "test.grid");
}
#endif
