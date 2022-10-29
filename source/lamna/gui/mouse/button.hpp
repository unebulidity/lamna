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
///   Date: 6/5/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_MOUSE_BUTTON_HPP
#define _LAMNA_GUI_MOUSE_BUTTON_HPP

#include "lamna/base/base.hpp"

namespace lamna {
namespace gui {
namespace mouse {

///////////////////////////////////////////////////////////////////////
///  Enum: button_which
///////////////////////////////////////////////////////////////////////
enum button_which {
    button_none = 0,

    button_left = (1 << 0),
    button_right = (1 << 1),
    button_middle = (1 << 2),

    last_button_plus_1,
    last_button = (last_button_plus_1 - 1),
    first_button = 1,
    next_button = 1
};

typedef implement_base button_implements;
typedef base button_extends;
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
    buttont(button_which which = button_none): which_(which) {
    }
    virtual ~buttont() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual button_which which() const {
        return which_;
    }
    virtual operator button_which() const {
        return which_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    button_which which_;
};
typedef buttont<> button;

} // namespace mouse
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_MOUSE_BUTTON_HPP 
