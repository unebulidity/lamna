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
///   File: rectangle.hpp
///
/// Author: $author$
///   Date: 9/16/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_RECTANGLE_HPP
#define _LAMNA_GUI_X11_RECTANGLE_HPP

#include "lamna/gui/x11/created.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef implement_base rectangle_implements;
typedef xos::base::wrappedt<XRectangle, int, 0> rectangle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: rectanglet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = rectangle_implements, class TExtends = rectangle_extends>

class _EXPORT_CLASS rectanglet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    rectanglet
    (int x, int y, unsigned int width, unsigned int height) {
        this->wrapped_.x = x;
        this->wrapped_.y = y;
        this->wrapped_.width = width;
        this->wrapped_.height = height;
    }
    rectanglet(const XExposeEvent& event) {
        this->wrapped_.x = event.x;
        this->wrapped_.y = event.y;
        this->wrapped_.width = event.width;
        this->wrapped_.height = event.height;
    }
    rectanglet(const XRectangle& copy) {
        this->wrapped_.x = copy.x;
        this->wrapped_.y = copy.y;
        this->wrapped_.width = copy.width;
        this->wrapped_.height = copy.height;
    }
    rectanglet(const rectanglet& copy) {
        this->wrapped_.x = copy.wrapped_.x;
        this->wrapped_.y = copy.wrapped_.y;
        this->wrapped_.width = copy.wrapped_.width;
        this->wrapped_.height = copy.wrapped_.height;
    }
    rectanglet() {
        this->wrapped_.x = 0;
        this->wrapped_.y = 0;
        this->wrapped_.width = 0;
        this->wrapped_.height = 0;
    }
    virtual ~rectanglet() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual rectanglet& set(const XRectangle& rect) {
        this->wrapped_.x = rect.x;
        this->wrapped_.y = rect.y;
        this->wrapped_.width = rect.width;
        this->wrapped_.height = rect.height;
        return *this;
    }
    virtual rectanglet& include(const XRectangle& rect) {
        int x2 = this->wrapped_.x + this->wrapped_.width,
            y2 = this->wrapped_.y + this->wrapped_.height,
            rx2 = rect.x + rect.width,
            ry2 = rect.y + rect.height;
        if ((x2 < rx2)) x2 = rx2;
        if ((y2 < ry2)) y2 = ry2;
        if ((this->wrapped_.x > rect.x)) this->wrapped_.x = rect.x;
        if ((this->wrapped_.y > rect.y)) this->wrapped_.y = rect.y;
        this->wrapped_.width = x2 - this->wrapped_.x;
        this->wrapped_.height = y2 - this->wrapped_.y;
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef rectanglet<> rectangle;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_RECTANGLE_HPP 
