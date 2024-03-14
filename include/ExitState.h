//
// Created by csaba on 3/5/24.
//

#ifndef EXITSTATE_H
#define EXITSTATE_H

// base class
#include "StateInterface.h"

class ExitState : public StateInterface {
private:
    ExitState() = default;

public:
    // singleton pattern
    ExitState(const ExitState&) = delete;
    ExitState& operator= (const ExitState&) = delete;
    static ExitState& getInstance();

    void enter(SDL_Renderer* renderer, int window_width, int window_height) override;
    void exit() override;

    StateInterface* handleEvents(const SDL_Event& event) override;
    StateInterface* update() override;
    void render() override;
};



#endif //EXITSTATE_H
