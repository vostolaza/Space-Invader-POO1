cmake_minimum_required(VERSION 3.14)
project(Proyecto)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Proyecto main.cpp CGame.cpp CGame.h Turret.cpp Turret.h Alien.cpp Alien.h Crab.cpp Crab.h Bala.cpp Bala.h
        Octopus.cpp Octopus.h UFunciones.cpp UFunciones.h Score.cpp Score.h UFO.cpp UFO.h)

target_link_libraries(Proyecto -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system)