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
///   File: colormap.hpp
///
/// Author: $author$
///   Date: 9/12/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_COLORMAP_HPP
#define _LAMNA_GUI_X11_COLORMAP_HPP

#include "lamna/gui/x11/created.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef xos::base::creatort<implement_base> colormap_creator;
typedef attachert<XColormap, int, None, XDisplay, colormap_creator> colormap_attacher;
typedef attachedt<XColormap, int, None, XDisplay, colormap_attacher> colormap_attached;
typedef createdt<XColormap, int, None, XDisplay, colormap_attacher, colormap_attached> colormap_created;
typedef colormap_attacher colormap_implements;
typedef colormap_created colormap_extends;
///////////////////////////////////////////////////////////////////////
///  Class: colormapt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = colormap_implements, class TExtends = colormap_extends>

class _EXPORT_CLASS colormapt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    colormapt
    (XDisplay* display = 0, XColormap detached = None, bool is_created = false)
    : Extends(display, detached, is_created) {
    }
    virtual ~colormapt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (XDisplay& display, XWindow window, XVisual& visual) {
        int alloc_entries = AllocAll;
        return create
        (display, window, visual, alloc_entries);
    }
    virtual bool create
    (XDisplay& display, XWindow window,
     XVisual& visual, int alloc_entries) {
        XColormap detached = None;
        if (None != (detached = (create_attached
            (display, window, visual, alloc_entries)))) {
            this->set_is_created();
            return true;
        }
        return None;
    }
    virtual bool destroy() {
        XDisplay* display = 0;
        XColormap detached = None;
        if (None != (this->detach(display))) {
            if ((display)) {
                if ((destroy_detached(*display, detached))) {
                    return true;
                }
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XColormap create_attached
    (XDisplay& display, XWindow window, XVisual& visual) {
        int alloc_entries = AllocAll;
        return create_attached
        (display, window, visual, alloc_entries);
    }
    virtual XColormap create_attached
    (XDisplay& display, XWindow window,
     XVisual& visual, int alloc_entries) {
        XColormap detached = None;
        if (None != (detached = (create_detached
            (display, window, visual, alloc_entries)))) {
            this->attach(&display, detached);
            return detached;
        }
        return None;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XColormap create_detached
    (XDisplay& display, XWindow window, XVisual& visual) const {
        int alloc_entries = AllocAll;
        return create_detached
        (display, window, visual, alloc_entries);
    }
    virtual XColormap create_detached
    (XDisplay& display, XWindow window,
     XVisual& visual, int alloc_entries) const {
        XColormap detached = None;
        if (None != (detached = (XCreateColormap
            (&display, window, &visual, alloc_entries)))) {
            return detached;
        } else {
            LAMNA_LOG_ERROR("failed None == XCreateColormap()");
        }
        return None;
    }
    virtual bool destroy_detached
    (XDisplay& display, XColormap detached) const {
        if (None != (detached)) {
            XFreeColormap(&display, detached);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XColormap attach_default(XDisplay& display) {
        unsigned int screen_number = XDefaultScreen(&display);
        XColormap detached = attach_default_of_screen(display, screen_number);
        return detached;
    }
    virtual XColormap attach_default_of_screen
    (XDisplay& display, unsigned int screen_number) {
        XScreen* screen = XScreenOfDisplay(&display, screen_number);
        XColormap detached = 0;
        if ((screen)) {
            detached = attach_default_of_screen(display, *screen);
        } else {
            LAMNA_LOG_ERROR("failed 0 == XScreenOfDisplay()");
        }
        return detached;
    }
    virtual XColormap attach_default_of_screen
    (XDisplay& display, XScreen& screen) {
        XColormap detached = 0;
        if ((this->destroyed())) {
            if ((detached = XDefaultColormapOfScreen(&screen))) {
                this->attach(&display, detached);
            }
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef colormapt<> colormap;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_COLORMAP_HPP 
