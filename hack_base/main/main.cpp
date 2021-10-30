#include "../hack_includes.h"
#ifdef CRT

g_cheat::memory::c_thread_manager g_thread_manager;

void main_thread() {
	if (g_engine.initialize()) {
		g_engine.hook_functions();
	}

	while (!GetAsyncKeyState(VK_DELETE))
		Sleep(100);

#ifndef SELL_BUILD
	g_engine.m_console.disable();
#endif
	g_engine.unhook_functions();
	g_cheat::memory::exception_manager::on_stop();

	g_thread_manager.delete_threads();

}
#endif


BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {

	if (fdwReason == DLL_PROCESS_ATTACH) {		
#ifdef CRT
		g_thread_manager.set_module_handle(hinstDLL);
		g_thread_manager.add_thread("main_thread", main_thread);
#else
		if (g_engine.initialize()) {
			g_engine.hook_functions();
		}
#endif

	}

	return true;
} 