//
// Created by Johannes Flieger on 11/05/2020.
//

#ifndef SDLGRID_GAME_OBJECTS_H
#define SDLGRID_GAME_OBJECTS_H

#include <iostream>
#include <string>

enum class Type
{
    Empty,
    Obstacle,
    Player,
    Treasure
};

struct Entity {
    std::size_t pos_x{0};
    std::size_t pos_y{0};
};

struct Player {
    Type  type;
    std::size_t pos_x{0};
    std::size_t pos_y{0};
    bool is_alive{true};
    Player(): type{Type::Player}{ std::cout << "Player object has been created: " << (Type::Player == this->type) << std::endl; };
};

struct Treasure {
    Type  type;
    int value_{100};
    std::size_t pos_x{0};
    std::size_t pos_y{0};
    Treasure(): type{Type::Treasure}{ std::cout << "Treasure object has been created: " << (Type::Treasure == this->type) << std::endl; };
};

#endif
