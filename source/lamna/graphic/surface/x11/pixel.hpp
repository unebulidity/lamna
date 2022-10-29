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
///   File: pixel.hpp
///
/// Author: $author$
///   Date: 9/19/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_X11_PIXEL_HPP
#define _LAMNA_GRAPHIC_SURFACE_X11_PIXEL_HPP

#include "lamna/graphic/surface/pixel.hpp"
#include "lamna/gui/x11/color.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace x11 {

///////////////////////////////////////////////////////////////////////
///  Class: pixel_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TPixelInterface = surface::pixel_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 TSize VRGBAxisSize = LAMNA_GRAPHIC_SURFACE_PIXEL_RGB_AXIS_SIZE,
 class TImplements = TPixelInterface>

class _EXPORT_CLASS pixel_interfacet: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual gui::x11::XPixel operator = (gui::x11::XPixel to) = 0;
    virtual operator gui::x11::XPixel() const = 0;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef pixel_interfacet<> pixel_interface;

///////////////////////////////////////////////////////////////////////
///  Class: pixelt
///////////////////////////////////////////////////////////////////////
template
<class TPixelInterface = pixel_interface,
 class TPixel = surface::pixel,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 TSize VRGBAxisSize = LAMNA_GRAPHIC_SURFACE_PIXEL_RGB_AXIS_SIZE,
 class TImplements = TPixelInterface, class TExtends = TPixel>

class _EXPORT_CLASS pixelt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pixelt(tSize r, tSize g, tSize b): pixel_(0) {
    }
    virtual ~pixelt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual gui::x11::XPixel operator = (gui::x11::XPixel to) {
        pixel_ = to;
        return pixel_;
    }
    virtual operator gui::x11::XPixel() const {
        return pixel_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    gui::x11::XPixel pixel_;
};
typedef pixelt<> pixel;

} // namespace x11 
} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_X11_PIXEL_HPP 
