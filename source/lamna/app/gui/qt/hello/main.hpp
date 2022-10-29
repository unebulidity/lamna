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
///   Date: 5/30/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_GUI_QT_HELLO_MAIN_HPP
#define _LAMNA_APP_GUI_QT_HELLO_MAIN_HPP

#include "lamna/app/gui/hello/main.hpp"
#include "lamna/gui/qt/application/window_main.hpp"
#include "lamna/graphic/surface/qt/color.hpp"
#include "lamna/graphic/surface/qt/image.hpp"
#include "lamna/graphic/surface/qt/context.hpp"
#include "lamna/graphic/surface/qt/pixel.hpp"
#include "lamna/graphic/surface/color.hpp"
#include "lamna/graphic/surface/context.hpp"
#include "lamna/graphic/surface/image.hpp"

namespace lamna {
namespace app {
namespace gui {
namespace qt {
namespace hello {

typedef gui::hello::surfacet<QMainWindow> MainWindowExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class MainWindow: public MainWindowExtends {
public:
    typedef MainWindowExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainWindow
    (int fg_color_red, int fg_color_green, int fg_color_blue)
    : Extends(fg_color_red, fg_color_green, fg_color_blue) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    void paintEvent(QPaintEvent* event) {
        QMainWindow* qMainWindow = this;
        int width = qMainWindow->width(), height = qMainWindow->height(), x = 0, y = 0;
        if ((2 <= (x = width/2)) && (2 <= (y = height/2))) {
            graphic::surface::qt::context gc(qMainWindow);
            graphic::surface::qt::image im(gc);
            graphic::surface::qt::color px(im, fg_color_red_, fg_color_green_, fg_color_blue_);
            im.SelectImage(&px);
            paint(im, x,y, x,y);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void mouseReleaseEvent(QMouseEvent *event) {
        lamna::gui::mouse::position p(event->x(), event->y());
        Qt::MouseButton button = Qt::NoButton;
        switch((button = event->button())) {
        case Qt::LeftButton:
            {
            lamna::gui::mouse::button b(lamna::gui::mouse::button_left);
            lamna::gui::mouse::event e(lamna::gui::mouse::event_button_release, b, p);
            this->on_mouse_release_event(e);
            break;
            }
        case Qt::RightButton:
            {
            lamna::gui::mouse::button b(lamna::gui::mouse::button_right);
            lamna::gui::mouse::event e(lamna::gui::mouse::event_button_release, b, p);
            this->on_mouse_release_event(e);
            break;
            }
        case Qt::MiddleButton:
            {
            lamna::gui::mouse::button b(lamna::gui::mouse::button_middle);
            lamna::gui::mouse::event e(lamna::gui::mouse::event_button_release, b, p);
            this->on_mouse_release_event(e);
            break;
            }
        }
        Extends::mouseReleaseEvent(event);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void invalidate() {
        this->update();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef gui::hello::maint
<lamna::gui::qt::application::window_main> main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: public main_extends {
public:
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
    virtual QMainWindow* create_main_window
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        QMainWindow* window = 0;
        if ((window = new MainWindow(fg_color_red_, fg_color_green_, fg_color_blue_))) {
            window->resize(width_, height_);
        }
        return window;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace hello
} // namespace qt 
} // namespace gui 
} // namespace app 
} // namespace lamna 

#endif // _LAMNA_APP_GUI_QT_HELLO_MAIN_HPP 
