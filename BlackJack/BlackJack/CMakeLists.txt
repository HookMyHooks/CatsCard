add_library(BlackJack STATIC
    Card.cpp
    Deck.cpp
    Game.cpp

    Card.h
    Deck.h
    Game.h

    ENumber.h
    EPlayer.h
    EState.h
    EValue.h
    IGame.h
    IGameListener.h
)

target_include_directories(BlackJack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
