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

    texture.loadFromFile(renderer, "../assets/test2.png");
}

void GameState::exit() {

}

StateInterface* GameState::handleEvents(const SDL_Event& event) {
    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_y) {
        return &ExitState::getInstance();
    }

    return nullptr;
}

StateInterface* GameState::update() {
    return nullptr;
}

void GameState::render() {
    texture.render(renderer, 0, 0);
}
