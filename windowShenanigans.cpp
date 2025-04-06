#include <SDL2/SDL.h>
#include <iostream>
#include <string>

void initShit(){
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }
}

SDL_Window* createWindow(const char* name,bool fullscreen,bool use3D){
    SDL_Window* window = SDL_CreateWindow(
        name,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        fullscreen ? (use3D ? SDL_WINDOW_VULKAN : SDL_WINDOW_SHOWN) | SDL_WINDOW_FULLSCREEN_DESKTOP : (use3D ? SDL_WINDOW_VULKAN : SDL_WINDOW_SHOWN) | SDL_WINDOW_RESIZABLE
    );
 
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return window;
    }
    
    return window;
}

SDL_Renderer* create2DScene(SDL_Window* window){
  return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void cleanScreen(SDL_Renderer* renderer){
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

void cleanupShit(SDL_Window* window){
  SDL_DestroyWindow(window);
  SDL_Quit();
}