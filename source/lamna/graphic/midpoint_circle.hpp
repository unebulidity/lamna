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
///   File: midpoint_circle.hpp
///
/// Author: $author$
///   Date: 5/31/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_MIDPOINT_CIRCLE_HPP
#define _LAMNA_GRAPHIC_MIDPOINT_CIRCLE_HPP

#include "lamna/graphic/image_base.hpp"

namespace lamna {
namespace graphic {

typedef unsigned int eCircleOctant;
enum {
    e_CIRCLE_OCTANT_NONE = 0,

    e_CIRCLE_OCTANT_1 = (1 << 0),
    e_CIRCLE_OCTANT_2 = (1 << 1),
    e_CIRCLE_OCTANT_3 = (1 << 2),
    e_CIRCLE_OCTANT_4 = (1 << 3),
    e_CIRCLE_OCTANT_5 = (1 << 4),
    e_CIRCLE_OCTANT_6 = (1 << 5),
    e_CIRCLE_OCTANT_7 = (1 << 6),
    e_CIRCLE_OCTANT_8 = (1 << 7),

    e_CIRCLE_OCTANT_NEXT = (e_CIRCLE_OCTANT_8 << 1),
    e_CIRCLE_OCTANT_ALL  = (e_CIRCLE_OCTANT_NEXT-1)
};

typedef eCircleOctant eCircleQuadrant;
enum {
    e_CIRCLE_QUADRANT_ALL = e_CIRCLE_OCTANT_ALL,

