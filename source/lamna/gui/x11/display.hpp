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
///   File: display.hpp
///
/// Author: $author$
///   Date: 9/9/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_DISPLAY_HPP
#define _LAMNA_GUI_X11_DISPLAY_HPP

#include "lamna/gui/x11/screen.hpp"
#include "lamna/gui/x11/x11.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef XDisplay* display_attached_t;
typedef xos::base::openert<implement_base> display_opener;
typedef xos::base::attachert<display_attached_t, int, 0, display_opener> display_attacher;
typedef xos::base::attachedt<display_attached_t, int, 0, display_attacher, base> display_attached;
typedef xos::base::openedt<display_attached_t, int, 0, display_attacher, display_attached> display_opened;
typedef display_attacher display_implements;
typedef display_opened display_extends;
///////////////////////////////////////////////////////////////////////
///  Class: displayt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = display_implements, class TExtends = display_extends>

class _EXPORT_CLASS displayt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    displayt(XDisplay* detached = 0, bool is_open = false)
    : Extends(detached, is_open) {
    }
    virtual ~displayt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open(const char* name) {
        XDisplay* detached = 0;
        if ((detached = this->open_attached(name))) {
            this->set_is_open();
            return true;
        }
        return false;
    }
    virtual bool close() {
        XDisplay* detached = 0;
        if ((detached = this->detach())) {
            if ((this->close_detached(detached))) {
                return true;
            }
        }
        return false;
    }
    virtual XDisplay* open_attached(const char* name) {
        XDisplay* detached = 0;
        if ((detached = this->open_detached(name))) {
            this->attach(detached);
            return detached;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XDisplay* open_detached(const char* name) const {
        if ((name)) {
            XDisplay* detached = 0;
            if ((detached = XOpenDisplay(name))) {
                return detached;
            } else {
                LAMNA_LOG_ERROR("failed 0 == XOpenDisplay(name = \"" << name << "\")");
            }
        }
        return 0;
    }
    virtual bool close_detached(XDisplay* detached) const {
        if ((detached)) {
            XCloseDisplay(detached);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XDisplay* attach(XDisplay* detached) {
        if ((detached = Extends::attach(detached))) {
            XScreen* screen = 0;
            if ((screen = screen_.get_attached(*detached))) {
                return detached;
            } else {
                LAMNA_LOG_ERROR("error 0 == screen_.get_attached()");
                Extends::detach();
            }
        }
        return 0;
    }
    virtual XDisplay* detach() {
        screen_.detach();
        return Extends::detach();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XScreen* screen_attached_to() const {
        return screen_.attached_to();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XWindow root_window_attached_to() const {
        XScreen* screen = 0;
        if ((screen = screen_attached_to())) {
            XWindow window = None;
            if (None != (window = XRootWindowOfScreen(screen))) {
                return window;
            } else {
                LAMNA_LOG_ERROR("failed None == XRootWindowOfScreen()");
            }
        }
        return None;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    screen screen_;
};
typedef displayt<> display;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_DISPLAY_HPP 
