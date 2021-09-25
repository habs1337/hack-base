


class c_offset {
public:	
	/*vcaller address*/
	g_cheat::memory::c_address m_virtual_caller;
	/*interfaces*/
	g_cheat::memory::c_address m_hwnd;

	/*vtables*/
	g_cheat::memory::c_address m_device_table;

	c_offset() = default;

	bool initialize(c_modules& modules);

};