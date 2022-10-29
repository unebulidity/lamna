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
///   File: event_target_members.hpp
///
/// Author: $author$
///   Date: 9/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_EVENT_TARGET_HPP
#include "lamna/gui/x11/x11.hpp"

namespace lamna {
namespace gui {
namespace x11 {

///////////////////////////////////////////////////////////////////////
///  Class: event_targett
///////////////////////////////////////////////////////////////////////
template <class TImplements = implement_base>
class _EXPORT_CLASS event_targett: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
#endif // _LAMNA_GUI_X11_EVENT_TARGET_HPP

    virtual bool on_KeyPress_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_KeyRelease_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_ButtonPress_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_ButtonRelease_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_MotionNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_EnterNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_LeaveNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_FocusIn_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_FocusOut_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_KeymapNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_Expose_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_GraphicsExpose_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_NoExpose_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_VisibilityNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_CreateNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_DestroyNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_UnmapNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_MapNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_MapRequest_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_ReparentNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_ConfigureNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_ConfigureRequest_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_GravityNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_ResizeRequest_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_CirculateNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_CirculateRequest_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_PropertyNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_SelectionClear_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_SelectionRequest_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_SelectionNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_ColormapNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_ClientMessage_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_MappingNotify_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = on_XEvent_default(xEvent);
        return isHandled;
    }
    virtual bool on_XEvent_default(const XEvent& xEvent) {
        bool isHandled = false;
        isHandled = default_XEvent_handler(xEvent);
        return isHandled;
    }
    static bool default_XEvent_handler(const XEvent& xEvent);

#ifndef _LAMNA_GUI_X11_EVENT_TARGET_HPP
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_EVENT_TARGET_HPP
