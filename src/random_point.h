//
// Created by Johannes Flieger on 01/09/2020.
//

#ifndef SDLGRID_RANDOM_POINT_H
#define SDLGRID_RANDOM_POINT_H

#include <random>
#include <tuple>

class RandomPoint {
    std::random_device rand_dev;
    std::mt19937 rand_eng;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

public:
    RandomPoint(std::size_t grid_width, std::size_t  grid_height);
    std::tuple<std::size_t, std::size_t> Generate();
};

#endif
