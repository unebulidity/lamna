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
///   File: filled_circle.hpp
///
/// Author: $author$
///   Date: 10/5/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_FILLED_CIRCLE_HPP
#define _LAMNA_GRAPHIC_SURFACE_FILLED_CIRCLE_HPP

#include "lamna/graphic/surface/object.hpp"

namespace lamna {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: filled_circlet
///////////////////////////////////////////////////////////////////////
template
<class TObject = object,
 class TImageInterface = image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TObject>

class _EXPORT_CLASS filled_circlet: public TExtends {
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
    filled_circlet
    (tImageInterface& image, tObject& color, tSize r)
    : Extends(image, r,r), circle_(image), color_(color), r_(r) {
    }
    virtual ~filled_circlet() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        if ((0 < w) && (0 < h) && (0 < r_)) {
            circle_.PlotCircle(color_, x,y, r_, e_CIRCLE_QUADRANT_4);
            circle_.PlotCircle(color_, x,y+h-1, r_, e_CIRCLE_QUADRANT_3);
            if ((2 < w)) {
                color_.Fill(this->surface_image_, x+1,y-r_+1, w-2,r_);
                color_.Fill(this->surface_image_, x+1,y+h-1, w-2,r_);
            }
            if ((2 < h)) {
                color_.Fill(this->surface_image_, x-r_+1,y+1, w+r_+r_-2,h-2);
            }
            circle_.PlotCircle(color_, x+w-1,y, r_, e_CIRCLE_QUADRANT_1);
            circle_.PlotCircle(color_, x+w-1,y+h-1, r_, e_CIRCLE_QUADRANT_2);
        }
        return error;
    }
    virtual eError Plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        circle_.PlotCircle(color_, x,y, r_);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    filled_midpoint_circle_image circle_;
    tObject& color_;
    tSize r_;
};
typedef filled_circlet<> filled_circle;

} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_FILLED_CIRCLE_HPP 
