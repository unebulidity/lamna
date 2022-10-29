///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 6/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WINDOWS_GETOPT_MAIN_HPP
#define _LAMNA_GUI_WINDOWS_GETOPT_MAIN_HPP

#include "lamna/gui/windows/main.hpp"
#include "lamna/gui/windows/cmdline_to_getopt_argv_parser.hpp"
#include "xos/base/getopt/main_extend.hpp"
#include "xos/base/getopt/main_implement.hpp"

namespace lamna {
namespace gui {
namespace windows {
namespace getopt {

typedef xos::base::getopt::main_implementt
<char, int, 0, windows::main_implements> main_implements;
typedef xos::base::getopt::main_extendt
<main_implements, windows::main> main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>
class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool before_create_main_window
    (lamna::gui::windows::window_class& main_window_class, 
     HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
        bool success = true;

        if ((cmdLine) && (cmdLine[0])) {
            string cmd(cmdLine);
            const char* chars = 0;
            size_t length = 0;

            if ((chars = cmd.has_chars(length))) {
                lamna::gui::windows::cmdline_to_getopt_argv_parser::argv_t a;
                lamna::gui::windows::cmdline_to_getopt_argv_parser p(a);

                if ((p.parse("hello", chars, length))) {
                    int argc = a.length();
                    char **argv = a.elements();
                    char **env = 0;

                    if ((this->before_main(argc, argv, env))) {
                    } else {
                    }
                }
            }
        }
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef maint<> main;

} // namespace getopt 
} // namespace windows 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WINDOWS_GETOPT_MAIN_HPP 
