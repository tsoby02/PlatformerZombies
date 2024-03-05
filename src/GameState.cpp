//
// Created by csaba on 3/6/24.
//

#include "GameState.h"

GameState& GameState::getInstance() {
    static GameState instance;
    return instance;
}

void GameState::enter(SDL_Renderer* renderer, int screen_width, int screen_height) {
    StateInterface::enter(renderer, screen_width, screen_height);
}

void GameState::exit() {

}

StateInterface* GameState::handleEvents(const SDL_Event& event) {
    return nullptr;
}

StateInterface* GameState::update() {
    return nullptr;
}

void GameState::render() {

}
