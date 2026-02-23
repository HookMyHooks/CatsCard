qt_standard_project_setup()

qt_add_executable(Frontend
    main.cpp
    StartWindow.cpp
    EndGame.cpp

    StartWindow.h
    EndGame.h
    StartWindow.ui
    EndGame.ui

    ../FrontEnd/FrontEnd.ui
    ../FrontEnd/CursorUtil.cpp
    ../FrontEnd/CursorUtil.h
    ../FrontEnd/FrontEnd.cpp
    ../FrontEnd/FrontEnd.h
)

qt_add_resources(Frontend app_resources
    PREFIX "/cards"
    FILES
        ../FrontEnd/button_exit.png
        ../FrontEnd/button_play.png
        ../FrontEnd/card_2.png
        ../FrontEnd/card_3.png
        ../FrontEnd/card_4.png
        ../FrontEnd/card_5.png
        ../FrontEnd/card_6.png
        ../FrontEnd/card_7.png
        ../FrontEnd/card_8.png
        ../FrontEnd/card_9.png
        ../FrontEnd/card_10.png
        ../FrontEnd/card_back.png
        ../FrontEnd/card_j.png
        ../FrontEnd/card_k.png
        ../FrontEnd/card_q.png
        ../FrontEnd/card_a.png
        ../FrontEnd/button_hold.png
        ../FrontEnd/logo.png
        ../FrontEnd/cursor.png
)

qt_add_resources(Frontend app_resources_endgame
    PREFIX "/endgame"
    FILES
        ../FrontEnd/winCard_player1.png
        ../FrontEnd/winCard_player2.png
        ../FrontEnd/draw.png
        ../FrontEnd/background_start.png
)

target_link_libraries(Frontend
    PRIVATE
        Qt6::Widgets
        BlackJack
)
