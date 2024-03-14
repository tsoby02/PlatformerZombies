//
// Created by csaba on 3/6/24.
//

#include "GameState.h"

GameState& GameState::getInstance() {
    static GameState instance;
    return instance;
}

void GameState::enter(SDL_Renderer* renderer, int window_width, int window_height) {
    StateInterface::enter(renderer, window_width, window_height);

    SCREEN_WIDTH = 854;
    SCREEN_HEIGHT = 480;

    scaleX = 1.0f * WINDOW_WIDTH / SCREEN_WIDTH;
    scaleY = 1.0f * WINDOW_HEIGHT / SCREEN_HEIGHT;

    background1.loadFromFile(renderer, "../assets/cave_tileset/background1.png");
    background2.loadFromFile(renderer, "../assets/cave_tileset/background2.png");
    background3.loadFromFile(renderer, "../assets/cave_tileset/background3.png");
    background4.loadFromFile(renderer, "../assets/cave_tileset/background4b.png");
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
    SDL_RenderSetScale(renderer, scaleX, scaleY);

    background1.render(renderer, 0, 0);
    background2.render(renderer, 0, 0);
    background3.render(renderer, 0, 0);
    background4.render(renderer, 0, 0);

    SDL_RenderSetScale(renderer, 1, 1);
}
