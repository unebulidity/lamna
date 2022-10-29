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
///   Date: 7/18/2019
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_CONSOLE_LAMNA_MAIN_HPP
#define _LAMNA_APP_CONSOLE_LAMNA_MAIN_HPP

#include "xos/console/lib/version/main.hpp"
#include "lamna/console/main.hpp"
#include "lamna/lib/lamna/version.hpp"

namespace lamna {
namespace app {
namespace console {
namespace lamna {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = ::xos::console::lib::version::maint
 < ::lamna::lib::lamna::version, 
   ::lamna::console::main::Implements, ::lamna::console::main >, 
   class TImplements = typename TExtends::Implements>

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
private:
    maint(const maint& copy) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS maint
typedef maint<> main;

} // namespace lamna
} // namespace console
} // namespace app
} // namespace lamna

#endif // _LAMNA_APP_CONSOLE_LAMNA_MAIN_HPP 
