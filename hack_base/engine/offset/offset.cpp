#include "../../hack_includes.h"



bool c_offset::initialize(c_modules& modules) {
	
	this->m_virtual_caller = modules.m_base_handle.find_pattern(XORSTR("\xFF\x27"), XORSTR("xx"));

#ifndef SELL_BUILD
#ifdef CRT
	printf("interfaces:\n");
#endif
	g_mini_crt::string::debug_text("interfaces:");
	g_mini_crt::string::debug_text("m_hwnd:", this->m_hwnd, 16);
	g_mini_crt::string::debug_text("device_table:", this->m_device_table, 16);
#endif

	if (!this->m_hwnd.is_valid() || !this->m_device_table.is_valid()) {
		return false;
	}


	return true;
}