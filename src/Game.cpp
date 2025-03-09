//
// Created by User on 09.03.2025.
//

#include "Game.h"

#include <sstream>

void Game::start() {
    _status = GameStatus::IN_PROGRESS;

    while (_status == GameStatus::IN_PROGRESS) {
        printStatus();
        auto [source, destination] = readMove();
        _board.executeMove(source, destination);
    }
}

void Game::restart() {
    _board.restart();
    _currentPlayer = Color::WHITE;
    start();
}

void Game::printStatus() {
    switch (_status) {
        case GameStatus::IN_PROGRESS: {
            _board.display();
            std::cout << "Current player: " << (_currentPlayer == Color::WHITE ? "White" : "Black")
                << "\n";
            break;
        }
        default: ;
    }
}

std::pair<Coordinate, Coordinate> Game::readMove() {
    std::string input;
    while (true) {
        std::cout << "Enter move";
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::string source, destination;

        if (!(iss >> source >> destination)
            || !Coordinate::validate(source)
            || !Coordinate::validate(destination)) {
            std::cout << "Invalid format! Use notation like 'e2 e4'.\n";
        } else {
            return std::make_pair(source, destination);
        }
    }
}

//
// std::pair<Coordinate, Coordinate> Game::parseMove(const std::string& input) {
//
//     if (!(iss >> from >> to)) {
//         std::cout << "Invalid format! Use notation like 'e2 e4'.\n";
//         return std::make_pair(Coordinate(0, 0), Coordinate(0, 0));
//         return {"", ""}; // Return empty strings to indicate failure
//     }
//
//     return {from, to};
// }