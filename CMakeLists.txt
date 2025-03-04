cmake_minimum_required(VERSION 3.16)
project(Chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chess
        main.cpp
        src/Board.cpp
        src/Piece.cpp
        src/Pawn.cpp
        src/King.cpp
        src/Queen.cpp
        src/Bishop.cpp
        src/Knight.cpp
        src/Rook.cpp
)

target_include_directories(Chess PRIVATE include)