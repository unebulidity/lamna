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
///   File: main_window.hpp
///
/// Author: $author$
///   Date: 9/10/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_MAIN_WINDOW_HPP
#define _LAMNA_GUI_X11_MAIN_WINDOW_HPP

#include "lamna/gui/x11/window.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef window_implements main_window_implements;
typedef window main_window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_windowt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_window_implements,
 class TExtends = main_window_extends>

class _EXPORT_CLASS main_windowt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_windowt
    (XDisplay* display = 0, XWindow detached = None, bool is_created = false)
    : Extends(display, detached, is_created) {
    }
    virtual ~main_windowt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_create(int argc, char_t** argv, char_t** env) {
        return 0;
    }
    virtual int on_destroy(int argc, char_t** argv, char_t** env) {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef main_windowt<> main_window;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_MAIN_WINDOW_HPP 
