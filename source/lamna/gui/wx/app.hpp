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
///   File: app.hpp
///
/// Author: $author$
///   Date: 9/24/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WX_APP_HPP
#define _LAMNA_GUI_WX_APP_HPP

#include "lamna/gui/wx/wx.hpp"
#include "wx/app.h"

namespace lamna {
namespace gui {
namespace wx {

typedef implement_base app_implements;
typedef wxApp app_extends;
///////////////////////////////////////////////////////////////////////
///  Class: appt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = app_implements, class TExtends = app_extends>

class _EXPORT_CLASS appt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    appt() {
    }
    virtual ~appt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef appt<> app;

} // namespace wx 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WX_APP_HPP 
