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
///   File: window_main.hpp
///
/// Author: $author$
///   Date: 9/9/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_WINDOW_MAIN_HPP
#define _LAMNA_GUI_X11_WINDOW_MAIN_HPP

#include "lamna/gui/x11/main.hpp"
#include "lamna/gui/x11/main_window.hpp"
#include "lamna/gui/x11/window.hpp"
#include "lamna/gui/x11/event_target.hpp"
#include "lamna/gui/x11/atom.hpp"

#define LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_X 0
#define LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_Y \
    LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_X

#define LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_WIDTH 100
#define LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_HEIGHT \
    LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_WIDTH

#define LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_BORDER_WIDTH 0
#define LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_BORDER_COLOR 0
#define LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_BACKGROUND_COLOR 0

namespace lamna {
namespace gui {
namespace x11 {

typedef main_implements window_main_implements;
typedef main window_main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: window_maint
///////////////////////////////////////////////////////////////////////
template
<class TEventTargetImplements = event_target,
 class TImplements = window_main_implements,
 class TExtends = window_main_extends>

class _EXPORT_CLASS window_maint
: virtual public TEventTargetImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TEventTargetImplements EventTargetImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    window_maint()
    : main_window_x_(LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_X),
      main_window_y_(LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_Y),
      main_window_width_(LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_WIDTH),
      main_window_height_(LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_HEIGHT),
      main_window_border_width_(LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_BORDER_WIDTH),
      main_window_border_color_(LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_BORDER_COLOR),
      main_window_background_color_(LAMNA_GUI_X11_WINDOW_MAIN_DEFAULT_WINDOW_BACKGROUND_COLOR),
      main_window_(0),
      wm_protocols_(None),
      wm_delete_window_(None) {
    }
    virtual ~window_maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_XEvent(const XEvent& event) {
        event_target* target = 0;
        if ((target = (main_window_))) {
            if ((event.xany.window == (main_window_->attached_to()))) {
                if ((event.type == (ClientMessage))) {
                    LAMNA_LOG_MESSAGE_DEBUG("ClientMessage...");
                    if ((event.xclient.message_type) == wm_protocols_) {
                        LAMNA_LOG_MESSAGE_DEBUG("WM_PROTOCOLS...");
                        if ((event.xclient.data.l[0]) == wm_delete_window_) {
                            LAMNA_LOG_MESSAGE_DEBUG("WM_DELETE_WINDOW...");
                            this->set_done_event_loop();
                            return true;
                        }
                    }
                }
                return target->on_XEvent(event);
            }
        }
        return EventTargetImplements::on_XEvent(event);
    }
    virtual bool before_on_XEvent(const XEvent& event) {
        return false;
    }
    virtual bool after_on_XEvent(const XEvent& event) {
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool process_XEvent(XEvent& event, XDisplay& display) {
        bool isHandled = false;
        if (!(isHandled = before_on_XEvent(event))) {
            if (!(isHandled = on_XEvent(event))) {
                isHandled = after_on_XEvent(event);
            }
        }
        return isHandled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool next_XEvent(XEvent& event, XDisplay& display) {
        XNextEvent(&display, &event);
        return true;
    }
    virtual bool no_next_XEvent(XDisplay& display) {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool peek_XEvent(XEvent& event, XDisplay& display) {
        if (False != (XCheckIfEvent(&display, &event, is_XEvent, (XPointer)(this))))
            return true;
        return false;
    }
    static Bool is_XEvent(XDisplay* display, XEvent* event, XPointer arg) {
        return True;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        XDisplay* display = 0;
        if ((display = this->display())) {
            if (!(this->set_done_event_loop(false))) {
                XEvent event;
                do {
                    LAMNA_LOG_MESSAGE_DEBUG("next_XEvent()...");
                    if ((next_XEvent(event, *display))) {
                        LAMNA_LOG_MESSAGE_DEBUG("...next_XEvent()");
                        process_XEvent(event, *display);
                    } else {
                        LAMNA_LOG_MESSAGE_DEBUG("...no_next_XEvent()");
                        if ((no_next_XEvent(*display))) {
                            break;
                        }
                    }
                } while (!(this->done_event_loop()));
            }
        }
        return err;
    }
    virtual int before_event_loop(int argc, char_t** argv, char_t** env) {
        int err = 1;
        XDisplay* display = 0;
        XScreen* screen = 0;
        XWindow root_window = None;
        if ((display = this->display()) && ((screen = this->screen()))
            && (None != (root_window = this->root_window()))) {
            if (!(err = before_open_main_window
                  (*display, *screen, root_window, argc, argv, env))) {
                main_window* window = 0;
                if ((window = open_main_window
                     (*display, *screen, root_window, argc, argv, env))) {
                    main_window_ = window;
                    if (!(err = after_open_main_window
                          (*window, *display, *screen, root_window, argc, argv, env))) {
                        return err;
                    }
                    main_window_ = 0;
                    close_main_window
                    (window, *display, *screen, root_window, argc, argv, env);
                } else {
                    err = 1;
                }
                after_close_main_window
                (*display, *screen, root_window, argc, argv, env);
            }
        }
        return err;
    }
    virtual int after_event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        main_window* window = 0;
        XDisplay* display = 0;
        XScreen* screen = 0;
        XWindow root_window = None;
        if ((window = main_window_) && (display = this->display())
            && ((screen = this->screen()))
            && (None != (root_window = this->root_window()))) {
            int err2 = 0;
            if ((err2 = before_close_main_window
                 (*window, *display, *screen, root_window, argc, argv, env))) {
                if (!(err)) err = err2;
            }
            main_window_ = 0;
            if (!(close_main_window
                  (window, *display, *screen, root_window, argc, argv, env))) {
                if (!(err)) err = 1;
            }
            if ((err2 = after_close_main_window
                 (*display, *screen, root_window, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        } else {
            err = 1;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual main_window* open_main_window
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_create_main_window
              (display, screen, root_window, argc, argv, env))) {
            main_window* window = 0;
            if ((window = create_main_window
                 (display, screen, root_window, argc, argv, env))) {
                if (!(err = after_create_main_window
                      (*window, display, screen, root_window, argc, argv, env))) {
                    window->map();
                    return window;
                }
                destroy_main_window
                (window, display, screen, root_window, argc, argv, env);
            }
            after_destroy_main_window
            (display, screen, root_window, argc, argv, env);
        }
        return 0;
    }
    virtual bool close_main_window
    (main_window* window, XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        if ((window)) {
            bool success = true;
            int err = 0;
            if (!(window->unmap())) {
                success = false;
            }
            if ((err = window->on_destroy(argc, argv, env))) {
                success = false;
            }
            if (!(destroy_main_window
                  (window, display, screen, root_window, argc, argv, env))) {
                success = false;
            }
            return success;
        }
        return false;
    }
    virtual int before_open_main_window
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        int err = 1;
        if ((atom_WM_PROTOCOLS_.create
             (display, LAMNA_GUI_X11_ATOM_NAME_WM_PROTOCOLS, true))) {
            if ((atom_WM_DELETE_WINDOW_.create
                 (display, LAMNA_GUI_X11_ATOM_NAME_WM_DELETE_WINDOW, true))) {
                wm_protocols_ = atom_WM_PROTOCOLS_.attached_to();
                wm_delete_window_ = atom_WM_DELETE_WINDOW_.attached_to();
                err = 0;
            } else {
                atom_WM_PROTOCOLS_.destroy();
            }
        } else {
        }
        return err;
    }
    virtual int after_open_main_window
    (main_window& window, XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        window.set_wm_protocols(&wm_delete_window_, 1);
        return err;
    }
    virtual int before_close_main_window
    (main_window& window, XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_close_main_window
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        wm_delete_window_ = None;
        if (!(atom_WM_DELETE_WINDOW_.destroy())) {
            if (!(err)) err = 1;
        }
        wm_protocols_ = None;
        if (!(atom_WM_PROTOCOLS_.destroy())) {
            if (!(err)) err = 1;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_create_main_window
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        main_window_background_color_ = this->white_pixel();
        main_window_border_color_ = this->black_pixel();
        return err;
    }
    virtual int after_create_main_window
    (main_window& window, XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_destroy_main_window
    (main_window& window, XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_destroy_main_window
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual main_window* create_main_window
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        main_window& window_created = main_window_created();
        if ((window_created.create
             (display, root_window, main_window_x_, main_window_y_,
              main_window_width_, main_window_height_,
              main_window_border_width_, main_window_border_color_,
              main_window_background_color_))) {
            window_created.select_input();
            return &window_created;
        }
        return 0;
    }
    virtual bool destroy_main_window
    (main_window* window, XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        main_window& window_created = main_window_created();
        if (window == (&window_created)) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual main_window& main_window_created() const {
        return ((main_window&)main_window_created_);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    int main_window_x_, main_window_y_;
    unsigned int main_window_width_, main_window_height_;
    unsigned int main_window_border_width_;
    XPixel main_window_border_color_;
    XPixel main_window_background_color_;
    main_window* main_window_;
    main_window main_window_created_;
    XAtom wm_protocols_;
    atom atom_WM_PROTOCOLS_;
    XAtom wm_delete_window_;
    atom atom_WM_DELETE_WINDOW_;
};
typedef window_maint<> window_main;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_WINDOW_MAIN_HPP 
