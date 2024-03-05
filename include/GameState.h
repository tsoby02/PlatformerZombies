//
// Created by csaba on 3/6/24.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H

// base class
#include "StateInterface.h"

class GameState : public StateInterface {
private:
    GameState() = default;

public:
    // singleton pattern
    GameState(const GameState&) = delete;
    GameState& operator= (const GameState&) = delete;
    static GameState& getInstance();

    void enter(SDL_Renderer* renderer, int screen_width, int screen_height) override;
    void exit() override;

    StateInterface* handleEvents(const SDL_Event& event) override;
    StateInterface* update() override;
    void render() override;
};



#endif //GAMESTATE_H
