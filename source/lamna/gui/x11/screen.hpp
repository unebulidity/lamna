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
///   File: screen.hpp
///
/// Author: $author$
///   Date: 9/10/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_SCREEN_HPP
#define _LAMNA_GUI_X11_SCREEN_HPP

#include "lamna/gui/x11/attached.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef attachert<XScreen*, int, 0, XDisplay> screen_attacher;
typedef attachedt<XScreen*, int, 0, XDisplay, screen_attacher> screen_attached;
typedef screen_attacher screen_implements;
typedef screen_attached screen_extends;
///////////////////////////////////////////////////////////////////////
///  Class: screent
///////////////////////////////////////////////////////////////////////
template
<class TImplements = screen_implements, class TExtends = screen_extends>

class _EXPORT_CLASS screent: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    screent
    (XDisplay* display = 0, XScreen* detached = 0)
    : Extends(display, detached) {
    }
    virtual ~screent() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int screen_number() const {
        XDisplay* display = 0;
        XScreen* detached = 0;
        if ((detached = this->attached_to())) {
            if ((display = this->display())) {
                int number = XScreenNumberOfScreen(detached);
                return number;
            }
        }
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XScreen* get_attached(XDisplay& display) {
        XScreen* detached = 0;
        this->detach();
        if ((detached = get_detached(display))) {
            this->attach(&display, detached);
            return detached;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XScreen* get_detached(XDisplay& display) const {
        int screen_number = XDefaultScreen(&display);
        XScreen* detached = get_detached(display, screen_number);
        return detached;
    }
    virtual XScreen* get_detached
    (XDisplay& display, int screen_number) const {
        XScreen* detached = 0;
        LAMNA_LOG_MESSAGE_DEBUG("XScreenOfDisplay(..., " << screen_number << ")...");
        if ((detached = XScreenOfDisplay(&display, screen_number))) {
            LAMNA_LOG_MESSAGE_DEBUG("...XScreenOfDisplay(..., " << screen_number << ")");
            return detached;
        } else {
            LAMNA_LOG_ERROR("failed 0 == XScreenOfDisplay(..., " << screen_number << ")");
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef screent<> screen;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_SCREEN_HPP 
