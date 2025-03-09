//
// Created by User on 04.03.2025.
//

#ifndef PIECE_H
#define PIECE_H
#include <string>
#include "Coordinate.h"

enum class Color {
    WHITE,
    BLACK
};

/**
 * @class Piece
 * @brief Base class for all chess pieces
 */
class Piece {
public:
    explicit Piece(Color color);

    virtual ~Piece() = default;

    [[nodiscard]] char name() const { return name_; }

    // virtual bool validateMove(const Coordinate &source, const Coordinate &target) = 0;

protected:
    char name_;
    Color color_;
};


#endif //PIECE_H
