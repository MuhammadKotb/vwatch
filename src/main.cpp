#include <iostream>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_sdl2.h>
#include <Bootstrapper.h>
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

        {

            ImGui::Begin("Hello, world!");

            ImGui::SetCursorPos(ImVec2(8,681));
            ImGui::BeginChild(17, ImVec2(1322,49), true);

            ImGui::EndChild();

            ImGui::SetCursorPos(ImVec2(21.5,694.5));
            ImGui::Button("play", ImVec2(36,19)); //remove size argument (ImVec2) to auto-resize

            ImGui::SetCursorPos(ImVec2(68.5,694.5));
            ImGui::Button("stop", ImVec2(36,19)); //remove size argument (ImVec2) to auto-resize
            ImGui::End();
        }

        ImGui::Render();
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

}