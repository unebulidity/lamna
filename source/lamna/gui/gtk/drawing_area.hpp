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
///   File: drawing_area.hpp
///
/// Author: $author$
///   Date: 8/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_GTK_DRAWING_AREA_HPP
#define _LAMNA_GUI_GTK_DRAWING_AREA_HPP

#include "lamna/gui/gtk/widget.hpp"

namespace lamna {
namespace gui {
namespace gtk {

typedef widget_implements drawing_area_implements;
typedef widget drawing_area_extends;
///////////////////////////////////////////////////////////////////////
///  Class: drawing_areat
///////////////////////////////////////////////////////////////////////
template
<class TImplements = drawing_area_implements,
 class TExtends = drawing_area_extends>

class _EXPORT_CLASS drawing_areat
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    drawing_areat() {
    }
    virtual ~drawing_areat() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual widget_attached_t create_detached() const {
        widget_attached_t detached = gtk_drawing_area_new();
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef drawing_areat<> drawing_area;

} // namespace gtk 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_GTK_DRAWING_AREA_HPP 
