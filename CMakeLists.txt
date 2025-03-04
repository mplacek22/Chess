cmake_minimum_required(VERSION 3.29)
project(Chess)

set(CMAKE_CXX_STANDARD 26)

add_executable(Chess main.cpp
        src/Board.cpp
        include/Board.h
        src/Piece.cpp
        include/Piece.h
        src/Pawn.cpp
        include/Pawn.h
        src/King.cpp
        include/King.h
        src/Queen.cpp
        include/Queen.h
        src/Bishop.cpp
        include/Bishop.h
        src/Knight.cpp
        include/Knight.h
        src/Root.cpp
        include/Root.h)
