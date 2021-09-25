#include "../../../hack_includes.h"


void* hooks::functions::hk_end_scene(LPDIRECT3DDEVICE9* device) {

    auto end_scene_original = g_engine.m_hook_manager.m_device.m_hook.call_original_method<hooks::types::end_scene_fn>
        (hooks::indexes::END_SCENE);

    
    return g_engine.m_offsets.m_virtual_caller.call_spoofed_function<void*>(end_scene_original, device);
}