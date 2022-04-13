#include "../../../hack_includes.h"


LRESULT hooks::functions::hk_wnd_proc(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param) {
    
    //return g_engine.m_offsets.m_sdk.m_virtual_caller.call_spoofed_function<LRESULT>(CallWindowProcA, original_wnd_proc, hwnd, msg, w_param, l_param);
    return 0;
}