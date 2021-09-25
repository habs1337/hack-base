#include "../../hack_includes.h"




c_engine::c_engine() {
	this->m_modules = c_modules();
	this->m_offsets = c_offset();
	this->m_hook_manager = c_hook_manager();
	this->m_sdk = c_sdk();
}


bool c_engine::initialize() {

#ifndef SELL_BUILD
#ifdef CRT
	if (!this->m_console.initialize()) {
		return false;
	}
#endif
#endif

	if (!this->m_modules.initialize()) {
		return false;
	}
	
	if (!this->m_offsets.initialize(this->m_modules)) {
		return false;
	}
	

	if (!this->m_hook_manager.initialize(this->m_offsets)) {
		return false;
	}

	if (!this->m_sdk.initialize(this->m_offsets)) {
		return false;
	}

	return true;
}

void c_engine::hook_functions() {

	
	hooks::original_wnd_proc = this->m_offsets.m_virtual_caller.call_spoofed_function<WNDPROC>(SetWindowLongPtrA, this->m_offsets.m_hwnd.as<HWND>(), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(hooks::functions::hk_wnd_proc));
	this->m_hook_manager.m_device.m_hook.setup_hook(hooks::indexes::RESET, g_cheat::memory::hooks::c_vmt::force_cast(&hooks::functions::hk_reset));
	this->m_hook_manager.m_device.m_hook.setup_hook(hooks::indexes::PRESENT, g_cheat::memory::hooks::c_vmt::force_cast(&hooks::functions::hk_present));
	this->m_hook_manager.m_device.m_hook.setup_hook(hooks::indexes::END_SCENE, g_cheat::memory::hooks::c_vmt::force_cast(&hooks::functions::hk_end_scene));
}


c_engine g_engine;