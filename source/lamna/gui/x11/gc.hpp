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
///   File: gc.hpp
///
/// Author: $author$
///   Date: 9/15/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_GC_HPP
#define _LAMNA_GUI_X11_GC_HPP

#include "lamna/gui/x11/created.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef xos::base::creatort<implement_base> gc_creator;
typedef attachert<XGC, int, 0, XDisplay, gc_creator> gc_attacher;
typedef attachedt<XGC, int, 0, XDisplay, gc_attacher> gc_attached;
typedef createdt<XGC, int, 0, XDisplay, gc_attacher, gc_attached> gc_created;
typedef gc_attacher gc_implements;
typedef gc_created gc_extends;
///////////////////////////////////////////////////////////////////////
///  Class: gct
///////////////////////////////////////////////////////////////////////
template
<class TImplements = gc_implements, class TExtends = gc_extends>

class _EXPORT_CLASS gct: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    gct(XDisplay* display = 0, XGC detached = 0, bool is_created = false)
    : Extends(display, detached, is_created),
      drawable_(None) {
    }
    virtual ~gct() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool fill_rectangle
    (int x, int y, unsigned int width, unsigned int height) {
        XDisplay* display = 0;
        XDrawable drawable = None;
        XGC detached = 0;
        if ((detached = this->attached_to(display, drawable))) {
            if ((display)) {
                if (None != (drawable)) {
                    XFillRectangle(display, drawable, detached, x,y, width,height);
                    return true;
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_region(XRegion region) {
        XDisplay* display = 0;
        XGC detached = 0;
        if ((detached = this->attached_to(display))) {
            if ((display)) {
                XSetRegion(display, detached, region);
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_foreground(XPixel pixel) {
        XDisplay* display = 0;
        XGC detached = 0;
        if ((detached = this->attached_to(display))) {
            if ((display)) {
                XSetForeground(display, detached, pixel);
                return true;
            }
        }
        return false;
    }
    virtual bool set_background(XPixel pixel) {
        XDisplay* display = 0;
        XGC detached = 0;
        if ((detached = this->attached_to(display))) {
            if ((display)) {
                XSetBackground(display, detached, pixel);
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (XDisplay& display, XDrawable drawable) {
        XGCValuesMask gc_values_mask = 0;
        XGCValues gc_values;
        return create
        (display, drawable, gc_values, gc_values_mask);
    }
    virtual bool create
    (XDisplay& display, XDrawable drawable,
     XGCValues& gc_values, XGCValuesMask gc_values_mask) {
        XGC detached = 0;
        if ((detached = create_attached
             (display, drawable, gc_values, gc_values_mask))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        XDisplay* display = 0;
        XDrawable drawable = None;
        XGC detached = 0;
        if ((detached = this->detach(display, drawable))) {
            if ((display)) {
                if (None != (drawable)) {
                    if ((destroy_detached(*display, drawable, detached))) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XGC create_attached
    (XDisplay& display, XDrawable drawable) {
        XGCValuesMask gc_values_mask = 0;
        XGCValues gc_values;
        return create_attached
        (display, drawable, gc_values, gc_values_mask);
    }
    virtual XGC create_attached
    (XDisplay& display, XDrawable drawable,
     XGCValues& gc_values, XGCValuesMask gc_values_mask) {
        if ((this->destroyed())) {
            XGC detached = 0;
            if ((detached = create_detached
                 (display, drawable, gc_values, gc_values_mask))) {
                this->attach(&display, drawable, detached);
                return detached;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XGC create_detached
    (XDisplay& display, XDrawable drawable) const {
        XGCValuesMask gc_values_mask = 0;
        XGCValues gc_values;
        return create_detached
        (display, drawable, gc_values, gc_values_mask);
    }
    virtual XGC create_detached
    (XDisplay& display, XDrawable drawable,
     XGCValues& gc_values, XGCValuesMask gc_values_mask) const {
        XGC detached = 0;
        if ((detached = XCreateGC
             (&display, drawable, gc_values_mask, &gc_values))) {
            return detached;
        } else {
            LAMNA_LOG_ERROR("failed 0 == XCreateGC()");
        }
        return 0;
    }
    virtual bool destroy_detached
    (XDisplay& display, XDrawable drawable, XGC detached) const {
        if ((detached)) {
            XFreeGC(&display, detached);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::attach;
    virtual XGC attach(XDisplay* display, XDrawable drawable, XGC detached) {
        detached = this->attach(display, detached);
        this->drawable_ = drawable;
        return detached;
    }
    using Extends::detach;
    virtual XGC detach(XDisplay*& display, XDrawable& drawable) {
        XGC detached = this->detach(display);
        drawable = this->drawable_;
        this->drawable_ = None;
        return detached;
    }
    using Extends::attached_to;
    virtual XGC attached_to(XDisplay*& display, XDrawable& drawable) const {
        XGC detached = this->attached_to(display);
        drawable = this->drawable_;
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    XDrawable drawable_;
};
typedef gct<> gc;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_GC_HPP 
