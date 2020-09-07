//
// Created by Johannes Flieger on 11/05/2020.
//

#ifndef SDLGRID_ENTITY_H
#define SDLGRID_ENTITY_H

#include <iostream>
#include <string>

enum class EntityType {
    Player,
    Treasure
};

class Entity {
public:
    std::size_t pos_x{0};
    std::size_t pos_y{0};
    EntityType GetType() const;
};

class Player {
    EntityType  type_{EntityType::Player};
public:
    std::size_t pos_x{0};
    std::size_t pos_y{0};
    bool is_alive{true};
    Player(): type_{EntityType::Player}{ std::cout << "Player object has been created: " << (EntityType::Player == this->type_) << std::endl; };
    EntityType  GetType() const { return type_; };
};

class Treasure {
    EntityType  type_{EntityType::Treasure};
    int value_{100};
public:
    std::size_t pos_x{0};
    std::size_t pos_y{0};
    Treasure(){ std::cout << "Treasure object has been created: " << (EntityType::Treasure == this->type_) << std::endl; };
    EntityType  GetType() const { return type_; };
};

#endif
