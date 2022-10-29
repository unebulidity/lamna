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
///   File: image_point.hpp
///
/// Author: $author$
///   Date: 6/4/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_POINT_HPP
#define _LAMNA_GRAPHIC_IMAGE_POINT_HPP

#include "lamna/graphic/image_base.hpp"
#include "xos/base/array.hpp"

namespace lamna {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: image_pointt
///////////////////////////////////////////////////////////////////////
template
<class TBase = base,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TExtends = TBase>

class _EXPORT_CLASS image_pointt: public TExtends {
public:
    typedef TExtends Extends;

    typedef TBase tBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;

    tInt m_x, m_y;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    image_pointt(tInt x, tInt y)
    : m_x(x), m_y(y) {
    }
    image_pointt(const image_pointt& copy)
    : m_x(copy.m_x), m_y(copy.m_y) {
    }
    image_pointt()
    : m_x(0), m_y(0) {
    }
    virtual ~image_pointt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare(const image_pointt& toPoint) const  {
        int unequal = 0;
        if (m_y > toPoint.m_y)
            unequal = 1;
        else
        if (m_y < toPoint.m_y)
            unequal = -1;
        else
        if (m_x > toPoint.m_x)
            unequal = 1;
        else
        if (m_x < toPoint.m_x)
            unequal = -1;
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef image_pointt<> image_point;

///////////////////////////////////////////////////////////////////////
///  Class: image_point_arrayt
///////////////////////////////////////////////////////////////////////
template
<class TWhat = image_point,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 TSize VSize = XOS_ARRAY_DEFAULT_SIZE,
 class TArray = xos::base::arrayt<TWhat, TSize, VSize>,
 class TExtends = TArray>

class _EXPORT_CLASS image_point_arrayt: public TExtends {
public:
    typedef TExtends Extends;

    typedef TWhat tWhat;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tLength QSort() {
        tLength count = this->length();
        if (0 < (count))
            this->QSort(0, count-1);
        return count;
    }
    virtual void QSort(tSize iFirst, tSize iLast) {
        tSize iNext, iPrev;
        if (iFirst < iLast) {
            if (iLast-iFirst>1) {
                for (iNext=iFirst, iPrev=iLast-1; iNext<iPrev;) {
                    for (;iNext<=iPrev; iNext++) {
                        if (Compare(iNext, iLast)>0)
                            break;
                    }
                    for (;iPrev>iNext; iPrev--) {
                        if (Compare(iPrev,iLast)<0) {
                            Swap(iNext++, iPrev--);
                            break;
                        }
                    }
                }
                if (iNext<iLast) {
                    Swap(iNext, iLast);
                    QSort(iNext+1, iLast);
                }
                if (iNext > iFirst)
                    QSort(iFirst, iNext-1);
            } else {
                if (Compare(iFirst, iLast)>0)
                    Swap(iFirst, iLast);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare(tSize iFirst, tSize iLast) const {
        int unequal = 0;
        if ((iFirst >= 0) && (iLast < this->length_))
            unequal = this->elements_[iFirst].Compare(this->elements_[iLast]);
        return unequal;
    }
    virtual void Swap(tSize iFirst, tSize iLast) {
        tWhat temp = this->elements_[iFirst];
        this->elements_[iFirst] = this->elements_[iLast];
        this->elements_[iLast] = temp;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tWhat* Points(tLength& pointsSize, tLength& pointsLength) const {
        tWhat* points = this->elements();
        pointsSize = this->size();
        pointsLength = this->length();
        return points;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef image_point_arrayt<> image_point_array;

///////////////////////////////////////////////////////////////////////
///  Class: image_point_trianglet
///////////////////////////////////////////////////////////////////////
template
<class TWhat = image_point,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TArray = image_point_arrayt<TWhat, TInt, TSize, TLength, 3>,
 class TExtends = TArray>

class _EXPORT_CLASS image_point_trianglet: public TExtends {
public:
    typedef TExtends Extends;

    typedef TWhat tWhat;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    image_point_trianglet(tInt x1,tInt y1, tInt x2,tInt y2, tInt x3,tInt y3) {
        this->elements_[0].m_x = x1;
        this->elements_[0].m_y = y1;
        this->elements_[1].m_x = x2;
        this->elements_[1].m_y = y2;
        this->elements_[2].m_x = x3;
        this->elements_[2].m_y = y3;
        this->size_ = (this->length_ = 3);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef image_point_trianglet<> image_point_triangle;

///////////////////////////////////////////////////////////////////////
///  Class: sorted_image_point_trianglet
///////////////////////////////////////////////////////////////////////
template
<class TWhat = image_point,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TArray = image_point_trianglet<TWhat, TInt, TSize, TLength>,
 class TExtends = TArray>

class _EXPORT_CLASS sorted_image_point_trianglet: public TExtends {
public:
    typedef TExtends Extends;

    typedef TWhat tWhat;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    sorted_image_point_trianglet
    (tInt x1,tInt y1, tInt x2,tInt y2, tInt x3,tInt y3)
    : Extends(x1,y1, x2,y2, x3,y3) {
        this->QSort();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef sorted_image_point_trianglet<> sorted_image_point_triangle;

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_POINT_HPP 
