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
///   Date: 5/30/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_MAIN_HPP
#define _LAMNA_GUI_MAIN_HPP

#include "lamna/console/main.hpp"
#include "lamna/gui/mouse/event.hpp"

namespace lamna {
namespace gui {

typedef console::main_implements main_implements;
typedef console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : done_event_loop_(false) {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_gui_main(argc, argv, env))) {
            int err2 = 0;
            LAMNA_LOG_MESSAGE_DEBUG("gui_main()...");
            err = gui_main(argc, argv, env);
            LAMNA_LOG_MESSAGE_DEBUG("...gui_main()");
            if ((err2 = after_gui_main(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int gui_main(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LAMNA_LOG_MESSAGE_DEBUG("before_event_loop()...");
        if (!(err = before_event_loop(argc, argv, env))) {
            int err2 = 0;
            LAMNA_LOG_MESSAGE_DEBUG("event_loop()...");
            err = event_loop(argc, argv, env);
            LAMNA_LOG_MESSAGE_DEBUG("...event_loop()");
            if ((err2 = after_event_loop(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    virtual int before_gui_main(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_gui_main(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_done_event_loop(bool is_true = true) {
        done_event_loop_ = is_true;
        return done_event_loop_;
    }
    virtual bool done_event_loop() const {
        return done_event_loop_;
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int __usage(int argc, char_t** argv, char_t** env) {
        int err = Extends::usage(argc, argv, env);
        return err;
    }
    virtual int __on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::on_option
        (optval, optarg, optname, optind, argc, argv, env);
        return err;
    }
    virtual int __on_argument
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        int err = Extends::on_argument
        (arg, argind, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* __option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = Extends::option_usage(optarg, longopt);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* __options(const struct option*& longopts) {
        const char_t* chars = Extends::options(longopts);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* __arguments(const char_t**& args) {
        const char_t* chars = Extends::arguments(args);
        args = 0;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool done_event_loop_;
};

} // namespace gui
} // namespace lamna 

#endif // _LAMNA_GUI_MAIN_HPP 
