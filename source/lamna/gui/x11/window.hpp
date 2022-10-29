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
///   File: window.hpp
///
/// Author: $author$
///   Date: 9/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_WINDOW_HPP
#define _LAMNA_GUI_X11_WINDOW_HPP

#include "lamna/gui/x11/gc.hpp"
#include "lamna/gui/x11/region.hpp"
#include "lamna/gui/x11/rectangle.hpp"
#include "lamna/gui/x11/event_target.hpp"
#include "lamna/gui/x11/event.hpp"
#include "lamna/gui/x11/created.hpp"
#include "lamna/gui/x11/attached.hpp"
#include "lamna/gui/x11/attacher.hpp"

#define LAMNA_GUI_X11_WINDOW_DEFAULT_XEVENT_MASK \
   ExposureMask|ColormapChangeMask|PropertyChangeMask|VisibilityChangeMask|\
   KeymapStateMask|EnterWindowMask|LeaveWindowMask|FocusChangeMask|\
   KeyPressMask|KeyReleaseMask|ButtonPressMask|ButtonReleaseMask|\
   PointerMotionMask|StructureNotifyMask|SubstructureNotifyMask|\
   SubstructureRedirectMask

#define LAMNA_GUI_X11_WINDOW_DEFAULT_XEVENT_GRAB_MASK \
   ButtonPressMask|ButtonReleaseMask|\
   PointerMotionMask|EnterWindowMask|LeaveWindowMask

