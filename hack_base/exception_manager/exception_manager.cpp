#include "../hack_includes.h"

#ifdef CRT
#ifndef SELL_BUILD

//define this if you need output to file
//#define LOGS_PATH "D:\\rust_internal\\"

namespace g_cheat::memory::exception_manager {

    PVOID exception_status = 0;
    size_t logs_counter = 0;
    uintptr_t base_module_handle = 0;

    bool is_bad_code_ptr(uintptr_t mod, void* ptr) {
        auto nt_header = PIMAGE_NT_HEADERS(mod + (PIMAGE_DOS_HEADER(mod))->e_lfanew);

        if (!nt_header)
            return true;

        auto section = IMAGE_FIRST_SECTION(nt_header);

        if (!section)
            return true;

        for (size_t i = 0; i < nt_header->FileHeader.NumberOfSections; i++, section++) {
            if ((section->Characteristics & IMAGE_SCN_MEM_EXECUTE) &&
                (uintptr_t(ptr) >= (mod + section->VirtualAddress)) &&
                (uintptr_t(ptr) < (mod + section->VirtualAddress + section->Misc.VirtualSize)))
                return false;
        }

        return true;
    }

    LONG WINAPI handle_exception(struct _EXCEPTION_POINTERS* ExceptionInfo)
    {
        PCONTEXT context = ExceptionInfo->ContextRecord;

        PEXCEPTION_RECORD exception_record = ExceptionInfo->ExceptionRecord;

#ifdef _AMD64_
        context->Rip++;
#else
        context->Eip++;
#endif    
        if (is_bad_code_ptr(base_module_handle, exception_record->ExceptionAddress)) {
            return EXCEPTION_EXECUTE_HANDLER;
        }

#ifdef LOGS_PATH
        std::string path = LOGS_PATH;
        path += "log_" + std::to_string(logs_counter);
        std::ofstream outfile(path);

        if (outfile.is_open() && outfile.good()) {
            outfile << "exception address:" << exception_record->ExceptionAddress << std::endl
                << "exception offset:" << reinterpret_cast<uintptr_t>(exception_record->ExceptionAddress) - base_module_handle << std::endl
                << "exception code:" << exception_record->ExceptionCode << std::endl
                << "exception flags:" << exception_record->ExceptionFlags << std::endl
                << "exception information:" << exception_record->ExceptionInformation << std::endl
                << "exception parameters:" << exception_record->NumberParameters << std::endl;


            outfile.close();
            logs_counter++;
        }
        else {
            printf("VEH exception!!! could not write to file!\n");
            printf("VEH exception!!! exception offset:%llx\n", reinterpret_cast<uintptr_t>(exception_record->ExceptionAddress) - base_module_handle);
            //g_mini_crt::string::debug_text("could not write to file!", 0);
            //g_mini_crt::string::debug_integer("exception offset", reinterpret_cast<uintptr_t>(exception_record->ExceptionAddress) - base_module_handle, 16, 0);
        }
#else
        //g_mini_crt::string::debug_integer("exception offset", reinterpret_cast<uintptr_t>(exception_record->ExceptionAddress) - base_module_handle, 16, 0);
        printf("VEH exception!!! exception offset:%llx\n", reinterpret_cast<uintptr_t>(exception_record->ExceptionAddress) - base_module_handle);
#endif
        return EXCEPTION_EXECUTE_HANDLER;
    }


    void on_work() {
        exception_status = AddVectoredExceptionHandler(1, handle_exception); //CALL_FIRST
    }

    void on_stop() {
        if (exception_status) {
            RemoveVectoredExceptionHandler(exception_status);
        }
    }

    void set_module_base(uintptr_t module_base) {
        base_module_handle = module_base;
    }
}
#endif
#endif