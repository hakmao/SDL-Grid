//
// Created by Johannes Flieger on 11/05/2020.
//

#ifndef SDLGRID_ENTITY_H
#define SDLGRID_ENTITY_H

enum class Type { Entity, Player, Treasure };

class Entity {
public:
    std::size_t pos_x{0};
    std::size_t pos_y{0};
    Type type{Type::Entity};
};

class Player : public Entity {
public:
    bool is_alive{true};
    Type type{Type::Player};
};

class Treasure: public Entity {
public:
    Type type{Type::Treasure};
};



#endif
