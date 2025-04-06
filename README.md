# hitine engine v1

# REQUIREMENTS: VULKAN AND SDL2 SDK

# API:
include hitineEngine.cpp into main

## windowShenanigans:
#### `initShit()` - initializes SDL2 
### `createWindow(const char* name,bool fullscreen,bool use3D)` - creates a window,name is title of the window,fullscreen is self explanatory,use3D makes window support Vulkan context
### `create2DScene(SDL_Window* window)` - creates 2D renderer
### `cleanScreen(SDL_Renderer* renderer)` - cleans the screen
### `CleanupShit(SDL_Window* window)` - cleans shit up after everything is finished
