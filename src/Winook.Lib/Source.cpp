#include "Source.h"
#include "Winook.h"
#include "MessageSender.h"
#include "StreamLineReader.h"

#include <cinttypes>
#include <regex>
#include <string>

#define LOGWINOOKLIB 0
#if _DEBUG && LOGWINOOKLIB
#define LOGWINOOKLIBPATH TEXT("C:\\Temp\\WinookLibHookProc_")
#include "DebugHelper.h"
TimestampLogger Logger = TimestampLogger(LOGWINOOKLIBPATH + TimestampLogger::GetTimestampString(TRUE) + TEXT(".log"), TRUE);
#endif

asio::io_context io_context;
MessageSender messagesender(io_context);

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD fdwReason, LPVOID lpReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
#if _DEBUG
        LogDllMain(hinst, TEXT("DLL_PROCESS_ATTACH"));
#endif
        Initialize(hinst);
        break;

    case DLL_THREAD_ATTACH:
#if _DEBUG
        LogDllMain(hinst, TEXT("DLL_THREAD_ATTACH"));
#endif
        break;

    case DLL_THREAD_DETACH:
#if _DEBUG
        LogDllMain(hinst, TEXT("DLL_THREAD_DETACH"));
#endif
        break;

    case DLL_PROCESS_DETACH:
#if _DEBUG
        LogDllMain(hinst, TEXT("DLL_PROCESS_DETACH"));
#endif
        break;
    }

    return TRUE;
}

void Initialize(HINSTANCE hinst)
{
    // Look for initialization file stored in %TEMP%

    TCHAR modulepath[kPathBufferSize];
    GetModuleFileName(NULL, modulepath, kPathBufferSize);
    const auto configfilepath = Winook::GetConfigFilePath(modulepath, hinst, GetCurrentProcessId(), GetThreadId(GetCurrentThread()));
    WIN32_FIND_DATA findfiledata;
    const auto find = FindFirstFile(configfilepath.c_str(), &findfiledata);
    if (find != INVALID_HANDLE_VALUE)
    {
        FindClose(find);
        StreamLineReader configfile(configfilepath);
        const auto port = std::stoi(configfile.ReadLine());
        configfile.Close();
        DeleteFile(configfilepath.c_str());
        messagesender.Connect(std::to_string(port));
    }
    else
    {
        // TODO: handle error
    }
}

#if _DEBUG
void LogDllMain(HINSTANCE hinst, std::wstring reason)
{
#if LOGWINOOKLIB
    std::wstringstream wss;
    wss << std::setw(16) << std::setfill(L'0') << std::hex << hinst;
    TCHAR procInfo[256];
    swprintf(procInfo, sizeof(procInfo), TEXT("Instance: %lx; Reason: %ls; ProcessId: %d; ThreadId: %d"), 
        PtrToLong(hinst), reason.c_str(), GetCurrentProcessId(), GetThreadId(GetCurrentThread()));
    Logger.WriteLine(procInfo);
#endif
}
#endif

LRESULT CALLBACK KeyboardHookProc(int code, WPARAM wParam, LPARAM lParam)
{
#if _DEBUG && LOGWINOOKLIB
    Logger.WriteLine(DebugHelper::FormatKeyboardHookMessage(code, wParam, lParam));
#endif
    if (code == HC_ACTION)
    {
        HookKeyboardMessage hkm;
        hkm.virtualKeyCode = (DWORD)wParam;
        hkm.flags = (DWORD)lParam;
        messagesender.SendMessage(&hkm, sizeof(HookKeyboardMessage));
    }

    return CallNextHookEx(NULL, code, wParam, lParam);
}

LRESULT CALLBACK MouseHookProc(int code, WPARAM wParam, LPARAM lParam) 
{
#if _DEBUG && LOGWINOOKLIB
    Logger.WriteLine(DebugHelper::FormatMouseHookMessage(code, wParam, lParam));
#endif
    if (code == HC_ACTION)
    {
        HookMouseMessage hmm{};
        hmm.messageCode = (DWORD)wParam;
        if (wParam == WM_MOUSEWHEEL)
        {
            auto pmhsx = (PMOUSEHOOKSTRUCTEX)lParam;
            hmm.pointX = pmhsx->pt.x;
            hmm.pointY = pmhsx->pt.y;
            hmm.hwnd = (DWORD)PtrToInt(pmhsx->hwnd);
            hmm.hitTestCode = (DWORD)pmhsx->wHitTestCode;
            hmm.zDelta = HIWORD(pmhsx->mouseData);
        }
        else
        {
            auto pmhs = (PMOUSEHOOKSTRUCT)lParam;
            hmm.pointX = pmhs->pt.x;
            hmm.pointY = pmhs->pt.y;
            hmm.hwnd = (DWORD)PtrToInt(pmhs->hwnd);
            hmm.hitTestCode = (DWORD)pmhs->wHitTestCode;
        }

        messagesender.SendMessage(&hmm, sizeof(HookMouseMessage));
    }

    return CallNextHookEx(NULL, code, wParam, lParam);
}