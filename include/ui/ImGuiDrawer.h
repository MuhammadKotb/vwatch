#pragma once
#include <imgui/imgui.h>
#include <functional>

namespace vw {

    class ImGuiDrawer {
    public:
        ImGuiDrawer();
        ~ImGuiDrawer();
        void Button(const char* name, ImVec2 vec, std::function<void()> f);
    };


}