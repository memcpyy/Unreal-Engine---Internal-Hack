#include "visuals.h"
#include "SDK.h"
#include "include/helper.h"
#include "include/Game.hpp"

using namespace DX11_Base;
using namespace CG;
void drawingShit::Esp()
{
        auto WORLD = reinterpret_cast<CG::UWorld**>(dwGameBase + g_GameData->offsets.oUWorld); if ((*WORLD) == nullptr) return;
        auto GAME_STATE = (*WORLD)->GameState; if ((GAME_STATE) == nullptr) return;
        //get local player
        auto LocalPlayer = (*WORLD)->OwningGameInstance->LocalPlayers[0];
        //Get Player Controller
        auto* Player_Controller = LocalPlayer->PlayerController;
        //Get acknowledge pawn
        auto Pawn = Player_Controller->AcknowledgedPawn;
        //Get the Entity 
        auto* Root = Pawn->RootComponent;
        //Player arrary
        auto Player_Array = GAME_STATE->PlayerArray;

        CG::ATaskForceCharacter* character = static_cast<CG::ATaskForceCharacter*>(Pawn);
        CG::APlayerState* Aplayerstate = static_cast<CG::APlayerState*>(Pawn->PlayerState);
        CG::ATaskForcePlayerState* taskforcePlayerState = static_cast<CG::ATaskForcePlayerState*>(Aplayerstate);
        //DEREFENCING AND MAKING MY CHECKS
        auto PERSISTENTLEVEL = (*WORLD)->PersistentLevel;
        if (PERSISTENTLEVEL == nullptr)
            return;

        //Check if its local player and not draw
        if (LocalPlayer == nullptr)
            return;
        //Check for player controler
        if (Player_Controller == nullptr)
            return;

        //Check for acknowleged pawn
        if (Pawn == nullptr)
            return;
        //CHECK FOR ROOT COMPONENT
        if (Root == nullptr)
            return;




        CG::FVector2D screen;
       // int CURTEAM;
       // CURTEAM = taskforcePlayerState->TeamNumber;

        for (int i = 1; i < Player_Array.Count(); i++)
        {
            auto pawn = Player_Array[i]->PawnPrivate; if ((pawn) == nullptr) continue;

            auto actor_root_component = pawn->RootComponent; if ((actor_root_component) == nullptr) continue;
            CG::ATaskForceCharacter* character = static_cast<CG::ATaskForceCharacter*>(pawn);
            CG::APlayerState* entAplayerstate = static_cast<CG::APlayerState*>(pawn->PlayerState);
            //AActor::GetActorEyesViewPoint
            CG::ATaskForcePlayerState* enttaskforcePlayerState = static_cast<CG::ATaskForcePlayerState*>(entAplayerstate);

            //Check if its a bot
            //if (visuals::Botesp)
            //{
            //    if (pawn->IsBotControlled()) continue;
            //}

            //check if they are alive
            //if (!character->IsAlive()) continue;
            
          //  if (enttaskforcePlayerState->TeamNumber == CURTEAM) continue;

            CG::FVector root_bone;
           
            //float height = abs(actor_root_component->RelativeLocation.Y - screen.Y);
            //float width = height * 0.65;

            //Info
            const wchar_t* actor_name = Aplayerstate->GetPlayerName().wc_str();
            char name[32];
            std::wcstombs(name, actor_name, 32);


              // Forward declare some elements
           //CG::FVector2D BOX;
           //CG::FVector ActorPosition{};
           //CG::FVector ActorBox{};
           //
           //// This gets the current players position and dimensions
           //Player_Array[i]->GetActorBounds(TRUE, &ActorPosition, &ActorBox);
           //float ActorHeight = ActorBox.Z;
           //float ActorWidth = ActorBox.X;
           //
           ////BOX DIMENSIONS
           ////Actor Position Point = Bottom Center of Actor
           //ImVec2 BoxBottomLeft{ (ActorPosition.X - (ActorWidth / 2)), ActorPosition.Y };
           //ImVec2 BoxBottomRight{ (ActorPosition.X + (ActorWidth / 2)), ActorPosition.Y };
           //ImVec2 BoxTopLeft{ (ActorPosition.X - (ActorWidth / 2)), (ActorHeight - ActorPosition.Y) };
           //ImVec2 BoxTopRight{ (ActorPosition.X + (ActorWidth / 2)), (ActorHeight - ActorPosition.Y) };
           //
            if (Player_Controller->ProjectWorldLocationToScreen(actor_root_component->RelativeLocation, &screen, true))
            {
                auto draw = ImGui::GetBackgroundDrawList();

                if (visuals::SnapLines)
                {
                    draw->AddLine(ImVec2(960, 0), ImVec2(screen.X, screen.Y - 30), ImColor(255, 0, 0), 1);
                }

                if (visuals::names)
                {
                    ImVec2 sz = ImGui::CalcTextSize(name, NULL, true);
                    draw->AddText(ImVec2(screen.X - sz.x / 2 - 1, screen.Y - 15), ImColor(255, 0, 0), name);
                }

                

                





            }



        }



    
}


