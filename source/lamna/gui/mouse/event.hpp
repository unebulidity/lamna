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
///   File: event.hpp
///
/// Author: $author$
///   Date: 6/5/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_MOUSE_EVENT_HPP
#define _LAMNA_GUI_MOUSE_EVENT_HPP

#include "lamna/gui/mouse/position.hpp"
#include "lamna/gui/mouse/button.hpp"
#include "lamna/base/base.hpp"

namespace lamna {
namespace gui {
namespace mouse {

///////////////////////////////////////////////////////////////////////
///  Enum: event_which
///////////////////////////////////////////////////////////////////////
enum event_which {
    event_none = 0,

    event_button_press        = (1 << 0),
    event_button_release      = (1 << 1),
    event_button_click        = (1 << 2),
    event_button_double_click = (1 << 3),

    last_event_plus_1,
    last_event = (last_event_plus_1 - 1),
    first_event = 1,
    next_event = 1
};

///////////////////////////////////////////////////////////////////////
///  Class: eventt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = implement_base, class TExtends = base>

class _EXPORT_CLASS eventt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    eventt
    (event_which which, const mouse::button& button, const mouse::position& position)
    : which_(which), button_(button), position_(position) {
    }
    eventt(event_which which = event_none): which_(which) {
    }
    eventt(const eventt& copy): which_(event_none) {
        this->operator = (copy);
    }
    virtual ~eventt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eventt& operator = (const eventt& copy) {
        position_ = copy.position_;
        switch (which_ = copy.which_) {
        case event_button_press:
        case event_button_release:
        case event_button_click:
        case event_button_double_click:
            button_ = copy.button_;
            break;
        }
        return *this;
    }
    virtual event_which which() const {
        return which_;
    }
    virtual mouse::position position() const {
        return position_;
    }
    virtual mouse::button button() const {
        return button_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    event_which which_;
    mouse::position position_;
    mouse::button button_;
};
typedef eventt<> event;

} // namespace mouse 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_MOUSE_EVENT_HPP 
