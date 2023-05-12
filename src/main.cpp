#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <imgui/imgui.h>
int main(int argc, char* asrgv[]) {


    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window =  SDL_CreateWindow("hello", 300, 200, 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    bool run = true;
    while(run) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.window.type == SDL_QUIT) {
                run = false;
            }
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


}