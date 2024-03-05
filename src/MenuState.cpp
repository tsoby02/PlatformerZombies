//
// Created by csaba on 3/5/24.
//

#include "MenuState.h"

MenuState& MenuState::getInstance() {
    static MenuState instance;
    return instance;
}

void MenuState::enter(SDL_Renderer* renderer, int screen_width, int screen_height) {
    StateInterface::enter(renderer, screen_width, screen_height);
}

void MenuState::exit() {

}

StateInterface* MenuState::handleEvents(const SDL_Event& event) {
    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_y) {
        return &ExitState::getInstance();
    }

    return nullptr;
}

StateInterface* MenuState::update() {
    return nullptr;
}

void MenuState::render() {

}
