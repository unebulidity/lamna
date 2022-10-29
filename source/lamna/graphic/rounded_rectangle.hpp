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
///   File: rounded_rectangle.hpp
///
/// Author: $author$
///   Date: 9/8/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_ROUNDED_RECTANGLE_HPP
#define _LAMNA_GRAPHIC_ROUNDED_RECTANGLE_HPP

#include "lamna/graphic/rectangle.hpp"

namespace lamna {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: rounded_rectanglet
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

class _EXPORT_CLASS rounded_rectanglet: public TExtends {
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
    rounded_rectanglet(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~rounded_rectanglet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotRoundedRectangle
    (tPixel &pixel, tInt cx,tInt cy,
     tSize cWidth, tSize cHeight,
     tSize radius, tSize thickness = 1,
     eRectangleCorner corner = e_RECTANGLE_CORNER_ALL,
     eRectangleSide side = e_RECTANGLE_SIDE_ALL) {
        tImageBaseInterface* old = this->m_image.SelectImage(&pixel);

        if ((e_RECTANGLE_CORNER_ALL == corner)
            && (e_RECTANGLE_SIDE_ALL == side)) {
            this->m_image.DrawRoundedRectangle
            (cx,cy, cWidth,cHeight, radius);
        } else {
            this->m_image.DrawRoundedRectangle
            (cx,cy, cWidth,cHeight, radius, thickness, corner, side);
        }
        this->m_image.SelectImage(old);
    }
};
typedef rounded_rectanglet<> rounded_rectangle;

///////////////////////////////////////////////////////////////////////
///  Class: filled_rounded_rectanglet
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

class _EXPORT_CLASS filled_rounded_rectanglet: public TExtends {
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
    filled_rounded_rectanglet(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~filled_rounded_rectanglet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotRoundedRectangle
    (tPixel &pixel, tInt cx,tInt cy,
     tSize cWidth, tSize cHeight,
     tSize radius, tSize thickness = 1,
     eRectangleCorner corner = e_RECTANGLE_CORNER_ALL,
     eRectangleSide side = e_RECTANGLE_SIDE_ALL) {
        tImageBaseInterface* old = this->m_image.SelectImage(&pixel);

        if ((e_RECTANGLE_CORNER_ALL == corner)
            && (e_RECTANGLE_SIDE_ALL == side)) {
            this->m_image.FillRoundedRectangle
            (cx,cy, cWidth,cHeight, radius);
        } else {
            this->m_image.FillRoundedRectangle
            (cx,cy, cWidth,cHeight, radius, thickness, corner, side);
        }
        this->m_image.SelectImage(old);
    }
};
typedef filled_rounded_rectanglet<> filled_rounded_rectangle;

///////////////////////////////////////////////////////////////////////
///  Class: hollowed_rounded_rectanglet
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

class _EXPORT_CLASS hollowed_rounded_rectanglet: public TExtends {
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
    hollowed_rounded_rectanglet(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~hollowed_rounded_rectanglet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotRoundedRectangle
    (tPixel &pixel, tInt cx,tInt cy,
     tSize cWidth, tSize cHeight,
     tSize radius, tSize thickness = 1,
     eRectangleCorner corner = e_RECTANGLE_CORNER_ALL,
     eRectangleSide side = e_RECTANGLE_SIDE_ALL) {
        tImageBaseInterface* old = this->m_image.SelectImage(&pixel);

        if ((e_RECTANGLE_CORNER_ALL == corner)
            && (e_RECTANGLE_SIDE_ALL == side)) {
            this->m_image.HollowRoundedRectangle
            (cx,cy, cWidth,cHeight, radius);
        } else {
            this->m_image.HollowRoundedRectangle
            (cx,cy, cWidth,cHeight, radius, thickness, corner, side);
        }
        this->m_image.SelectImage(old);
    }
};
typedef hollowed_rounded_rectanglet<> hollowed_rounded_rectangle;

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_ROUNDED_RECTANGLE_HPP 
