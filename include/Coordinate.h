//
// Created by User on 04.03.2025.
//

#ifndef COORDINATE_H
#define COORDINATE_H
#include <iostream>
#include <stdexcept>

#endif //COORDINATE_H

struct Coordinate {
    Coordinate(const int file, const int rank) {
        if (!validate(file, rank)) {
            throw std::invalid_argument(
                "Invalid coordinates. File and rank must be between 0 and 7");
        }
        this->file_ = file;
        this->rank_ = rank;
    }

    Coordinate(const std::string &chessNotation) {
        if (!validate(chessNotation)) {
            throw std::invalid_argument(
                "Invalid chess notation. File must be between 'a' and 'h' and rank between '1' and '8'");
        }
        file_ = chessNotation[0] - 'a';
        rank_ = chessNotation[1] - '1';
    }

    [[nodiscard]] std::string toChessNotation() const {
        return std::string{static_cast<char>('a' + file_), static_cast<char>('1' + rank_)};
    }

    static bool validate(const std::string &chessNotation) {
        return chessNotation[0] >= 'a' && chessNotation[0] <= 'h' && chessNotation[1] >= '1' &&
               chessNotation[1] <= '8';
    }

    [[nodiscard]] int file() const {
        return file_;
    }

    [[nodiscard]] int rank() const {
        return rank_;
    }

private:
    int file_; //a-h
    int rank_; //1-8

    static bool validate(const int file, const int rank) {
        return file >= 0 && rank >= 0 && file < 8 && rank < 8;
    }
};
