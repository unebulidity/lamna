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
///   File: hollow_midpoint_ellipse.hpp
///
/// Author: $author$
///   Date: 6/2/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_HOLLOW_MIDPOINT_ELLIPSE_HPP
#define _LAMNA_GRAPHIC_HOLLOW_MIDPOINT_ELLIPSE_HPP

#include "lamna/graphic/midpoint_ellipse.hpp"

namespace lamna {
namespace graphic {

class _EXPORT_CLASS hollow_midpoint_ellipse;

///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_ellipset
///////////////////////////////////////////////////////////////////////
template
<class TMidpointEllipse = midpoint_ellipse,
 class TImageBaseInterface = image_base_interface,
 class TImage = TImageBaseInterface,
 class TPixel = TImageBaseInterface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TMidpointEllipse>

class _EXPORT_CLASS hollow_midpoint_ellipset: public TExtends {
public:
    typedef TExtends Extends;

    typedef TMidpointEllipse tMidpointEllipse;
    typedef TImageBaseInterface tImageBaseInterface;
    typedef TImage tImage;
    typedef TPixel tPixel;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    hollow_midpoint_ellipset(tImage& image)
    : Extends(image),
      m_x1(0),m_y1(0),m_w1(0),
      m_x2(0),m_y2(0),m_w2(0),
      m_x3(0),m_y3(0),m_w3(0),
      m_x4(0),m_y4(0),m_w4(0) {
    }
    virtual ~hollow_midpoint_ellipset() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void EllipsePlot
    (tPixel &pixel, tInt a,tInt b, tInt cx,tInt cy, tInt x,tInt y,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        if (q != e_ELLIPSE_QUADRANT_ALL) {
            if (q & e_ELLIPSE_QUADRANT_1) {
                EllipseHollow(pixel, m_x1,m_y1,m_w1, cx+x+1, cy - y, a-x);
            }
            if (q & e_ELLIPSE_QUADRANT_2) {
                EllipseHollow(pixel, m_x2,m_y2,m_w2, cx+x+1, cy + y, a-x);
            }
            if (q & e_ELLIPSE_QUADRANT_3) {
                EllipseHollow(pixel, m_x3,m_y3,m_w3, cx-a, cy + y, a-x);
            }
            if (q & e_ELLIPSE_QUADRANT_4) {
                EllipseHollow(pixel, m_x4,m_y4,m_w4, cx-a, cy - y, a-x);
            }
        } else {
            EllipseHollow(pixel, m_x1,m_y1,m_w1, cx+x+1, cy - y, a-x);
            EllipseHollow(pixel, m_x2,m_y2,m_w2, cx+x+1, cy + y, a-x);
            EllipseHollow(pixel, m_x3,m_y3,m_w3, cx-a, cy + y, a-x);
            EllipseHollow(pixel, m_x4,m_y4,m_w4, cx-a, cy - y, a-x);
        }
    }
    virtual void EllipseHollow
    (tPixel &pixel, tInt& xQ,tInt& yQ, tInt& wQ, tInt x,tInt y, tInt w) {
        if ((0 < wQ) && (yQ != y)) {
            this->Fill(pixel, xQ,yQ, wQ,1);
        }
        xQ = x;
        yQ = y;
        wQ = w;
    }
    virtual void EllipseStart() {
        m_x1 = (m_y1 = (m_w1 = 0));
        m_x2 = (m_y2 = (m_w2 = 0));
        m_x3 = (m_y3 = (m_w3 = 0));
        m_x4 = (m_y4 = (m_w4 = 0));
    }
    virtual void EllipseFinish(tPixel &pixel) {
        if ((0 < m_w1)) {
            this->Fill(pixel, m_x1,m_y1, m_w1,1);
        }
        if ((0 < m_w2)) {
            this->Fill(pixel, m_x2,m_y2, m_w2,1);
        }
        if ((0 < m_w3)) {
            this->Fill(pixel, m_x3,m_y3, m_w3,1);
        }
        if ((0 < m_w4)) {
            this->Fill(pixel, m_x4,m_y4, m_w4,1);
        }
        m_x1 = (m_y1 = (m_w1 = 0));
        m_x2 = (m_y2 = (m_w2 = 0));
        m_x3 = (m_y3 = (m_w3 = 0));
        m_x4 = (m_y4 = (m_w4 = 0));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tInt m_x1,m_y1,m_w1;
    tInt m_x2,m_y2,m_w2;
    tInt m_x3,m_y3,m_w3;
    tInt m_x4,m_y4,m_w4;
};

typedef hollow_midpoint_ellipset<> hollow_midpoint_ellipse_extends;
///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_ellipse
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS hollow_midpoint_ellipse: public hollow_midpoint_ellipse_extends {
public:
    typedef hollow_midpoint_ellipse_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    hollow_midpoint_ellipse(tImage& image): Extends(image) {
    }
    virtual ~hollow_midpoint_ellipse() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotEllipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        EllipseStart();
        MidpointEllipseT<Extends, tPixel, tInt>
        (*this, pixel, cx,cy, a,b, q);
        EllipseFinish(pixel);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_HOLLOW_MIDPOINT_ELLIPSE_HPP 
