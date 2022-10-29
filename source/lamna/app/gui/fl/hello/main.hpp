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
///   Date: 9/30/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_GUI_FL_HELLO_MAIN_HPP
#define _LAMNA_APP_GUI_FL_HELLO_MAIN_HPP

#include "lamna/app/gui/hello/main.hpp"
#include "lamna/gui/fl/main.hpp"
#include "lamna/gui/fl/window.hpp"
#include "lamna/graphic/surface/filled_circle.hpp"
#include "lamna/graphic/surface/fl/color.hpp"
#include "lamna/graphic/surface/fl/object.hpp"
#include "lamna/graphic/surface/fl/image.hpp"
#include "lamna/graphic/surface/fl/context.hpp"
#include "lamna/graphic/surface/fl/pixel.hpp"

namespace lamna {
namespace app {
namespace gui {
namespace fl {
namespace hello {

typedef implement_base window_implements;
typedef gui::hello::surfacet<lamna::gui::fl::window> window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: window
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS window
: virtual public window_implements, public window_extends {
public:
    typedef window_implements Implements;
    typedef window_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    window(int width, int height) {
        w(width);
        h(height);
    }
    virtual ~window() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void invalidate() {
        redraw();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void draw() {
        int x = (w()/2), y = (h()/2), b = (border());
        fill_rectangle(0,0, w(),h(), color());
        if ((borders()+2 < x) && (borders()+2 < y)) {
            graphic::surface::fl::context gc(*this);
            graphic::surface::fl::image im(gc);
            graphic::surface::fl::color px
            (im, fg_color_red_, fg_color_green_, fg_color_blue_);
            graphic::surface::filled_circle ob(im, px, (b>5)?(b):(5));
            im.SelectImage(&ob);
            paint(im, x,y, x,y);
        }
    }
    virtual int handle_FL_LEFT_MOUSE_RELEASE(int x, int y) {
        int handled = 1;
        lamna::gui::mouse::position p(x, y);
        lamna::gui::mouse::button b(lamna::gui::mouse::button_left);
        lamna::gui::mouse::event e(lamna::gui::mouse::event_button_release, b, p);
        LAMNA_LOG_MESSAGE_DEBUG("...handle_FL_LEFT_MOUSE_RELEASE(x = " << x <<", y =" << y << ")");
        this->on_mouse_release_event(e);
        return handled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef lamna::gui::fl::main_implements main_implements;
typedef gui::hello::maint<lamna::gui::fl::main> main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main(): window_(0) {
    }
    virtual ~main() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Fl_Window* create_window(int argc, char_t** argv, char_t** env) {
        if ((window_ = new window(this->width(), this->height()))) {
            window_->size_range(this->width()/2, this->height()/2);
        }
        return window_;
    }
    virtual int destroy_window
    (Fl_Window* window, int argc, char_t** argv, char_t** env) {
        int err = 1;
        if ((window) && (window_ == window)) {
            delete window_;
            window_ = 0;
            err = 0;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    window* window_;
};

} // namespace hello 
} // namespace fl 
} // namespace gui 
} // namespace app 
} // namespace lamna 

#endif // _LAMNA_APP_GUI_FL_HELLO_MAIN_HPP 
