


class c_modules {
public:
	g_cheat::memory::c_module m_base_handle;
	g_cheat::memory::c_module m_shell;
	g_cheat::memory::c_module m_client_fx;
	g_cheat::memory::c_module m_d3d9;

	c_modules() = default;

	bool initialize();

};


