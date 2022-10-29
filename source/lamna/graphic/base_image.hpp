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
///   File: base_image.hpp
///
/// Author: $author$
///   Date: 9/9/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_BASE_IMAGE_HPP
#define _LAMNA_GRAPHIC_BASE_IMAGE_HPP

#include "lamna/graphic/hollow_midpoint_ellipse.hpp"
#include "lamna/graphic/hollow_midpoint_circle.hpp"
#include "lamna/graphic/midpoint_ellipse.hpp"
#include "lamna/graphic/midpoint_circle.hpp"
#include "lamna/graphic/bresenham_line.hpp"
#include "lamna/graphic/triangle.hpp"
#include "lamna/graphic/rectangle.hpp"
#include "lamna/graphic/image_base.hpp"

namespace lamna {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: image_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TInterfaceBase = image_base_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TInterfaceBase>

class _EXPORT_CLASS image_interfacet: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef image_interfacet tImageInterface;
    typedef TInterfaceBase tInterfaceBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageInterface* CreateColor
    (tSize r, tSize g, tSize b, tSize o = 0, tSize w = 1, tSize h = 1) {
        tImageInterface* image = 0;
        return image;
    }
    virtual eError Destroy(tImageInterface& image) {
        eError error = e_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Plot(tImageInterface& image, tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        tImageInterface* prevImage = SelectImage(&image);
        error = Plot(x,y);
        SelectAsImage(prevImage);
        return error;
    }
    virtual eError Fill
    (tImageInterface& image, tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        tImageInterface* prevImage = SelectImage(&image);
        error = Fill(x,y, w,h);
        SelectAsImage(prevImage);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError Fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError Draw(tOffset x, tOffset y, tOffset x2, tOffset y2) {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual eError DrawCircle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError FillCircle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError HollowCircle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual eError DrawEllipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError FillEllipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError HollowEllipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual eError DrawTriangle
    (tOffset x1, tOffset y1, tOffset x2, tOffset y2, tOffset x3, tOffset y3) {
        eError error = e_ERROR_NONE;
        Draw(x1,y1, x2,y2);
        Draw(x2,y2, x3,y3);
        Draw(x3,y3, x1,y1);
        return error;
    }
    virtual eError FillTriangle
    (tOffset x1, tOffset y1, tOffset x2, tOffset y2, tOffset x3, tOffset y3) {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual eError DrawRectangle
    (tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        Fill(x,y, w-1,1);
        Fill(x+w-1,y, 1,h-1);
        Fill(x+1,y+h-1, w-1,1);
        Fill(x,y+1, 1,h-1);
        return error;
    }
    virtual eError FillRectangle
    (tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        Fill(x,y, w,h);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError DrawRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r) {
        eError error = e_ERROR_NONE;
        DrawCircle(x,y, r, e_CIRCLE_QUADRANT_4);
        DrawCircle(x+w-1,y, r, e_CIRCLE_QUADRANT_1);
        DrawCircle(x+w-1,y+h-1, r, e_CIRCLE_QUADRANT_2);
        DrawCircle(x,y+h-1, r, e_CIRCLE_QUADRANT_3);
        if (2 < w) {
            Fill(x+1,y-r+1, w-2,1);
            Fill(x+1,y+h+r-1, w-2,1);
        }
        if (2 < h) {
            Fill(x-r+1,y, 1,h-2);
            Fill(x+w+r-1,y, 1,h-2);
        }
        return error;
    }
    virtual eError FillRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r) {
        eError error = e_ERROR_NONE;
        FillCircle(x,y, r, e_CIRCLE_QUADRANT_4);
        FillCircle(x+w-1,y, r, e_CIRCLE_QUADRANT_1);
        FillCircle(x+w-1,y+h-1, r, e_CIRCLE_QUADRANT_2);
        FillCircle(x,y+h-1, r, e_CIRCLE_QUADRANT_3);
        if (2 < w) {
            Fill(x+1,y-r+1, w-2,r);
            Fill(x+1,y+h-1, w-2,r);
        }
        if (2 < h) {
            Fill(x-r+1,y, w+r+r-2,h-2);
        }
        return error;
    }
    virtual eError HollowRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r) {
        eError error = e_ERROR_NONE;
        HollowCircle(x,y, r, e_CIRCLE_QUADRANT_4);
        HollowCircle(x+w-1,y, r, e_CIRCLE_QUADRANT_1);
        HollowCircle(x+w-1,y+h-1, r, e_CIRCLE_QUADRANT_2);
        HollowCircle(x,y+h-1, r, e_CIRCLE_QUADRANT_3);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError DrawEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry) {
        eError error = e_ERROR_NONE;
        DrawEllipse(x,y, rx,ry, e_CIRCLE_QUADRANT_4);
        DrawEllipse(x+w-1,y, rx,ry, e_CIRCLE_QUADRANT_1);
        DrawEllipse(x+w-1,y+h-1, rx,ry, e_CIRCLE_QUADRANT_2);
        DrawEllipse(x,y+h-1, rx,ry, e_CIRCLE_QUADRANT_3);
        if (2 < w) {
            Fill(x+1,y-ry+1, w-2,1);
            Fill(x+1,y+h+ry-1, w-2,1);
        }
        if (2 < h) {
            Fill(x-rx+1,y, 1,h-2);
            Fill(x+w+rx-1,y, 1,h-2);
        }
        return error;
    }
    virtual eError FillEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry) {
        eError error = e_ERROR_NONE;
        FillEllipse(x,y, rx,ry, e_CIRCLE_QUADRANT_4);
        FillEllipse(x+w-1,y, rx,ry, e_CIRCLE_QUADRANT_1);
        FillEllipse(x+w-1,y+h-1, rx,ry, e_CIRCLE_QUADRANT_2);
        FillEllipse(x,y+h-1, rx,ry, e_CIRCLE_QUADRANT_3);
        if (2 < w) {
            Fill(x+1,y-ry+1, w-2,ry);
            Fill(x+1,y+h-1, w-2,ry);
        }
        if (2 < h) {
            Fill(x-rx+1,y, w+rx+rx-2,h-2);
        }
        return error;
    }
    virtual eError HollowEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry) {
        eError error = e_ERROR_NONE;
        HollowEllipse(x,y, rx,ry, e_CIRCLE_QUADRANT_4);
        HollowEllipse(x+w-1,y, rx,ry, e_CIRCLE_QUADRANT_1);
        HollowEllipse(x+w-1,y+h-1, rx,ry, e_CIRCLE_QUADRANT_2);
        HollowEllipse(x,y+h-1, rx,ry, e_CIRCLE_QUADRANT_3);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError DrawRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r,
     tSize thickness, eRectangleCorner corner, eRectangleSide side) {
        eError error = e_ERROR_NONE;
        if ((e_RECTANGLE_CORNER_TOP_LEFT & corner))     DrawCircle(x,y, r, e_CIRCLE_QUADRANT_4);
        if ((e_RECTANGLE_CORNER_TOP_RIGHT & corner))    DrawCircle(x+w-1,y, r, e_CIRCLE_QUADRANT_1);
        if ((e_RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) DrawCircle(x+w-1,y+h-1, r, e_CIRCLE_QUADRANT_2);
        if ((e_RECTANGLE_CORNER_BOTTOM_LEFT & corner))  DrawCircle(x,y+h-1, r, e_CIRCLE_QUADRANT_3);
        if ((e_RECTANGLE_SIDE_LEFT & side)) Fill(x-r+1,y, 1,h);
        if ((e_RECTANGLE_SIDE_TOP & side)) Fill(x,y-r+1, w,1);
        if ((e_RECTANGLE_SIDE_RIGHT & side)) Fill(x+w-1,y, 1,h);
        if ((e_RECTANGLE_SIDE_BOTTOM & side)) Fill(x,y+h-1, w,1);
        return error;
    }
    virtual eError FillRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r,
     tSize thickness, eRectangleCorner corner, eRectangleSide side) {
        eError error = e_ERROR_NONE;
        if ((e_RECTANGLE_CORNER_TOP_LEFT & corner))     FillCircle(x,y, r, e_CIRCLE_QUADRANT_4);
        if ((e_RECTANGLE_CORNER_TOP_RIGHT & corner))    FillCircle(x+w-1,y, r, e_CIRCLE_QUADRANT_1);
        if ((e_RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) FillCircle(x+w-1,y+h-1, r, e_CIRCLE_QUADRANT_2);
        if ((e_RECTANGLE_CORNER_BOTTOM_LEFT & corner))  FillCircle(x,y+h-1, r, e_CIRCLE_QUADRANT_3);
        if ((e_RECTANGLE_SIDE_LEFT & side)) Fill(x-r+1,y, r,h);
        if ((e_RECTANGLE_SIDE_TOP & side)) Fill(x,y-r+1, w,r);
        if ((e_RECTANGLE_SIDE_RIGHT & side)) Fill(x+w-1,y, r,h);
        if ((e_RECTANGLE_SIDE_BOTTOM & side)) Fill(x,y+r+h-1, w,r);
        return error;
    }
    virtual eError HollowRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r,
     tSize thickness, eRectangleCorner corner, eRectangleSide side) {
        eError error = e_ERROR_NONE;
        if ((e_RECTANGLE_CORNER_TOP_LEFT & corner))     HollowCircle(x,y, r, e_CIRCLE_QUADRANT_4);
        if ((e_RECTANGLE_CORNER_TOP_RIGHT & corner))    HollowCircle(x+w-1,y, r, e_CIRCLE_QUADRANT_1);
        if ((e_RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) HollowCircle(x+w-1,y+h-1, r, e_CIRCLE_QUADRANT_2);
        if ((e_RECTANGLE_CORNER_BOTTOM_LEFT & corner))  HollowCircle(x,y+h-1, r, e_CIRCLE_QUADRANT_3);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError DrawEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry,
     tSize thickness, eRectangleCorner corner, eRectangleSide side) {
        eError error = e_ERROR_NONE;
        if ((e_RECTANGLE_CORNER_TOP_LEFT & corner))     DrawEllipse(x,y, rx,ry, e_CIRCLE_QUADRANT_4);
        if ((e_RECTANGLE_CORNER_TOP_RIGHT & corner))    DrawEllipse(x+w-1,y, rx,ry, e_CIRCLE_QUADRANT_1);
        if ((e_RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) DrawEllipse(x+w-1,y+h-1, rx,ry, e_CIRCLE_QUADRANT_2);
        if ((e_RECTANGLE_CORNER_BOTTOM_LEFT & corner))  DrawEllipse(x,y+h-1, rx,ry, e_CIRCLE_QUADRANT_3);
        if ((e_RECTANGLE_SIDE_LEFT & side)) Fill(x-rx+1,y, 1,h);
        if ((e_RECTANGLE_SIDE_TOP & side)) Fill(x,y-ry+1, w,1);
        if ((e_RECTANGLE_SIDE_RIGHT & side)) Fill(x+w-1,y, 1,h);
        if ((e_RECTANGLE_SIDE_BOTTOM & side)) Fill(x,y+ry+h-1, w,1);
        return error;
    }
    virtual eError FillEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry,
     tSize thickness, eRectangleCorner corner, eRectangleSide side) {
        eError error = e_ERROR_NONE;
        if ((e_RECTANGLE_CORNER_TOP_LEFT & corner))     FillEllipse(x,y, rx,ry, e_CIRCLE_QUADRANT_4);
        if ((e_RECTANGLE_CORNER_TOP_RIGHT & corner))    FillEllipse(x+w-1,y, rx,ry, e_CIRCLE_QUADRANT_1);
        if ((e_RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) FillEllipse(x+w-1,y+h-1, rx,ry, e_CIRCLE_QUADRANT_2);
        if ((e_RECTANGLE_CORNER_BOTTOM_LEFT & corner))  FillEllipse(x,y+h-1, rx,ry, e_CIRCLE_QUADRANT_3);
        if ((e_RECTANGLE_SIDE_LEFT & side)) Fill(x-rx+1,y, rx,h);
        if ((e_RECTANGLE_SIDE_TOP & side)) Fill(x,y-ry+1, w,ry);
        if ((e_RECTANGLE_SIDE_RIGHT & side)) Fill(x+w-1,y, rx,h);
        if ((e_RECTANGLE_SIDE_BOTTOM & side)) Fill(x,y+h-1, w,ry);
        return error;
    }
    virtual eError HollowEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry,
     tSize thickness, eRectangleCorner corner, eRectangleSide side) {
        eError error = e_ERROR_NONE;
        if ((e_RECTANGLE_CORNER_TOP_LEFT & corner))     HollowEllipse(x,y, rx,ry, e_CIRCLE_QUADRANT_4);
        if ((e_RECTANGLE_CORNER_TOP_RIGHT & corner))    HollowEllipse(x+w-1,y, rx,ry, e_CIRCLE_QUADRANT_1);
        if ((e_RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) HollowEllipse(x+w-1,y+h-1, rx,ry, e_CIRCLE_QUADRANT_2);
        if ((e_RECTANGLE_CORNER_BOTTOM_LEFT & corner))  HollowEllipse(x,y+h-1, rx,ry, e_CIRCLE_QUADRANT_3);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageInterface* SelectAsImage(tImageInterface* image) {
        tImageInterface* prevImage = 0;
        if (image)
            prevImage = image->SelectAsImage();
        else
        prevImage = SetImage(image);
        return prevImage;
    }
    virtual tImageInterface* SelectAsImage() {
        tImageInterface* prevImage = Image();
        return prevImage;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageInterface* SetAsImage(tImageInterface* image) {
        tImageInterface* prevImage = 0;
        if (image)
            prevImage = image->SetAsImage();
        else
        prevImage = Image();
        return prevImage;
    }
    virtual tImageInterface* SetAsImage() {
        tImageInterface* prevImage = Image();
        return prevImage;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageInterface* SelectImage(tImageInterface* image) {
        tImageInterface* prevImage = Image();
        SetImage(image);
        return prevImage;
    }
    virtual tImageInterface* SetImage(tImageInterface* image) {
        tImageInterface* prevImage = 0;
        return prevImage;
    }
    virtual tImageInterface* Image() const {
        tImageInterface* image = 0;
        return image;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef image_interfacet<> image_interface;

///////////////////////////////////////////////////////////////////////
///  Class: base_imaget
///////////////////////////////////////////////////////////////////////
template
<class TImageInterface = image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TBase = base,
 class TExtends = TBase>

class _EXPORT_CLASS base_imaget: public TExtends {
public:
    typedef TExtends Extends;

    typedef TImageInterface tImageInterface;
    typedef TBase tBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    base_imaget(tImageInterface& image): m_image(image) {
    }
    virtual ~base_imaget() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Plot(tImageInterface& image, tOffset x, tOffset y) {
        eError error = image.Plot(x,y);
        return error;
    }
    virtual eError Fill
    (tImageInterface& image, tOffset x, tOffset y, tSize w, tSize h) {
        eError error = image.Fill(x,y, w,h);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Plot(tOffset x, tOffset y) {
        eError error = m_image.Plot(x,y);
        return error;
    }
    virtual eError Fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = m_image.Fill(x,y, w,h);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageInterface& m_image;
};
typedef base_imaget<> base_image;

typedef image_interface selected_image;

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_BASE_IMAGE_HPP 
