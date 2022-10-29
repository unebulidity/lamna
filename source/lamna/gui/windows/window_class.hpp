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
///   File: window_class.hpp
///
/// Author: $author$
///   Date: 6/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WINDOWS_WINDOW_CLASS_HPP
#define _LAMNA_GUI_WINDOWS_WINDOW_CLASS_HPP

#include "lamna/gui/windows/atom.hpp"
#include "lamna/gui/windows/window.hpp"
#include "lamna/base/base.hpp"

#define LAMNA_GUI_WINDOWS_WINDOW_CLASSNAME_CHARS \
    "lamna::gui::windows::window_class"

namespace lamna {
namespace gui {
namespace windows {

typedef atom_implements window_class_implements;
typedef atom window_class_extends;
///////////////////////////////////////////////////////////////////////
///  Class: window_classt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = window_class_implements, 
 class TExtends = window_class_extends>

class _EXPORT_CLASS window_classt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    window_classt
    (LPCSTR windowClassNameChars = LAMNA_GUI_WINDOWS_WINDOW_CLASSNAME_CHARS,
     WNDPROC wndProc = window::WindowProc,
     int windowExtra=(int)(sizeof(window*)),
     int windowExtraOffset=0,
     int classExtra=0,
     int classExtraOffset=0,
     UINT style=0,
     ATOM detached = 0, bool is_created = false)
    : Extends(detached, is_created),
      m_windowClassName(windowClassNameChars),
      m_windowClassNameChars(m_windowClassName.chars()),
      m_wndProc(wndProc),
      m_hBackgroundBrush(0),
      m_hCursor(0),
      m_windowExtra(windowExtra),
      m_windowExtraOffset(windowExtraOffset),
      m_classExtra(classExtra),
      m_classExtraOffset(classExtraOffset),
      m_style(style) {
    }
    virtual ~window_classt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (HINSTANCE instance, LPCSTR classname = NULL, WNDPROC wndproc = NULL,
     LPCSTR menuname = NULL, HICON icon = NULL, HICON iconsm = NULL,
     HCURSOR cursor = NULL, HBRUSH background = NULL, UINT style = 0,
     int wndextra = -1, int clsextra = -1) {
        bool isSuccess = false;
        ATOM detached = 0;

        if (!(this->destroyed())) {
            return false;
        }
        if (classname) {
            SetWindowClassName(classname);
        } else {
            if (!(classname = GetWindowClassName())) {
                return false;
            }
        }
        if (!wndproc) {
            if (!(wndproc = GetWindowProc())) {
                return false;
            }
        }
        if (!background) {
            background = GetBackground();
        }
        if (0 > wndextra) {
            wndextra = GetWindowExtra();
        }
        if (0 > clsextra) {
            clsextra = GetClassExtra();
        }
        if (!style) {
            style = GetStyle();
        }
        if ((isSuccess = (NULL != (detached = create_detached
            (m_wndClass, instance, classname, wndproc, menuname, icon, 
             iconsm, cursor, background, style, wndextra, clsextra))))) {
             this->attach_created(detached);
        }
        return isSuccess;
    }
    virtual bool destroy() {
        bool isSuccess = false;
        ATOM detached = 0;
        if ((detached = this->detach())) {
            isSuccess = destroy_detached(detached, m_wndClass);
        }
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ATOM create_detached
    (WNDCLASSEXA& wndClass, 
     HINSTANCE instance, LPCSTR classname, WNDPROC wndproc = NULL,
     LPCSTR menuname = NULL, HICON icon = NULL, HICON iconsm = NULL,
     HCURSOR cursor = NULL, HBRUSH background = NULL, UINT style = 0,
     int wndextra = 0, int clsextra = 0, bool isInitial = false) {
        ATOM detached = NULL;

        memset(&wndClass, 0, sizeof(WNDCLASSEXA));
        wndClass.cbSize = sizeof(WNDCLASSEXA);
        wndClass.hInstance = instance;
        wndClass.lpszClassName = classname;
        wndClass.style = style;
        wndClass.cbClsExtra = clsextra;
        wndClass.cbWndExtra = wndextra;

        if ((NULL != menuname) || isInitial) {
            wndClass.lpszMenuName = menuname;
        }
        if ((NULL != icon) || isInitial) {
            wndClass.hIcon = icon;
        }
        if ((NULL != iconsm) || isInitial) {
            wndClass.hIconSm = iconsm;
        }
        if ((NULL != cursor) || isInitial) {
            wndClass.hCursor = cursor;
        } else {
            if (NULL == wndClass.hCursor) {
                wndClass.hCursor = GetDefaultCursor();
            }
        }
        if ((NULL != background) || isInitial) {
            wndClass.hbrBackground = background;
        } else { 
            if (NULL == wndClass.hbrBackground) {
                wndClass.hbrBackground = GetDefaultBackground();
            }
        }
        if ((NULL != wndproc) || isInitial) {
            wndClass.lpfnWndProc = wndproc;
        } else {
            if (NULL == wndClass.lpfnWndProc) {
                wndClass.lpfnWndProc = GetDefaultWindowProc();
            }
        }
        if (!(NULL != (detached = RegisterClassExA(&wndClass)))) {
            DWORD dwError = GetLastError();
            LAMNA_LOG_ERROR("failed " << dwError << " on RegisterClassExA()");
        }
        return detached;
    }
    virtual bool destroy_detached
    (ATOM detached, const WNDCLASSEXA& wndClass) {
        bool isSuccess = false;
        if ((detached)) {
            if (!(isSuccess = !(TRUE != (UnregisterClassA
                (wndClass.lpszClassName, wndClass.hInstance))))) {
                DWORD dwError = GetLastError();
                LAMNA_LOG_ERROR("failed " << dwError << " on UnregisterClass()");
            }
        }
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SetWindowClassName(LPCSTR chars) {
        ssize_t count = 0;
        m_windowClassName.assign(chars);
        if (0 < (count = m_windowClassName.length()))
        if ((chars = m_windowClassName.c_str()))
            m_windowClassNameChars = chars;
        return count;
    }
    virtual LPCSTR GetWindowClassName() const {
        LPCSTR chars = m_windowClassNameChars;
        return chars;
    }
    virtual LPCSTR name() const {
        LPCSTR chars = GetWindowClassName();
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual WNDPROC SetWindowProc(WNDPROC wndProc) {
        m_wndProc = wndProc;
        return wndProc;
    }
    virtual WNDPROC GetWindowProc() const {
        WNDPROC wndProc = m_wndProc;
        return wndProc;
    }
    virtual WNDPROC GetDefaultWindowProc() const 
    {
        WNDPROC wndproc = DefWindowProc;
        return wndproc;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int SetWindowExtra(int bytes) {
        int count = (m_windowExtra = bytes);
        return count;
    }
    virtual int GetWindowExtra() const {
        int count = m_windowExtra;
        return count;
    }
    virtual int SetWindowExtraOffset(int bytes) {
        int count = 0;
        return count;
    }
    virtual int GetWindowExtraOffset() const {
        int count = m_windowExtraOffset;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int SetClassExtra(int bytes) {
        int count = (m_classExtra = bytes);
        return count;
    }
    virtual int GetClassExtra() const {
        int count = m_classExtra;
        return count;
    }
    virtual int SetClassExtraOffset(int bytes) {
        int count = 0;
        return count;
    }
    virtual int GetClassExtraOffset() const {
        int count = m_classExtraOffset;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HBRUSH SetBackground(HBRUSH hBrush) {
        m_hBackgroundBrush = hBrush;
        return hBrush;
    }
    virtual HBRUSH GetBackground() const {
        HBRUSH hBrush = NULL;
        hBrush = m_hBackgroundBrush;
        return hBrush;
    }
    virtual HBRUSH GetDefaultBackground() const {
        HBRUSH handle = (HBRUSH)GetStockObject(WHITE_BRUSH);
        return handle;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HCURSOR SetCursor(HCURSOR hCursor) {
        HCURSOR handle = (m_hCursor = hCursor);
        return handle;
    }
    virtual HCURSOR GetCursor() const {
        HCURSOR handle = m_hCursor;
        return handle;
    }
    virtual HCURSOR GetDefaultCursor() const {
        HCURSOR handle = LoadCursor(NULL, IDC_ARROW);
        return handle;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual UINT SetStyle(UINT toStyle) {
        UINT style = 0;
        style = (m_style = toStyle);
        return style;
    }
    virtual UINT GetStyle() const {
        UINT style = 0;
        style = (m_style);
        return style;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static LPCSTR DefaultWindowClassNameChars() {
        static LPCSTR chars = LAMNA_GUI_WINDOWS_WINDOW_CLASSNAME_CHARS;
        return chars;
    }
    static LPCSTR default_name() {
        static LPCSTR chars = DefaultWindowClassNameChars();
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string m_windowClassName;
    LPCSTR m_windowClassNameChars;
    WNDPROC m_wndProc;
    HBRUSH m_hBackgroundBrush;
    HCURSOR m_hCursor;
    int m_windowExtra;
    int m_windowExtraOffset;
    int m_classExtra;
    int m_classExtraOffset;
    UINT m_style;
    WNDCLASSEXA m_wndClass;
};
typedef window_classt<> window_class;

} // namespace windows 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WINDOWS_WINDOW_CLASS_HPP 
