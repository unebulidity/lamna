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
///   Date: 9/9/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_MAIN_HPP
#define _LAMNA_GUI_X11_MAIN_HPP

#include "lamna/gui/x11/display.hpp"
#include "lamna/gui/x11/context.hpp"
#include "lamna/gui/x11/colormap.hpp"
#include "lamna/gui/x11/color.hpp"
#include "lamna/gui/main.hpp"

#define LAMNA_GUI_X11_MAIN_DISPLAY_NAME ":0.0"

namespace lamna {
namespace gui {
namespace x11 {

typedef gui::main_implements main_implements;
typedef gui::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>

class _EXPORT_CLASS maint: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint()
    : display_name_(LAMNA_GUI_X11_MAIN_DISPLAY_NAME),
      display_(0), screen_(0),
      root_window_(None), context_(None),
      colormap_(None), black_pixel_(0), white_pixel_(0) {
    }
    virtual ~maint() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_gui_main(int argc, char_t** argv, char_t** env) {
        int err = 1;
        LAMNA_LOG_MESSAGE_DEBUG("before_open_display()...");
        if (!(err = this->before_open_display(argc, argv, env))) {
            XDisplay* display = 0;
            XScreen* screen = 0;
            XWindow root_window = None;
            LAMNA_LOG_MESSAGE_DEBUG("open_display()...");
            if ((display = this->open_display
                (screen, root_window, argc, argv, env))) {
                LAMNA_LOG_MESSAGE_DEBUG("after_open_display()...");
                if ((err = this->after_open_display
                     (*display, *screen, root_window, argc, argv, env))) {
                    this->close_display
                    (display, screen, root_window, argc, argv, env);
                } else {
                    LAMNA_LOG_MESSAGE_DEBUG("...after_open_display()");
                    display_ = display;
                    screen_ = screen;
                    root_window_ = root_window;
                }
            } else {
                err = 1;
            }
        }
        return err;
    }
    virtual int after_gui_main(int argc, char_t** argv, char_t** env) {
        int err = 1;
        XDisplay* display = 0;
        XScreen* screen = 0;
        XWindow root_window = None;
        if ((display = display_) && (screen = screen_) && (root_window = root_window_)) {
            int err2 = 0;
            display_ = 0;
            screen_ = 0;
            root_window_ = 0;
            LAMNA_LOG_MESSAGE_DEBUG("before_close_display()...");
            if (!(err = this->before_close_display
                  (*display, *screen, root_window, argc, argv, env))) {
                LAMNA_LOG_MESSAGE_DEBUG("...before_close_display()");
            }
            LAMNA_LOG_MESSAGE_DEBUG("close_display()...");
            if ((this->close_display
                 (display, screen, root_window, argc, argv, env))) {
                LAMNA_LOG_MESSAGE_DEBUG("...close_display()");
            } else {
                if (!(err)) err = 1;
            }
            LAMNA_LOG_MESSAGE_DEBUG("after_close_display()...");
            if (!(err2 = this->after_close_display(argc, argv, env))) {
                LAMNA_LOG_MESSAGE_DEBUG("...after_close_display()");
            } else {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_open_display(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_open_display
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char** argv, char** env) {
        int err = 1;
        if (!(err = before_create_context
            (display, screen, root_window, argc, argv, env))) {
            XContext context = None;
            if (None != (context = create_context
                (display, screen, root_window, argc, argv, env))) {
                if (!(err = after_create_context
                    (context, display, screen, root_window, argc, argv, env))) {
                    context_ = context;
                }
            } else {
                err = 1;
                after_destroy_context
                (display, screen, root_window, argc, argv, env);
            }
        }
        return err;
    }
    virtual int before_close_display
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char** argv, char** env) {
        int err = 0, err2 = 0;
        XContext context = None;
        err = before_destroy_context
        (context, display, screen, root_window, argc, argv, env);
        if (None != (context = context_)) {
            context_ = None;
            if (!(destroy_context
                 (context, display, screen, root_window, argc, argv, env))) {
                if (!(err)) err = 1;
            }
        }
        if ((err2 = after_destroy_context
             (display, screen, root_window, argc, argv, env))) {
            if (!(err)) err = err2;
        }
        return err;
    }
    virtual int after_close_display(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XDisplay* open_display
    (XScreen*& screen, XWindow& root_window, int argc, char_t** argv, char_t** env) {
        const char* name = 0;
        if ((name = display_name_.has_chars())) {
            if ((display_opened_.open(name))) {
                root_window = display_opened_.root_window_attached_to();
                screen = display_opened_.screen_attached_to();
                return display_opened_.attached_to();
            }
        }
        return 0;
    }
    virtual bool close_display
    (XDisplay* display, XScreen* screen,
     XWindow root_window, int argc, char_t** argv, char_t** env) {
        if ((display) && (display == (display_opened_.attached_to()))) {
            if ((display_opened_.close())) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_create_context
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_create_context
    (XContext context, XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char** argv, char** env) {
        int err = 1;
        if (None != (colormap_ = colormap_created_.attach_default_of_screen(display, screen))) {
            if ((black_color_.attach_black_of_screen(display, screen))) {
                black_pixel_ = black_color_.attached_to();
                if ((white_color_.attach_white_of_screen(display, screen))) {
                    white_pixel_ = white_color_.attached_to();
                    err = 0;
                }
            }
        }
        return err;
    }
    virtual int before_destroy_context
    (XContext context, XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_destroy_context
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XContext create_context
    (XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char** argv, char** env) {
        if ((context_created_.create(display))) {
            return context_created_.attached_to();
        }
        return None;
    }
    virtual bool destroy_context
    (XContext context,
     XDisplay& display, XScreen& screen,
     XWindow root_window, int argc, char** argv, char** env) {
        if (context == (context_created_.attached_to())) {
            return context_created_.destroy();
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XDisplay* display() const {
        return display_;
    }
    virtual XScreen* screen() const {
        return screen_;
    }
    virtual XWindow root_window() const {
        return root_window_;
    }
    virtual XContext context() const {
        return context_;
    }
    virtual XColormap colormap() const {
        return colormap_;
    }
    virtual XPixel black_pixel() const {
        return black_pixel_;
    }
    virtual XPixel white_pixel() const {
        return white_pixel_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string display_name_;
    XDisplay* display_;
    XScreen* screen_;
    XWindow root_window_;
    x11::display display_opened_;
    XContext context_;
    x11::context context_created_;
    XColormap colormap_;
    x11::colormap colormap_created_;
    XPixel black_pixel_, white_pixel_;
    x11::color black_color_, white_color_;
};
typedef maint<> main;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_MAIN_HPP 
