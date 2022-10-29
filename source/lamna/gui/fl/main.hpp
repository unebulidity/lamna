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
///   Date: 9/30/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_FL_MAIN_HPP
#define _LAMNA_GUI_FL_MAIN_HPP

#include "lamna/gui/main.hpp"
#include "lamna/gui/fl/fl.hpp"

#define LAMNA_GUI_FL_MAIN_WINDOW_WIDTH 400
#define LAMNA_GUI_FL_MAIN_WINDOW_HEIGHT 200

namespace lamna {
namespace gui {
namespace fl {

typedef gui::main_implements main_implements;
typedef gui::main main_extends;
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
    maint(): window_(0) {
    }
    virtual ~maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Fl_Window* create_window(int argc, char_t** argv, char_t** env) {
        Fl_Window* window = 0;
        if ((window = new Fl_Window(this->width(), this->height()))) {
        }
        return window;
    }
    virtual int destroy_window
    (Fl_Window* window, int argc, char_t** argv, char_t** env) {
        int err = 1;
        if ((window)) {
            delete window;
            err = 0;
        }
        return err;
    }
    virtual int before_create_window(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_create_window
    (Fl_Window& window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        int fl_argc = (argc)?(1):(0);
        char_t** fl_argv = argv;
        window.end();
        window.show(fl_argc, fl_argv);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int fl_run(int argc, char_t** argv, char_t** env) {
        int err = ::Fl::run();
        return err;
    }
    virtual int before_fl_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LAMNA_LOG_MESSAGE_DEBUG("before_create_window()...");
        if (!(err = before_create_window(argc, argv, env))) {
            LAMNA_LOG_MESSAGE_DEBUG("create_window()...");
            if ((window_ = create_window(argc, argv, env))) {
                LAMNA_LOG_MESSAGE_DEBUG("after_create_window()...");
                if (!(err = after_create_window(*window_, argc, argv, env))) {
                    return err;
                }
                destroy_window(window_, argc, argv, env);
                window_ = 0;
            }
        }
        return err;
    }
    virtual int after_fl_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LAMNA_LOG_MESSAGE_DEBUG("before_fl_run()...");
        if (!(err = before_fl_run(argc, argv, env))) {
            int err2 = 0;
            LAMNA_LOG_MESSAGE_DEBUG("fl_run()...");
            err = fl_run(argc, argv, env);
            LAMNA_LOG_MESSAGE_DEBUG("after_fl_run()...");
            if ((err2 = after_fl_run(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int width() const {
        return LAMNA_GUI_FL_MAIN_WINDOW_WIDTH;
    }
    virtual int height() const {
        return LAMNA_GUI_FL_MAIN_WINDOW_HEIGHT;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Fl_Window* window_;
};
typedef maint<> main;

} // namespace fl 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_FL_MAIN_HPP 
