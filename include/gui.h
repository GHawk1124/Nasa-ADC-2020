#pragma once

#include "imgui/imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"

inline void showGui() {
    //create a window called "Settings" and add stuff to it
    ImGui::Begin("Settings");
    static int max_slope = 15;
    static int distance = 0;
    static int min_slope = 0;
    //create a collapsing dropdown inside the window
    if (ImGui::CollapsingHeader("Pathfinding Controls")) {
        //sliders to control pathfinding algorithm params
        ImGui::SliderInt("Max slope angle", &max_slope, 5, 40, "%f°");
        ImGui::SliderInt("Min slope angle", &max_slope, 0, 35, "%f°");
        ImGui::SliderInt("Max checkpoint distance", &distance, 0, 50, "%fm");
        ImGui::Button("Recompute path");
        ImGui::SameLine();
        //create a hoverable tooltip (on same line)
        ImGui::TextDisabled("(?)");
        if (ImGui::IsItemHovered()) {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted("This may take a long time");
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
    }

    //collapsing dropdown #2
    if (ImGui::CollapsingHeader("Recolor options")) {
        const char* items[] = {"None", "Altitude", "Slope"};
        static int current_index = 0;
        const char* combo_label = items[current_index];

        //show dropdown select menu, keep the selected item selected.
        if (ImGui::BeginCombo("Color type", combo_label, 0)) {
            for (int n = 0; n < IM_ARRAYSIZE(items); n++) {
                const bool is_selected = (current_index == n);

                if (ImGui::Selectable(items[n], is_selected)) {
                    current_index = n;
                }

                if (is_selected) {
                    ImGui::SetItemDefaultFocus();
                }
            }

            ImGui::EndCombo();
        }
    }
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}
