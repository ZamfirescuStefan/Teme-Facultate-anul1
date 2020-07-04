cmake_minimum_required(VERSION 3.15)
project(Tema_2_Poo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++11 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2")
add_executable(Tema_2_Poo main.cpp Vector.cpp Vector.h Lista.cpp Lista.h Matrice.cpp Matrice.h Graf.cpp Graf.h Graf_neorientat.cpp Graf_neorientat.h Graf_orientat.cpp Graf_orientat.h)