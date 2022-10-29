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
///   File: image_base.hpp
///
/// Author: $author$
///   Date: 5/26/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_BASE_HPP
#define _LAMNA_GRAPHIC_IMAGE_BASE_HPP

#include "lamna/base/base.hpp"

namespace lamna {
namespace graphic {

typedef int eError;
enum {
    e_ERROR_NONE = 0,
    e_ERROR_FAILED,
};

typedef unsigned int eOctant;
enum {
    e_OCTANT_NONE = 0,

    e_OCTANT_1 = (1 << 0),
    e_OCTANT_2 = (1 << 1),

    e_OCTANT_3 = (1 << 2),
    e_OCTANT_4 = (1 << 3),

    e_OCTANT_5 = (1 << 4),
    e_OCTANT_6 = (1 << 5),

    e_OCTANT_7 = (1 << 6),
    e_OCTANT_8 = (1 << 7),

    e_OCTANT_FIRST = (e_OCTANT_1),
    e_OCTANT_LAST = (e_OCTANT_8),
    e_OCTANT_NEXT = (e_OCTANT_LAST << 1),
    e_OCTANT_ALL  = (e_OCTANT_NEXT - 1),
    e_OCTANT_BITS = 1
};

typedef unsigned int eQuadrant;
enum {
    e_QUADRANT_ALL = e_OCTANT_ALL,

    e_QUADRANT_1 = (e_OCTANT_1 | e_OCTANT_2),
    e_QUADRANT_2 = (e_OCTANT_3 | e_OCTANT_4),
    e_QUADRANT_3 = (e_OCTANT_5 | e_OCTANT_6),
    e_QUADRANT_4 = (e_OCTANT_7 | e_OCTANT_8),

    e_QUADRANT_TOP_RIGHT    = (e_QUADRANT_1),
    e_QUADRANT_BOTTOM_RIGHT = (e_QUADRANT_2),
    e_QUADRANT_BOTTOM_LEFT  = (e_QUADRANT_3),
    e_QUADRANT_TOP_LEFT     = (e_QUADRANT_4),

    e_QUADRANT_FIRST = e_QUADRANT_1,
    e_QUADRANT_LAST = e_QUADRANT_4,
    e_QUADRANT_BITS = 2
};

///////////////////////////////////////////////////////////////////////
///  Class: image_base_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TInterfaceBase = implement_base,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TInterfaceBase>

class _EXPORT_CLASS image_base_interfacet: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef image_base_interfacet tImageBaseInterface;
    typedef TInterfaceBase tInterfaceBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Plot
    (tImageBaseInterface& pixel, tOffset x,tOffset y) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError Fill
    (tImageBaseInterface& pixel, tOffset x,tOffset y, tSize w,tSize h) {
        eError error = e_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError FillEllipse
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize w,tSize h, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError FillEllipseRectangle
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize w,tSize h, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError HollowEllipse
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize w,tSize h, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError HollowEllipseRectangle
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize w,tSize h, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError FillCircle
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize r, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError HollowCircle
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize r, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError FillTriangle
    (tImageBaseInterface& pixel,
     tOffset x1, tOffset y1, tOffset x2, tOffset y2, tOffset x3, tOffset y3) {
        eError error = e_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef image_base_interfacet<> image_base_interface;

///////////////////////////////////////////////////////////////////////
///  Class: image_baset
///////////////////////////////////////////////////////////////////////
template
<class TImageBaseInterface = image_base_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TBase = base,
 class TImplements = TImageBaseInterface, class TExtends = TBase>

class _EXPORT_CLASS image_baset: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TImageBaseInterface tImageBaseInterface;
    typedef TBase tBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    image_baset(tImageBaseInterface& image): m_image(image) {
    }
    virtual ~image_baset() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Plot
    (tImageBaseInterface& pixel, tOffset x,tOffset y) {
        eError error = e_ERROR_NONE;
        error = pixel.Plot(m_image, x,y);
        return error;
    }
    virtual eError Fill
    (tImageBaseInterface& pixel, tOffset x,tOffset y, tSize w,tSize h) {
        eError error = e_ERROR_NONE;
        error = pixel.Fill(m_image, x,y, w,h);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageBaseInterface& m_image;
};
typedef image_baset<> image_base;

typedef image_base image_base_position_extends;
///////////////////////////////////////////////////////////////////////
///  Class: image_base_position
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS image_base_position: public image_base_position_extends {
public:
    typedef image_base_position_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    image_base_position
    (tOffset x=0, tOffset y=0, bool isIn = false)
    : Extends(*this), m_x(x), m_y(y), m_isIn(isIn) {
    }
    virtual ~image_base_position() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Plot(tImageBaseInterface& pixel, tOffset x,tOffset y) {
        eError error = e_ERROR_NONE;
        if ((m_x == x) && (m_y == y))
            SetIsIn();
        return error;
    }
    virtual eError Fill
    (tImageBaseInterface& pixel, tOffset x,tOffset y, tSize w,tSize h) {
        eError error = e_ERROR_NONE;
        if ((m_x >= x) && (m_x < (x+(tOffset)(w)))
            && (m_y >= y) && (m_y < (y+(tOffset)(h))))
            SetIsIn();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int SetIsIn(bool isTrue = true) {
        m_isIn = isTrue;
        return m_isIn;
    }
    virtual bool IsIn() const {
        return m_isIn;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tOffset m_x, m_y;
    bool m_isIn;
};

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_BASE_HPP 
