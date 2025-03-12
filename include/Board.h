//
// Created by User on 04.03.2025.
//

#ifndef BOARD_H
#define BOARD_H
#include <Coordinate.h>
#include <memory>


#include "Move.h"
#include "Piece.h"


class Board {
public:
    static constexpr int BOARD_SIZE = 8;

    Board();

    ~Board() = default;

    void initialize();

    void display() const;

    void executeMove(const Move &move);

    [[nodiscard]] bool validateMove(const Coordinate<> &source, const Coordinate<> &destination) const;

    void restart();

    [[nodiscard]] std::shared_ptr<Piece> getPieceAt(const Coordinate<> &coordinate) const;

private:
    std::shared_ptr<Piece> board_[BOARD_SIZE][BOARD_SIZE];
};


#endif //BOARD_H
