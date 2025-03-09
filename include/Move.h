//
// Created by User on 09.03.2025.
//

#ifndef MOVE_H
#define MOVE_H
#include "Coordinate.h"


struct Move {
    Coordinate source;
    Coordinate destination;

    Move(const Coordinate source, const Coordinate destination): source(source),
                                                                 destination(destination) {
    }
};


#endif //MOVE_H
