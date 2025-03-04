cmake_minimum_required(VERSION 3.29)
project(Chess)

set(CMAKE_CXX_STANDARD 26)

add_executable(Chess main.cpp
        Board.cpp
        Board.h
        Piece.cpp
        Piece.h
        Pawn.cpp
        Pawn.h
        King.cpp
        King.h
        Queen.cpp
        Queen.h
        Bishop.cpp
        Bishop.h
        Knight.cpp
        Knight.h
        Root.cpp
        Root.h)
