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
///   File: main.hpp
///
/// Author: $author$
///   Date: 6/6/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WINDOWS_MAIN_HPP
#define _LAMNA_GUI_WINDOWS_MAIN_HPP

#include "lamna/gui/windows/main_window.hpp"
#include "lamna/gui/windows/window_class.hpp"
#include "xos/io/logger.hpp"
#include "xos/mt/locker.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"

namespace lamna {
namespace gui {
namespace windows {

typedef xos::mt::locker main_locker;
typedef main_locker* main_attached_t;

typedef main_locker main_implements;
typedef xos::base::attachert
<main_attached_t, int, 0, main_implements> main_attacher;
typedef xos::base::attachedt
<main_attached_t, int, 0, main_attacher, base> main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint()
    : the_main_(get_the_main()), 
      main_window_class_(0), main_window_(0) {
        get_the_main() = this;
    }
    virtual ~maint() {
        if (this == (get_the_main())) {
            get_the_main() = the_main_;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int the_WinMain
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t logfv(const char_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t log(const char_t* out, ssize_t length = -1) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t logln() {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool unlock() {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->unlock();
        }
        return true;
    }
    virtual bool lock() {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->lock();
        }
        return true;
    }
    virtual xos::mt::wait_status try_lock() {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->try_lock();
        }
        return xos::mt::wait_success;
    }
    virtual xos::mt::wait_status timed_lock(mseconds_t milliseconds) {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->timed_lock(milliseconds);
        }
        return xos::mt::wait_success;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int WinMain
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 1;
        if ((main_window_class_)) {
            if ((main_window_)) {
                if (!(err = before_WinMainLoop
                    (*main_window_, *main_window_class_, 
                     hInstance, hPrevInstance, cmdLine, cmdShow))) {
                    int err2  = 0;
                    err = WinMainLoop
                    (*main_window_, *main_window_class_, 
                     hInstance, hPrevInstance, cmdLine, cmdShow);
                    if ((err2 = after_WinMainLoop
                       (*main_window_, *main_window_class_, 
                        hInstance, hPrevInstance, cmdLine, cmdShow))) {
                        if (!(err)) err = err2;
                    }
                }
            } else {
                LAMNA_LOG_ERROR("unexpected 0 == (main_window_");
            }
        } else {
            LAMNA_LOG_ERROR("unexpected 0 == (main_window_class_");
        }
        return err;
    }
    virtual int before_WinMain
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 1;

        if ((before_create_main_window_class
             (hInstance, hPrevInstance, cmdLine, cmdShow))) {

            if ((main_window_class_ = create_main_window_class
                 (hInstance, hPrevInstance, cmdLine, cmdShow))) {

                if ((before_create_main_window
                     (*main_window_class_, hInstance, hPrevInstance, cmdLine, cmdShow))) {

                    if ((main_window_ = create_main_window
                         (*main_window_class_, hInstance, hPrevInstance, cmdLine, cmdShow))) {

                        if ((before_show_main_window
                             (*main_window_, *main_window_class_, 
                              hInstance, hPrevInstance, cmdLine, cmdShow))) {

                            if ((show_main_window
                                 (*main_window_, *main_window_class_, 
                                  hInstance, hPrevInstance, cmdLine, cmdShow))) {
                                err = 0;
                                return err;
                            }
                        }
                        destroy_main_window
                        (*main_window_, *main_window_class_, 
                         hInstance, hPrevInstance, cmdLine, cmdShow);
                    }
                }
                destroy_main_window_class
                (*main_window_class_, 
                 hInstance, hPrevInstance, cmdLine, cmdShow);
            }
        }
        return err;
    }
    virtual int after_WinMain
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        if ((main_window_) && (main_window_class_)) {
            if (!(before_destroy_main_window
                 (*main_window_, *main_window_class_, 
                  hInstance, hPrevInstance, cmdLine, cmdShow))) {
                if (!(err)) err = 1;
            }
            if (!(destroy_main_window
                 (*main_window_, *main_window_class_, 
                  hInstance, hPrevInstance, cmdLine, cmdShow))) {
                if (!(err)) err = 1;
            }
        } else {
            LAMNA_LOG_ERROR("unexpected 0 == main_window_");
            if (!(err)) err = 1;
        }
        if ((main_window_class_)) {
            if (!(before_destroy_main_window_class
                 (*main_window_class_, hInstance, hPrevInstance, cmdLine, cmdShow))) {
                if (!(err)) err = 1;
            }
            if (!(destroy_main_window_class
                 (*main_window_class_, hInstance, hPrevInstance, cmdLine, cmdShow))) {
                if (!(err)) err = 1;
            }
        } else {
            LAMNA_LOG_ERROR("unexpected 0 == main_window_class_");
            if (!(err)) err = 1;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int WinMainLoop
    (window& main_window, window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        MSG msg;
        while ((GetMessage(&msg, NULL, 0,0))) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return err;
    }
    virtual int before_WinMainLoop
    (window& main_window, window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        return err;
    }
    virtual int after_WinMainLoop
    (window& main_window, window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int operator ()
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        int err = 0, err2 = 0;
        if (!(err = before_WinMain(hInstance, hPrevInstance, cmdLine, cmdShow))) {
            err = WinMain(hInstance, hPrevInstance, cmdLine, cmdShow);
            if ((err2 = after_WinMain(hInstance, hPrevInstance, cmdLine, cmdShow))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual window* create_main_window
    (window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         LPCSTR windowClassName = 0;
         if ((windowClassName = main_window_class.GetWindowClassName())) {
             if ((window_.create(hInstance, windowClassName))) {
                 return &window_;
             }
         }
         return 0;
    }
    virtual bool destroy_main_window
    (window& main_window, window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         if (&main_window == (&window_)) {
             if ((window_.destroy())) {
                 return true;
             }
         }
         return false;
    }
    virtual bool show_main_window
    (window& main_window, window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         if ((main_window.show())) {
             return true;
         }
         return false;
    }
    virtual bool before_create_main_window
    (window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         return true;
    }
    virtual bool before_destroy_main_window
    (window& main_window, window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         return true;
    }
    virtual bool before_show_main_window
    (window& main_window, window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual window_class* create_main_window_class
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        if ((window_class_.create(hInstance))) {
            return &window_class_;
        }
        return 0;
    }
    virtual bool destroy_main_window_class
    (window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         if ((&main_window_class == (&window_class_))) {
             if ((window_class_.destroy())) {
                 return true;
             }
         }
         return false;
    }
    virtual bool before_create_main_window_class
    (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         return true;
    }
    virtual bool before_destroy_main_window_class
    (window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual BOOL GetMessage
    (LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax) {
        if ((::GetMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax))) {
            return TRUE;
        }
        return FALSE;
    }
    virtual BOOL TranslateMessage(CONST MSG* lpMsg) {
        if ((::TranslateMessage(lpMsg))) {
            return TRUE;
        }
        return FALSE;
    }
    virtual LRESULT DispatchMessage(CONST MSG* lpMsg) {
        LRESULT lResult = 0;
        if ((lResult = ::DispatchMessage(lpMsg))) {
            return lResult;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static maint*& get_the_main();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    maint* the_main_;
    window_class* main_window_class_;
    window_class window_class_;
    window* main_window_;
    main_window window_;
};
typedef maint<> main;

} // namespace windows 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WINDOWS_MAIN_HPP 
