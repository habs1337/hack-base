namespace hooks {

	namespace types {
		typedef void*(*reset_fn)(LPDIRECT3DDEVICE9*, D3DPRESENT_PARAMETERS*);
		typedef void* (*present_fn)(LPDIRECT3DDEVICE9*, const RECT*, const RECT*, HWND, const RGNDATA*);
		typedef void* (*end_scene_fn)(LPDIRECT3DDEVICE9*);

		typedef void*(*wnd_proc_fn)(HWND, UINT, WPARAM, LPARAM);
	}

	namespace functions {
		void* hk_reset(LPDIRECT3DDEVICE9* device, D3DPRESENT_PARAMETERS* parameter); //rcx edx r8 r9
		void* hk_present(LPDIRECT3DDEVICE9* device, const RECT* source_rect, const RECT* dest_rect, HWND dest_window_override, const RGNDATA* dirty_region); 
		void* hk_end_scene(LPDIRECT3DDEVICE9* device); 

		LRESULT hk_wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	}

	namespace indexes {
		enum {
			RESET = 16,
			PRESENT,
			END_SCENE = 42
		};
	}

	extern WNDPROC original_wnd_proc;
}


class c_table {
public:

	g_cheat::memory::c_address m_table_ptr;
	g_cheat::memory::hooks::c_vmt m_hook;
	bool m_valid;

	c_table();
	c_table(g_cheat::memory::c_address table_ptr);

	bool initialize();


};


class c_hook_manager {
public:
	c_table m_device;

	c_hook_manager() = default;

	bool initialize(c_offset& offsets);
};
