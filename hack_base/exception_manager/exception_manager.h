#ifndef SELL_BUILD

namespace g_cheat::memory::exception_manager {

    bool is_bad_code_ptr(uintptr_t mod, void* ptr);
    LONG WINAPI handle_exception(struct _EXCEPTION_POINTERS* ExceptionInfo);
    void on_work();
    void on_stop();
    void set_module_base(uintptr_t module_base);

}

#endif 

