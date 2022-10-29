///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 9/8/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_RECTANGLE_HPP
#define _LAMNA_GRAPHIC_RECTANGLE_HPP

#include "lamna/graphic/image_base.hpp"

namespace lamna {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Enum: eRectangleCorner
///////////////////////////////////////////////////////////////////////
typedef int eRectangleCorner;
enum {
    e_RECTANGLE_CORNER_NONE         = 0,

    e_RECTANGLE_CORNER_TOP_LEFT     = (1 << 0),
    e_RECTANGLE_CORNER_TOP_RIGHT    = (1 << 1),
    e_RECTANGLE_CORNER_BOTTOM_LEFT  = (1 << 2),
    e_RECTANGLE_CORNER_BOTTOM_RIGHT = (1 << 3),

    e_RECTANGLE_CORNER_ALL          = ((1 << 4)-1)
};

///////////////////////////////////////////////////////////////////////
///  Enum: eRectangleSide
///////////////////////////////////////////////////////////////////////
typedef int eRectangleSide;
enum {
    e_RECTANGLE_SIDE_NONE   = 0,

    e_RECTANGLE_SIDE_LEFT   = (1 << 0),
    e_RECTANGLE_SIDE_TOP    = (1 << 1),
    e_RECTANGLE_SIDE_RIGHT  = (1 << 2),
    e_RECTANGLE_SIDE_BOTTOM = (1 << 3),

    e_RECTANGLE_SIDE_ALL    = (1 << 4)-1
};

///////////////////////////////////////////////////////////////////////
///  Class: rectanglet
///////////////////////////////////////////////////////////////////////
template
<class TImageBase = image_base,
 class TImageBaseInterface = image_base_interface,
 class TImage = TImageBaseInterface,
 class TPixel = TImageBaseInterface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TImageBase>

class _EXPORT_CLASS rectanglet: public TExtends {
public:
    typedef TExtends Extends;

    typedef TImageBaseInterface tImageBaseInterface;
    typedef TImageBase tImageBase;
    typedef TImage tImage;
    typedef TPixel tPixel;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    rectanglet(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~rectanglet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotRectangle
    (tPixel &pixel, tInt cx,tInt cy,
     tSize cWidth, tSize cHeight, tSize thickness = 1,
     eRectangleCorner corner = e_RECTANGLE_CORNER_ALL,
     eRectangleSide side = e_RECTANGLE_SIDE_ALL) {
        tImageBaseInterface* old = this->m_image.SelectImage(&pixel);

        if ((e_RECTANGLE_CORNER_ALL == corner)
            && (e_RECTANGLE_SIDE_ALL == side)) {
            this->m_image.DrawRectangle
            (cx,cy, cWidth,cHeight);
        }
        this->m_image.SelectImage(old);
    }
};
typedef rectanglet<> rectangle;

///////////////////////////////////////////////////////////////////////
///  Class: filled_rectanglet
///////////////////////////////////////////////////////////////////////
template
<class TImageBase = image_base,
 class TImageBaseInterface = image_base_interface,
 class TImage = TImageBaseInterface,
 class TPixel = TImageBaseInterface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TImageBase>

class _EXPORT_CLASS filled_rectanglet: public TExtends {
public:
    typedef TExtends Extends;

    typedef TImageBaseInterface tImageBaseInterface;
    typedef TImageBase tImageBase;
    typedef TImage tImage;
    typedef TPixel tPixel;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filled_rectanglet(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~filled_rectanglet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotRectangle
    (tPixel &pixel, tInt cx,tInt cy,
     tSize cWidth, tSize cHeight, tSize thickness = 1,
     eRectangleCorner corner = e_RECTANGLE_CORNER_ALL,
     eRectangleSide side = e_RECTANGLE_SIDE_ALL) {
        tImageBaseInterface* old = this->m_image.SelectImage(&pixel);

        if ((e_RECTANGLE_CORNER_ALL == corner)
            && (e_RECTANGLE_SIDE_ALL == side)) {
            this->m_image.FillRectangle
            (cx,cy, cWidth,cHeight);
        }
        this->m_image.SelectImage(old);
    }
};
typedef filled_rectanglet<> filled_rectangle;

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_RECTANGLE_HPP 
