#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Engine.h"

#include <memory>

class Game{
    std::unique_ptr<Engine> engine;

public:
    typedef enum {
        mainMenu,
        optionsMenu,
        inGame
    } State;
    
    State currentState; //current state of the game

    Game();

    void runMainLoop();
    void handleEvents();
    void displayGame();
    void displayMainMenu();
    void displayOptionsMenu();
};

#endif
