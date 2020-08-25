cmake_minimum_required(VERSION 3.16)
project(serpientesEscaleras)

set(CMAKE_CXX_STANDARD 14)

add_executable(serpientesEscaleras MyGame.cpp MyGame.h Player.cpp Player.h Board.cpp Board.h Case.cpp Case.h dado.cpp dado.h snakes.cpp Snake.cpp Snake.h Ladder.cpp Ladder.h MyException.cpp MyException.h)