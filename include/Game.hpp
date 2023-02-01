#pragma once
#include "helper.h"
#include "Console.hpp"

namespace DX11_Base {
	struct Offsets
	{  
		int oGObjects = 0x30556F8;// OLD 0x30526B8;    //    OLD 0x030574B8;    //    OLD 0x3155DD0;        //    OLD    0x3154D10;
		int oFNames = 0x303E180;// OLD 0x303B140;    //    OLD 0x0303FF40;    //    OLD 0x3155DD0;        //    OLD    0x3154D10;
		int oUWorld = 0x3156850;// OLD 0x3153800; // OLD 0x3155680;    //    OLD 0x3158640;    //    OLD 0x3155DD0;        //    OLD 0x3154D10;
	};
	class GameData
	{
	public:
		Offsets offsets;
		explicit GameData();
		~GameData() noexcept = default;
		GameData(GameData const&) = delete;
		GameData(GameData&&) = delete;
		GameData& operator=(GameData const&) = delete;
		GameData& operator=(GameData&&) = delete;
	};

	class GameVariables
	{
	public:

		//	Dx & ImGui
		int g_GamePid{};
		HANDLE g_GameHandle{};
		HWND g_GameWindow{};
		int g_GameWidth;
		int g_GameHeight;
		ImVec2 g_WindowSize{};
		LPCSTR g_GameTitle;
		LPCSTR g_ClassName;
		LPCSTR g_GamePath;

		//	MENU RELATED
		bool m_ShowMenu{};
		bool m_ShowHud{};
		bool m_ShowDemo{};

		explicit GameVariables();
		~GameVariables() noexcept = default;
		GameVariables(GameVariables const&) = delete;
		GameVariables(GameVariables&&) = delete;
		GameVariables& operator=(GameVariables const&) = delete;
		GameVariables& operator=(GameVariables&&) = delete;

		void Init();
	};

	inline std::unique_ptr<GameData> g_GameData;
	inline std::unique_ptr<GameVariables> g_GameVariables;
}

