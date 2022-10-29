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
///   File: context.hpp
///
/// Author: $author$
///   Date: 6/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_CONTEXT_HPP
#define _LAMNA_GRAPHIC_SURFACE_CONTEXT_HPP

#include "lamna/graphic/surface/pixel.hpp"

namespace lamna {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: context_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TPixelInterface = pixel_interface,
 class TInterfaceBase = implement_base,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TInterfaceBase>

class _EXPORT_CLASS context_interfacet: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TPixelInterface tPixelInterface;
    typedef TInterfaceBase tInterfaceBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tPixelInterface& color) {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetForeground
    (tPixelInterface& oldColor, const tPixelInterface& toColor) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError SetForeground(const tPixelInterface& toColor) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual const tPixelInterface* Foreground() const {
        const tPixelInterface* color = 0;
        return color;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetBackground
    (tPixelInterface& oldColor, const tPixelInterface& toColor) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError SetBackground(const tPixelInterface& toColor) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual const tPixelInterface* Background() const {
        const tPixelInterface* color = 0;
        return color;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef context_interfacet<> context_interface;

///////////////////////////////////////////////////////////////////////
///  Class: contextt
///////////////////////////////////////////////////////////////////////
template
<class TPixelInterface = pixel_interface,
 class TInterfaceBase = context_interface,
 class TBase = base,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TInterfaceBase, class TExtends = TBase>

class _EXPORT_CLASS contextt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TPixelInterface tPixelInterface;
    typedef TInterfaceBase tInterfaceBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    contextt() {
    }
    virtual ~contextt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef contextt<> context;

} // namespace surface
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_CONTEXT_HPP 
        

