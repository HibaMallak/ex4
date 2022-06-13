cmake_minimum_required(VERSION 3.20)
project(untitled3)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled3 main.cpp  Mtmchkin.cpp Mtmchkin.h Barfight.cpp Barfight.h Card.cpp Card.h Dragon.cpp Dragon.h
        Exception.h Fairy.cpp Fairy.h Fighter.cpp Fighter.h Goblin.cpp Goblin.h Merchant.cpp Merchant.h
        Pitfall.h Pitfall.cpp Player.cpp Player.h Rogue.cpp Rogue.h test.cpp Treasure.cpp Treasure.h utilities.cpp
        utilities.h Vampire.cpp Vampire.h Wizard.h Wizard.cpp Queue.h)
