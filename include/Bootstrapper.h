#pragma once 
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_sdl2.h>
#include <iostream>
extern "C" { 
    #include <SDL2/SDL.h>
}

namespace vw {
    int createContext(SDL_Window* window);
    int destroyContext();
}

