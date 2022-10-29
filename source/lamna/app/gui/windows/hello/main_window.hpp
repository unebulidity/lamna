///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: main_window.hpp
///
/// Author: $author$
///   Date: 6/16/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_GUI_WINDOWS_HELLO_MAIN_WINDOW_HPP
#define _LAMNA_APP_GUI_WINDOWS_HELLO_MAIN_WINDOW_HPP

#include "lamna/app/gui/hello/main.hpp"
#include "lamna/gui/windows/main_window.hpp"
#include "lamna/graphic/surface/windows/color.hpp"
#include "lamna/graphic/surface/windows/image.hpp"
#include "lamna/graphic/surface/windows/context.hpp"
#include "lamna/graphic/surface/windows/pixel.hpp"
#include "lamna/graphic/surface/color.hpp"
#include "lamna/graphic/surface/context.hpp"
#include "lamna/graphic/surface/image.hpp"

namespace lamna {
namespace app {
namespace gui {
namespace windows {
namespace hello {

typedef lamna::gui::windows::main_window_implements main_window_implements;
typedef gui::hello::surfacet
<lamna::gui::windows::main_window> main_window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_window
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main_window
: virtual public main_window_implements, public main_window_extends {
public:
    typedef main_window_implements Implements;
    typedef main_window_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_window() {
    }
    virtual ~main_window() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT on_WM_PAINT_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        HDC hDC = 0;
        PAINTSTRUCT ps;
        if ((hDC = BeginPaint(hWnd, &ps))) {
            RECT rect;
            if ((GetClientRect(hWnd, &rect))) {
                int x = 0, y = 0;
                int width = rect.right - rect.left;
                int height = rect.bottom - rect.top;
                if ((2 <= (x = width/2)) && (2 <= (y = height/2))) {
                    graphic::surface::windows::context gc(hDC);
                    graphic::surface::windows::image im(gc);
                    graphic::surface::windows::color px
                    (im, fg_color_red_, fg_color_green_, fg_color_blue_);
                    im.SelectImage(&px);
                    paint(im, x,y, x,y);
                }
            }
            EndPaint(hWnd, &ps);
        } else {
            lResult = on_message_default(hWnd,msg,wParam,lParam);
        }
        return lResult;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT on_WM_SIZE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        InvalidateRect(hWnd, NULL, TRUE);
        return lResult;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT on_WM_LBUTTONUP_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        if ((hWnd)) {
            size_t x = LOWORD(lParam);
            size_t y = HIWORD(lParam);
            lamna::gui::mouse::position p(x, y);
            lamna::gui::mouse::button b(lamna::gui::mouse::button_left);
            lamna::gui::mouse::event e(lamna::gui::mouse::event_button_release, b, p);
            this->on_mouse_release_event(e);
        }
        return lResult;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void invalidate() {
        Extends::Extends::invalidate();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace hello 
} // namespace windows 
} // namespace gui 
} // namespace app 
} // namespace lamna 

#endif // _LAMNA_APP_GUI_WINDOWS_HELLO_MAIN_WINDOW_HPP 
