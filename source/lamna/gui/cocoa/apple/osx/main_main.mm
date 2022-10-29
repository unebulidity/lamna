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
///   File: main_main.mm
///
/// Author: $author$
///   Date: 10/15/2015
///////////////////////////////////////////////////////////////////////
#include "lamna/gui/cocoa/apple/osx/main_main.hh"
#include "xos/base/main.cpp"

namespace lamna {
namespace gui {
namespace cocoa {
namespace apple {
namespace osx {

} // namespace osx 
} // namespace apple 
} // namespace cocoa 
} // namespace gui 
} // namespace lamna 

///////////////////////////////////////////////////////////////////////
/// Function: main
///////////////////////////////////////////////////////////////////////
int main(int argc, char** argv, char** env) {
    int command_argc = argc;
    char** command_argv = argv;
    char** command_env = env;

    int err = xos::base::main::the_main
    (command_argc, command_argv, command_env);
    return err;
}
