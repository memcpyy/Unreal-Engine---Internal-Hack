#pragma once
#define DEBUG 1

#include <windows.h>
#include <Psapi.h>
#include <TlHelp32.h>

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

#include <iostream>
#include <conio.h>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

//	External Libraries
#include "../libs/ImGui/imgui.h"
#include "../libs/ImGui/imgui_internal.h"
#include "../libs/ImGui/imgui_Impl_dx11.h"
#include "../libs/ImGui/imgui_Impl_Win32.h"
#include "../libs/MinHook/MinHook.h"

//	INTERNET
#include <Wininet.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "wininet.lib")

namespace DX11_Base {
	using namespace std::chrono_literals;
	inline HMODULE g_hModule{};
	inline LPCWSTR g_ModuleName{};
	inline std::atomic_bool g_Running{};
	inline std::atomic_bool g_KillSwitch = FALSE;
	static uintptr_t dwGameBase = (uintptr_t)GetModuleHandleA(NULL);

	struct Vector2 {
		float x, y;
	};

	struct Vector3 {
		float x, y, z;
	};

	struct Vector4 {
		float x, y, z, w;
	};

	struct DoubleVector2 {
		double x, y;
	};

	struct DoubleVector3 {
		double x, y, z;
	};

	struct DoubleVector4 {
		double x, y, z, w;
	};

	struct matrix
	{
		float Matrix[16];
	};
}


namespace weapon
{
	inline bool aimbot = false;
	inline bool noRecoil = false;
	inline float smoothing = 10.f;
	inline float rcsAmount = 10.f;
	inline int rcsAmountY = 0;
	inline int rcsAmountX = 0;
	inline bool rapid_fire = false;
	inline bool unlimited_ammo = false;
	inline bool no_recoil = false;
	inline bool drawFov = false;
	inline int fovSize = 100;
	inline bool fovFilled = false;
	inline int crosshairSize = 4;
	inline int crosshiarStyle = 0;
	inline bool drawCrosshair = false;
}
namespace visuals
{
	inline int espStyle = 0;

	inline bool cornerbox = false;
	inline bool esp = false;
	inline bool SnapLines = false;
	inline bool Botesp = false;
	inline bool ShowTeam = false;
	inline bool heldtItem = false;

	inline bool names = false;
	inline bool playerDistance = false;
	inline bool lootnames = false;
	inline bool lootDistance = false;
	inline bool boxEsp = false;
	inline bool worldesp = false;
	inline bool projectileesp = false;
	inline bool showguns = false;


	
	


}

namespace misc
{
	inline bool godmode = false;
	inline bool customFov = false;
	inline float customFov_Amount = 90.f;
	inline int movementmode = 1;
}