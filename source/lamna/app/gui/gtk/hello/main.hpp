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
///   Date: 6/21/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_GUI_GTK_HELLO_MAIN_HPP
#define _LAMNA_APP_GUI_GTK_HELLO_MAIN_HPP

#include "lamna/app/gui/hello/main.hpp"
#include "lamna/gui/gtk/application/window_main.hpp"
#include "lamna/gui/gtk/cairo/context.hpp"
#include "lamna/gui/gtk/drawing_area.hpp"
#include "lamna/graphic/surface/cairo/color.hpp"
#include "lamna/graphic/surface/cairo/image.hpp"
#include "lamna/graphic/surface/cairo/context.hpp"
#include "lamna/graphic/surface/cairo/pixel.hpp"
#include "lamna/graphic/surface/color.hpp"
#include "lamna/graphic/surface/context.hpp"
#include "lamna/graphic/surface/image.hpp"

namespace lamna {
namespace app {
namespace gui {
namespace gtk {
namespace hello {

typedef lamna::gui::gtk::widget_signals widget_signals;

typedef gui::hello::surfacet
<lamna::gui::gtk::drawing_area> drawing_area_extends;
///////////////////////////////////////////////////////////////////////
///  Class: drawing_area
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS drawing_area: public drawing_area_extends {
public:
    typedef drawing_area_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    drawing_area() {
    }
    virtual ~drawing_area() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_draw(GtkWidget* widget, cairo_t* cr) {
        gint width = 0, height = 0, x = 0, y = 0;
        if ((get_size(width, height))) {
            if ((2 <= (x = width/2)) && (2 <= (y = height/2))) {
                lamna::graphic::surface::cairo::context gc(cr);
                graphic::surface::cairo::image im(gc);
                graphic::surface::cairo::color px
                (im, fg_color_red_, fg_color_green_, fg_color_blue_);
                im.SelectImage(&px);
                paint(im, x,y, x,y);
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_left_1button_release_event(GtkWidget* widget, GdkEvent* event) {
        LAMNA_LOG_MESSAGE_DEBUG("on_signal_left_1button_release_event()...");
        if ((event)) {
            GdkEventButton& eb = *((GdkEventButton*)(event));
            lamna::gui::mouse::position p(eb.x, eb.y);
            lamna::gui::mouse::button b(lamna::gui::mouse::button_left);
            lamna::gui::mouse::event e(lamna::gui::mouse::event_button_release, b, p);
            this->on_mouse_release_event(e);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_signal_left_1button_release_event()");
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void invalidate() {
        this->queue_draw();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef lamna::gui::gtk::application::window window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: window
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS window: public window_extends {
public:
    typedef window_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    window() {
    }
    virtual ~window() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() {
        GtkWidget* parent = this->attached_to();
        if ((parent)) {
            GtkWidget* child = 0;
            if ((child = d_.create_attached())) {
                d_.connect_signal_draw();
                d_.connect_signal_button_events();
                gtk_container_add(GTK_CONTAINER(parent), child);
            }
        }
        return true;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_configure
    (GtkWidget* widget, GdkWindow *window, gint x,gint y,
     gint width,gint height, gboolean sent_explicitly) {
        LAMNA_LOG_MESSAGE_DEBUG("on_signal_configure(..., x=" << x << ",y=" << y << ", width=" << width << ",height=" << height << ")...");
        LAMNA_LOG_MESSAGE_DEBUG("...on_signal_configure(..., x=" << x << ",y=" << y << ", width=" << width << ",height=" << height << ")");
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    drawing_area d_;
};

typedef lamna::gui::gtk::application::window_main_implements main_implements;
typedef gui::hello::maint
<lamna::gui::gtk::application::window_main> main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public widget_signals,
  virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual GtkWidget* create_main_window(GtkApplication *application) {
        GtkWidget* detached = window_.create_attached(application);
        if ((detached)) {
            window_.set_size_request(width_, height_);
            window_.init();
            window_.connect_signal_configure_event();
        }
        return detached;
    }
    virtual bool destroy_main_window
    (GtkWidget* main_window, GtkApplication *application) {
        if ((main_window) && (application)
            && (application == (this->application_))) {
            window_.detach();
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    window window_;
};

} // namespace hello 
} // namespace gtk 
} // namespace gui 
} // namespace app 
} // namespace lamna 

#endif // _LAMNA_APP_GUI_GTK_HELLO_MAIN_HPP 
