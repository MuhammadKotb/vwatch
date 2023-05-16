#pragma once 
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <types.h>


namespace vw {
    void drawScene();
    void drawTriangle(vw::Triangle triangle, vw::ColorNorm color);

}