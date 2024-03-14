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
    const char* title;
    int width;
    int height;

    Uint32 windowID;
    bool fullscreen;
    bool vsync;

    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Window(const char* title, int width, int height);
    ~Window();

    [[nodiscard]] SDL_Renderer* getRenderer() const { return renderer; }
    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }

    void resize(int width, int height);
    void handleEvents(const SDL_Event& event);
};



#endif //WINDOW_H
