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
///   File: color.hpp
///
/// Author: $author$
///   Date: 6/2/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_QT_COLOR_HPP
#define _LAMNA_GRAPHIC_SURFACE_QT_COLOR_HPP

#include "lamna/graphic/surface/qt/object.hpp"
#include "lamna/graphic/surface/qt/pixel.hpp"
#include "lamna/graphic/surface/color.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: colort
///////////////////////////////////////////////////////////////////////
template
<class TQObject = object,
 class TQImageInterface = image_interface,
 class TQPixelInterface = pixel_interface,
 class TQPixel = pixel,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TColor = surface::colort
 <TQObject, TQImageInterface, TQPixelInterface, TQPixel>,
 class TImplements = TQPixelInterface, class TExtends = TColor>

class _EXPORT_CLASS colort: virtual public TImplements, public TExtends {
public:
    typedef TExtends Extends;

    typedef TQImageInterface tQImageInterface;
    typedef TColor tColor;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    colort
    (tQImageInterface& surfaceQImage,
     tSize r = 0, tSize g = 0, tSize b = 0, tSize width = 1, tSize height = 1)
    : Extends(surfaceQImage, r,g,b, width,height) {
    }
    virtual ~colort() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        context_interface& gc = this->SurfaceQImage().SurfaceQContext();
        const pixel_interface& color = this->Color();
        tSize r = this->Red(), g = this->Green(), b = this->Blue();
        w = w+this->Width()-1; h = h+this->Height()-1;
        gc.FillRectangle(x,y, w,h, color);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator const QColor&() const {
        return this->Color();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef colort<> color;

} // namespace qt 
} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_QT_COLOR_HPP 
