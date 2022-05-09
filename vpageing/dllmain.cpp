// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

UINT32* memaccesstmp;
int pagesize;
UINT8* tempmem;
int (*memaccesses)(UINT32, int, int);
int (*pagehandler)(int);

#ifdef __cplusplus
extern "C" {
#endif

    __declspec(dllexport) void memaccessptrset(UINT32* tmp, int tmp2) { memaccesstmp = tmp; pagesize = tmp2; }
    __declspec(dllexport) void setmemaccess4nonmac(int (*tmp)(UINT32, int, int)) { memaccesses = tmp; }
    __declspec(dllexport) void setpagehandler(int (*tmp)(int)) { pagehandler = tmp; }
    __declspec(dllexport) int memaccessmod(UINT32 addr, int val, int type) { switch (type) { case 0: if ((pagehandler != 0) && (memaccesstmp[addr / pagesize] == 0)) { if (pagehandler(addr) == 0) { return 0; } else if (pagehandler(addr) == 1) { return memaccesses(addr, val, type); } } tempmem[memaccesstmp[addr / pagesize] + (addr % pagesize)] = val; return 0; case 1: if ((pagehandler != 0) && (memaccesstmp[addr / pagesize] == 0)) { if (pagehandler(addr) == 0) { return 0; } else if (pagehandler(addr) == 1) { return memaccesses(addr, val, type); } } return tempmem[memaccesstmp[addr / pagesize] + (addr % pagesize)]; default: return memaccesses(addr, val, type); } }

#ifdef __cplusplus
}
#endif
