#include "../../hack_includes.h"



bool c_offset::initialize(c_modules& modules) {
	
	this->m_sdk.m_virtual_caller = modules.m_base_handle.find_pattern(XORSTR("\xFF\x27"), XORSTR("xx"));

#ifndef SELL_BUILD
#ifdef CRT
	printf("virtual tables:\n");
	printf("window descriptor:%x\n", this->m_virtual_table.m_window_descriptor);
	printf("swapchain:%x\n\n", this->m_virtual_table.m_device_table);

	printf("functions:\n");
	printf("0:%x\n\n", 0);

	printf("render:\n");
	printf("0:%x\n\n", 0);

	printf("sdk:\n");
	printf("0:%x\n\n", 0);
#else
	g_mini_crt::string::debug_text("virtual tables:", 0);
	g_mini_crt::string::debug_integer("m_hwnd:", this->m_virtual_table.m_window_descriptor, 16, 0);
	g_mini_crt::string::debug_integer("device_table:", this->m_virtual_table.m_device_table, 16, 0);

	g_mini_crt::string::debug_text("functions:", 0);
	g_mini_crt::string::debug_integer("0:",  0, 16, 0);

	g_mini_crt::string::debug_text("render:", 0);
	g_mini_crt::string::debug_integer("0:", 0, 16, 0);

	g_mini_crt::string::debug_text("sdk:", 0);
	g_mini_crt::string::debug_integer("0:", 0, 16, 0);
#endif
#endif

	if (!this->m_virtual_table.m_window_descriptor.is_valid() || !this->m_virtual_table.m_device_table.is_valid()) {
		return false;
	}


	return true;
}