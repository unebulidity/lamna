///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   Date: 7/25/2019
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_GUI_LAMNA_HELLO_MAIN_HPP
#define _LAMNA_APP_GUI_LAMNA_HELLO_MAIN_HPP

#include "lamna/app/gui/hello/main.hpp"
#include "lamna/gui/main.hpp"

namespace lamna {
namespace gui {
namespace lamna {

typedef base Widget;
typedef Widget MainWindow;
typedef gui::main WindowMain;

} // namespace lamna
} // namespace gui
} // namespace lamna

namespace lamna {
namespace app {
namespace gui {
namespace lamna {
namespace hello {

typedef gui::hello::surfacet< ::lamna::gui::lamna::MainWindow > MainWindowExtends;
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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef gui::hello::maint< ::lamna::gui::lamna::WindowMain > main_extends;
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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace hello
} // namespace lamna
} // namespace gui
} // namespace app
} // namespace lamna


#endif // _LAMNA_APP_GUI_LAMNA_HELLO_MAIN_HPP 

