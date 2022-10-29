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
///   Date: 6/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_PIXEL_HPP
#define _LAMNA_GRAPHIC_SURFACE_PIXEL_HPP

#include "lamna/graphic/image.hpp"

#define LAMNA_GRAPHIC_SURFACE_PIXEL_RGB_AXIS_SIZE 256

namespace lamna {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: pixel_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TInterfaceBase = implement_base,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 TSize VRGBAxisSize = LAMNA_GRAPHIC_SURFACE_PIXEL_RGB_AXIS_SIZE,
 class TImplements = TInterfaceBase>

class _EXPORT_CLASS pixel_interfacet: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TInterfaceBase tInterfaceBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual byte_t rgb_axis_to_byte(tSize x) const {
        byte_t to = ((byte_t)x);
        return to;
    }
    virtual float rgb_axis_to_float(tSize x) const {
        float to = ((float)(x % rgb_axis_size()))/((float)(rgb_axis_size()));
        return to;
    }
    virtual double rgb_axis_to_double(tSize x) const {
        double to = ((double)(x % rgb_axis_size()))/((double)(rgb_axis_size()));
        return to;
    }
    virtual tSize rgb_axis_size() const {
        return VRGBAxisSize;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef pixel_interfacet<> pixel_interface;

///////////////////////////////////////////////////////////////////////
///  Class: pixelt
///////////////////////////////////////////////////////////////////////
template
<class TInterfaceBase = pixel_interface,
 class TBase = base,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 TSize VRGBAxisSize = LAMNA_GRAPHIC_SURFACE_PIXEL_RGB_AXIS_SIZE,
 class TImplements = TInterfaceBase, class TExtends = TBase>

class _EXPORT_CLASS pixelt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TInterfaceBase tInterfaceBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pixelt(tSize r, tSize g, tSize b, tSize a) {
    }
    pixelt(tSize r, tSize g, tSize b) {
    }
    pixelt() {
    }
    virtual ~pixelt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef pixelt<> pixel;

} // namespace surface
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_PIXEL_HPP 
