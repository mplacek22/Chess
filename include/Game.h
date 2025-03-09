//
// Created by User on 09.03.2025.
//

#ifndef GAME_H
#define GAME_H
#include <Board.h>
#include <Piece.h>


enum class GameStatus {
    NEW,
    IN_PROGRESS,
    PAT,
    CHECK,
    CHECK_MATE
};

class Game {
public:
    void start();

    void restart();

    void exit();

    void printStatus();

    static std::pair<Coordinate, Coordinate> readMove();

private:
    Color _currentPlayer = Color::WHITE;
    Board _board = Board();
    GameStatus _status = GameStatus::NEW;

    std::pair<Coordinate, Coordinate> parseMove(const std::string& input);
};


#endif //GAME_H
