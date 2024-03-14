//
// Created by csaba on 3/6/24.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H

// SDL
#include <SDL.h>

// local includes
#include "StateInterface.h"
#include "ExitState.h"
#include "Texture.h"

class GameState : public StateInterface {
private:
    GameState() = default;

    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;

    float scaleX, scaleY;

    Texture background1;
    Texture background2;
    Texture background3;
    Texture background4;

public:
    // singleton pattern
    GameState(const GameState&) = delete;
    GameState& operator= (const GameState&) = delete;
    static GameState& getInstance();

    void enter(SDL_Renderer* renderer, int window_width, int window_height) override;
    void exit() override;

    StateInterface* handleEvents(const SDL_Event& event) override;
    StateInterface* update() override;
    void render() override;
};



#endif //GAMESTATE_H
