//
// Created by User on 04.03.2025.
//

#include "../include/Board.h"

#include <iostream>

#include "../include/Bishop.h"
#include "../include/Knight.h"
#include "../include/Pawn.h"
#include "../include/Queen.h"
#include "../include/Rook.h"

Board::Board() {
    initialize();
}

Board::~Board() {
    //todo
}

void Board::initialize() {
    board_[0][0] = std::make_unique<Rook>(Color::WHITE);
    board_[0][1] = std::make_unique<Knight>(Color::WHITE);
    board_[0][2] = std::make_unique<Bishop>(Color::WHITE);
    board_[0][3] = std::make_unique<Queen>(Color::WHITE);
    board_[0][4] = std::make_unique<Knight>(Color::WHITE);
    board_[0][5] = std::make_unique<Bishop>(Color::WHITE);
    board_[0][6] = std::make_unique<Knight>(Color::WHITE);
    board_[0][7] = std::make_unique<Rook>(Color::WHITE);

    for (int i = 0; i < 8; ++i) {
        board_[1][i] = std::make_unique<Pawn>(Color::WHITE);
        board_[6][i] = std::make_unique<Pawn>(Color::BLACK);
    }

    board_[7][0] = std::make_unique<Rook>(Color::BLACK);
    board_[7][1] = std::make_unique<Knight>(Color::BLACK);
    board_[7][2] = std::make_unique<Bishop>(Color::BLACK);
    board_[7][3] = std::make_unique<Queen>(Color::BLACK);
    board_[7][4] = std::make_unique<Knight>(Color::BLACK);
    board_[7][5] = std::make_unique<Bishop>(Color::BLACK);
    board_[7][6] = std::make_unique<Knight>(Color::BLACK);
    board_[7][7] = std::make_unique<Rook>(Color::BLACK);
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
