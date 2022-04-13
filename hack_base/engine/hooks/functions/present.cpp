#include "../../../hack_includes.h"


void* hooks::functions::hk_present(LPDIRECT3DDEVICE9* device, const RECT* source_rect, const RECT* dest_rect, HWND dest_window_override, const RGNDATA* dirty_region) {

    auto present_original = g_engine.m_hook_manager.m_device.m_hook.call_original_method<hooks::types::present_fn>
        (hooks::indexes::PRESENT);
    
   //return g_engine.m_offsets.m_sdk.m_virtual_caller.call_spoofed_function<void*>(present_original, device, source_rect, dest_rect, dest_window_override, dirty_region);
    return 0;
}