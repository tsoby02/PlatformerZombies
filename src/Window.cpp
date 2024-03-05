//
// Created by csaba on 3/5/24.
//

#include "Window.h"

Window::Window(const char* title, int width, int height) : window_title(title), window_width(width), window_height(height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        throw std::runtime_error("ERROR: Window could not be created! " + std::string(SDL_GetError()));
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        throw std::runtime_error("ERROR: Renderer could not be created! " + std::string(SDL_GetError()));
    }

    windowID = SDL_GetWindowID(window);
    fullscreen = false;
    vsync = true;
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window = nullptr;
}

void Window::resize(int new_width, int new_height) {
    SDL_SetWindowSize(window, new_width, new_height);
    window_width = new_width;
    window_height = new_height;
}

void Window::handleEvents(const SDL_Event& event) {

}
