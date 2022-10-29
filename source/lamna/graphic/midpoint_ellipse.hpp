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
///   File: midpoint_ellipse.hpp
///
/// Author: $author$
///   Date: 5/31/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_MIDPOINT_ELLIPSE_HPP
#define _LAMNA_GRAPHIC_MIDPOINT_ELLIPSE_HPP

#include "lamna/graphic/midpoint_circle.hpp"

namespace lamna {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Enum: eEllipseQuadrant
///////////////////////////////////////////////////////////////////////
typedef unsigned int eEllipseQuadrant;
enum {
    e_ELLIPSE_QUADRANT_ALL = e_CIRCLE_QUADRANT_ALL,

    e_ELLIPSE_QUADRANT_1 = e_CIRCLE_QUADRANT_1,
    e_ELLIPSE_QUADRANT_2 = e_CIRCLE_QUADRANT_2,
    e_ELLIPSE_QUADRANT_3 = e_CIRCLE_QUADRANT_3,
    e_ELLIPSE_QUADRANT_4 = e_CIRCLE_QUADRANT_4,
};

///////////////////////////////////////////////////////////////////////
/// Function: MidpointEllipseT
///////////////////////////////////////////////////////////////////////
template<class TImage, class TPixel, class TInt>

void MidpointEllipseT
(TImage &image, TPixel &pixel,
 TInt cx, TInt cy, TInt a, TInt b,
 eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
    TInt x, y, a2, b2, S, T;

    if ((1 == a) && (1 == b)) {
        image.Plot(pixel, cx,cy);
    }
    else if ((1 == a) && (1 < b)) {
            image.Fill(pixel, cx,cy-b+1, 1,b+b-1);
    }
    else if ((1 < a) && (1 == b)) {
            image.Fill(pixel, cx-a+1,cy, a+a-1,1);
    }
    else if ((0 < --a) && (0 < --b)) {
        a2 = a*a;
        b2 = b*b;
        x = 0;
        y = b;
        S = a2*(1-2*b) + 2*b2;
        T = b2 - 2*a2*(2*b-1);

        image.EllipsePlot(pixel, a,b, cx,cy, x,y, q);

        do {
            if (S<0) {
                S += 2*b2*(2*x+3);
                T += 4*b2*(x+1);
                x++;
            }
            else if (T<0) {
                S += 2*b2*(2*x+3) - 4*a2*(y-1);
                T += 4*b2*(x+1) - 2*a2*(2*y-3);
                x++;
                y--;
            }
            else {
                S -= 4*a2*(y-1);
                T -= 2*a2*(2*y-3);
                y--;
            }

            image.EllipsePlot(pixel, a,b, cx,cy, x,y, q);
        } while (y>0);
    }
}

class _EXPORT_CLASS midpoint_ellipse;

///////////////////////////////////////////////////////////////////////
///  Class: midpoint_ellipset
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

class _EXPORT_CLASS midpoint_ellipset: public TExtends {
public:
    typedef TExtends Extends;

    typedef TImageBase tImageBase;
    typedef TImageBaseInterface tImageBaseInterface;
    typedef TImage tImage;
    typedef TPixel tPixel;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    midpoint_ellipset(tImage& image): Extends(image) {
    }
    virtual ~midpoint_ellipset() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void EllipsePlot
    (tPixel &pixel, tInt a,tInt b, tInt cx,tInt cy, tInt x,tInt y,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        if (q != e_ELLIPSE_QUADRANT_ALL) {
            if (q & e_ELLIPSE_QUADRANT_1) {
                this->Plot(pixel, cx + x, cy - y);
            }
            if (q & e_ELLIPSE_QUADRANT_2) {
                this->Plot(pixel, cx + x, cy + y);
            }
            if (q & e_ELLIPSE_QUADRANT_3) {
                this->Plot(pixel, cx - x, cy + y);
            }
            if (q & e_ELLIPSE_QUADRANT_4) {
                this->Plot(pixel, cx - x, cy - y);
            }
        }
        else {
            this->Plot(pixel, cx + x, cy + y);
            this->Plot(pixel, cx - x, cy - y);
            this->Plot(pixel, cx + x, cy - y);
            this->Plot(pixel, cx - x, cy + y);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

class _EXPORT_CLASS filled_midpoint_ellipse;

///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_ellipset
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

class _EXPORT_CLASS filled_midpoint_ellipset: public TExtends {
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
    filled_midpoint_ellipset(tImage& image): Extends(image) {
    }
    virtual ~filled_midpoint_ellipset() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void EllipsePlot
    (tPixel &pixel, tInt a,tInt b, tInt cx,tInt cy, tInt x,tInt y,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        if (q != e_ELLIPSE_QUADRANT_ALL) {
            if (q & e_ELLIPSE_QUADRANT_1) {
                this->Fill(pixel, cx, cy - y, x+1, 1);
            }
            if (q & e_ELLIPSE_QUADRANT_2) {
                this->Fill(pixel, cx, cy + y, x+1, 1);
            }
            if (q & e_ELLIPSE_QUADRANT_3) {
                this->Fill(pixel, cx - x, cy + y, x+1, 1);
            }
            if (q & e_ELLIPSE_QUADRANT_4) {
                this->Fill(pixel, cx - x, cy - y, x+1, 1);
            }
        } else {
            this->Fill(pixel, cx - x, cy + y, x+x+1, 1);
            this->Fill(pixel, cx - x, cy - y, x+x+1, 1);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef midpoint_ellipset<> midpoint_ellipse_extends;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_ellipse
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS midpoint_ellipse: public midpoint_ellipse_extends {
public:
    typedef midpoint_ellipse_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    midpoint_ellipse(tImage& image): Extends(image) {
    }
    virtual ~midpoint_ellipse() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotEllipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        MidpointEllipseT<Extends, tPixel, tInt>
        (*this, pixel, cx,cy, a,b, q);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef filled_midpoint_ellipset<> filled_midpoint_ellipse_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_ellipse
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_midpoint_ellipse: public filled_midpoint_ellipse_extends {
public:
    typedef filled_midpoint_ellipse_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filled_midpoint_ellipse(tImage& image): Extends(image) {
    }
    virtual ~filled_midpoint_ellipse() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotEllipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        MidpointEllipseT<Extends, tPixel, tInt>
        (*this, pixel, cx,cy, a,b, q);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_MIDPOINT_ELLIPSE_HPP 
