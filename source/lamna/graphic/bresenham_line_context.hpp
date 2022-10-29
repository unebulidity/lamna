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
///   File: bresenham_line_context.hpp
///
/// Author: $author$
///   Date: 6/4/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_BRESENHAM_LINE_CONTEXT_HPP
#define _LAMNA_GRAPHIC_BRESENHAM_LINE_CONTEXT_HPP

#include "lamna/graphic/image_base.hpp"

namespace lamna {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: bresenham_line_contextt
///////////////////////////////////////////////////////////////////////
template
<class TBase = base,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TBase>

class _EXPORT_CLASS bresenham_line_contextt: public TExtends {
public:
    typedef TExtends Extends;
    typedef bresenham_line_contextt Derives;

    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;
    typedef bool (Derives::*MFinish)(TInt& x, TInt& y);

    MFinish m_finish;
    TInt x1,y1,x2,y2,dx,dy,i1,i2,d;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    bresenham_line_contextt(): m_finish(0) {
    }
    virtual ~bresenham_line_contextt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Start
    (TInt& x,TInt& y,TInt p_x1,TInt p_y1, TInt p_x2,TInt p_y2) {
        bool isTrue = false;
        x = (x1 = p_x1);
        y = (y1 = p_y1);
        x2 = p_x2;
        y2 = p_y2;

        if (0 > (dx = x2-x1))
            dx = -dx;

        if (0 > (dy = y2-y1))
            dy = -dy;

        if (dx < dy)
        {
            d = 2*dx-dy;
            i1 = 2*dx;
            i2 = 2*(dx - dy);

            if (y1 > y2)
            {
                if (x2 < x1)
                    m_finish = &Derives::FinishMinusYminusX;
                else
                m_finish = &Derives::FinishMinusYplusX;
            }
            else
            {
                if (x2 < x1)
                    m_finish = &Derives::FinishYminusX;
                else
                m_finish = &Derives::FinishYplusX;
            }

            isTrue = true;
        }
        else
        {
            d = 2*dy-dx;
            i1 = 2*dy;
            i2 = 2*(dy - dx);

            if (x1 > x2)
            {
                if (y2 < y1)
                    m_finish = &Derives::FinishMinusXminusY;
                else
                m_finish = &Derives::FinishMinusXplusY;
            }
            else
            {
                if (y2 < y1)
                    m_finish = &Derives::FinishXminusY;
                else
                m_finish = &Derives::FinishXplusY;
            }

            isTrue = true;
        }
        return isTrue;
    }
    virtual bool Finish(TInt& x, TInt& y) {
        bool isTrue = false;
        if (m_finish)
            isTrue = (this->*m_finish)(x,y);
        return isTrue;
    }
    virtual bool FinishYminusX(TInt& x, TInt& y) {
        bool isTrue = false;
        if ((isTrue = ((++y) <= y2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                --x;
            }
        }
        return isTrue;
    }
    virtual bool FinishYplusX(TInt& x, TInt& y) {
        bool isTrue = false;
        if ((isTrue = ((++y) <= y2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                x++;
            }
        }
        return isTrue;
    }
    virtual bool FinishXminusY(TInt& x, TInt& y) {
        bool isTrue = false;
        if ((isTrue = ((++x) <= x2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                --y;
            }
        }
        return isTrue;
    }
    virtual bool FinishXplusY(TInt& x, TInt& y) {
        bool isTrue = false;
        if ((isTrue = ((++x) <= x2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                y++;
            }
        }
        return isTrue;
    }
    virtual bool FinishMinusYminusX(TInt& x, TInt& y) {
        bool isTrue = false;
        if ((isTrue = ((--y) >= y2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                --x;
            }
        }
        return isTrue;
    }
    virtual bool FinishMinusYplusX(TInt& x, TInt& y) {
        bool isTrue = false;
        if ((isTrue = ((--y) >= y2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                x++;
            }
        }
        return isTrue;
    }
    virtual bool FinishMinusXminusY(TInt& x, TInt& y) {
        bool isTrue = false;
        if ((isTrue = ((--x) >= x2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                --y;
            }
        }
        return isTrue;
    }
    virtual bool FinishMinusXplusY(TInt& x, TInt& y) {
        bool isTrue = false;
        if ((isTrue = ((--x) >= x2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                y++;
            }
        }
        return isTrue;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef bresenham_line_contextt<> bresenham_line_context;

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_BRESENHAM_LINE_CONTEXT_HPP 
