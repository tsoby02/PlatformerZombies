//
// Created by csaba on 3/6/24.
//

#include "Texture.h"

Texture::Texture() {
    texture = nullptr;
    w = 0;
    h = 0;
}

Texture::~Texture() {
    free();
}

void Texture::loadFromFile(SDL_Renderer* renderer, const std::string& path, const Uint8 red, const Uint8 blue, const Uint8 green) {
    free();

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr) {
        throw std::runtime_error("ERROR: Image from " + path + " could not be loaded! " + std::string(IMG_GetError()));
    }
    if(SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, red, blue, green)) < 0) {
        std::cout << "WARNING: Color keying on image from " << path << " could not be set! " << std::string(SDL_GetError()) << std::endl;
    }

    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if(texture == nullptr) {
        throw std::runtime_error("ERROR: Unable to create texture from image from " + path + "! " + std::string(SDL_GetError()));
    }
    w = loadedSurface->w;
    h = loadedSurface->h;

    SDL_FreeSurface(loadedSurface);
}

void Texture::loadFromText(SDL_Renderer* renderer, const std::string& text, TTF_Font* font, SDL_Color textColor) {
    free();

    SDL_Surface* loadedSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    if(loadedSurface == nullptr) {
        throw std::runtime_error("ERROR: Unable to create surface from text: " + text + std::string(TTF_GetError()));
    }

    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if(texture == nullptr) {
        throw std::runtime_error("ERROR: Unable to create texture from text: " + text + "! " + std::string(SDL_GetError()));
    }
    w = loadedSurface->w;
    h = loadedSurface->h;

    SDL_FreeSurface(loadedSurface);
}

void Texture::free() {
    if(texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        w = 0;
        h = 0;
    }
}


void Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* srcRect, double angle, SDL_Point* center) {
    SDL_Rect renderRect = {x, y, this->w, this->h};
    if(srcRect != nullptr) {
        renderRect.w = srcRect->w;
        renderRect.h = srcRect->h;
    }

    SDL_RenderCopyEx(renderer, this->texture, srcRect, &renderRect, angle, center, SDL_FLIP_NONE);
}

void Texture::createBlankTexture(SDL_Renderer* renderer, SDL_TextureAccess access, int width, int height) {
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, access, width, height);
    if(texture == nullptr){
        throw std::runtime_error("Unable to create blank texture!" + std::string(SDL_GetError()));
    }
    w = width;
    h = height;
}

void Texture::setAsTarget(SDL_Renderer* renderer) {
    SDL_SetRenderTarget(renderer, texture);
}

void Texture::setWindowAsTarget(SDL_Renderer* renderer) {
    SDL_SetRenderTarget(renderer, nullptr);
}
