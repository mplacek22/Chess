#include <iostream>

#include "Game.h"
#include "include/Board.h"

int main() {
    // const Board board;
    // board.display();

    // const auto a1 = Coordinate(0, 0);
    // std::cout << a1.toChessNotation() << std::endl;
    // const auto h8 = Coordinate(7, 7);
    // std::cout << h8.toChessNotation() << std::endl;
    // const Coordinate c2{"c2"};
    // std::cout << c2.toChessNotation() << std::endl;

    Game game;
    game.start();

    return 0;
}
