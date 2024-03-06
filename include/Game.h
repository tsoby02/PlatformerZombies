//
// Created by csaba on 3/5/24.
//

#ifndef GAME_H
#define GAME_H

// includes
#include <iostream>
#include <stdexcept>
#include <string>

// SDL
#include <SDL.h>

// local includes
#include "Window.h"
#include "StateInterface.h"
#include "MenuState.h"
#include "GameState.h"
#include "ExitState.h"

class Game {
private:
    Window* window;
    SDL_Event event;

    // state machine
    StateInterface* currentState;
    StateInterface* nextState;
    MenuState& menuState = MenuState::getInstance();
    GameState& gameState = GameState::getInstance();
    ExitState& exitState = ExitState::getInstance();



public:
    Game();
    ~Game();

    [[nodiscard]] StateInterface* getCurrentState() const { return currentState; }
    [[nodiscard]] StateInterface* getExitState() const { return &exitState; }

    void initStateMachine();
    void setNextState(StateInterface* nextState);
    void changeState();

    void handleEvents();
    void update();
    void render();
};



#endif //GAME_H
