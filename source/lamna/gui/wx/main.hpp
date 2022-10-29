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
///   Date: 9/23/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WX_MAIN_HPP
#define _LAMNA_GUI_WX_MAIN_HPP

#include "lamna/gui/main.hpp"
#include "lamna/gui/wx/app.hpp"

namespace lamna {
namespace gui {
namespace wx {

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
    maint() {
    }
    virtual ~maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int entry(int argc, char_t** argv, char_t** env) {
        int wx_argc = optind - argc;
        char_t** wx_argv = argv + optind;
        int err = wxEntry(wx_argc, wx_argv);
        return err;
    }
    virtual int before_entry(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_entry(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LAMNA_LOG_MESSAGE_DEBUG("before_entry()...");
        if (!(err = before_entry(argc, argv, env))) {
            int err2 = 0;
            LAMNA_LOG_MESSAGE_DEBUG("entry()...");
            err = entry(argc, argv, env);
            LAMNA_LOG_MESSAGE_DEBUG("after_entry()...");
            if ((err2 = after_entry(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef maint<> main;

} // namespace wx 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WX_MAIN_HPP 