    e_CIRCLE_QUADRANT_1 = (e_CIRCLE_OCTANT_1|e_CIRCLE_OCTANT_2),
    e_CIRCLE_QUADRANT_2 = (e_CIRCLE_OCTANT_3|e_CIRCLE_OCTANT_4),
    e_CIRCLE_QUADRANT_3 = (e_CIRCLE_OCTANT_5|e_CIRCLE_OCTANT_6),
    e_CIRCLE_QUADRANT_4 = (e_CIRCLE_OCTANT_7|e_CIRCLE_OCTANT_8),
};

///////////////////////////////////////////////////////////////////////
///  Function: MidpointCircleT
///////////////////////////////////////////////////////////////////////
template
<class TImage, class TPixel, class TInt>

void MidpointCircleT
(TImage &image, TPixel &pixel,
 TInt cx, TInt cy, TInt r, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
    TInt x, y, d;
    if (1 == r) {
        image.CirclePlot(pixel, r, cx,cy, o);
    } else if (0 < (y = --r)) {
        d = 1-r;
        for (x = 0; x < y; x++) {
            image.CirclePlot(pixel, r, cx,cy, x,y, o);
            if (d<0) {
                d += 2*x+3;
            } else {
                d += 2*(x-y)+5;
                --y;
            }
        }
        image.CirclePlot(pixel, r, cx,cy, x,y, o);
    }
}

class _EXPORT_CLASS midpoint_circle;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_circlet
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

class _EXPORT_CLASS midpoint_circlet: public TExtends {
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
    midpoint_circlet(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~midpoint_circlet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void CirclePlot
    (TPixel &pixel, tInt r,
     tInt cx,tInt cy, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        this->Plot(pixel, cx, cy);
    }
    virtual void CirclePlot
    (TPixel &pixel, tInt r, tInt cx,tInt cy,
     tInt x,tInt y, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        if (o != e_CIRCLE_OCTANT_ALL) {
            if (o & e_CIRCLE_OCTANT_8) this->Plot(pixel, cx-x, cy-y);
            if (o & e_CIRCLE_OCTANT_1) this->Plot(pixel, cx+x, cy-y);

            if (o & e_CIRCLE_OCTANT_7) this->Plot(pixel, cx-y, cy-x);
            if (o & e_CIRCLE_OCTANT_2) this->Plot(pixel, cx+y, cy-x);

            if (o & e_CIRCLE_OCTANT_6) this->Plot(pixel, cx-y, cy+x);
            if (o & e_CIRCLE_OCTANT_3) this->Plot(pixel, cx+y, cy+x);

            if (o & e_CIRCLE_OCTANT_5) this->Plot(pixel, cx-x, cy+y);
            if (o & e_CIRCLE_OCTANT_4) this->Plot(pixel, cx+x, cy+y);
        } else {
            this->Plot(pixel, cx-x, cy-y);
            this->Plot(pixel, cx+x, cy-y);

            this->Plot(pixel, cx-y, cy-x);
            this->Plot(pixel, cx+y, cy-x);

            this->Plot(pixel, cx-y, cy+x);
            this->Plot(pixel, cx+y, cy+x);

            this->Plot(pixel, cx-x, cy+y);
            this->Plot(pixel, cx+x, cy+y);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

class _EXPORT_CLASS filled_midpoint_circle;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_circlet
///////////////////////////////////////////////////////////////////////
template
<class TMidpointCircle = midpoint_circle,
 class TImageBaseInterface = image_base_interface,
 class TImage = TImageBaseInterface,
 class TPixel = TImageBaseInterface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TMidpointCircle>

class _EXPORT_CLASS filled_midpoint_circlet: public TExtends {
public:
    typedef TExtends Extends;

    typedef TMidpointCircle tMidpointCircle;
    typedef TImageBaseInterface tImageBaseInterface;
    typedef TImage tImage;
    typedef TPixel tPixel;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filled_midpoint_circlet(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~filled_midpoint_circlet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void CirclePlot
    (TPixel &pixel, tInt r,
     tInt cx,tInt cy, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        this->Plot(pixel, cx, cy);
    }
    virtual void CirclePlot
    (TPixel &pixel, tInt r, tInt cx,tInt cy,
     tInt x,tInt y, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        if (o != e_CIRCLE_OCTANT_ALL) {
            if ((o & e_CIRCLE_QUADRANT_4) == e_CIRCLE_QUADRANT_4) {
                this->Fill(pixel, cx-x, cy-y, x+1, 1);
                this->Fill(pixel, cx-y, cy-x, y+1, 1);
            }
            if ((o & e_CIRCLE_QUADRANT_1) == e_CIRCLE_QUADRANT_1) {
                this->Fill(pixel, cx, cy-y, x+1, 1);
                this->Fill(pixel, cx, cy-x, y+1, 1);
            }
            if ((o & e_CIRCLE_QUADRANT_3) == e_CIRCLE_QUADRANT_3) {
                this->Fill(pixel, cx-y, cy+x, y+1, 1);
                this->Fill(pixel, cx-x, cy+y, x+1, 1);
            }
            if ((o & e_CIRCLE_QUADRANT_2) == e_CIRCLE_QUADRANT_2) {
                this->Fill(pixel, cx, cy+x, y+1, 1);
                this->Fill(pixel, cx, cy+y, x+1, 1);
            }
        } else {
            if (1 > x) {
                this->Plot(pixel, cx, cy-y);
            } else {
                this->Fill(pixel, cx-x, cy-y, x+x+1, 1);
            }

            if (1 > y) {
                this->Plot(pixel, cx, cy-x);
            } else {
                this->Fill(pixel, cx-y, cy-x, y+y+1, 1);
            }

            if (1 > y) {
                this->Plot(pixel, cx, cy+x);
            } else {
                this->Fill(pixel, cx-y, cy+x, y+y+1, 1);
            }

            if (1 > x) {
                this->Plot(pixel, cx, cy+y);
            } else {
                this->Fill(pixel, cx-x, cy+y, x+x+1, 1);
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef midpoint_circlet<> midpoint_circle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_circle
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS midpoint_circle: public midpoint_circle_extends {
public:
    typedef midpoint_circle_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    midpoint_circle(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~midpoint_circle() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotCircle
    (tImageBaseInterface &pixel, tInt cx,tInt cy,
     tInt r, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        MidpointCircleT<Extends, tImageBaseInterface, tInt>
        (*this, pixel, cx,cy,r, o);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef filled_midpoint_circlet<> filled_midpoint_circle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_circle
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_midpoint_circle: public filled_midpoint_circle_extends {
public:
    typedef filled_midpoint_circle_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filled_midpoint_circle(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~filled_midpoint_circle() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotCircle
    (tImageBaseInterface &pixel, tInt cx,tInt cy,
     tInt r, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        MidpointCircleT<Extends, tImageBaseInterface, tInt>
        (*this, pixel, cx,cy,r, o);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_MIDPOINT_CIRCLE_HPP 
