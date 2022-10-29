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
///   File: triangle.hpp
///
/// Author: $author$
///   Date: 9/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_TRIANGLE_HPP
#define _LAMNA_GRAPHIC_SURFACE_TRIANGLE_HPP

#include "lamna/graphic/triangle_image.hpp"
#include "lamna/graphic/triangle.hpp"
#include "lamna/graphic/surface/object.hpp"

namespace lamna {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: trianglet
///////////////////////////////////////////////////////////////////////
template
<class TObject = object,
 class TImageInterface = image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TObject>

class _EXPORT_CLASS trianglet: public TExtends {
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
    trianglet
    (tImageInterface& image, tObject& color,
     tOffset x1, tOffset y1, tOffset x2, tOffset y2,
     tOffset x3, tOffset y3, tSize thick = 1)
    : Extends(image), triangle_(image),
      color_(color),
      x1_(x1),y1_(y1), x2_(x2),y2_(y2), x3_(x3),y3_(y3),
      thick_(thick) {
    }
    virtual ~trianglet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError Plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        triangle_.PlotTriangle
        (color_, x+x1_,y+y1_, x+x2_,y+y2_, x+x3_,y+y3_, thick_);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    triangle_image triangle_;
    tObject& color_;
    tOffset x1_,y1_, x2_,y2_, x3_,y3_;
    tSize thick_;
};
typedef trianglet<> triangle;

///////////////////////////////////////////////////////////////////////
///  Class: filled_trianglet
///////////////////////////////////////////////////////////////////////
template
<class TObject = object,
 class TImageInterface = image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TObject>

class _EXPORT_CLASS filled_trianglet: public TExtends {
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
    filled_trianglet
    (tImageInterface& image, tObject& color,
     tOffset x1, tOffset y1, tOffset x2, tOffset y2,
     tOffset x3, tOffset y3, tSize thick = 1)
    : Extends(image), triangle_(image),
      color_(color),
      x1_(x1),y1_(y1), x2_(x2),y2_(y2), x3_(x3),y3_(y3),
      thick_(thick) {
    }
    virtual ~filled_trianglet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError Plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        triangle_.PlotTriangle
        (color_, x+x1_,y+y1_, x+x2_,y+y2_, x+x3_,y+y3_, thick_);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    filled_triangle_image triangle_;
    tObject& color_;
    tOffset x1_,y1_, x2_,y2_, x3_,y3_;
    tSize thick_;
};
typedef filled_trianglet<> filled_triangle;

} // namespace surface
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_TRIANGLE_HPP 
