//
// Created by User on 04.03.2025.
//

#ifndef BOARD_H
#define BOARD_H
#include <memory>


#include "Piece.h"


class Board {
public:
    Board();

    ~Board() = default;

    void initialize();

    void display() const;

    void executeMove(const Coordinate &source, const Coordinate &destination);

    void restart();

private:
    std::unique_ptr<Piece> board_[8][8];
};


#endif //BOARD_H
