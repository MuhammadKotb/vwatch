#include "imgui/imgui.h"
#include <functional>
#include <ui/ImGuiDrawer.h>



vw::ImGuiDrawer::ImGuiDrawer() {

}

vw::ImGuiDrawer::~ImGuiDrawer() {

}


void vw::ImGuiDrawer::Button(const char* name, ImVec2 vec, std::function<void()> fucnction) {
    if(ImGui::Button(name, vec)) {
        fucnction();
    }
}