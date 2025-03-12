//
// Created by User on 09.03.2025.
//

#ifndef GAME_H
#define GAME_H
#include <vector>
#include <Board.h>
#include <Move.h>
#include <unordered_set>

#include "Handler.h"


enum class GameStatus {
    NEW,
    IN_PROGRESS,
    CHECK,
    CHECK_MATE,
    STALE_MATE,
    DRAW
};

class Game {
public:
    Game();

    void start();

    void restart();

    void exit();

    void printStatus() const;

private:
    Color _currentPlayer = Color::WHITE;
    Board _board = Board();
    GameStatus _status = GameStatus::NEW;
    std::pmr::vector<Move> _moves;

    std::unique_ptr<Handler> moveValidator_;
    static const std::unordered_set<PieceType> PROMOTION_PIECES;

    static Move readMove();

    static std::string readUserInput();

    PieceType getPromotionPieceTypeFromPlayer() const;

    void displayPromotionInfo() const;

    static void displayPromotionError();

    std::pair<Coordinate<>, Coordinate<> > parseMove(const std::string &input);

    bool validateMove(Move &move) const;

    // Move moveParse(Coordinate &source, Coordinate &destination);

    void switchPlayer();

    void updateGameStatus();

    static void printInvalidMove();
};


#endif //GAME_H
