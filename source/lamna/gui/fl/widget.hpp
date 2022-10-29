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
///   File: widget.hpp
///
/// Author: $author$
///   Date: 9/30/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_FL_WIDGET_HPP
#define _LAMNA_GUI_FL_WIDGET_HPP

#include "lamna/gui/fl/fl.hpp"

namespace lamna {
namespace gui {
namespace fl {

typedef implement_base widget_events_implements;
///////////////////////////////////////////////////////////////////////
///  Class: widget_eventst
///////////////////////////////////////////////////////////////////////
template
<class TImplements = widget_events_implements>

class _EXPORT_CLASS widget_eventst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int handle_FL_LEFT_MOUSE_RELEASE(int x, int y) {
        int handled = 0;
        return handled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int handle_FL_RIGHT_MOUSE_RELEASE(int x, int y) {
        int handled = 0;
        return handled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int handle_FL_RELEASE(int button, int x, int y) {
        int handled = 0;
        switch(button) {
        case FL_LEFT_MOUSE: {
            handled = handle_FL_LEFT_MOUSE_RELEASE(x, y);
            break; }
        case FL_RIGHT_MOUSE: {
            handled = handle_FL_RIGHT_MOUSE_RELEASE(x, y);
            break; }
        }
        return handled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void fill_rectangle(int x,int y,int w,int h, Fl_Color c) const {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef widget_eventst<> widget_events;

typedef widget_events widget_implements;
///////////////////////////////////////////////////////////////////////
///  Class: widgett
///////////////////////////////////////////////////////////////////////
template
<class TExtends, class TImplements = widget_implements>

class _EXPORT_CLASS widgett: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    widgett(int width, int height): Extends(width, height) {
    }
    widgett(): Extends(0, 0) {
    }
    virtual ~widgett() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int handle(int event) {
        int handled = 0;
        switch(event) {
        case FL_RELEASE: {
            handled = this->handle_FL_RELEASE
            (Fl::event_button(), Fl::event_x(), Fl::event_y());
            break; }
        }
        if (!(handled)) {
            handled = Extends::handle(event);
        }
        return handled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void fill_rectangle(int x,int y,int w,int h, Fl_Color c) const {
        this->draw_box(FL_FLAT_BOX, x,y, w,h, c);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace fl 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_FL_WIDGET_HPP 
