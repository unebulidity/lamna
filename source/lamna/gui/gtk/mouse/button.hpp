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
///   File: button.hpp
///
/// Author: $author$
///   Date: 7/30/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_GTK_MOUSE_BUTTON_HPP
#define _LAMNA_GUI_GTK_MOUSE_BUTTON_HPP

#include "lamna/gui/mouse/button.hpp"
#include "lamna/gui/gtk/gtk.hpp"

#define LAMNA_GUI_GTK_MOUSE_BUTTON_LEFT 1
#define LAMNA_GUI_GTK_MOUSE_BUTTON_RIGHT 3
#define LAMNA_GUI_GTK_MOUSE_BUTTON_MIDDLE 2

namespace lamna {
namespace gui {
namespace gtk {
namespace mouse {

typedef gui::mouse::button_implements button_implements;
typedef gui::mouse::button button_extends;
///////////////////////////////////////////////////////////////////////
///  Class: buttont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = button_implements, class TExtends = button_extends>

class _EXPORT_CLASS buttont: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    buttont() {
    }
    virtual ~buttont() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static gui::mouse::button_which which(GdkEvent* event) {
        if ((event)) {
            guint button = event->button.button;
            if ((button != left())) {
                if ((button != right())) {
                    if ((button != middle())) {
                    } else {
                        return gui::mouse::button_middle;
                    }
                } else {
                    return gui::mouse::button_right;
                }
            } else {
                return gui::mouse::button_left;
            }
        }
        return gui::mouse::button_none;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static guint& left() {
        static guint value = LAMNA_GUI_GTK_MOUSE_BUTTON_LEFT;
        return value;
    }
    static guint& right() {
        static guint value = LAMNA_GUI_GTK_MOUSE_BUTTON_RIGHT;
        return value;
    }
    static guint& middle() {
        static guint value = LAMNA_GUI_GTK_MOUSE_BUTTON_MIDDLE;
        return value;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef buttont<> button;

} // namespace mouse 
} // namespace gtk 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_GTK_MOUSE_BUTTON_HPP 
