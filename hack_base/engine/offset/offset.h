


class c_offset {
public:	

	struct virtual_table {
		g_cheat::memory::c_address m_window_descriptor; // hwnd
		g_cheat::memory::c_address m_device_table;

	}m_virtual_table;

	struct virtual_function_t {
		

	}m_virtual_function;

	struct render_t {

	}m_render;

	struct sdk_t {
		g_cheat::memory::c_address m_virtual_caller;

	}m_sdk;



	c_offset() = default;

	bool initialize(c_modules& modules);

};