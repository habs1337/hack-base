#include "../../../hack_includes.h"



void* hooks::functions::hk_reset(LPDIRECT3DDEVICE9* device, D3DPRESENT_PARAMETERS* parameter) {
  
    auto reset_original = g_engine.m_hook_manager.m_device.m_hook.call_original_method<hooks::types::reset_fn>
        (hooks::indexes::RESET);
   
    //return g_engine.m_offsets.m_sdk.m_virtual_caller.call_spoofed_function<void*>(reset_original, device, parameter);
    return 0;
}