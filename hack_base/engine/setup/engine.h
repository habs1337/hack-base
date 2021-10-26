
class c_engine {
public:

	
#ifdef CRT
	c_console m_console;
#endif

	c_modules m_modules;
	c_offset m_offsets;
	c_hook_manager m_hook_manager;
	c_sdk m_sdk;


	c_engine();


	bool initialize();

	void hook_functions();
	void unhook_functions();
};

extern c_engine g_engine;