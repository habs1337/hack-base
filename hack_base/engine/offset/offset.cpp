#include "../../hack_includes.h"



bool c_offset::initialize(c_modules& modules) {
	
	this->m_virtual_caller = modules.m_base_handle.find_pattern(XORSTR("\xFF\x27"), XORSTR("xx"));

#ifndef SELL_BUILD
#ifdef CRT
	printf("interfaces:\n");
#else
	g_mini_crt::string::debug_text("interfaces:", 0);
	g_mini_crt::string::debug_integer("m_hwnd:", this->m_hwnd, 16, 0);
	g_mini_crt::string::debug_integer("device_table:", this->m_device_table, 16, 0);
#endif
#endif

	if (!this->m_hwnd.is_valid() || !this->m_device_table.is_valid()) {
		return false;
	}


	return true;
}