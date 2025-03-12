//
// Created by User on 04.03.2025.
//

#include "../include/Board.h"


#include <iostream>
#include <string>

#include "../include/Bishop.h"
#include "../include/Knight.h"
#include "../include/Pawn.h"
#include "../include/Queen.h"
#include "../include/Rook.h"

Board::Board() {
    initialize();
}

void Board::initialize() {
    board_[0][0] = std::make_shared<Rook>(Color::WHITE);
    board_[0][1] = std::make_shared<Knight>(Color::WHITE);
    board_[0][2] = std::make_shared<Bishop>(Color::WHITE);
    board_[0][3] = std::make_shared<Queen>(Color::WHITE);
    board_[0][4] = std::make_shared<Knight>(Color::WHITE);
    board_[0][5] = std::make_shared<Bishop>(Color::WHITE);
    board_[0][6] = std::make_shared<Knight>(Color::WHITE);
    board_[0][7] = std::make_shared<Rook>(Color::WHITE);

    for (int i = 0; i < 8; ++i) {
        board_[1][i] = std::make_shared<Pawn>(Color::WHITE);
        board_[6][i] = std::make_shared<Pawn>(Color::BLACK);
    }

    board_[7][0] = std::make_shared<Rook>(Color::BLACK);
    board_[7][1] = std::make_shared<Knight>(Color::BLACK);
    board_[7][2] = std::make_shared<Bishop>(Color::BLACK);
    board_[7][3] = std::make_shared<Queen>(Color::BLACK);
    board_[7][4] = std::make_shared<Knight>(Color::BLACK);
    board_[7][5] = std::make_shared<Bishop>(Color::BLACK);
    board_[7][6] = std::make_shared<Knight>(Color::BLACK);
    board_[7][7] = std::make_shared<Rook>(Color::BLACK);
}

void Board::display() const {
    std::cout << "   a b c d e f g h\n  -----------------" << std::endl;
    for (int i = 7; i >= 0; --i) {
        std::string line = std::to_string(i + 1) + "| ";
        for (int j = 0; j < 8; ++j) {
            if (board_[i][j] != nullptr) {
                line += board_[i][j]->name();
            } else
                line += '.';
            line += ' ';
        }
        line += '|' + std::to_string(i + 1);
        std::cout << line << std::endl;
    }
    std::cout << "  -----------------\n   a b c d e f g h" << std::endl;
}

void Board::executeMove(const Move& move) {
    switch (move.moveType) {
        case MoveType::NORMAL:
        case MoveType::CAPTURE: {
            board_[move.destination.rank()][move.destination.file()] = std::move(
                board_[move.source.rank()][move.source.file()]);
            break;
        }
        case MoveType::PROMOTION: {
            board_[move.destination.rank()][move.destination.file()] = Piece::create(
                getPieceAt(move.source)->color(), move.promotionPieceType);
            board_[move.source.rank()][move.source.file()] = nullptr;
            break;
        }
        default: {
        }
        // case MoveType::CASTLING: {
        // }
    }
}


// void Board::executeMove(const Coordinate<>& source, const Coordinate<>& destination) {
//     if (board_[source.rank()][source.file()] == nullptr) {
//         throw std::invalid_argument("There is no piece on source coordinate");
//     }
//     board_[destination.rank()][destination.file()] =
//         std::move(board_[source.rank()][source.file()]);
// }

bool Board::validateMove(const Coordinate<>& source, const Coordinate<>& destination) const {
    if (board_[source.rank()][source.file()] == nullptr || board_[destination.rank()][destination.
            file()] == nullptr) {
        return false;
    }
    return true;
}


void Board::restart() {
    initialize();
}

std::shared_ptr<Piece> Board::getPieceAt(const Coordinate<>& coordinate) const {
    return board_[coordinate.rank()][coordinate.file()];
}
