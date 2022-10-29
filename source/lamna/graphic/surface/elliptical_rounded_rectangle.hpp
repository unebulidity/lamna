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
///   File: elliptical_rounded_rectangle.hpp
///
/// Author: $author$
///   Date: 9/9/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_ELLIPTICAL_ROUNDED_RECTANGLE_HPP
#define _LAMNA_GRAPHIC_SURFACE_ELLIPTICAL_ROUNDED_RECTANGLE_HPP

#include "lamna/graphic/elliptical_rounded_rectangle_image.hpp"
#include "lamna/graphic/elliptical_rounded_rectangle.hpp"
#include "lamna/graphic/surface/object.hpp"

namespace lamna {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: elliptical_rounded_rectanglet
///////////////////////////////////////////////////////////////////////
template
<class TObject = object,
 class TImageInterface = image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TObject>

class _EXPORT_CLASS elliptical_rounded_rectanglet: public TExtends {
public:
    typedef TExtends Extends;

    typedef TObject tObject;
    typedef TImageInterface tImageInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    elliptical_rounded_rectanglet
    (tImageInterface& image, tObject& color,
     tSize w, tSize h, tSize rx, tSize ry, tSize thick = 1,
     eRectangleCorner corner = e_RECTANGLE_CORNER_ALL,
     eRectangleSide side = e_RECTANGLE_SIDE_ALL)
    : Extends(image), rectangle_(image),
      color_(color), w_(w),h_(h), rx_(rx),ry_(ry),
      thick_(thick), corner_(corner), side_(side) {
    }
    virtual ~elliptical_rounded_rectanglet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError Plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        rectangle_.PlotEllipticalRoundedRectangle
        (color_, x,y, w_,h_, rx_,ry_, thick_, corner_, side_);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    elliptical_rounded_rectangle_image rectangle_;
    tObject& color_;
    tSize w_, h_, rx_, ry_, thick_;
    eRectangleCorner corner_;
    eRectangleSide side_;
};
typedef elliptical_rounded_rectanglet<> elliptical_rounded_rectangle;

///////////////////////////////////////////////////////////////////////
///  Class: filled_elliptical_rounded_rectanglet
///////////////////////////////////////////////////////////////////////
template
<class TObject = object,
 class TImageInterface = image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TObject>

class _EXPORT_CLASS filled_elliptical_rounded_rectanglet: public TExtends {
public:
    typedef TExtends Extends;

    typedef TObject tObject;
    typedef TImageInterface tImageInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filled_elliptical_rounded_rectanglet
    (tImageInterface& image, tObject& color,
     tSize w, tSize h, tSize rx, tSize ry, tSize thick = 1,
     eRectangleCorner corner = e_RECTANGLE_CORNER_ALL,
     eRectangleSide side = e_RECTANGLE_SIDE_ALL)
    : Extends(image), rectangle_(image),
      color_(color), w_(w),h_(h), rx_(rx),ry_(ry),
      thick_(thick), corner_(corner), side_(side) {
    }
    virtual ~filled_elliptical_rounded_rectanglet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError Plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        rectangle_.PlotEllipticalRoundedRectangle
        (color_, x,y, w_,h_, rx_,ry_, thick_, corner_, side_);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    filled_elliptical_rounded_rectangle_image rectangle_;
    tObject& color_;
    tSize w_, h_, rx_, ry_, thick_;
    eRectangleCorner corner_;
    eRectangleSide side_;
};
typedef filled_elliptical_rounded_rectanglet<> filled_elliptical_rounded_rectangle;

///////////////////////////////////////////////////////////////////////
///  Class: hollowed_elliptical_rounded_rectanglet
///////////////////////////////////////////////////////////////////////
template
<class TObject = object,
 class TImageInterface = image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TObject>

class _EXPORT_CLASS hollowed_elliptical_rounded_rectanglet: public TExtends {
public:
    typedef TExtends Extends;

    typedef TObject tObject;
    typedef TImageInterface tImageInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    hollowed_elliptical_rounded_rectanglet
    (tImageInterface& image, tObject& color,
     tSize w, tSize h, tSize rx, tSize ry, tSize thick = 1,
     eRectangleCorner corner = e_RECTANGLE_CORNER_ALL,
     eRectangleSide side = e_RECTANGLE_SIDE_ALL)
    : Extends(image), rectangle_(image),
      color_(color), w_(w),h_(h), rx_(rx),ry_(ry),
      thick_(thick), corner_(corner), side_(side) {
    }
    virtual ~hollowed_elliptical_rounded_rectanglet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError Plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        rectangle_.PlotEllipticalRoundedRectangle
        (color_, x,y, w_,h_, rx_,ry_, thick_, corner_, side_);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    hollowed_elliptical_rounded_rectangle_image rectangle_;
    tObject& color_;
    tSize w_, h_, rx_, ry_, thick_;
    eRectangleCorner corner_;
    eRectangleSide side_;
};
typedef hollowed_elliptical_rounded_rectanglet<> hollowed_elliptical_rounded_rectangle;

} // namespace surface
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_ELLIPTICAL_ROUNDED_RECTANGLE_HPP 
