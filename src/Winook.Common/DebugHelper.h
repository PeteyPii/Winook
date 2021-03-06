#pragma once

#include <Windows.h>

#include <iomanip>
#include <map>
#include <sstream>
#include <string>

class DebugHelper
{
public:
    static std::wstring FormatWindowMessage(MSG msg);
    static std::wstring FormatWindowMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    static std::wstring FormatMouseHookMessage(int code, WPARAM wParam, LPARAM lParam);
    static std::wstring FormatKeyboardHookMessage(int code, WPARAM wParam, LPARAM lParam);
private:
    DebugHelper() { }
};

const std::map<UINT, std::wstring> kWindowMessageCodeMap =
{
    { WM_NULL, TEXT("WM_NULL") },
    { WM_CREATE, TEXT("WM_CREATE") },
    { WM_DESTROY, TEXT("WM_DESTROY") },
    { WM_MOVE, TEXT("WM_MOVE") },
    { WM_SIZE, TEXT("WM_SIZE") },
    { WM_ACTIVATE, TEXT("WM_ACTIVATE") },
    { WM_SETFOCUS, TEXT("WM_SETFOCUS") },
    { WM_KILLFOCUS, TEXT("WM_KILLFOCUS") },
    { WM_ENABLE, TEXT("WM_ENABLE") },
    { WM_SETREDRAW, TEXT("WM_SETREDRAW") },
    { WM_SETTEXT, TEXT("WM_SETTEXT") },
    { WM_GETTEXT, TEXT("WM_GETTEXT") },
    { WM_GETTEXTLENGTH, TEXT("WM_GETTEXTLENGTH") },
    { WM_PAINT, TEXT("WM_PAINT") },
    { WM_CLOSE, TEXT("WM_CLOSE") },
    { WM_QUERYENDSESSION, TEXT("WM_QUERYENDSESSION") },
    { WM_QUERYOPEN, TEXT("WM_QUERYOPEN") },
    { WM_ENDSESSION, TEXT("WM_ENDSESSION") },
    { WM_QUIT, TEXT("WM_QUIT") },
    { WM_ERASEBKGND, TEXT("WM_ERASEBKGND") },
    { WM_SYSCOLORCHANGE, TEXT("WM_SYSCOLORCHANGE") },
    { WM_SHOWWINDOW, TEXT("WM_SHOWWINDOW") },
    { WM_WININICHANGE, TEXT("WM_WININICHANGE") },
    { WM_DEVMODECHANGE, TEXT("WM_DEVMODECHANGE") },
    { WM_ACTIVATEAPP, TEXT("WM_ACTIVATEAPP") },
    { WM_FONTCHANGE, TEXT("WM_FONTCHANGE") },
    { WM_TIMECHANGE, TEXT("WM_TIMECHANGE") },
    { WM_CANCELMODE, TEXT("WM_CANCELMODE") },
    { WM_SETCURSOR, TEXT("WM_SETCURSOR") },
    { WM_MOUSEACTIVATE, TEXT("WM_MOUSEACTIVATE") },
    { WM_CHILDACTIVATE, TEXT("WM_CHILDACTIVATE") },
    { WM_QUEUESYNC, TEXT("WM_QUEUESYNC") },
    { WM_GETMINMAXINFO, TEXT("WM_GETMINMAXINFO") },
    { WM_PAINTICON, TEXT("WM_PAINTICON") },
    { WM_ICONERASEBKGND, TEXT("WM_ICONERASEBKGND") },
    { WM_NEXTDLGCTL, TEXT("WM_NEXTDLGCTL") },
    { WM_SPOOLERSTATUS, TEXT("WM_SPOOLERSTATUS") },
    { WM_DRAWITEM, TEXT("WM_DRAWITEM") },
    { WM_MEASUREITEM, TEXT("WM_MEASUREITEM") },
    { WM_DELETEITEM, TEXT("WM_DELETEITEM") },
    { WM_VKEYTOITEM, TEXT("WM_VKEYTOITEM") },
    { WM_CHARTOITEM, TEXT("WM_CHARTOITEM") },
    { WM_SETFONT, TEXT("WM_SETFONT") },
    { WM_GETFONT, TEXT("WM_GETFONT") },
    { WM_SETHOTKEY, TEXT("WM_SETHOTKEY") },
    { WM_GETHOTKEY, TEXT("WM_GETHOTKEY") },
    { WM_QUERYDRAGICON, TEXT("WM_QUERYDRAGICON") },
    { WM_COMPAREITEM, TEXT("WM_COMPAREITEM") },
    { WM_GETOBJECT, TEXT("WM_GETOBJECT") },
    { WM_COMPACTING, TEXT("WM_COMPACTING") },
    { WM_COMMNOTIFY, TEXT("WM_COMMNOTIFY") },
    { WM_WINDOWPOSCHANGING, TEXT("WM_WINDOWPOSCHANGING") },
    { WM_WINDOWPOSCHANGED, TEXT("WM_WINDOWPOSCHANGED") },
    { WM_POWER, TEXT("WM_POWER") },
    { WM_COPYDATA, TEXT("WM_COPYDATA") },
    { WM_CANCELJOURNAL, TEXT("WM_CANCELJOURNAL") },
    { WM_NOTIFY, TEXT("WM_NOTIFY") },
    { WM_INPUTLANGCHANGEREQUEST, TEXT("WM_INPUTLANGCHANGEREQUEST") },
    { WM_INPUTLANGCHANGE, TEXT("WM_INPUTLANGCHANGE") },
    { WM_TCARD, TEXT("WM_TCARD") },
    { WM_HELP, TEXT("WM_HELP") },
    { WM_USERCHANGED, TEXT("WM_USERCHANGED") },
    { WM_NOTIFYFORMAT, TEXT("WM_NOTIFYFORMAT") },
    { WM_CONTEXTMENU, TEXT("WM_CONTEXTMENU") },
    { WM_STYLECHANGING, TEXT("WM_STYLECHANGING") },
    { WM_STYLECHANGED, TEXT("WM_STYLECHANGED") },
    { WM_DISPLAYCHANGE, TEXT("WM_DISPLAYCHANGE") },
    { WM_GETICON, TEXT("WM_GETICON") },
    { WM_SETICON, TEXT("WM_SETICON") },
    { WM_NCCREATE, TEXT("WM_NCCREATE") },
    { WM_NCDESTROY, TEXT("WM_NCDESTROY") },
    { WM_NCCALCSIZE, TEXT("WM_NCCALCSIZE") },
    { WM_NCHITTEST, TEXT("WM_NCHITTEST") },
    { WM_NCPAINT, TEXT("WM_NCPAINT") },
    { WM_NCACTIVATE, TEXT("WM_NCACTIVATE") },
    { WM_GETDLGCODE, TEXT("WM_GETDLGCODE") },
    { WM_SYNCPAINT, TEXT("WM_SYNCPAINT") },
    { WM_NCMOUSEMOVE, TEXT("WM_NCMOUSEMOVE") },
    { WM_NCLBUTTONDOWN, TEXT("WM_NCLBUTTONDOWN") },
    { WM_NCLBUTTONUP, TEXT("WM_NCLBUTTONUP") },
    { WM_NCLBUTTONDBLCLK, TEXT("WM_NCLBUTTONDBLCLK") },
    { WM_NCRBUTTONDOWN, TEXT("WM_NCRBUTTONDOWN") },
    { WM_NCRBUTTONUP, TEXT("WM_NCRBUTTONUP") },
    { WM_NCRBUTTONDBLCLK, TEXT("WM_NCRBUTTONDBLCLK") },
    { WM_NCMBUTTONDOWN, TEXT("WM_NCMBUTTONDOWN") },
    { WM_NCMBUTTONUP, TEXT("WM_NCMBUTTONUP") },
    { WM_NCMBUTTONDBLCLK, TEXT("WM_NCMBUTTONDBLCLK") },
    { WM_NCXBUTTONDOWN, TEXT("WM_NCXBUTTONDOWN") },
    { WM_NCXBUTTONUP, TEXT("WM_NCXBUTTONUP") },
    { WM_NCXBUTTONDBLCLK, TEXT("WM_NCXBUTTONDBLCLK") },
    { WM_INPUT_DEVICE_CHANGE, TEXT("WM_INPUT_DEVICE_CHANGE") },
    { WM_INPUT, TEXT("WM_INPUT") },
    { WM_KEYFIRST, TEXT("WM_KEYFIRST") },
    { WM_KEYDOWN, TEXT("WM_KEYDOWN") },
    { WM_KEYUP, TEXT("WM_KEYUP") },
    { WM_CHAR, TEXT("WM_CHAR") },
    { WM_DEADCHAR, TEXT("WM_DEADCHAR") },
    { WM_SYSKEYDOWN, TEXT("WM_SYSKEYDOWN") },
    { WM_SYSKEYUP, TEXT("WM_SYSKEYUP") },
    { WM_SYSCHAR, TEXT("WM_SYSCHAR") },
    { WM_SYSDEADCHAR, TEXT("WM_SYSDEADCHAR") },
    { WM_KEYLAST, TEXT("WM_KEYLAST") },
    { WM_KEYLAST, TEXT("WM_KEYLAST") },
    { WM_IME_STARTCOMPOSITION, TEXT("WM_IME_STARTCOMPOSITION") },
    { WM_IME_ENDCOMPOSITION, TEXT("WM_IME_ENDCOMPOSITION") },
    { WM_IME_COMPOSITION, TEXT("WM_IME_COMPOSITION") },
    { WM_IME_KEYLAST, TEXT("WM_IME_KEYLAST") },
    { WM_INITDIALOG, TEXT("WM_INITDIALOG") },
    { WM_COMMAND, TEXT("WM_COMMAND") },
    { WM_SYSCOMMAND, TEXT("WM_SYSCOMMAND") },
    { WM_TIMER, TEXT("WM_TIMER") },
    { WM_HSCROLL, TEXT("WM_HSCROLL") },
    { WM_VSCROLL, TEXT("WM_VSCROLL") },
    { WM_INITMENU, TEXT("WM_INITMENU") },
    { WM_INITMENUPOPUP, TEXT("WM_INITMENUPOPUP") },
    { WM_GESTURE, TEXT("WM_GESTURE") },
    { WM_GESTURENOTIFY, TEXT("WM_GESTURENOTIFY") },
    { WM_MENUSELECT, TEXT("WM_MENUSELECT") },
    { WM_MENUCHAR, TEXT("WM_MENUCHAR") },
    { WM_ENTERIDLE, TEXT("WM_ENTERIDLE") },
    { WM_MENURBUTTONUP, TEXT("WM_MENURBUTTONUP") },
    { WM_MENUDRAG, TEXT("WM_MENUDRAG") },
    { WM_MENUGETOBJECT, TEXT("WM_MENUGETOBJECT") },
    { WM_UNINITMENUPOPUP, TEXT("WM_UNINITMENUPOPUP") },
    { WM_MENUCOMMAND, TEXT("WM_MENUCOMMAND") },
    { WM_CHANGEUISTATE, TEXT("WM_CHANGEUISTATE") },
    { WM_UPDATEUISTATE, TEXT("WM_UPDATEUISTATE") },
    { WM_QUERYUISTATE, TEXT("WM_QUERYUISTATE") },
    { WM_CTLCOLORMSGBOX, TEXT("WM_CTLCOLORMSGBOX") },
    { WM_CTLCOLOREDIT, TEXT("WM_CTLCOLOREDIT") },
    { WM_CTLCOLORLISTBOX, TEXT("WM_CTLCOLORLISTBOX") },
    { WM_CTLCOLORBTN, TEXT("WM_CTLCOLORBTN") },
    { WM_CTLCOLORDLG, TEXT("WM_CTLCOLORDLG") },
    { WM_CTLCOLORSCROLLBAR, TEXT("WM_CTLCOLORSCROLLBAR") },
    { WM_CTLCOLORSTATIC, TEXT("WM_CTLCOLORSTATIC") },
    { MN_GETHMENU, TEXT("MN_GETHMENU") },
    { WM_MOUSEMOVE, TEXT("WM_MOUSEMOVE") },
    { WM_LBUTTONDOWN, TEXT("WM_LBUTTONDOWN") },
    { WM_LBUTTONUP, TEXT("WM_LBUTTONUP") },
    { WM_LBUTTONDBLCLK, TEXT("WM_LBUTTONDBLCLK") },
    { WM_RBUTTONDOWN, TEXT("WM_RBUTTONDOWN") },
    { WM_RBUTTONUP, TEXT("WM_RBUTTONUP") },
    { WM_RBUTTONDBLCLK, TEXT("WM_RBUTTONDBLCLK") },
    { WM_MBUTTONDOWN, TEXT("WM_MBUTTONDOWN") },
    { WM_MBUTTONUP, TEXT("WM_MBUTTONUP") },
    { WM_MBUTTONDBLCLK, TEXT("WM_MBUTTONDBLCLK") },
    { WM_MOUSEWHEEL, TEXT("WM_MOUSEWHEEL") },
    { WM_XBUTTONDOWN, TEXT("WM_XBUTTONDOWN") },
    { WM_XBUTTONUP, TEXT("WM_XBUTTONUP") },
    { WM_XBUTTONDBLCLK, TEXT("WM_XBUTTONDBLCLK") },
    { WM_MOUSEHWHEEL, TEXT("WM_MOUSEHWHEEL") },
    { WM_PARENTNOTIFY, TEXT("WM_PARENTNOTIFY") },
    { WM_ENTERMENULOOP, TEXT("WM_ENTERMENULOOP") },
    { WM_EXITMENULOOP, TEXT("WM_EXITMENULOOP") },
    { WM_NEXTMENU, TEXT("WM_NEXTMENU") },
    { WM_SIZING, TEXT("WM_SIZING") },
    { WM_CAPTURECHANGED, TEXT("WM_CAPTURECHANGED") },
    { WM_MOVING, TEXT("WM_MOVING") },
    { WM_POWERBROADCAST, TEXT("WM_POWERBROADCAST") },
    { WM_DEVICECHANGE, TEXT("WM_DEVICECHANGE") },
    { WM_MDICREATE, TEXT("WM_MDICREATE") },
    { WM_MDIDESTROY, TEXT("WM_MDIDESTROY") },
    { WM_MDIACTIVATE, TEXT("WM_MDIACTIVATE") },
    { WM_MDIRESTORE, TEXT("WM_MDIRESTORE") },
    { WM_MDINEXT, TEXT("WM_MDINEXT") },
    { WM_MDIMAXIMIZE, TEXT("WM_MDIMAXIMIZE") },
    { WM_MDITILE, TEXT("WM_MDITILE") },
    { WM_MDICASCADE, TEXT("WM_MDICASCADE") },
    { WM_MDIICONARRANGE, TEXT("WM_MDIICONARRANGE") },
    { WM_MDIGETACTIVE, TEXT("WM_MDIGETACTIVE") },
    { WM_MDISETMENU, TEXT("WM_MDISETMENU") },
    { WM_ENTERSIZEMOVE, TEXT("WM_ENTERSIZEMOVE") },
    { WM_EXITSIZEMOVE, TEXT("WM_EXITSIZEMOVE") },
    { WM_DROPFILES, TEXT("WM_DROPFILES") },
    { WM_MDIREFRESHMENU, TEXT("WM_MDIREFRESHMENU") },
    { WM_POINTERDEVICECHANGE, TEXT("WM_POINTERDEVICECHANGE") },
    { WM_POINTERDEVICEINRANGE, TEXT("WM_POINTERDEVICEINRANGE") },
    { WM_POINTERDEVICEOUTOFRANGE, TEXT("WM_POINTERDEVICEOUTOFRANGE") },
    { WM_TOUCH, TEXT("WM_TOUCH") },
    { WM_NCPOINTERUPDATE, TEXT("WM_NCPOINTERUPDATE") },
    { WM_NCPOINTERDOWN, TEXT("WM_NCPOINTERDOWN") },
    { WM_NCPOINTERUP, TEXT("WM_NCPOINTERUP") },
    { WM_POINTERUPDATE, TEXT("WM_POINTERUPDATE") },
    { WM_POINTERDOWN, TEXT("WM_POINTERDOWN") },
    { WM_POINTERUP, TEXT("WM_POINTERUP") },
    { WM_POINTERENTER, TEXT("WM_POINTERENTER") },
    { WM_POINTERLEAVE, TEXT("WM_POINTERLEAVE") },
    { WM_POINTERACTIVATE, TEXT("WM_POINTERACTIVATE") },
    { WM_POINTERCAPTURECHANGED, TEXT("WM_POINTERCAPTURECHANGED") },
    { WM_TOUCHHITTESTING, TEXT("WM_TOUCHHITTESTING") },
    { WM_POINTERWHEEL, TEXT("WM_POINTERWHEEL") },
    { WM_POINTERHWHEEL, TEXT("WM_POINTERHWHEEL") },
#ifdef __MINGW32__
    { 0x0250, TEXT("DM_POINTERHITTEST") },
#else
    { DM_POINTERHITTEST, TEXT("DM_POINTERHITTEST") },
#endif
    { WM_IME_SETCONTEXT, TEXT("WM_IME_SETCONTEXT") },
    { WM_IME_NOTIFY, TEXT("WM_IME_NOTIFY") },
    { WM_IME_CONTROL, TEXT("WM_IME_CONTROL") },
    { WM_IME_COMPOSITIONFULL, TEXT("WM_IME_COMPOSITIONFULL") },
    { WM_IME_SELECT, TEXT("WM_IME_SELECT") },
    { WM_IME_CHAR, TEXT("WM_IME_CHAR") },
    { WM_IME_REQUEST, TEXT("WM_IME_REQUEST") },
    { WM_IME_KEYDOWN, TEXT("WM_IME_KEYDOWN") },
    { WM_IME_KEYUP, TEXT("WM_IME_KEYUP") },
    { WM_MOUSEHOVER, TEXT("WM_MOUSEHOVER") },
    { WM_MOUSELEAVE, TEXT("WM_MOUSELEAVE") },
    { WM_NCMOUSEHOVER, TEXT("WM_NCMOUSEHOVER") },
    { WM_NCMOUSELEAVE, TEXT("WM_NCMOUSELEAVE") },
    { WM_WTSSESSION_CHANGE, TEXT("WM_WTSSESSION_CHANGE") },
    { WM_TABLET_FIRST, TEXT("WM_TABLET_FIRST") },
    { WM_TABLET_LAST, TEXT("WM_TABLET_LAST") },
    { WM_DPICHANGED, TEXT("WM_DPICHANGED") },
    { WM_CUT, TEXT("WM_CUT") },
    { WM_COPY, TEXT("WM_COPY") },
    { WM_PASTE, TEXT("WM_PASTE") },
    { WM_CLEAR, TEXT("WM_CLEAR") },
    { WM_UNDO, TEXT("WM_UNDO") },
    { WM_RENDERFORMAT, TEXT("WM_RENDERFORMAT") },
    { WM_RENDERALLFORMATS, TEXT("WM_RENDERALLFORMATS") },
    { WM_DESTROYCLIPBOARD, TEXT("WM_DESTROYCLIPBOARD") },
    { WM_DRAWCLIPBOARD, TEXT("WM_DRAWCLIPBOARD") },
    { WM_PAINTCLIPBOARD, TEXT("WM_PAINTCLIPBOARD") },
    { WM_VSCROLLCLIPBOARD, TEXT("WM_VSCROLLCLIPBOARD") },
    { WM_SIZECLIPBOARD, TEXT("WM_SIZECLIPBOARD") },
    { WM_ASKCBFORMATNAME, TEXT("WM_ASKCBFORMATNAME") },
    { WM_CHANGECBCHAIN, TEXT("WM_CHANGECBCHAIN") },
    { WM_HSCROLLCLIPBOARD, TEXT("WM_HSCROLLCLIPBOARD") },
    { WM_QUERYNEWPALETTE, TEXT("WM_QUERYNEWPALETTE") },
    { WM_PALETTEISCHANGING, TEXT("WM_PALETTEISCHANGING") },
    { WM_PALETTECHANGED, TEXT("WM_PALETTECHANGED") },
    { WM_HOTKEY, TEXT("WM_HOTKEY") },
    { WM_PRINT, TEXT("WM_PRINT") },
    { WM_PRINTCLIENT, TEXT("WM_PRINTCLIENT") },
    { WM_APPCOMMAND, TEXT("WM_APPCOMMAND") },
    { WM_THEMECHANGED, TEXT("WM_THEMECHANGED") },
    { WM_CLIPBOARDUPDATE, TEXT("WM_CLIPBOARDUPDATE") },
    { WM_DWMCOMPOSITIONCHANGED, TEXT("WM_DWMCOMPOSITIONCHANGED") },
    { WM_DWMNCRENDERINGCHANGED, TEXT("WM_DWMNCRENDERINGCHANGED") },
    { WM_DWMCOLORIZATIONCOLORCHANGED, TEXT("WM_DWMCOLORIZATIONCOLORCHANGED") },
    { WM_DWMWINDOWMAXIMIZEDCHANGE, TEXT("WM_DWMWINDOWMAXIMIZEDCHANGE") },
    { WM_DWMSENDICONICTHUMBNAIL, TEXT("WM_DWMSENDICONICTHUMBNAIL") },
    { WM_DWMSENDICONICLIVEPREVIEWBITMAP, TEXT("WM_DWMSENDICONICLIVEPREVIEWBITMAP") },
    { WM_GETTITLEBARINFOEX, TEXT("WM_GETTITLEBARINFOEX") },
    { WM_HANDHELDFIRST, TEXT("WM_HANDHELDFIRST") },
    { WM_HANDHELDLAST, TEXT("WM_HANDHELDLAST") },
    { WM_AFXFIRST, TEXT("WM_AFXFIRST") },
    { WM_AFXLAST, TEXT("WM_AFXLAST") },
    { WM_PENWINFIRST, TEXT("WM_PENWINFIRST") },
    { WM_PENWINLAST, TEXT("WM_PENWINLAST") },
    { WM_APP, TEXT("WM_APP") }
};

