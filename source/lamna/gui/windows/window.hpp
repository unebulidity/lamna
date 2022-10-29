///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: window.hpp
///
/// Author: $author$
///   Date: 6/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WINDOWS_WINDOW_HPP
#define _LAMNA_GUI_WINDOWS_WINDOW_HPP

#include "lamna/gui/windows/message_target.hpp"

#define LAMNA_GUI_WINDOWS_DEFAULT_WINDOW_STYLE \
    WS_VISIBLE | WS_OVERLAPPED | WS_THICKFRAME | \
    WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX

#define LAMNA_GUI_WINDOWS_DEFAULT_WINDOW_EXSTYLE 0

namespace lamna {
namespace gui {
namespace windows {

typedef message_target window_implements;
typedef hwnd window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: windowt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = window_implements, class TExtends = window_extends>

class _EXPORT_CLASS windowt
: virtual public window_implements, public window_extends {
public:
    typedef window_implements Implements;
    typedef window_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    windowt
    (HINSTANCE instance = 0, HWND detached = 0, bool is_created = false)
    : Extends(instance, detached, is_created) {
    }
    virtual ~windowt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (HINSTANCE hInstance, LPCSTR className, 
     LPCSTR windowName = NULL, HWND hParentWnd = NULL, 
     HMENU hMenu = NULL, DWORD style = LAMNA_GUI_WINDOWS_DEFAULT_WINDOW_STYLE,
     DWORD exStyle = LAMNA_GUI_WINDOWS_DEFAULT_WINDOW_EXSTYLE, 
     int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, 
     int width = CW_USEDEFAULT, int height = CW_USEDEFAULT,
     LPVOID lParam = NULL) {
        bool isSuccess = create
        (exStyle, className, windowName, style, 
         x,y, width,height, hParentWnd, hMenu, hInstance, lParam);
        return isSuccess;
    }
    virtual bool create
    (DWORD exStyle, LPCSTR className, LPCSTR windowName, DWORD style, 
     int x, int y, int width, int height, HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam) {
        bool isSuccess = false;
        HWND detached;

        if ((this->destroyed())) {
            if ((isSuccess = (NULL != (detached = create_detached
                (exStyle, className, windowName, style, 
                 x, y, width, height, hParentWnd, hMenu, hInstance, 
                 (lParam)?(lParam):((message_target*)(this))))))) {
                this->attach_created(hInstance, detached);
            }
        }
        return isSuccess;
    }
    virtual bool destroy() {
        bool isSuccess = false;
        HWND detached = 0;
        if ((detached = this->detach()))
            isSuccess = destroy_detached(detached);
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HWND create_detached
    (DWORD exStyle, LPCSTR className, LPCSTR windowName, DWORD style, 
     int x, int y, int width, int height, HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam) const {
        HWND detached = NULL;
        if (!(NULL != (detached = CreateWindowExA
            (exStyle, className, windowName, style, 
             x, y, width, height, hParentWnd, hMenu, hInstance, lParam)))) {
            DWORD dwError = GetLastError();
            LAMNA_LOG_ERROR("failed " << dwError << " on CreateWindowExA()"); 
        }
        return detached;
    }
    virtual bool destroy_detached(HWND detached) const {
        bool isSuccess = false;
        if ((detached)) {
            if (!(isSuccess = (FALSE != DestroyWindow(detached)))) {
                DWORD dwError = GetLastError();
                LAMNA_LOG_ERROR("failed " << dwError << " on DestroyWindow()"); 
            }
        }
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool show(int nCmdShow = SW_SHOWNORMAL) {
        HWND hWnd = 0;
        if ((hWnd = this->attached_to())) {
            if ((ShowWindow(hWnd, nCmdShow))) {
                return true;
            }
        }
        return false;
    }
    virtual bool hide(int nCmdShow = SW_HIDE) {
        return show(nCmdShow);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool invalidate(bool eraseBackground = true) {
        HWND hWnd = 0;
        if ((hWnd = this->attached_to())) {
            if ((InvalidateRect(hWnd, NULL, eraseBackground))) {
                return true;
            }
        }
        return false;
    }
    virtual bool validate() {
        HWND hWnd = 0;
        if ((hWnd = this->attached_to())) {
            if ((ValidateRect(hWnd, NULL))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_size(int width, int height) {
        HWND hWnd = 0;
        if ((hWnd = this->attached_to())) {
            RECT rect;
            if ((GetWindowRect(hWnd, &rect))) {
                HWND hWndParent = 0;
                if ((hWndParent = GetParent(hWnd))) {
                    POINT p;
                    p.x = rect.left;
                    p.y = rect.top;
                    if ((ScreenToClient(hWndParent, &p))) {
                        rect.left = p.y;
                        rect.top = p.y;
                    } else {
                        return false;
                    }
                }
                if ((SetWindowPos(hWnd, NULL, rect.left,rect.top, width,height, 0))) {
                    return true;
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef windowt<> window;

} // namespace windows 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WINDOWS_WINDOW_HPP 
