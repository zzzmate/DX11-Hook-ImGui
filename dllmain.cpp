#include "Utils/Utils.h"
#include "Utils/Backend/Backend.h"

#define QWORD int64_t

// run it in Release | x64, already set up everything

QWORD WINAPI MainThread(LPVOID param)
{
	RunBackend.Load(); // load everything

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(420)); // no cpu frying in my city
		if (Utils::keyPressed(VK_END)) break;  // uninject 
	}
	
	RunBackend.Unload(); // unload everything
	return 0;
}

BOOL __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case 1:
		HANDLE hMainThread = CreateThread(nullptr, 0, LPTHREAD_START_ROUTINE(MainThread), hModule, 0, nullptr);
		if (hMainThread)
			CloseHandle(hMainThread);
		break;
	}

	return TRUE;
}