inline std::wstring DebugHelper::FormatWindowMessage(MSG msg)
{
    std::wstringstream wss;
    wss << TEXT("hwnd: ") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << msg.hwnd << TEXT("; ");
    auto messagecode = kWindowMessageCodeMap.find(msg.message) == kWindowMessageCodeMap.end() ? TEXT("") : TEXT(" (") + kWindowMessageCodeMap.at(msg.message) + TEXT(")");
    wss << TEXT("message: ") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << msg.message << messagecode << TEXT("; ");
    wss << TEXT("wParam: ") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << msg.wParam << TEXT("; ");
    wss << TEXT("lParam: ") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << msg.lParam << TEXT("; ");
    wss << TEXT("time: ") << msg.time << TEXT("; ");
    wss << TEXT("pt: (") << msg.pt.x << TEXT(", ") << msg.pt.y << ")";

    return wss.str();
}

inline std::wstring DebugHelper::FormatWindowMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    std::wstringstream wss;
    auto messagecode = kWindowMessageCodeMap.find(uMsg) == kWindowMessageCodeMap.end() ? TEXT("") : TEXT(" (") + kWindowMessageCodeMap.at(uMsg) + TEXT(")");
    wss << TEXT("message: ") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << uMsg << messagecode << TEXT("; ");
    wss << TEXT("wParam: ") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << wParam << TEXT("; ");
    wss << TEXT("lParam: ") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << lParam << TEXT("; ");

    return wss.str();
}

