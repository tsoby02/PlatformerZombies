//
// Created by csaba on 3/5/24.
//

#ifndef WINDOW_H
#define WINDOW_H

// includes
#include <stdexcept>
#include <string>

// SDL
#include <SDL.h>

class Window {
private:
    int window_width;
    int window_height;
    const char* window_title;

    Uint32 windowID;
    bool fullscreen;
    bool vsync;

    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Window(const char* title, int width, int height);
    ~Window();

    [[nodiscard]] SDL_Renderer* getRenderer() const { return renderer; }
    [[nodiscard]] int getWidth() const { return window_width; }
    [[nodiscard]] int getHeight() const { return window_height; }

    void resize(int new_width, int new_height);
    void handleEvents(const SDL_Event& event);
};



#endif //WINDOW_H
