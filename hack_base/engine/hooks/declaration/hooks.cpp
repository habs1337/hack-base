#include "../../../hack_includes.h"

c_table::c_table() {
	m_table_ptr = nullptr;
	m_valid = false;
	m_hook = g_cheat::memory::hooks::c_vmt();
}


c_table::c_table(g_cheat::memory::c_address table_ptr) {
	m_table_ptr = table_ptr;
	m_valid = false;
	m_hook = g_cheat::memory::hooks::c_vmt();

	this->initialize();
}


bool c_table::initialize() {
    
	if (m_hook.init(m_table_ptr.as<void**>())) {
		m_valid = true;
	}

	return m_valid;

}



bool c_hook_manager::initialize(c_offset& offsets) {

	this->m_device = c_table(offsets.m_virtual_table.m_device_table);

#ifndef SELL_BUILD
#ifdef CRT
	printf("hook tables:\n");	
#else
	g_mini_crt::string::debug_text("hook tables", 0);
	g_mini_crt::string::debug_integer("device:", static_cast<uintptr_t>(this->m_device.m_valid), 16, 0);
#endif
#endif

	if (!this->m_device.m_valid) {
		return false;
	}

	return true;
}


WNDPROC hooks::original_wnd_proc = nullptr;