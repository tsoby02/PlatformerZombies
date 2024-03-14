//
// Created by csaba on 3/5/24.
//

#ifndef STATEINTERFACE_H
#define STATEINTERFACE_H

#include <SDL.h>

class StateInterface {
protected:
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
    SDL_Renderer* renderer;

public:
    virtual void enter(SDL_Renderer* renderer, int window_width, int window_height) {
        WINDOW_WIDTH = window_width;
        WINDOW_HEIGHT = window_height;
        this->renderer = renderer;
    }
    virtual void exit() = 0;

    virtual StateInterface* handleEvents(const SDL_Event& event) = 0;
    virtual StateInterface* update() = 0;
    virtual void render() = 0;

    virtual ~StateInterface() = default;

};

#endif //STATEINTERFACE_H
