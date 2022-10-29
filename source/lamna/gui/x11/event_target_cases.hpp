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
///   File: event_target_cases.hpp
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
    virtual bool on_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        switch(xEvent.type) {
#endif // _LAMNA_GUI_X11_EVENT_TARGET_HPP

        case KeyPress:
             isHandled = on_KeyPress_XEvent(xEvent);
             break;

        case KeyRelease:
             isHandled = on_KeyRelease_XEvent(xEvent);
             break;

        case ButtonPress:
             isHandled = on_ButtonPress_XEvent(xEvent);
             break;

        case ButtonRelease:
             isHandled = on_ButtonRelease_XEvent(xEvent);
             break;

        case MotionNotify:
             isHandled = on_MotionNotify_XEvent(xEvent);
             break;

        case EnterNotify:
             isHandled = on_EnterNotify_XEvent(xEvent);
             break;

        case LeaveNotify:
             isHandled = on_LeaveNotify_XEvent(xEvent);
             break;

        case FocusIn:
             isHandled = on_FocusIn_XEvent(xEvent);
             break;

        case FocusOut:
             isHandled = on_FocusOut_XEvent(xEvent);
             break;

        case KeymapNotify:
             isHandled = on_KeymapNotify_XEvent(xEvent);
             break;

        case Expose:
             isHandled = on_Expose_XEvent(xEvent);
             break;

        case GraphicsExpose:
             isHandled = on_GraphicsExpose_XEvent(xEvent);
             break;

        case NoExpose:
             isHandled = on_NoExpose_XEvent(xEvent);
             break;

        case VisibilityNotify:
             isHandled = on_VisibilityNotify_XEvent(xEvent);
             break;

        case CreateNotify:
             isHandled = on_CreateNotify_XEvent(xEvent);
             break;

        case DestroyNotify:
             isHandled = on_DestroyNotify_XEvent(xEvent);
             break;

        case UnmapNotify:
             isHandled = on_UnmapNotify_XEvent(xEvent);
             break;

        case MapNotify:
             isHandled = on_MapNotify_XEvent(xEvent);
             break;

        case MapRequest:
             isHandled = on_MapRequest_XEvent(xEvent);
             break;

        case ReparentNotify:
             isHandled = on_ReparentNotify_XEvent(xEvent);
             break;

        case ConfigureNotify:
             isHandled = on_ConfigureNotify_XEvent(xEvent);
             break;

        case ConfigureRequest:
             isHandled = on_ConfigureRequest_XEvent(xEvent);
             break;

        case GravityNotify:
             isHandled = on_GravityNotify_XEvent(xEvent);
             break;

        case ResizeRequest:
             isHandled = on_ResizeRequest_XEvent(xEvent);
             break;

        case CirculateNotify:
             isHandled = on_CirculateNotify_XEvent(xEvent);
             break;

        case CirculateRequest:
             isHandled = on_CirculateRequest_XEvent(xEvent);
             break;

        case PropertyNotify:
             isHandled = on_PropertyNotify_XEvent(xEvent);
             break;

        case SelectionClear:
             isHandled = on_SelectionClear_XEvent(xEvent);
             break;

        case SelectionRequest:
             isHandled = on_SelectionRequest_XEvent(xEvent);
             break;

        case SelectionNotify:
             isHandled = on_SelectionNotify_XEvent(xEvent);
             break;

        case ColormapNotify:
             isHandled = on_ColormapNotify_XEvent(xEvent);
             break;

        case ClientMessage:
             isHandled = on_ClientMessage_XEvent(xEvent);
             break;

        case MappingNotify:
             isHandled = on_MappingNotify_XEvent(xEvent);
             break;

        default:
             isHandled = on_XEvent_default(xEvent);
             break;

#ifndef _LAMNA_GUI_X11_EVENT_TARGET_HPP
        }
        return isHandled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_EVENT_TARGET_HPP
