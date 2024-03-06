//
// Created by csaba on 3/6/24.
//

#ifndef TEXTURE_H
#define TEXTURE_H

// includes
#include <iostream>
#include <string>
#include <stdexcept>

// SDL
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Texture {
private:
    SDL_Texture* texture;
    int w;
    int h;

public:
    Texture();
    ~Texture();

    void loadFromFile(SDL_Renderer* renderer, const std::string& path, const Uint8 red = 0, const Uint8 blue = 255, const Uint8 green = 255);
    void loadFromText(SDL_Renderer* renderer, const std::string& text, TTF_Font* font, SDL_Color textColor);
    void free();

    //x, y are coordinates to render ; srcRect is the rect from the texture to be rendered
    void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* srcRect = nullptr, double angle = 0.0, SDL_Point* center = nullptr);

    void createBlankTexture(SDL_Renderer* renderer, SDL_TextureAccess access, int width, int height);
    void setAsTarget(SDL_Renderer* renderer);
    static void setWindowAsTarget(SDL_Renderer* renderer);
};



#endif //TEXTURE_H
