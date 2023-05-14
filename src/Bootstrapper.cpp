#include <Bootstrapper.h>



int vw::createContext(SDL_Window* window) {
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    if(gl_context == NULL) {
        std::cout << "Error while creating gl context\n";
        std::cout << SDL_GetError();
    }
    SDL_GL_MakeCurrent(window, gl_context);
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); 

    (void)io;

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     
    
    ImGui::StyleColorsDark();

    if(!ImGui_ImplSDL2_InitForOpenGL(window, gl_context)) {
        std::cout << "Error while initing ImplSDL2\n";
        return -1;
    }
    if(!ImGui_ImplOpenGL3_Init()) {
        std::cout << "Error while initing ImplOpengl3\n";
        return -1;
    }
    return 0;
}


int vw::destroyContext() {
    return 0;
}