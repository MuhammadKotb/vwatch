#include "types.h"
#include <functional>
#include <iostream>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_sdl2.h>
#include <Bootstrapper.h>
#include <ui/ImGuiDrawer.h>
#include <Drawer.h>
extern "C" {
    #include <SDL2/SDL_opengl.h>
    #include <SDL2/SDL.h>
    #include <libavcodec/avcodec.h>
}






int main(int argc, char* asrgv[]) {

    
    if(SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "Error -> " << SDL_GetError() << "\n";
        SDL_Quit();
        exit(0);
    }

    
 
    SDL_Window* window =  SDL_CreateWindow("hello", 300, 200, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    vw::createContext(window);
    bool run = true;


    AVCodec* decoder = avcodec_find_decoder(AV_CODEC_ID_CINEPAK);
    AVCodecContext* codec_context = avcodec_alloc_context3(decoder);
    
    vw::ImGuiDrawer imgui_drawer;
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glOrtho( -100.0, 100.0,-100.0, 100.0, 1, 0);
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_MODELVIEW);

    while(run) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if(event.window.type == SDL_QUIT) {
                run = false;
            }
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        
        ImGui::Begin("helo");
        imgui_drawer.Button("play", {50, 50}, [](){std::cout << "x\n";});
        ImGui::End();
        
        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        vw::Triangle tri{50, 50, 50, 100, 100, 100};
        vw::ColorNorm color{0, 0, 0};
        drawTriangle(tri, color);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

}