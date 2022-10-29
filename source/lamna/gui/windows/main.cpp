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
///   File: main.cpp
///
/// Author: $author$
///   Date: 6/6/2015
///////////////////////////////////////////////////////////////////////
#include "lamna/gui/windows/main.hpp"
#include "xos/io/main/logger.hpp"
#include "xos/mt/main/mutex.hpp"

namespace lamna {
namespace gui {
namespace windows {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements, class TExtends>
int maint<TImplements, TExtends>::the_WinMain
(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow) {
    int err = 1;
    maint* main = 0;

    if ((main = get_the_main())) {
        xos::mt::main::mutext<maint> mutex(*main);
        xos::io::main::loggert<char, int, 0, maint> logger(*main);

        // initialize logger
        //
        XOS_LOGGER_INIT();

        err = (*main)(hInstance, hPrevInstance, cmdLine, cmdShow);

        // finalize logger
        //
        XOS_LOGGER_FINI();
    }
    return err;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements, class TExtends>
maint<TImplements, TExtends>*& maint<TImplements, TExtends>::get_the_main() {
    static maint<TImplements, TExtends>* the_main = 0;
    return the_main;
}

} // namespace windows 
} // namespace gui 
} // namespace lamna 
