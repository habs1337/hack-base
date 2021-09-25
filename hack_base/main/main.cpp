#include "../hack_includes.h"


BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {

	if (fdwReason == DLL_PROCESS_ATTACH) {

		if (g_engine.initialize()) {
			g_engine.hook_functions();
		}
		
	}

	return true;
} 