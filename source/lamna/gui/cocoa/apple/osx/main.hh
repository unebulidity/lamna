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
///   File: main.hh
///
/// Author: $author$
///   Date: 10/15/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_COCOA_APPLE_OSX_MAIN_HH
#define _LAMNA_GUI_COCOA_APPLE_OSX_MAIN_HH

#include "lamna/gui/cocoa/iOptMain.hh"
#include "lamna/gui/main.hpp"

namespace lamna {
namespace gui {
namespace cocoa {
namespace apple {
namespace osx {

typedef gui::main_implements main_implements;
typedef gui::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main(): main_(0) {
    }
    virtual ~main() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        id<iOptMain> main = 0;
        if ((main = main_)) {

            LAMNA_LOG_MESSAGE_DEBUG("[main beforeMain:argc argv:argv env:env]...");
            if (!(err = [main beforeMain:argc argv:argv env:env])) {
                int err2 = 0;

                LAMNA_LOG_MESSAGE_DEBUG("[main main:argc argv:argv env:env]...");
                if ((err = [main main:argc argv:argv env:env])) {
                    LAMNA_LOG_DEBUG("...error " << err << " on [main main]");
                }
                LAMNA_LOG_MESSAGE_DEBUG("[main afterMain:argc argv:argv env:env]...");
                if ((err2 = [main afterMain:argc argv:argv env:env])) {
                    LAMNA_LOG_DEBUG("...error " << err << " on [main afterMain]");
                    if (!err) err = err2;
                }
            } else {
                LAMNA_LOG_DEBUG("...error " << err << " on [main beforeMain]");
            }
        } else {
            LAMNA_LOG_ERROR("unexpected main_ == 0");
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 1;
        id<iOptMain> main = 0;
        if ((main = main_)) {
            err = [main onOption:optval optarg:optarg optname:optname
                        optind:optind argc:argc argv:argv env:env];
        } else {
            err = __on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_argument
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        int err = 1;
        id<iOptMain> main = 0;
        if ((main = main_)) {
            err = [main onArgument:arg argind:argind argc:argc argv:argv env:env];
        } else {
            err = __on_argument
            (arg, argind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = 0;
        id<iOptMain> main = 0;
        if ((main = main_)) {
            chars = [main optionUsage:optarg longopt:longopt];
        } else {
            chars = __option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        const char_t* chars = 0;
        id<iOptMain> main = 0;
        if ((main = main_)) {
            chars = [main options:longopts];
        } else {
            chars = __options(longopts);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& args) {
        const char_t* chars = 0;
        id<iOptMain> main = 0;
        if ((main = main_)) {
            chars = [main arguments:args];
        } else {
            chars = __arguments(args);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_main(int argc, char_t** argv, char_t** env) {
        int err = 1;
        id<iOptMain> main = 0;
        LAMNA_LOG_MESSAGE_DEBUG("main = [iMain create]...");
        if ((main = [iMain create:this])) {
            main_ = main;
            if ((err = Extends::before_main(argc, argv, env))) {
                LAMNA_LOG_MESSAGE_DEBUG("[main destroy]...");
                [main destroy];
                main_ = 0;
            } else {
            }
        } else {
            LAMNA_LOG_ERROR("failed on [iMain create]");
        }
        return err;
    }
    virtual int after_main(int argc, char_t** argv, char_t** env) {
        int err = Extends::after_main(argc, argv, env);
        id<iOptMain> main = 0;
        if ((main = main_)) {
            main_ = 0;
            LAMNA_LOG_MESSAGE_DEBUG("[main destroy]...");
            [main destroy];
        } else {
            LAMNA_LOG_ERROR("unexpected main_ == 0");
            if (!(err)) err = 1;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    id<iOptMain> main_;
};

} // namespace osx 
} // namespace apple 
} // namespace cocoa 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_COCOA_APPLE_OSX_MAIN_HH 
