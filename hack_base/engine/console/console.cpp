#include "../../hack_includes.h"




#ifdef CRT

bool c_console::initialize() {
	m_is_opened_console = AllocConsole();
	if (m_is_opened_console) {
		freopen_s(&m_write_stream, "con", "w", stdout);
		return true;
	}

	return false;
}

bool c_console::disable() {
	if (m_is_opened_console) {
		fclose(m_write_stream);
		FreeConsole();
		return true;
	}

	return false;
}
#endif
