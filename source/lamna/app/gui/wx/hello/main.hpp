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
///   Date: 9/23/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_GUI_WX_HELLO_MAIN_HPP
#define _LAMNA_APP_GUI_WX_HELLO_MAIN_HPP

#include "lamna/app/gui/hello/main.hpp"
#include "lamna/gui/wx/main.hpp"
#include "lamna/graphic/surface/wx/color.hpp"
#include "lamna/graphic/surface/wx/object.hpp"
#include "lamna/graphic/surface/wx/image.hpp"
#include "lamna/graphic/surface/wx/context.hpp"
#include "lamna/graphic/surface/wx/pixel.hpp"

#define LAMNA_APP_GUI_WX_HELLO_NAME "wxlhello"
#define LAMNA_APP_GUI_WX_HELLO_SEPARATOR " -- "

namespace lamna {
namespace app {
namespace gui {
namespace wx {
namespace hello {

typedef lamna::gui::wx::main_implements main_implements;
typedef gui::hello::maint<lamna::gui::wx::main> main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : name_(LAMNA_APP_GUI_WX_HELLO_NAME),
      separator_(LAMNA_APP_GUI_WX_HELLO_SEPARATOR) {
        wxVersionInfo versionInfo = wxGetLibraryVersionInfo();
        wxString version = versionInfo.GetVersionString();

        if ((0 < version.length())) {
            const char* chars = 0;

            if ((chars = version.c_str()) && (chars[0])) {
                name_.append(separator());
                name_.append(chars);
            }
        }
    }
    virtual ~main() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* name() const {
        return name_.chars();
    }
    virtual const char* separator() const {
        return separator_.chars();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static main& the_instance();
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string name_, separator_;
};

typedef implement_base frame_implements;
typedef gui::hello::surfacet<wxFrame> frame_extends;
///////////////////////////////////////////////////////////////////////
///  Class: frame
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS frame
: virtual public frame_implements, public frame_extends {
public:
    typedef frame_implements Implements;
    typedef frame_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    frame
    (const wxString& title,
     const wxPoint& pos, const wxSize& size, const wxColour& fg)
    : Extends(fg.Red(), fg.Green(), fg.Blue()),
      width_(size.GetWidth()), height_(size.GetHeight()) {
        Create((wxWindow*)0, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE, wxFrameNameStr);
    }
    virtual ~frame() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool OnInit() {
        bool success = true;
        return success;
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void invalidate() {
        Refresh();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnPaintEvent(wxPaintEvent& event) {
        int x = (width_ / 2), y = (height_ / 2);
        LAMNA_LOG_MESSAGE_DEBUG("OnPaintEvent()...");
        if ((2 <= (x)) && (2 <= (y))) {
            wxPaintDC dc(this);
            graphic::surface::wx::context gc(dc);
            graphic::surface::wx::image im(gc);
            graphic::surface::wx::color px
            (im, fg_color_red_, fg_color_green_, fg_color_blue_);
            im.SelectImage(&px);
            paint(im, x,y, x,y);
        }
    }
    virtual void OnSizeEvent(wxSizeEvent& event) {
        wxRect rect = GetClientRect();
        LAMNA_LOG_MESSAGE_DEBUG("OnSizeEvent()...");
        width_ = rect.GetRight() - rect.GetLeft();
        height_ = rect.GetBottom() - rect.GetTop();
        Refresh();
    }
    virtual void OnLButtonUpEvent(wxMouseEvent& event) {
        lamna::gui::mouse::position p(event.GetX(), event.GetY());
        lamna::gui::mouse::button b(lamna::gui::mouse::button_left);
        lamna::gui::mouse::event e(lamna::gui::mouse::event_button_release, b, p);
        LAMNA_LOG_MESSAGE_DEBUG("OnLButtonUpEvent()...");
        this->on_mouse_release_event(e);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    int width_, height_;
    DECLARE_EVENT_TABLE()
};

typedef lamna::gui::wx::app_implements app_implements;
typedef lamna::gui::wx::app app_extends;
///////////////////////////////////////////////////////////////////////
///  Class: app
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS app: virtual public app_implements, public app_extends {
public:
    typedef app_implements Implements;
    typedef app_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    app(): main_(main::the_instance()) {
    }
    virtual ~app() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool OnInit() {
        hello::frame* frame = 0;
        if ((frame = new hello::frame
             (main_.name(), wxDefaultPosition,
              wxSize(main_.width(), main_.height()),
              wxColour(main_.fg_color_red(), main_.fg_color_green(), main_.fg_color_blue())))) {
            if ((frame->OnInit())) {
                frame->Show();
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    main& main_;
};

} // namespace hello
} // namespace wx 
} // namespace gui 
} // namespace app 
} // namespace lamna 

#endif // _LAMNA_APP_GUI_WX_HELLO_MAIN_HPP 
