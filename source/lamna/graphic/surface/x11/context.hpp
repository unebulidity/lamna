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
///   Date: 9/19/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_X11_CONTEXT_HPP
#define _LAMNA_GRAPHIC_SURFACE_X11_CONTEXT_HPP

#include "lamna/graphic/surface/x11/pixel.hpp"
#include "lamna/graphic/surface/context.hpp"
#include "lamna/gui/x11/gc.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace x11 {

///////////////////////////////////////////////////////////////////////
///  Class: context_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = surface::context_interface,
 class TPixelInterface = pixel_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TContextInterface>

class _EXPORT_CLASS context_interfacet: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TPixelInterface tPixelInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tPixelInterface& color) {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef context_interfacet<> context_interface;

///////////////////////////////////////////////////////////////////////
///  Class: contextt
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = context_interface,
 class TContext = surface::context,
 class TPixelInterface = pixel_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TContextInterface, class TExtends = TContext>

class _EXPORT_CLASS contextt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TPixelInterface tPixelInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    contextt(gui::x11::gc& _gc): gc_(_gc) {
    }
    virtual ~contextt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tPixelInterface& color) {
        eError error = e_ERROR_NONE;
        gc_.set_foreground(color);
        gc_.fill_rectangle(x,y, width,height);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    gui::x11::gc& gc_;
};
typedef contextt<> context;

} // namespace x11 
} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_X11_CONTEXT_HPP 
