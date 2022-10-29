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
///   File: hollow_midpoint_circle.hpp
///
/// Author: $author$
///   Date: 6/3/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_HOLLOW_MIDPOINT_CIRCLE_HPP
#define _LAMNA_GRAPHIC_HOLLOW_MIDPOINT_CIRCLE_HPP

#include "lamna/graphic/midpoint_circle.hpp"

namespace lamna {
namespace graphic {

class _EXPORT_CLASS hollow_midpoint_circle;

///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_circlet
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

class _EXPORT_CLASS hollow_midpoint_circlet: public TExtends {
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
    hollow_midpoint_circlet(tImage& image)
    : Extends(image),
      m_x1(0),m_y1(0),m_w1(0),
      m_x2(0),m_y2(0),m_w2(0),
      m_x3(0),m_y3(0),m_w3(0),
      m_x4(0),m_y4(0),m_w4(0),
      m_x11(0),m_y11(0),m_w11(0),
      m_x12(0),m_y12(0),m_w12(0),
      m_x13(0),m_y13(0),m_w13(0),
      m_x14(0),m_y14(0),m_w14(0) {
    }
    virtual ~hollow_midpoint_circlet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void CirclePlot
    (TPixel &pixel, tInt r,
     tInt cx,tInt cy, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
    }
    virtual void CirclePlot
    (TPixel &pixel, tInt r, tInt cx,tInt cy,
     tInt x,tInt y, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        if (o != e_CIRCLE_OCTANT_ALL) {
            if ((o & e_CIRCLE_OCTANT_1) == e_CIRCLE_OCTANT_1) {
                CircleHollow(pixel, m_x1,m_y1,m_w1, cx+x+1, cy - y, r-x);
            }
            if ((o & e_CIRCLE_OCTANT_2) == e_CIRCLE_OCTANT_2) {
                CircleHollow(pixel, m_x11,m_y11,m_w11, cx+y+1, cy - x, r-y);
            }
            if ((o & e_CIRCLE_OCTANT_3) == e_CIRCLE_OCTANT_3) {
                CircleHollow(pixel, m_x12,m_y12,m_w12, cx+y+1, cy + x, r-y);
            }
            if ((o & e_CIRCLE_OCTANT_4) == e_CIRCLE_OCTANT_4) {
                CircleHollow(pixel, m_x2,m_y2,m_w2, cx+x+1, cy + y, r-x);
            }
            if ((o & e_CIRCLE_OCTANT_5) == e_CIRCLE_OCTANT_5) {
                CircleHollow(pixel, m_x3,m_y3,m_w3, cx-r, cy + y, r-x);
            }
            if ((o & e_CIRCLE_OCTANT_6) == e_CIRCLE_OCTANT_6) {
                CircleHollow(pixel, m_x13,m_y13,m_w13, cx-r, cy + x, r-y);
            }
            if ((o & e_CIRCLE_OCTANT_7) == e_CIRCLE_OCTANT_7) {
                CircleHollow(pixel, m_x14,m_y14,m_w14, cx-r, cy - x, r-y);
            }
            if ((o & e_CIRCLE_OCTANT_8) == e_CIRCLE_OCTANT_8) {
                CircleHollow(pixel, m_x4,m_y4,m_w4, cx-r, cy - y, r-x);
            }
        } else {
            CircleHollow(pixel, m_x1,m_y1,m_w1, cx+x+1, cy - y, r-x);
            CircleHollow(pixel, m_x11,m_y11,m_w11, cx+y+1, cy - x, r-y);

            CircleHollow(pixel, m_x12,m_y12,m_w12, cx+y+1, cy + x, r-y);
            CircleHollow(pixel, m_x2,m_y2,m_w2, cx+x+1, cy + y, r-x);

            CircleHollow(pixel, m_x3,m_y3,m_w3, cx-r, cy + y, r-x);
            CircleHollow(pixel, m_x13,m_y13,m_w13, cx-r, cy + x, r-y);

            CircleHollow(pixel, m_x14,m_y14,m_w14, cx-r, cy - x, r-y);
            CircleHollow(pixel, m_x4,m_y4,m_w4, cx-r, cy - y, r-x);
        }
    }
    virtual void CircleHollow
    (tPixel &pixel, tInt& xQ,tInt& yQ, tInt& wQ, tInt x,tInt y, tInt w) {
        if ((0 < wQ) && (yQ != y)) {
            this->Fill(pixel, xQ,yQ, wQ,1);
        }
        xQ = x;
        yQ = y;
        wQ = w;
    }
    virtual void CircleStart() {
        m_x1 = (m_y1 = (m_w1 = 0));
        m_x2 = (m_y2 = (m_w2 = 0));
        m_x3 = (m_y3 = (m_w3 = 0));
        m_x4 = (m_y4 = (m_w4 = 0));
        m_x11 = (m_y11 = (m_w11 = 0));
        m_x12 = (m_y12 = (m_w12 = 0));
        m_x13 = (m_y13 = (m_w13 = 0));
        m_x14 = (m_y14 = (m_w14 = 0));
    }
    virtual void CircleFinish(tPixel &pixel) {
        if ((0 < m_w1)) {
            this->Fill(pixel, m_x1,m_y1, m_w1,1);
        }
        if ((0 < m_w11)) {
            this->Fill(pixel, m_x11,m_y11, m_w11,1);
        }
        if ((0 < m_w2)) {
            this->Fill(pixel, m_x2,m_y2, m_w2,1);
        }
        if ((0 < m_w12)) {
            this->Fill(pixel, m_x12,m_y12, m_w12,1);
        }
        if ((0 < m_w3)) {
            this->Fill(pixel, m_x3,m_y3, m_w3,1);
        }
        if ((0 < m_w13)) {
            this->Fill(pixel, m_x13,m_y13, m_w13,1);
        }
        if ((0 < m_w4)) {
            this->Fill(pixel, m_x4,m_y4, m_w4,1);
        }
        if ((0 < m_w14)) {
            this->Fill(pixel, m_x14,m_y14, m_w14,1);
        }
        m_x1 = (m_y1 = (m_w1 = 0));
        m_x2 = (m_y2 = (m_w2 = 0));
        m_x3 = (m_y3 = (m_w3 = 0));
        m_x4 = (m_y4 = (m_w4 = 0));
        m_x11 = (m_y11 = (m_w11 = 0));
        m_x12 = (m_y12 = (m_w12 = 0));
        m_x13 = (m_y13 = (m_w13 = 0));
        m_x14 = (m_y14 = (m_w14 = 0));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tInt m_x1,m_y1,m_w1;
    tInt m_x2,m_y2,m_w2;
    tInt m_x3,m_y3,m_w3;
    tInt m_x4,m_y4,m_w4;
    tInt m_x11,m_y11,m_w11;
    tInt m_x12,m_y12,m_w12;
    tInt m_x13,m_y13,m_w13;
    tInt m_x14,m_y14,m_w14;
};

typedef hollow_midpoint_circlet<> hollow_midpoint_circle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_circle
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS hollow_midpoint_circle: public hollow_midpoint_circle_extends {
public:
    typedef hollow_midpoint_circle_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    hollow_midpoint_circle(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~hollow_midpoint_circle() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotCircle
    (tImageBaseInterface &pixel, tInt cx,tInt cy,
     tInt r, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        CircleStart();
        MidpointCircleT<Extends, tImageBaseInterface, tInt>
        (*this, pixel, cx,cy,r, o);
        CircleFinish(pixel);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_HOLLOW_MIDPOINT_CIRCLE_HPP 
