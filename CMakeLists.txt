cmake_minimum_required(VERSION 4.1)
project(jogo_dos_palitos)

set(CMAKE_CXX_STANDARD 26)

add_executable(jogo_dos_palitos
        main.cpp
        Jogador.cpp
        Jogador.h
        Jogo.cpp
        Jogo.h)
