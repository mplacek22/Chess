//
// Created by User on 09.03.2025.
//

#include "Game.h"

#include <sstream>

#include "PieceOwnershipHandler.h"
#include "SourcePieceHandler.h"
#include "SpecialMoveHandler.h"


Game::Game() {
    auto pieceMove = std::make_unique<SourcePieceHandler>();
    auto ownershipValidator = std::make_unique<OwnershipValidationHandler>();
    auto specialMoveHandler = std::make_unique<SpecialMoveHandler>();

    ownershipValidator->setNext(std::move(specialMoveHandler));
    pieceMove->setNext(std::move(ownershipValidator));

    moveValidator_ = std::move(pieceMove);
}

void Game::start() {
    _status = GameStatus::IN_PROGRESS;

    while (_status == GameStatus::IN_PROGRESS) {
        printStatus();
        if (auto move = readMove(); validateMove(move)) {
            if (move.moveType == MoveType::PROMOTION) {
                move.promotionPieceType = getPromotionPieceTypeFromPlayer();
            }
            _board.executeMove(move);
            updateGameStatus();
            switchPlayer();
        } else {
            printInvalidMove();
        }
    }
}

void Game::restart() {
    _board.restart();
    _currentPlayer = Color::WHITE;
    start();
}

void Game::printStatus() const {
    switch (_status) {
        case GameStatus::IN_PROGRESS: {
            _board.display();
            std::cout << "Current player: " << (_currentPlayer == Color::WHITE ? "White" : "Black")
                << std::endl;
            break;
        }
        default: ;
    }
}

Move Game::readMove() {
    std::string input;
    while (true) {
        std::cout << "Enter move" << std::endl;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::string source, destination;

        if (!(iss >> source >> destination)
            || !Coordinate<>::validate(source)
            || !Coordinate<>::validate(destination)) {
            std::cout << "Invalid format! Use notation like 'e2 e4'." << std::endl;
        } else {
            return {Coordinate(source), Coordinate(destination)};
        }
    }
}

std::string Game::readUserInput() {
    std::string userInput;
    std::cin >> userInput;
    return userInput;
}

PieceType Game::getPromotionPieceTypeFromPlayer() const {
    while (true) {
        displayPromotionInfo();
        if (auto userInput = readUserInput(); userInput.size() == 1) {
            try {
                if (PieceType promotionPieceType = Piece::charToPieceType(userInput[0]);
                    PROMOTION_PIECES.contains(promotionPieceType))
                    return promotionPieceType;
                displayPromotionError();
            } catch ([[maybe_unused]] const std::invalid_argument& e) {
                displayPromotionError();
            }
        }
    }
}

// Move Game::moveParse(Coordinate<>& source, Coordinate<>& destination) {
// }

void Game::displayPromotionInfo() const {
    std::cout <<
        "Choose piece type you want to promote the pawn to.\nWrite single letter from this selection [Q, N, R, B]"
        << std::endl;
}

void Game::displayPromotionError() {
    std::cout << "Invalid promotion piece type!" << std::endl;
}

bool Game::validateMove(Move& move) const {
    return moveValidator_->handle(move, std::as_const(_board), _currentPlayer);
}


void Game::switchPlayer() {
    _currentPlayer = _currentPlayer == Color::WHITE ? Color::BLACK : Color::WHITE;
}

void Game::updateGameStatus() {
    //todo
}

void Game::printInvalidMove() {
    std::cout << "Invalid move. Try again" << std::endl;
}

const std::unordered_set<PieceType> Game::PROMOTION_PIECES = {
    PieceType::QUEEN, PieceType::ROOK, PieceType::BISHOP, PieceType::KNIGHT
};