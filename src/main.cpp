#include <iostream>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_sdl2.h>
extern "C" {
    #include <SDL2/SDL.h>
    #include <libavcodec/avcodec.h>
}



int main(int argc, char* asrgv[]) {

    
    if(SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "SDL INIT ERROR\n";
        SDL_Quit();
        exit(0);
    }
    SDL_Window* window =  SDL_CreateWindow("hello", 300, 200, 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    bool run = true;
    AVCodec* decoder = avcodec_find_decoder(AV_CODEC_ID_CINEPAK);
    AVCodecContext* codec_context = avcodec_alloc_context3(decoder);


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