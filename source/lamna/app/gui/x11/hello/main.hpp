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
///   File: main.hpp
///
/// Author: $author$
///   Date: 9/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_GUI_X11_HELLO_MAIN_HPP
#define _LAMNA_APP_GUI_X11_HELLO_MAIN_HPP

#include "lamna/app/gui/hello/main.hpp"
#include "lamna/graphic/surface/x11/color.hpp"
#include "lamna/graphic/surface/x11/image.hpp"
#include "lamna/graphic/surface/x11/context.hpp"
#include "lamna/graphic/surface/x11/pixel.hpp"
#include "lamna/graphic/surface/color.hpp"
#include "lamna/graphic/surface/context.hpp"
#include "lamna/graphic/surface/image.hpp"
#include "lamna/gui/x11/window_main.hpp"
#include "lamna/gui/x11/main_window.hpp"
#include "lamna/gui/x11/window.hpp"
#include "lamna/gui/x11/main.hpp"
#include "lamna/gui/main.hpp"

namespace lamna {
namespace app {
namespace gui {
namespace x11 {
namespace hello {

typedef lamna::gui::x11::main_window_implements main_window_implements;
typedef gui::hello::surfacet
<lamna::gui::x11::main_window> main_window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_window
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main_window
: virtual public main_window_implements, public main_window_extends {
public:
    typedef main_window_implements Implements;
    typedef main_window_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_window
    (lamna::gui::x11::colormap& colormap)
    : colormap_(colormap), left_button_(1), width_(0), height_(0) {
    }
    virtual ~main_window() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::paint;
    virtual bool paint
    (lamna::gui::x11::gc& _gc,
     lamna::gui::x11::region& _region,
     lamna::gui::x11::rectangle& _rectangle) {
        int x = _rectangle.wrapped().x,
            y = _rectangle.wrapped().y,
            width = _rectangle.wrapped().width,
            height = _rectangle.wrapped().height;
        if (width_ > (width)) width = width_;
        if (height_ > (height)) height = height_;
        if ((2 <= (x = width/2)) && (2 <= (y = height/2))) {
            lamna::gui::x11::XDisplay* display = 0;
            if ((display = this->display())) {
                lamna::gui::x11::XColormap colormap = None;
                if (None != (colormap = colormap_.attached_to())) {
                    lamna::gui::x11::xcolor xcolor
                    (fg_color_red_, fg_color_green_, fg_color_blue_);
                    if ((color_.create(*display, colormap, xcolor))) {
                        graphic::surface::x11::context gc(_gc);
                        graphic::surface::x11::image im(gc);
                        graphic::surface::x11::color px
                        (im, xcolor, color_.attached_to());
                        im.SelectImage(&px);
                        paint(im, x,y, x,y);
                        color_.destroy();
                    }
                }
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_ButtonRelease_XEvent(const XEvent& event) {
        bool isHandled = on_XEvent_default(event);
        unsigned int button = event.xbutton.button;
        LAMNA_LOG_MESSAGE_DEBUG("ButtonRelease button = " << button << "...");
        if (left_button_ == (button)) {
            size_t x = event.xbutton.x, y = event.xbutton.y;
            lamna::gui::mouse::position p(x, y);
            lamna::gui::mouse::button b(lamna::gui::mouse::button_left);
            lamna::gui::mouse::event e(lamna::gui::mouse::event_button_release, b, p);
            this->on_mouse_release_event(e);
        }
        return isHandled;
    }
    virtual bool on_ConfigureNotify_XEvent(const XEvent& event) {
        bool isHandled = on_XEvent_default(event);
        width_ = event.xconfigure.width;
        height_ = event.xconfigure.height;
        return isHandled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void invalidate() {
        Extends::Extends::invalidate(true);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    lamna::gui::x11::colormap& colormap_;
    lamna::gui::x11::color color_;
    int left_button_;
    unsigned int width_, height_;
};

typedef lamna::gui::x11::window_main_implements main_implements;
typedef gui::hello::maint<lamna::gui::x11::window_main> main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements,public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main(): main_window_(this->colormap_created_) {
        this->main_window_width_ = LAMNA_APP_GUI_HELLO_WIDTH;
        this->main_window_height_ = LAMNA_APP_GUI_HELLO_HEIGHT;
    }
    virtual ~main() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual lamna::gui::x11::main_window& main_window_created() const {
        return ((lamna::gui::x11::main_window&)main_window_);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    main_window main_window_;
};

} // namespace hello 
} // namespace x11 
} // namespace gui 
} // namespace app 
} // namespace lamna 

#endif // _LAMNA_APP_GUI_X11_HELLO_MAIN_HPP 
