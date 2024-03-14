//
// Created by csaba on 3/5/24.
//

#ifndef MENUSTATE_H
#define MENUSTATE_H

// base class
#include "StateInterface.h"
#include "ExitState.h"

class MenuState : public StateInterface {
private:
    MenuState() = default;

public:
    // singleton pattern
    MenuState(const MenuState&) = delete;
    MenuState& operator= (const MenuState&) = delete;
    static MenuState& getInstance();

    void enter(SDL_Renderer* renderer, int window_width, int window_height) override;
    void exit() override;

    StateInterface* handleEvents(const SDL_Event& event) override;
    StateInterface* update() override;
    void render() override;
};



#endif //MENUSTATE_H
