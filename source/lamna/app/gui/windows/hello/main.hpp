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
///   Date: 6/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_GUI_WINDOWS_HELLO_MAIN_HPP
#define _LAMNA_APP_GUI_WINDOWS_HELLO_MAIN_HPP

#include "lamna/app/gui/windows/hello/main_window.hpp"
#include "lamna/gui/windows/window_main.hpp"
#include "lamna/gui/windows/main.hpp"

namespace lamna {
namespace app {
namespace gui {
namespace windows {
namespace hello {

typedef lamna::gui::windows::window_main_implements main_implements;
typedef gui::hello::maint<lamna::gui::windows::window_main> main_extends;
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
    main() {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual lamna::gui::windows::window* create_main_window
    (lamna::gui::windows::window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         LPCSTR windowClassName = 0;
         if ((windowClassName = main_window_class.GetWindowClassName())) {
             if ((window_.create(hInstance, windowClassName))) {
                 window_.set_size(width_, height_);
                 return &window_;
             }
         }
         return 0;
    }
    virtual bool destroy_main_window
    (lamna::gui::windows::window& main_window, 
     lamna::gui::windows::window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
         if (&main_window == (&window_)) {
             if ((window_.destroy())) {
                 return true;
             }
         }
         return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    main_window window_;
};

} // namespace hello 
} // namespace windows 
} // namespace gui 
} // namespace app 
} // namespace lamna 

#endif // _LAMNA_APP_GUI_WINDOWS_HELLO_MAIN_HPP 
