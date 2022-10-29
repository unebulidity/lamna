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
///   File: pixel.hh
///
/// Author: $author$
///   Date: 10/18/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_COCOA_PIXEL_HH
#define _LAMNA_GRAPHIC_SURFACE_COCOA_PIXEL_HH

#include "lamna/gui/cocoa/iCocoa.hh"
#include "lamna/graphic/surface/pixel.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace cocoa {

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
    virtual operator iColor*() const = 0;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef pixel_interfacet<> pixel_interface;

///////////////////////////////////////////////////////////////////////
///  Class: pixelt
///////////////////////////////////////////////////////////////////////
template
<class TQPixelInterface = pixel_interface,
 class TPixel = surface::pixel,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 TSize VRGBAxisSize = LAMNA_GRAPHIC_SURFACE_PIXEL_RGB_AXIS_SIZE,
 class TImplements = TQPixelInterface, class TExtends = TPixel>

class _EXPORT_CLASS pixelt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pixelt(int r, int g, int b, int a): iColor_(make_color(r,g,b,a)) {
    }
    pixelt(int r, int g, int b): iColor_(make_color(r,g,b)) {
    }
    pixelt(): iColor_(make_color(0,0,0)) {
    }
    virtual ~pixelt() {
        if ((iColor_)) {
            [iColor release];
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual iColor* make_color(int r, int g, int b, int a) const {
        float red = this->rgb_axis_to_float(r),
              green = this->rgb_axis_to_float(g),
              blue = this->rgb_axis_to_float(b),
              alpha = this->rgb_axis_to_float(a);
        return make_color(red, green, blue, alpha);
    }
    virtual iColor* make_color(int r, int g, int b) const {
        float red = this->rgb_axis_to_float(r),
              green = this->rgb_axis_to_float(g),
              blue = this->rgb_axis_to_float(b),
              alpha = 1.0;
        return make_color(red, green, blue, alpha);
    }
    virtual iColor* make_color(float red, float green, float blue, float alpha) const {
        iColor* color = nil;
        color = [[iColor colorWithDeviceRed:red green:green blue:blue alpha:alpha] retain];
        return color;
    }
    virtual operator iColor*() const {
        return iColor_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    iColor* iColor_;
};
typedef pixelt<> pixel;

} // namespace cocoa
} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_COCOA_PIXEL_HH 
        

