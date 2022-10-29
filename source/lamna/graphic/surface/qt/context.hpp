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
///   Date: 6/2/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_QT_CONTEXT_HPP
#define _LAMNA_GRAPHIC_SURFACE_QT_CONTEXT_HPP

#include "lamna/graphic/surface/qt/pixel.hpp"
#include "lamna/graphic/surface/context.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: context_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = surface::context_interface,
 class TQPixelInterface = pixel_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TContextInterface>

class _EXPORT_CLASS context_interfacet: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TQPixelInterface tQPixelInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tQPixelInterface& color) {
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
 class TQPixelInterface = pixel_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TContextInterface, class TExtends = TContext>

class _EXPORT_CLASS contextt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TQPixelInterface tQPixelInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    contextt(QPaintDevice* device): qPainter_(device) {
    }
    virtual ~contextt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tQPixelInterface& color) {
        eError error = e_ERROR_NONE;
        const QColor& qColor = color;
        const QRect rect(x,y, width,height);
        qPainter_.fillRect(rect, color);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    QPainter qPainter_;
};
typedef contextt<> context;

} // namespace qt 
} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_QT_CONTEXT_HPP 
