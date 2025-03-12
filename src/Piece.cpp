//
// Created by User on 04.03.2025.
//

#include "../include/Piece.h"

#include <Bishop.h>
#include <King.h>
#include <Knight.h>
#include <Pawn.h>
#include <Queen.h>
#include <Rook.h>

#include <stdexcept>

Piece::Piece(const Color color) {
    color_ = color;
}

std::shared_ptr<Piece> Piece::create(Color color, const PieceType pieceType) {
    switch (pieceType) {
        case PieceType::PAWN:
            return std::make_shared<Pawn>(color);
        case PieceType::KNIGHT:
            return std::make_shared<Knight>(color);
        case PieceType::BISHOP:
            return std::make_shared<Bishop>(color);
        case PieceType::ROOK:
            return std::make_shared<Rook>(color);
        case PieceType::KING:
            return std::make_shared<King>(color);
        case PieceType::QUEEN:
            return std::make_shared<Queen>(color);
        default:
            return nullptr;
    }
}

PieceType Piece::charToPieceType(const char name) {
    if (PIECE_TYPE_MAP.contains(name))
        return PIECE_TYPE_MAP.find(name)->second;
    throw std::invalid_argument("No such piece type");
}

const std::unordered_map<char, PieceType> Piece::PIECE_TYPE_MAP = {
    {'N', PieceType::KNIGHT},
    {'B', PieceType::BISHOP},
    {'R', PieceType::ROOK},
    {'Q', PieceType::QUEEN},
    {'P', PieceType::PAWN},
    {'K', PieceType::KING}

};

