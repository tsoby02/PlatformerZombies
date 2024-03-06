//
// Created by csaba on 3/5/24.
//

#include "Game.h"

Game::Game() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("ERROR: Could not initialize SDL!" + std::string(SDL_GetError()));
    }
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::cout << "WARNING: Linear texture filtering not enabled." << std::endl;
    }

    window = new Window("Platformer zombie geme", 640, 480);

    currentState = nullptr;
    nextState = nullptr;
}

Game::~Game() {
    delete window;
    SDL_Quit();
}

void Game::initStateMachine() {
    currentState = &gameState;
    currentState->enter(window->getRenderer(), window->getWidth(), window->getHeight());
}

void Game::setNextState(StateInterface* nextState) {
    if(this->nextState != &exitState) {
        this->nextState = nextState;
    }
}

void Game::changeState() {
    if(nextState != nullptr) {
        currentState->exit();
        nextState->enter(window->getRenderer(), window->getWidth(), window->getHeight());
        // it might be necessary to know the previous state in the next state's enter
        currentState = nextState;
        nextState = nullptr;
    }
}

void Game::handleEvents() {
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            setNextState(&exitState);
        }

        setNextState( currentState->handleEvents(event) );
    }
}

void Game::update() {
    setNextState( currentState->update() );
}

void Game::render() {
    SDL_SetRenderDrawColor(window->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(window->getRenderer());

    currentState->render();

    SDL_RenderPresent(window->getRenderer());
}
