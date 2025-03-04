//
// Created by User on 04.03.2025.
//

#ifndef PIECE_H
#define PIECE_H
#include <string>

enum class Color {
    WHITE,
    BLACK
};

class Piece {
    public:
    explicit Piece(Color color);
    virtual ~Piece() = default;

    [[nodiscard]] char name() const { return name_; }
    // virtual bool validateMove() = 0;

protected:
    char name_;
private:
    Color color_;
};



#endif //PIECE_H
