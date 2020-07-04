cmake_minimum_required(VERSION 3.16)
project(Tema_3_POO)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ASM_FLAGS "-Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2")
add_executable(Tema_3_POO main.cpp ContBancar.cpp ContBancar.h Exception.cpp Exception.h ContEconomii.cpp ContEconomii.h ContCurent.cpp ContCurent.h GestionareConturi.cpp GestionareConturi.h Data.cpp Data.h)