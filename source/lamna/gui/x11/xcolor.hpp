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
///   File: xcolor.hpp
///
/// Author: $author$
///   Date: 9/14/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_XCOLOR_HPP
#define _LAMNA_GUI_X11_XCOLOR_HPP

#include "lamna/gui/x11/created.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef xos::base::wrapped_implements xcolor_implements;
typedef xos::base::wrappedt<XColor, int, 0> xcolor_extends;
///////////////////////////////////////////////////////////////////////
///  Class: xcolort
///////////////////////////////////////////////////////////////////////
template
<class TImplements = xcolor_implements, class TExtends = xcolor_extends>

class _EXPORT_CLASS xcolort: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    xcolort(uint8_t r, uint8_t g, uint8_t b) {
        this->copy_rgb(r, g, b);
    }
    xcolort(const xcolort& copy): Extends(copy) {
    }
    xcolort() {
    }
    virtual ~xcolort() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual xcolort& copy_rgb(uint8_t r, uint8_t g, uint8_t b) {
        XColor& color = this->wrapped();
        unsigned long iL = (1 << (16))-1;
        unsigned short iS = (1 << (8))-1;
        unsigned short rS = (unsigned short)((iL*r)/iS);
        unsigned short gS = (unsigned short)((iL*g)/iS);
        unsigned short bS = (unsigned short)((iL*b)/iS);
        this->clear();
        color.red = rS;
        color.green = gS;
        color.blue = bS;
        return *this;
    }
    virtual xcolort& clear() {
        this->set(0);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef xcolort<> xcolor;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_XCOLOR_HPP 
