#include "../hack_includes.h"

FORCEINLINE void on_init() {
	//fix of TLS initialization
	g_engine = c_engine();

	if (g_engine.initialize()) {
		g_engine.hook_functions();
	}
}

#ifdef CRT
g_cheat::memory::c_thread_manager thread_manager;
void on_stop() {
	while (!GetAsyncKeyState(VK_DELETE))
		Sleep(100);

#ifndef SELL_BUILD
	g_engine.m_console.disable();
#endif
	g_engine.unhook_functions();

	g_cheat::memory::exception_manager::on_stop();

	thread_manager.delete_threads();
}
void main_thread() {
	on_init();
	on_stop();
}
#endif






BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {

	if (fdwReason == DLL_PROCESS_ATTACH) {		
#ifdef CRT
		g_cheat::memory::exception_manager::set_module_base(reinterpret_cast<uintptr_t>(hinstDLL));
		g_cheat::memory::exception_manager::on_work();
		thread_manager.set_module_handle(hinstDLL);
		thread_manager.add_thread("main_thread", main_thread);
#else
		on_init();
#endif

	}

	return true;
} 