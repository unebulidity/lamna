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
///   File: bresenham_line.hpp
///
/// Author: $author$
///   Date: 6/3/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_BRESENHAM_LINE_HPP
#define _LAMNA_GRAPHIC_BRESENHAM_LINE_HPP

#include "lamna/graphic/image_base.hpp"

namespace lamna {
namespace graphic {

///////////////////////////////////////////////////////////////////////
/// Function: BresenhamLineT
///////////////////////////////////////////////////////////////////////
template <class TImage, class TPixel, class TInt>

void BresenhamLineT
(TImage &image, TPixel &pixel, TInt x1, TInt y1, TInt x2, TInt y2)
{
    TInt dx,dy,i1,i2,d,x,y;

    x = x1;
    y = y1;

    if (0 > (dx = x2-x1))
        dx = -dx;

    if (0 > (dy = y2-y1))
        dy = -dy;

    if (dx < dy)
    {
        d = 2*dx-dy;
        i1 = 2*dx;
        i2 = 2*(dx - dy);

        image.Plot(pixel, x, y);

        if (y1 > y2)
        {
            if (x1 > x2)
            {
                while ((((--y) >= y2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        --x;
                    }
                    image.Plot(pixel, x, y);
                }
            }
            else
            {
                while ((((--y) >= y2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        x++;
                    }
                    image.Plot(pixel, x, y);
                }
            }
        }
        else
        {
            if (x1 > x2)
            {
                while ((((++y) <= y2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        --x;
                    }
                    image.Plot(pixel, x, y);
                }
            }
            else
            {
                while ((((++y) <= y2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        x++;
                    }
                    image.Plot(pixel, x, y);
                }
            }
        }
    }
    else
    {
        d = 2*dy-dx;
        i1 = 2*dy;
        i2 = 2*(dy - dx);

        image.Plot(pixel, x, y);

        if (x1 > x2)
        {
            if (y1 > y2)
            {
                while ((((--x) >= x2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        --y;
                    }
                    image.Plot(pixel, x, y);
                }
            }
            else
            {
                while ((((--x) >= x2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        y++;
                    }
                    image.Plot(pixel, x, y);
                }
            }
        }
        else
        {
            if (y1 > y2)
            {
                while ((((++x) <= x2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        --y;
                    }
                    image.Plot(pixel, x, y);
                }
            }
            else
            {
                while ((((++x) <= x2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        y++;
                    }
                    image.Plot(pixel, x, y);
                }
            }
        }
    }
}

class _EXPORT_CLASS bresenham_line;

///////////////////////////////////////////////////////////////////////
///  Class: bresenham_linet
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

class _EXPORT_CLASS bresenham_linet: public TExtends {
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
    bresenham_linet(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~bresenham_linet() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef bresenham_linet<> bresenham_line_extends;
///////////////////////////////////////////////////////////////////////
///  Class: bresenham_line
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS bresenham_line: public bresenham_line_extends {
public:
    typedef bresenham_line_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    bresenham_line(tImageBaseInterface& image): Extends(image) {
    }
    virtual ~bresenham_line() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawLine(tPixel &pixel, tInt x1,tInt y1, tInt x2,tInt y2) {
        BresenhamLineT<Extends, tPixel, tInt>
        (*this, pixel, x1,y1, x2,y2);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_BRESENHAM_LINE_HPP 
