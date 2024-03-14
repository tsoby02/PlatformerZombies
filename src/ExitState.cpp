//
// Created by csaba on 3/5/24.
//

#include "ExitState.h"

ExitState& ExitState::getInstance() {
    static ExitState instance;
    return instance;
}

void ExitState::enter(SDL_Renderer* renderer, int window_width, int window_height) {
    StateInterface::enter(renderer, window_width, window_height);
}

void ExitState::exit() {

}

StateInterface* ExitState::handleEvents(const SDL_Event& event) {
    return nullptr;
}

StateInterface* ExitState::update() {
    return nullptr;
}

void ExitState::render() {

}
