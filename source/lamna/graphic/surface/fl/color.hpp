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
///   Date: 10/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_FL_COLOR_HPP
#define _LAMNA_GRAPHIC_SURFACE_FL_COLOR_HPP

#include "lamna/graphic/surface/fl/object.hpp"
#include "lamna/graphic/surface/color.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace fl {

///////////////////////////////////////////////////////////////////////
///  Class: colort
///////////////////////////////////////////////////////////////////////
template
<class TObject = object,
 class TImageInterface = image_interface,
 class TPixelInterface = pixel_interface,
 class TPixel = pixel,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TColor = surface::colort
 <TObject, TImageInterface, TPixelInterface, TPixel>,
 class TImplements = TPixelInterface, class TExtends = TColor>

class _EXPORT_CLASS colort: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef image_base_interface tImageBaseInterface;
    typedef TImageInterface tImageInterface;
    typedef TColor tColor;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    colort
    (tImageInterface& surfaceImage,
     tSize r = 0, tSize g = 0, tSize b = 0, tSize width = 1, tSize height = 1)
    : Extends(surfaceImage, r,g,b, width,height) {
    }
    virtual ~colort() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        context_interface& gc = this->SurfaceImage().SurfaceContext();
        const pixel_interface& color = this->Color();
        tSize r = this->Red(), g = this->Green(), b = this->Blue();
        w = w+this->Width()-1; h = h+this->Height()-1;
        gc.FillRectangle(x,y, w,h, color);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator Fl_Color() const {
        return (this->Color());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef colort<> color;

} // namespace fl 
} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_FL_COLOR_HPP 