void drawingShit::worldEsp()
{
    auto WORLD = reinterpret_cast<CG::UWorld**>(dwGameBase + g_GameData->offsets.oUWorld); if ((*WORLD) == nullptr) return;
    auto GAME_STATE = (*WORLD)->GameState; if ((GAME_STATE) == nullptr) return;
    //get local player
    auto LocalPlayer = (*WORLD)->OwningGameInstance->LocalPlayers[0];
    //Get Player Controller
    auto* Player_Controller = LocalPlayer->PlayerController;
    //Get acknowledge pawn
    auto Pawn = Player_Controller->AcknowledgedPawn;
    //Get the Entity 
    auto* Root = Pawn->RootComponent;
    //Player arrary
    auto Player_Array = GAME_STATE->PlayerArray;

    CG::ATaskForceCharacter* character = static_cast<CG::ATaskForceCharacter*>(Pawn);
    CG::APlayerState* Aplayerstate = static_cast<CG::APlayerState*>(Pawn->PlayerState);
    CG::ATaskForcePlayerState* taskforcePlayerState = static_cast<CG::ATaskForcePlayerState*>(Aplayerstate);
    //DEREFENCING AND MAKING MY CHECKS
    auto PERSISTENTLEVEL = (*WORLD)->PersistentLevel;
    if (PERSISTENTLEVEL == nullptr)
        return;

    //Check if its local player and not draw
    if (LocalPlayer == nullptr)
        return;
    //Check for player controler
    if (Player_Controller == nullptr)
        return;

    //Check for acknowleged pawn
    if (Pawn == nullptr)
        return;
    //CHECK FOR ROOT COMPONENT
    if (Root == nullptr)
        return;




    CG::FVector2D screen;




    //draw objects on map 
    auto Actor_Array = PERSISTENTLEVEL->Actors;
    for (int i = 0; i < Actor_Array.Count(); i++)
    {
        auto Current_Actor = Actor_Array[i];
        {
            if (Current_Actor == nullptr) continue;
            if (Current_Actor->RootComponent == nullptr) continue;

            if (visuals::worldesp)
            {
                auto weapon_552 = Current_Actor->IsA(CG::ABP_Weapon_552_C::StaticClass()); //552
                auto weapon_AK47 = Current_Actor->IsA(CG::ABP_Weapon_AK47_C::StaticClass()); //AK47
                auto weapon_M4A1 = Current_Actor->IsA(CG::ABP_Weapon_M4A1_C::StaticClass()); //m4a1
                auto weapon_AUG = Current_Actor->IsA(CG::ABP_Weapon_AUG_C::StaticClass()); //aug
                auto weapon_MP5 = Current_Actor->IsA(CG::ABP_Weapon_MP5_C::StaticClass()); //mp5
                auto weapon_UMP = Current_Actor->IsA(CG::ABP_Weapon_UMP45_C::StaticClass()); //Ump
                auto weapon_M14 = Current_Actor->IsA(CG::ABP_Weapon_M14_C::StaticClass()); //m14
                if (!(weapon_552 || weapon_M14 || weapon_UMP || weapon_MP5 || weapon_AUG || weapon_M4A1 || weapon_AK47))
                {
                    continue;    // Do something
                }

                if (Player_Controller->ProjectWorldLocationToScreen(Current_Actor->RootComponent->RelativeLocation, &screen, false))
                {
                    auto draw = ImGui::GetBackgroundDrawList();

                    if (visuals::showguns)
                    {
                        ImVec2 sz = ImGui::CalcTextSize(Current_Actor->GetName().c_str(), NULL, true);
                        draw->AddText(ImVec2(screen.X - sz.x / 2 - 1, screen.Y - 15), ImColor(255, 0, 0), Current_Actor->GetName().c_str());
                        //draw->AddText(ImVec2(screen.X - sz.x / 2 - 1, screen.Y - 30), ImColor(255, 0, 0), "%i", distance);
                    }


                }

            }


            if (visuals::projectileesp)
            {

                auto weapon_M18 = Current_Actor->IsA(CG::ABP_Weapon_M18_C::StaticClass()); //m18 grenade
                auto weapon_M67 = Current_Actor->IsA(CG::ABP_Weapon_M67_C::StaticClass());//UMP
                if (!(weapon_M67 || weapon_M18))
                {
                    continue;    // Do something
                }

                if (Player_Controller->ProjectWorldLocationToScreen(Current_Actor->RootComponent->RelativeLocation, &screen, false))
                {
                    auto draw = ImGui::GetBackgroundDrawList();

                    if (visuals::projectileesp)
                    {
                        ImVec2 sz = ImGui::CalcTextSize(Current_Actor->GetName().c_str(), NULL, true);
                        draw->AddText(ImVec2(screen.X - sz.x / 2 - 1, screen.Y - 15), ImColor(255, 0, 0), Current_Actor->GetName().c_str());
                        //draw->AddText(ImVec2(screen.X - sz.x / 2 - 1, screen.Y - 30), ImColor(255, 0, 0), "%i", distance);
                    }
                }

            }



        }


    }
}


void drawingShit::staticDrawing()
{

    if (weapon::drawFov)
    {
        auto draw = ImGui::GetBackgroundDrawList();

        draw->AddCircle(ImVec2(1920 / 2, 1080 / 2), weapon::fovSize, ImColor(255, 255, 255), 100, 0);

        if (weapon::fovFilled)
        {
            draw->AddCircleFilled(ImVec2(1920 / 2, 1080 / 2), weapon::fovSize, ImColor(0, 0, 0, 90), 100);
        }



    }

    if (weapon::drawCrosshair)
    {
        auto draw = ImGui::GetBackgroundDrawList();

        draw->AddCircleFilled(ImVec2(1920 / 2, 1080 / 2), 2, ImColor(255, 0, 0), 0);
        
    }


}
