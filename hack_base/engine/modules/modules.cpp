#include "../../hack_includes.h"



bool c_modules::initialize() {
	
	this->m_base_handle.find_module();



	this->m_shell.find_module(XORSTR(L"\\cshell_x64.dll"));
	this->m_client_fx.find_module(XORSTR(L"\\clientfx_x64.fxd"));
	this->m_d3d9.find_module(XORSTR(L"\\d3d9.dll"));

#ifndef SELL_BUILD	
#ifdef CRT //output
	printf("modules:\n");
#else
	g_mini_crt::string::debug_text("modules:", 0);
	g_mini_crt::string::debug_integer("m_base_handle:", this->m_base_handle.m_start, 16, 0);
	g_mini_crt::string::debug_integer("m_shell:", this->m_shell.m_start, 16, 0);
	g_mini_crt::string::debug_integer("m_client_fx:", this->m_client_fx.m_start, 16, 0);
	g_mini_crt::string::debug_integer("m_d3d9:", this->m_d3d9.m_start, 16, 0);
#endif
#endif
	
	if (!this->m_base_handle.is_valid() || !this->m_shell.is_valid() || !this->m_client_fx.is_valid() || !this->m_d3d9.is_valid()) {
		return false;
	}

	return true;
}