namespace lamna {
namespace gui {
namespace x11 {

typedef xos::base::creatort<implement_base> window_creator;
typedef attachert<XWindow, int, None, XDisplay, window_creator> window_attacher;
typedef attachedt<XWindow, int, None, XDisplay, window_attacher> window_attached;
typedef createdt<XWindow, int, None, XDisplay, window_attacher, window_attached> window_created;
typedef window_attacher window_implements;
typedef window_created window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: windowt
///////////////////////////////////////////////////////////////////////
template
<class TEventTargetImplements = event_target,
 class TImplements = window_implements, class TExtends = window_extends>

class _EXPORT_CLASS windowt
: virtual public TEventTargetImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TEventTargetImplements EventTargetImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    windowt
    (XDisplay* display = 0, XWindow detached = None, bool is_created = false)
    : Extends(display, detached, is_created),
      Expose_XEvent_count_(0) {
    }
    virtual ~windowt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_Expose_XEvent(const XEvent& event) {
        rectangle rect(event.xexpose);
        XRegion region = 0;
        bool is_handled = true;

        if (!(region = paint_region_.attached_to())) {
            LAMNA_LOG_MESSAGE_DEBUG("paint_region_.create_attached()...");
            if (!(region = paint_region_.create_attached())) {
                is_handled = false;
            }
            LAMNA_LOG_MESSAGE_DEBUG("...paint_region_.create_attached()");
        }

        if (1 > (Expose_XEvent_count_++)) {
            paint_rectangle_.set(rect);
        } else {
            paint_rectangle_.include(rect);
        }

        if (1 > (event.xexpose.count)) {
            if ((is_handled)) {
                is_handled = on_paint(event);
            }
            if ((region)) {
                paint_region_.destroy();
            }
            Expose_XEvent_count_ = 0;
        }
        return is_handled;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_paint(const XEvent& event) {
        bool is_handled = false;
        rectangle* _rectangle = 0;
        region* _region = 0;
        gc* _gc = 0;

        if ((_gc = begin_paint(_region, _rectangle))) {
            is_handled = paint(*_gc, *_region, *_rectangle);
            end_paint(_gc, _region, _rectangle);
        }
        return is_handled;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual gc* begin_paint(region*& _region, rectangle*& _rectangle) {
        XRegion region = 0;
        if ((region = (paint_region_.attached_to()))) {
            gc* _gc = 0;
            if ((_gc = get_gc())) {
                _region = &paint_region_;
                _rectangle = &paint_rectangle_;
                return _gc;
            }
        }
        return 0;
    }
    virtual bool end_paint
    (gc* _gc, region* _region, rectangle* _rectangle) {
        bool success = free_gc(_gc);
        if (_region != (&paint_region_)) {
            success = false;
        }
        if (_rectangle != (&paint_rectangle_)) {
            success = false;
        }
        return success;
    }
    virtual bool paint
    (gc& _gc, region& _region, rectangle& _rectangle) {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual gc* get_gc() {
        XGC gc = 0;
        if (!(gc = (gc_.attached_to()))) {
            XDisplay* display = 0;
            XWindow window = None;
            if (None != (window = this->attached_to(display))) {
                if ((gc = gc_.create_attached(*display, window))) {
                    return &gc_;
                }
            }
        } else {
            return &gc_;
        }
        return 0;
    }
    virtual bool free_gc(gc* _gc) {
        if (_gc == (&gc_)) {
            if ((gc_.destroy())) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_wm_protocols(XAtom* protocols, int count) {
        XDisplay* display = 0;
        XWindow detached = None;
        if ((display = this->display()) && (None != (detached = this->attached_to()))) {
            if ((protocols)) {
                Status status = 0;
                if ((status = XSetWMProtocols(display, detached, protocols, count))) {
                    return true;
                } else {
                    LAMNA_LOG_ERROR("failed " << status << " on XSetWMProtocols()");
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool select_input() {
        XEventMask event_mask = default_XEventMask();
        return select_input(event_mask);
    }
    virtual bool select_input(XEventMask event_mask) {
        XDisplay* display = 0;
        XWindow detached = None;
        if ((display = this->display()) && (None != (detached = this->attached_to()))) {
            XSelectInput(display, detached, event_mask);
            return true;
        }
        return false;
    }
    static XEventMask default_XEventMask() {
        static XEventMask event_mask = LAMNA_GUI_X11_WINDOW_DEFAULT_XEVENT_MASK;
        return event_mask;
    }
    static XEventMask default_grab_XEventMask() {
        static XEventMask event_mask = LAMNA_GUI_X11_WINDOW_DEFAULT_XEVENT_GRAB_MASK;
        return event_mask;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool map() {
        XDisplay* display = 0;
        XWindow detached = None;
        if ((display = this->display()) && (None != (detached = this->attached_to()))) {
            XMapWindow(display, detached);
            return true;
        }
        return false;
    }
    virtual bool unmap() {
        XDisplay* display = 0;
        XWindow detached = None;
        if ((display = this->display()) && (None != (detached = this->attached_to()))) {
            XUnmapWindow(display, detached);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool invalidate(bool erase_background = false) {
        XWindowAttributes window_attributes;
        if ((get_attributes(window_attributes))) {
            LAMNA_LOG_MESSAGE_DEBUG("invalidate(0,0, " << window_attributes.width << "," << window_attributes.height << ")...");
            if ((invalidate(0,0, window_attributes.width, window_attributes.height, erase_background))) {
                LAMNA_LOG_MESSAGE_DEBUG("...invalidate(0,0, " << window_attributes.width << "," << window_attributes.height << ")");
                return true;
            }
        }
        return false;
    }
    virtual bool invalidate
    (int x, int y, int width, int height, bool erase_background = false) {
        XDisplay* display = 0;
        XWindow detached = None;
        if ((display = this->display()) && (None != (detached = this->attached_to()))) {
            if ((erase_background)) {
                XClearArea(display, detached, x,y, width,height, True);
                return true;
            } else {
                Expose_event event(display, detached, x,y, width,height);
                if ((event.send()))
                    return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool change_background(XPixel background) {
        XSetWindowAttributesMask set_window_attributes_mask = CWBackPixel;
        XSetWindowAttributes set_window_attributes;
        set_window_attributes.background_pixel = background;
        if ((change_attributes(set_window_attributes_mask, set_window_attributes))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool change_attributes
    (XSetWindowAttributesMask set_window_attributes_mask,
     XSetWindowAttributes& set_window_attributes) {
        XDisplay* display = 0;
        XWindow detached = None;
        if ((display = this->display()) && (None != (detached = this->attached_to()))) {
            XChangeWindowAttributes
            (display, detached, set_window_attributes_mask, &set_window_attributes);
            return true;
        }
        return false;
    }
    virtual bool get_attributes
    (XWindowAttributes& window_attributes) {
        XDisplay* display = 0;
        XWindow detached = None;
        if ((display = this->display()) && (None != (detached = this->attached_to()))) {
            XGetWindowAttributes(display, detached, &window_attributes);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool store_name(const char* name) {
        XDisplay* display = 0;
        XWindow detached = None;
        if ((name) && (display = this->display()) && (None != (detached = this->attached_to()))) {
            XStoreName(display, detached, name);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (XDisplay& display, XWindow parent_window,
     int x, int y, unsigned int width, unsigned int height,
     unsigned int border_width, XPixel border, XPixel background) {
        XWindow detached = None;
        if (None != (detached = create_attached
            (display, parent_window, x,y, width,height,
             border_width, border, background))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        XDisplay* display = 0;
        XWindow detached = None;
        if (None != (detached = this->detach(display))) {
            if ((display)) {
                if ((this->destroy_detached(*display, detached))) {
                    return true;
                }
            } else {
                LAMNA_LOG_ERROR("unexpected 0 == display");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XWindow create_attached
    (XDisplay& display, XWindow parent_window,
     int x, int y, unsigned int width, unsigned int height,
     unsigned int border_width, XPixel border, XPixel background) {
        XWindow detached = None;
        if (None != (detached = create_detached
            (display, parent_window, x,y, width,height,
             border_width, border, background))) {
            this->attach(&display, detached);
            return detached;
        }
        return None;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XWindow create_detached
    (XDisplay& display, XWindow parent_window,
     int x, int y, unsigned int width, unsigned int height,
     unsigned int border_width, XPixel border, XPixel background) const {
        XWindow detached = None;
        if (!(None != (detached = XCreateSimpleWindow
            (&display, parent_window, x,y, width,height,
             border_width, border, background)))) {
            LAMNA_LOG_ERROR("failed on XCreateSimpleWindow()");
        }
        return detached;
    }
    virtual bool destroy_detached
    (XDisplay& display, XWindow detached) const {
        if (None != (detached)) {
            XDestroyWindow(&display, detached);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    unsigned int Expose_XEvent_count_;
    gc gc_;
    region paint_region_;
    rectangle paint_rectangle_;
};
typedef windowt<> window;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_WINDOW_HPP 
