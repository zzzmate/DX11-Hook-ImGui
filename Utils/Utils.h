#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <thread>
#include <MinHook.h> // @IF ERROR: install please vcpkg then run this: "vcpkg install minhook:x64-windows-static"

#include "./ImGui/imgui.h"
#include "./ImGui/imgui_impl_win32.h"
#include "./ImGui/imgui_impl_dx11.h"

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

namespace Utils {
	inline bool keyPressed(int vKey)
	{
		return (GetAsyncKeyState(vKey) & 1) != 0;
	}
}