//
// Created by Johannes Flieger on 01/09/2020.
//

#include "random_point.h"

RandomPoint::RandomPoint(std::size_t grid_width, std::size_t grid_height)
: rand_eng{ rand_dev()},
random_w{0, static_cast<int>(grid_width)},
random_h{0, static_cast<int>(grid_height)}
{}

std::tuple<std::size_t, std::size_t> RandomPoint::Generate()
{
    std::size_t x = static_cast<std::size_t>( random_w(rand_eng));
    std::size_t y = static_cast<std::size_t>(random_h(rand_eng));

    return std::make_tuple(x,y);
}