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
///   File: object.hpp
///
/// Author: $author$
///   Date: 10/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_GLIB_OBJECT_HPP
#define _LAMNA_GUI_GLIB_OBJECT_HPP

#include "lamna/gui/glib/glib.hpp"

namespace lamna {
namespace gui {
namespace glib {

///////////////////////////////////////////////////////////////////////
///  Class: object_implementst
///////////////////////////////////////////////////////////////////////
template <class TImplements = implement_base>
class _EXPORT_CLASS object_implementst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef object_implementst<> object_implements;
typedef base object_extends;
///////////////////////////////////////////////////////////////////////
///  Class: objectt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = object_implements, class TExtends = object_extends>

class _EXPORT_CLASS objectt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    objectt() {
    }
    virtual ~objectt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef objectt<> object;

} // namespace glib
} // namespace gui 
} // namespace lamna 


#endif // _LAMNA_GUI_GLIB_OBJECT_HPP 
        

