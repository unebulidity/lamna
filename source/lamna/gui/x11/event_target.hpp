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
///   File: event_target.hpp
///
/// Author: $author$
///   Date: 9/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_EVENT_TARGET_HPP
#define _LAMNA_GUI_X11_EVENT_TARGET_HPP

#include "lamna/gui/x11/x11.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef implement_base event_target_implements;
///////////////////////////////////////////////////////////////////////
///  Class: event_target
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS event_target: virtual public event_target_implements {
public:
    typedef event_target_implements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
#include "lamna/gui/x11/event_target_members.hpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_XEvent(const XEvent& xEvent) {
        bool isHandled = false;
        switch(xEvent.type) {
#include "lamna/gui/x11/event_target_cases.hpp"
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