inline std::wstring DebugHelper::FormatMouseHookMessage(int code, WPARAM wParam, LPARAM lParam)
{
    std::wstringstream wss;
    wss << TEXT("code: ") << code << TEXT("; ");
    auto messagecode = (UINT)wParam;
    auto messagecodestring = kWindowMessageCodeMap.find(messagecode) == kWindowMessageCodeMap.end() ? TEXT("") : TEXT(" (") + kWindowMessageCodeMap.at(messagecode) + TEXT(")");
    wss << TEXT("message code: 0x") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << messagecode << messagecodestring << TEXT("; ");
    auto mousehookstructpointer = (PMOUSEHOOKSTRUCT)lParam;
    wss << TEXT("pt(") << std::dec << mousehookstructpointer->pt.x << TEXT(", ") << mousehookstructpointer->pt.y << TEXT("); ");
    wss << TEXT("hwnd: 0x") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << PtrToInt(mousehookstructpointer->hwnd) << TEXT("; ");
    wss << TEXT("HitTestCode: ") << std::dec << mousehookstructpointer->wHitTestCode << TEXT("; ");

    return wss.str();
}

inline std::wstring DebugHelper::FormatKeyboardHookMessage(int code, WPARAM wParam, LPARAM lParam)
{
    std::wstringstream wss;
    wss << TEXT("code: ") << code << TEXT("; ");
    auto virtualkeycode = (UINT)wParam;
    wss << TEXT("virtual-key code: 0x") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << virtualkeycode << TEXT("; ");
    auto flags = (UINT)lParam;
    wss << TEXT("flags: 0x") << std::setw(8) << std::setfill(TEXT('0')) << std::hex << flags << TEXT("; ");

    return wss.str();
}