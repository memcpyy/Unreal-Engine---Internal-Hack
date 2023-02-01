#include "../include/Menu.hpp"
#include "../SDK.h"
#include "../visuals.h"

using namespace DX11_Base;


using namespace CG;

namespace DX11_Base {
    

    namespace Styles {
        void InitStyle()
        {
            ImGuiStyle& style = ImGui::GetStyle();
            ImVec4* colors = ImGui::GetStyle().Colors;

            //	STYLE PROPERTIES
            style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
            style.WindowMinSize = ImVec2(600, 400);

            //  Base ImGui Styling , Aplying a custyom style is left up to you.
            ImGui::StyleColorsClassic();

            /// EXAMPLE COLOR 
            //colors[ImGuiCol_FrameBg] = ImVec4(0, 0, 0, 0);

            //	COLORS
            if (g_Menu->dbg_RAINBOW_THEME) {
                //  RGB MODE STLYE PROPERTIES
                colors[ImGuiCol_Separator] = ImVec4(g_Menu->dbg_RAINBOW);
                colors[ImGuiCol_TitleBg] = ImVec4(0, 0, 0, 1.0f);
                colors[ImGuiCol_TitleBgActive] = ImVec4(0, 0, 0, 1.0f);
                colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0, 0, 0, 1.0f);
                colors[ImGuiCol_Button] = ImVec4(g_Menu->dbg_RAINBOW);
                colors[ImGuiCol_ButtonActive] = ImVec4(g_Menu->dbg_RAINBOW);
                colors[ImGuiCol_ButtonHovered] = ImVec4(g_Menu->dbg_RAINBOW);
            }
            else {
                /// YOUR DEFAULT STYLE PROPERTIES HERE
            }
        }
    }


    static int menutab = 0;
    static int VisualSubTab = 0;
    static int WeaponSubTab = 0;
    static int SelfSubTab = 0;
    namespace Tabs {
        void TABMain()
        {

            ImGui::BeginChild("##LeftSide", ImVec2(130, 300), true);
            {

                ImGui::TextColored(ImColor(g_Menu->dbg_RAINBOW), "   REAPER.GG");
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();


                if (ImGui::Button("Main", ImVec2(115, 25)))
                    menutab = 0;

                if (ImGui::Button("Visuals", ImVec2(115, 25)))
                    menutab = 1;

                if (ImGui::Button("Self", ImVec2(115, 25)))
                    menutab = 2;

                if (ImGui::Button("Settiings", ImVec2(115, 25)))
                    menutab = 3;

                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();

                ImGui::TextColored(ImColor(g_Menu->dbg_RAINBOW), "Version   1.0.1");
                ImGui::TextColored(ImColor(g_Menu->dbg_RAINBOW), "Made By   Kizzy");

                ImGui::EndChild();
            }

            {
                ImGui::SameLine(0);
                ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
                ImGui::SameLine();


            }

            ImGui::BeginChild("##RightSide", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), true);
            {

                auto center = [](float avail_width, float element_width, float padding = 0)
                {
                    ImGui::SameLine((avail_width / 2) - (element_width / 2) + padding);
                };

                auto center_text = [&](const char* format, float spacing = 15, ImColor color = ImColor(255, 255, 255)) {
                    center(ImGui::GetContentRegionAvail().x, ImGui::CalcTextSize(format).x);
                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + spacing);
                    ImGui::TextColored(color.Value, format);
                };

                //Header 1

                //center_text(data.status.c_str(), 18, (data.undetected ? ImColor(0, 255, 0) : ImColor(255,0,0)));  **IS FOR LOADER**

                float dbg_RAINBOW[] = { 1.f, 0.f, 0.f };

                if (menutab == 0)
                {
                    ImGui::Text("Weapons");
                    
                    ImGui::Separator();

                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 110);
                    if (ImGui::Button("Main", ImVec2(85, 20)))
                        WeaponSubTab = 0;
                    ImGui::SameLine();
                    if (ImGui::Button("Weapon", ImVec2(85, 20)))
                        WeaponSubTab = 1;


                    ImGui::Separator();
                    
                    if (WeaponSubTab == 0)
                    {
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Checkbox("Crosshair", &weapon::drawCrosshair);
                        ImGui::SameLine();
                        ImGui::ColorEdit3("##CrosshairColor", dbg_RAINBOW, ImGuiColorEditFlags_NoInputs);
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Checkbox("Fov", &weapon::drawFov);
                        ImGui::SameLine();
                        ImGui::ColorEdit3("##FovColor", dbg_RAINBOW, ImGuiColorEditFlags_NoInputs);
                        if (weapon::drawFov)
                        {
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Checkbox("Fov-Filled", &weapon::fovFilled);
                        }
                    }

                    if (WeaponSubTab == 1)
                    {
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Checkbox("Aim-Bot", &weapon::aimbot);
                        ImGui::SameLine();
                        ImGui::SetNextItemWidth(90);
                        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 25);
                        ImGui::SliderFloat("Smoothing", &weapon::smoothing, 0.1f, 30.f);
                        if (weapon::aimbot)
                        {
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Checkbox("Silent-Aim", &weapon::aimbot);


                        }

                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Checkbox("No-Recoil", &weapon::noRecoil);
                        if (weapon::noRecoil)
                        {
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::SetNextItemWidth(90);
                            ImGui::SliderFloat("RCS-Amount", &weapon::rcsAmount, 0.f, 10.f);
                            ImGui::SliderInt("X-Amount", &weapon::rcsAmountY, 0, 10);
                            ImGui::SliderInt("Y-Amount", &weapon::rcsAmountX, 0, 10);
                            ImGui::Spacing();
                        }
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Checkbox("Rapid-Fire", &weapon::rapid_fire);
                        
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Checkbox("Unlimited-Ammo", &weapon::unlimited_ammo);
                    }



                }



                if (menutab == 1)
                {
                    center_text("Visuals");


                    ImGui::Separator();
                    
                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 80);
                    if (ImGui::Button("Player", ImVec2(85, 20)))
                        VisualSubTab = 0;
                    ImGui::SameLine();
                    if (ImGui::Button("World", ImVec2(85, 20)))
                        VisualSubTab = 1;
                    ImGui::SameLine();
                    if (ImGui::Button("Chams", ImVec2(85, 20)))
                        VisualSubTab = 2;
                    ImGui::Separator();
                    
                    if (VisualSubTab == 0) //Player
                    {
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Checkbox("Box-Esp", &visuals::boxEsp);
                        ImGui::SameLine();
                        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 30);
                        ImGui::ColorEdit3("##ESPCOLOR", dbg_RAINBOW, ImGuiColorEditFlags_NoInputs);
                        ImGui::SetNextItemWidth(100);
                        ImGui::SameLine();
                        ImGui::Combo("##STYLE", &visuals::espStyle, "2Dbox\0 3Dbox\00 Cornerfilled\000");
                        if (visuals::boxEsp)
                        {
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Checkbox("Show-Names", &visuals::names);
                            ImGui::SameLine();
                            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 9);
                            ImGui::Checkbox("Show-Distance", &visuals::playerDistance);
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Checkbox("Held-Item", &visuals::heldtItem);
                            ImGui::SameLine();
                            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 15);
                            ImGui::Checkbox("Snap-Lines", &visuals::SnapLines);
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Checkbox("Show-Team", &visuals::ShowTeam);
                            ImGui::SameLine();
                            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 15);
                            ImGui::Checkbox("Show-Bots", &visuals::Botesp);


                        }
                    }
                   
                    if (VisualSubTab == 1) //World
                    {
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Checkbox("World-Esp", &visuals::worldesp);
                        ImGui::SameLine();
                        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 15);
                        ImGui::ColorEdit3("##WORLDESP", dbg_RAINBOW, ImGuiColorEditFlags_NoInputs);
                        if (visuals::worldesp)
                        {
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::Checkbox("Distance", &visuals::lootDistance);
                            ImGui::SameLine();
                            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 21);
                            ImGui::Checkbox("Weapon-Names", &visuals::showguns);

                        }
                    }

                    if (VisualSubTab == 2) //Misc
                    {
                        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 150);
                        ImGui::Text("!!COMING SOON!!");
                    }

                }

                if (menutab == 2)
                {
                    center_text("Self");
                    ImGui::Separator();

                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 110);
                    if (ImGui::Button("Movement", ImVec2(85, 20)))
                        SelfSubTab = 0;
                    ImGui::SameLine();
                    if (ImGui::Button("Misc", ImVec2(85, 20)))
                        SelfSubTab = 1;
                    

                    ImGui::Separator();

                    if (SelfSubTab == 0) //mOVEMENT
                    {
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::SetNextItemWidth(40);
                        if (ImGui::Button("UFO ON"))
                        {
                            auto WORLD = reinterpret_cast<CG::UWorld**>(dwGameBase + g_GameData->offsets.oUWorld); if ((*WORLD) == nullptr) return;
                            auto GAME_STATE = (*WORLD)->GameState; if ((GAME_STATE) == nullptr) return;
                            auto LocalPlayer = (*WORLD)->OwningGameInstance->LocalPlayers[0];
                            //Get Player Controller
                            auto* Player_Controller = LocalPlayer->PlayerController;
                            auto Pawn = Player_Controller->AcknowledgedPawn;
                            auto actor_root_component = Pawn->RootComponent; if ((actor_root_component) == nullptr) return;
                            CG::ATaskForceCharacter* character = static_cast<CG::ATaskForceCharacter*>(Pawn);
                            //Check if its local player and not draw
                            if (LocalPlayer == nullptr)
                                return;
                            if (Player_Controller == nullptr)
                                return;
                            auto Collision = Pawn->GetActorEnableCollision();


                            character->CharacterMovement->MovementMode = CG::EMovementMode::MOVE_Flying;
                        }
                        ImGui::SameLine();
                        if (ImGui::Button("UFO OFF"))
                        {
                            auto WORLD = reinterpret_cast<CG::UWorld**>(dwGameBase + g_GameData->offsets.oUWorld); if ((*WORLD) == nullptr) return;
                            auto GAME_STATE = (*WORLD)->GameState; if ((GAME_STATE) == nullptr) return;
                            auto LocalPlayer = (*WORLD)->OwningGameInstance->LocalPlayers[0];
                            //Get Player Controller
                            auto* Player_Controller = LocalPlayer->PlayerController;
                            auto Pawn = Player_Controller->AcknowledgedPawn;
                            auto actor_root_component = Pawn->RootComponent; if ((actor_root_component) == nullptr) return;
                            CG::ATaskForceCharacter* character = static_cast<CG::ATaskForceCharacter*>(Pawn);
                            //Check if its local player and not draw
                            if (LocalPlayer == nullptr)
                                return;
                            if (Player_Controller == nullptr)
                                return;
                            auto Collision = Pawn->GetActorEnableCollision();


                            character->CharacterMovement->MovementMode = CG::EMovementMode::MOVE_Walking;
                        }
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Spacing();
                        //GodMode
                        ImGui::Checkbox("No Collision", &misc::godmode);

                       


                    }

                    if (SelfSubTab == 1) //MISC
                    {
                        ImGui::Spacing();
                        ImGui::Spacing();

                        //char* NameBuff[16];
                   //ImGui::InputText("Custom Name",(char*)&NameBuff, 18);
                   //ImGui::SameLine();
                        if (ImGui::Button("Change Name"))
                        {
                            auto WORLD = reinterpret_cast<CG::UWorld**>(dwGameBase + g_GameData->offsets.oUWorld); if ((*WORLD) == nullptr) return;
                            auto GAME_STATE = (*WORLD)->GameState; if ((GAME_STATE) == nullptr) return;

                            auto LocalPlayer = (*WORLD)->OwningGameInstance->LocalPlayers[0];

                            auto* Player_Controller = LocalPlayer->PlayerController;

                            auto Pawn = Player_Controller->AcknowledgedPawn;

                            auto* Root = Pawn->RootComponent;
                            auto Player_Array = GAME_STATE->PlayerArray;

                            CG::ATaskForceCharacter* character = static_cast<CG::ATaskForceCharacter*>(Pawn);

                            //SetName
                            Player_Controller->SetName(L"IM JUST BETTER");

                        }
                        //Fov
                        ImGui::SliderFloat(("##FOVAMOUNT"), &misc::customFov_Amount, 70.f, 130.f);
                        ImGui::SameLine();
                        ImGui::SetNextItemWidth(40);
                        if (ImGui::Button("Set Fov"))
                        {
                            auto WORLD = reinterpret_cast<CG::UWorld**>(dwGameBase + g_GameData->offsets.oUWorld); if ((*WORLD) == nullptr) return;
                            auto GAME_STATE = (*WORLD)->GameState; if ((GAME_STATE) == nullptr) return;
                            auto LocalPlayer = (*WORLD)->OwningGameInstance->LocalPlayers[0];
                            //Get Player Controller
                            auto* Player_Controller = LocalPlayer->PlayerController;

                            auto PERSISTENTLEVEL = (*WORLD)->PersistentLevel;
                            if (PERSISTENTLEVEL == nullptr)
                                return;
                            //Check if its local player and not draw
                            if (LocalPlayer == nullptr)
                                return;
                            //Check for player controler
                            if (Player_Controller == nullptr)
                                return;

                            Player_Controller->FOV(misc::customFov_Amount);

                        }
                    }
 
                }

                if (menutab == 3)
                {
                    center_text("Settings");
                    ImGui::Separator();
                    ImGui::Spacing();



                    if (ImGui::Button("UNHOOK DLL", ImVec2(ImGui::GetWindowContentRegionWidth() - 3, 20))) {
#if DEBUG
                        g_Console->printdbg("\n\n[+] UNHOOK INITIALIZED [+]\n\n", g_Console->color.red);
#endif
                        g_KillSwitch = TRUE;
                    }

                }

                ImGui::EndChild();
            }
        }
    }
               
}

    void Menu::Draw()
    {
        if (g_GameVariables->m_ShowMenu)
            MainMenu();

        if (g_GameVariables->m_ShowHud)
            HUD(&g_GameVariables->m_ShowHud);

        if (g_GameVariables->m_ShowDemo)
            ImGui::ShowDemoWindow();
        //Visuals
        if (visuals::boxEsp) 
            drawingShit::Esp();

        if (visuals::worldesp)
            drawingShit::worldEsp();
        
        drawingShit::staticDrawing();
        //Visuals
    }

    void Menu::MainMenu()
    {
        if (!g_GameVariables->m_ShowDemo)
            Styles::InitStyle();

        if (g_Menu->dbg_RAINBOW_THEME) {
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(g_Menu->dbg_RAINBOW));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(g_Menu->dbg_RAINBOW));
            ImGui::PushStyleColor(ImGuiCol_BorderShadow, ImVec4(g_Menu->dbg_RAINBOW));
        }
        if (!ImGui::Begin("Task Force", &g_GameVariables->m_ShowMenu, 96))
        {
            ImGui::End();
            return;
        }
        if (g_Menu->dbg_RAINBOW_THEME) {
            ImGui::PopStyleColor();
            ImGui::PopStyleColor();
            ImGui::PopStyleColor();
        }

        //  Display Menu Content
        Tabs::TABMain();

        //  I like to use tabs to display my content in an organized manner, Here is an example on how you could do the same
        //  As a courtesy I have left the TABS namespace with an Example Tab
        //if (ImGui::BeginTabBar("##tabs", ImGuiTabBarFlags_None))
        //{
        //    if (ImGui::BeginTabItem("MAIN"))
        //    {
        //        Tabs::TABMain();
        //        ImGui::EndTabItem();
        //    }
        //    ImGui::EndTabBar();
        //}
        ImGui::End();
    }

    void Menu::HUD(bool* p_open)
    {

    }

    void Menu::Loops()
    {
        //ammonshit & rapid fire shit
        if (weapon::unlimited_ammo)
        {
            auto WORLD = reinterpret_cast<CG::UWorld**>(dwGameBase + g_GameData->offsets.oUWorld); if ((*WORLD) == nullptr) return;
            auto GAME_STATE = (*WORLD)->GameState; if ((GAME_STATE) == nullptr) return;
            auto LocalPlayer = (*WORLD)->OwningGameInstance->LocalPlayers[0];
            //Get Player Controller
            auto* Player_Controller = LocalPlayer->PlayerController;
            auto Pawn = Player_Controller->AcknowledgedPawn;
            auto actor_root_component = Pawn->RootComponent; if ((actor_root_component) == nullptr) return;
            CG::ATaskForceCharacter* character = static_cast<CG::ATaskForceCharacter*>(Pawn);
            //Check if its local player
            if (LocalPlayer == nullptr)
                return;
            if (Player_Controller == nullptr)
                return;
            if (character->CurrentWeapon == nullptr)
                return;

            //GetCurrentAmmo & set it to ammount
            character->CurrentWeapon->CurrentAmmo = 1337;
            character->CurrentWeapon->CurrentAmmoInClip = 1337;


        }
        if (weapon::rapid_fire)
        {
            auto WORLD = reinterpret_cast<CG::UWorld**>(dwGameBase + g_GameData->offsets.oUWorld); if ((*WORLD) == nullptr) return;
            auto GAME_STATE = (*WORLD)->GameState; if ((GAME_STATE) == nullptr) return;
            auto LocalPlayer = (*WORLD)->OwningGameInstance->LocalPlayers[0];
            //Get Player Controller
            auto* Player_Controller = LocalPlayer->PlayerController;
            auto Pawn = Player_Controller->AcknowledgedPawn;
            auto actor_root_component = Pawn->RootComponent; if ((actor_root_component) == nullptr) return;
            CG::ATaskForceCharacter* character = static_cast<CG::ATaskForceCharacter*>(Pawn);
            //Check if its local player
            if (LocalPlayer == nullptr)
                return;
            if (character->CurrentWeapon == nullptr)
                return;
            if (Player_Controller == nullptr)
                return;
            //RapidFre
            character->CurrentWeapon->WeaponConfig.RoundsPerMinute = 20000;

        }
        if (weapon::no_recoil)
        {
            auto WORLD = reinterpret_cast<CG::UWorld**>(dwGameBase + g_GameData->offsets.oUWorld); if ((*WORLD) == nullptr) return;
            auto GAME_STATE = (*WORLD)->GameState; if ((GAME_STATE) == nullptr) return;
            auto LocalPlayer = (*WORLD)->OwningGameInstance->LocalPlayers[0];
            //Get Player Controller
            auto* Player_Controller = LocalPlayer->PlayerController;
            auto Pawn = Player_Controller->AcknowledgedPawn;
            auto actor_root_component = Pawn->RootComponent; if ((actor_root_component) == nullptr) return;
            CG::ATaskForceCharacter* character = static_cast<CG::ATaskForceCharacter*>(Pawn);
            //Check if its local player
            if (LocalPlayer == nullptr)
                return;
            if (Player_Controller == nullptr)
                return;
            if (character->CurrentWeapon == nullptr)
                return;

            character->CurrentWeapon->WeaponConfig.RecoilYawMin = -0.1f;
            character->CurrentWeapon->WeaponConfig.RecoilYawMax = -0.1f;
            character->CurrentWeapon->WeaponConfig.RecoilPitchMax = -0.1f;
            character->CurrentWeapon->WeaponConfig.RecoilPitchMin = -0.1f;
            character->CurrentWeapon->WeaponConfig.RecoilAdditiveFactor = -0.1f;
            character->CurrentWeapon->WeaponConfig.RecoilMax = 1;
            character->CurrentWeapon->WeaponConfig.DamageScale = 100.0;


        }
        if (misc::godmode)
        {
            auto WORLD = reinterpret_cast<CG::UWorld**>(dwGameBase + g_GameData->offsets.oUWorld); if ((*WORLD) == nullptr) return;
            auto GAME_STATE = (*WORLD)->GameState; if ((GAME_STATE) == nullptr) return;
            auto LocalPlayer = (*WORLD)->OwningGameInstance->LocalPlayers[0];
            //Get Player Controller
            auto* Player_Controller = LocalPlayer->PlayerController;
            auto Pawn = Player_Controller->AcknowledgedPawn;
            auto actor_root_component = Pawn->RootComponent; if ((actor_root_component) == nullptr) return;
            CG::ATaskForceCharacter* character = static_cast<CG::ATaskForceCharacter*>(Pawn);
            //Check if its local player
            if (LocalPlayer == nullptr)
                return;
            if (Player_Controller == nullptr)
                return;
            if (character->CurrentWeapon == nullptr)
                return;

            auto Collision = Pawn->GetActorEnableCollision();
            if (Collision)
                Pawn->SetActorEnableCollision(FALSE);




        }

    }
