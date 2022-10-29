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
///   Date: 6/20/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_GTK_MAIN_HPP
#define _LAMNA_GUI_GTK_MAIN_HPP

#include "lamna/gui/main.hpp"
#include "lamna/gui/gtk/gtk.hpp"

namespace lamna {
namespace gui {
namespace gtk {

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
    maint() {
    }
    virtual ~maint() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_gui_main(int argc, char_t** argv, char_t** env) {
        int err = 0;
        int* pargc = 0;
        char*** pargv = 0;
        LAMNA_LOG_MESSAGE_DEBUG("gtk_init_check()...");
        if (TRUE != (gtk_init_check(pargc ,pargv))) {
            LAMNA_LOG_ERROR("failed on gtk_init_check()");
            err = 1;
        } else {
            LAMNA_LOG_MESSAGE_DEBUG("...gtk_init_check()");
        }
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
        LAMNA_LOG_MESSAGE_DEBUG("gtk_main()...");
        gtk_main();
        LAMNA_LOG_MESSAGE_DEBUG("...gtk_main()");
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef maint<> main;

} // namespace gtk 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_GTK_MAIN_HPP 
