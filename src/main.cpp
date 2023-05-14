#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_sdl2.h>
extern "C" {
    #include <SDL2/SDL_opengl.h>
    #include <SDL2/SDL.h>
    #include <libavcodec/avcodec.h>
}

const char* glsl_version = "#version 130";


int main(int argc, char* asrgv[]) {

    
    if(SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "Error -> " << SDL_GetError() << "\n";
        SDL_Quit();
        exit(0);
    }
    
 
    SDL_Window* window =  SDL_CreateWindow("hello", 300, 200, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    if(!ImGui_ImplOpenGL3_Init(glsl_version)) {
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
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
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");
            ImGui::End();
        }

        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);

        // SDL_RenderClear(renderer);
        // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        // SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}