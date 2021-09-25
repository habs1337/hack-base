#include "../../hack_includes.h"




#ifdef CRT

bool c_console::initialize() {
	AllocConsole();
	freopen_s(&m_write_stream, "con", "w", stdout);

	return true;
}

bool c_console::disable() {
	fclose(m_write_stream);
	FreeConsole();

	return true;
}
#endif
