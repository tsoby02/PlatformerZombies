//
// Created by csaba on 3/5/24.
//

#ifndef STATEINTERFACE_H
#define STATEINTERFACE_H

#include <SDL.h>

class StateInterface {
protected:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    SDL_Renderer* renderer;

public:
    virtual void enter(SDL_Renderer* renderer, int screen_width, int screen_height) {
        SCREEN_WIDTH = screen_width;
        SCREEN_HEIGHT = screen_height;
        this->renderer = renderer;
    }
    virtual void exit() = 0;

    virtual StateInterface* handleEvents(const SDL_Event& event) = 0;
    virtual StateInterface* update() = 0;
    virtual void render() = 0;

    virtual ~StateInterface() = default;

};

#endif //STATEINTERFACE_H
