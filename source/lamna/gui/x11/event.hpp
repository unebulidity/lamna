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
///   Date: 9/10/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_EVENT_HPP
#define _LAMNA_GUI_X11_EVENT_HPP

#include "lamna/gui/x11/x11.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef implement_base event_implements;
typedef xos::base::wrappedt<XEvent> event_extends;
///////////////////////////////////////////////////////////////////////
///  Class: event
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS event
: virtual public event_implements, public event_extends {
public:
    typedef event_implements Implements;
    typedef event_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    event
    (XDisplay* display, XWindow window, XEventType type,
     bool sent = false, unsigned long serial = 0) {
        wrapped().xany.display = display;
        wrapped().xany.window = window;
        wrapped().xany.send_event = (Bool)((sent)?(True):(False));
        wrapped().xany.serial = serial;
        wrapped().xany.type = type;
    }
    event(const event& copy): Extends(copy) {
    }
    event() {
    }
    virtual ~event() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool send(bool propigate = false, XEventMask mask = 0) {
        XDisplay* display = wrapped().xany.display;
        XWindow window = wrapped().xany.window;
        if ((display) && (None != (window))) {
            Bool bPropigate = (Bool)((propigate)?(True):(False));
            LAMNA_LOG_MESSAGE_DEBUG("XSendEvent()...");
            if ((XSendEvent(display, window, bPropigate, mask, &wrapped()))) {
                LAMNA_LOG_MESSAGE_DEBUG("...XSendEvent()");
                return true;
            } else {
                LAMNA_LOG_ERROR("failed on XSendEvent()");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator XEvent& () const {
        return wrapped();
    }
    virtual operator XEvent* () const {
        return &wrapped();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///  Class: Expose_event
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Expose_event: public event {
public:
    typedef event Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Expose_event
    (XDisplay* display, XWindow window,
     int x,int y, int width,int height, int count = 0,
     XEventType type = Expose, bool sent = false, unsigned long serial = 0)
    : Extends(display, window, type, sent, serial) {
        wrapped().xexpose.x = x;
        wrapped().xexpose.y = y;
        wrapped().xexpose.width = width;
        wrapped().xexpose.height = height;
        wrapped().xexpose.count = count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace x11
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_EVENT_HPP 
