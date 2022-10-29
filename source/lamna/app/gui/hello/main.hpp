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
///   Date: 9/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_GUI_HELLO_MAIN_HPP
#define _LAMNA_APP_GUI_HELLO_MAIN_HPP

#include "lamna/graphic/surface/image.hpp"
#include "lamna/gui/mouse/event.hpp"

#define LAMNA_APP_GUI_HELLO_WIDTH 400
#define LAMNA_APP_GUI_HELLO_HEIGHT 200
#define LAMNA_APP_GUI_HELLO_BORDER 10

#define LAMNA_APP_GUI_HELLO_FG_COLOR_RED   0
#define LAMNA_APP_GUI_HELLO_FG_COLOR_GREEN 0
#define LAMNA_APP_GUI_HELLO_FG_COLOR_BLUE  255

namespace lamna {
namespace app {
namespace gui {
namespace hello {

///////////////////////////////////////////////////////////////////////
///  Class: surfacet
///////////////////////////////////////////////////////////////////////
template <class TExtends>

class _EXPORT_CLASS surfacet: public TExtends {
public:
    typedef TExtends Extends;
    typedef surfacet Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    surfacet(int fg_color_red, int fg_color_green, int fg_color_blue)
    : fg_color_red_(fg_color_red),
      fg_color_green_(fg_color_green),
      fg_color_blue_(fg_color_blue),
      border_(LAMNA_APP_GUI_HELLO_BORDER),
      paint_(0) {
    }
    surfacet()
    : fg_color_red_(LAMNA_APP_GUI_HELLO_FG_COLOR_RED),
      fg_color_green_(LAMNA_APP_GUI_HELLO_FG_COLOR_GREEN),
      fg_color_blue_(LAMNA_APP_GUI_HELLO_FG_COLOR_BLUE),
      border_(LAMNA_APP_GUI_HELLO_BORDER),
      paint_(0) {
    }
    virtual ~surfacet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef void (Derives::*paint_t)
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    void paint_FillEllipse
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.FillEllipse(x,y, w,h);
    }
    void paint_DrawEllipse
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.DrawEllipse(x,y, w,h);
    }
    void paint_HollowEllipse
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.HollowEllipse(x,y, w,h);
    }
    void paint_FillCircle
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.FillCircle(x,y, r);
    }
    void paint_DrawCircle
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.DrawCircle(x,y, r);
    }
    void paint_HollowCircle
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.HollowCircle(x,y, r);
    }
    void paint_FillTriangle
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.FillTriangle(x,y-h,x+w,y+h,x-w,y+h);
    }
    void paint_Draw
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.Draw(x-w,y-h, x+w,y+h);
        im.Draw(x-w,y+h, x+w,y-h);
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    void paint
    (graphic::surface::image_interface& im, int x, int y, int w, int h) {
        int borders = (border_ + border_);
        if ((borders < w) && (borders < h)) {
            int r = ((w -= borders) > (h -= borders))?(h):(w);
            if ((paint_)) {
                (this->*paint_)(im, x,y, w,h, r);
            } else {
                (this->*(paint_ = &Derives::paint_FillEllipse))(im, x,y, w,h, r);
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_mouse_release_event(const lamna::gui::mouse::event& e) {
        LAMNA_LOG_MESSAGE_DEBUG("on_mouse_release_event() in...");
        if ((paint_ == &Derives::paint_FillEllipse)) {
            paint_ = &Derives::paint_DrawEllipse;
        } else if ((paint_ == &Derives::paint_DrawEllipse)) {
                paint_ = &Derives::paint_HollowEllipse;
        } else if ((paint_ == &Derives::paint_HollowEllipse)) {
                paint_ = &Derives::paint_FillCircle;
        } else if ((paint_ == &Derives::paint_FillCircle)) {
                paint_ = &Derives::paint_DrawCircle;
        } else if ((paint_ == &Derives::paint_DrawCircle)) {
                paint_ = &Derives::paint_HollowCircle;
        } else if ((paint_ == &Derives::paint_HollowCircle)) {
                paint_ = &Derives::paint_FillTriangle;
        } else if ((paint_ == &Derives::paint_FillTriangle)) {
                paint_ = &Derives::paint_Draw;
        } else {
            paint_ = &Derives::paint_FillEllipse;
        }
        this->invalidate();
        LAMNA_LOG_MESSAGE_DEBUG("on_mouse_release_event() ...out");
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void invalidate() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int border() const {
        return this->border_;
    }
    virtual int borders() const {
        return border()+border();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t fg_color_red() const {
        return fg_color_red_;
    }
    virtual size_t fg_color_green() const {
        return fg_color_green_;
    }
    virtual size_t fg_color_blue() const {
        return fg_color_blue_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    size_t fg_color_red_, fg_color_green_, fg_color_blue_;
    int border_;
    paint_t paint_;
};

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template <class TExtends>

class _EXPORT_CLASS maint: public TExtends {
public:
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint()
    : fg_color_red_(LAMNA_APP_GUI_HELLO_FG_COLOR_RED),
      fg_color_green_(LAMNA_APP_GUI_HELLO_FG_COLOR_GREEN),
      fg_color_blue_(LAMNA_APP_GUI_HELLO_FG_COLOR_BLUE),
      width_(LAMNA_APP_GUI_HELLO_WIDTH),
      height_(LAMNA_APP_GUI_HELLO_HEIGHT),
      border_(LAMNA_APP_GUI_HELLO_BORDER) {
    }
    virtual ~maint() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int width() const {
        return this->width_;
    }
    virtual int height() const {
        return this->height_;
    }
    virtual int border() const {
        return this->border_;
    }
    virtual int borders() const {
        return border()+border();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int fg_color_red() const {
        return this->fg_color_red_;
    }
    virtual int fg_color_green() const {
        return this->fg_color_green_;
    }
    virtual int fg_color_blue() const {
        return this->fg_color_blue_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    int fg_color_red_, fg_color_green_, fg_color_blue_;
    int width_, height_, border_;
};

} // namespace hello
} // namespace gui 
} // namespace app 
} // namespace lamna 

#endif // _LAMNA_APP_GUI_HELLO_MAIN_HPP 
