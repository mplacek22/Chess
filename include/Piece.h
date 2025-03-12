//
// Created by User on 04.03.2025.
//

#ifndef PIECE_H
#define PIECE_H
#include <map>
#include <memory>
#include <string>
#include <unordered_map>

enum class Color {
    WHITE,
    BLACK
};

enum class PieceType {
    BISHOP = 'B',
    KING = 'K',
    KNIGHT = 'N',
    PAWN = 'P',
    QUEEN = 'Q',
    ROOK = 'R'
};

/**
 * @class Piece
 * @brief Base class for all chess pieces
 */
// template<typename BoardRepresentationType>
class Piece {
public:
    explicit Piece(Color color);

    static std::shared_ptr<Piece> create(Color color, PieceType pieceType);

    virtual ~Piece() = default;

    [[nodiscard]] char name() const { return name_; }

    [[nodiscard]] PieceType type() const { return type_; }

    [[nodiscard]] Color color() const { return color_; }

    static PieceType charToPieceType(char name);

    // virtual bool validateMove(Move &move, BoardRepresentationType &board) = 0;

protected:
    char name_;
    Color color_;
    PieceType type_;
    static const std::unordered_map<char, PieceType> PIECE_TYPE_MAP;

private:
};


#endif //PIECE_H
