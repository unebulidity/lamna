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
///   File: key_icon.hpp
///
/// Author: $author$
///   Date: 9/8/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_SHAPE_KEY_ICON_HPP
#define _LAMNA_GRAPHIC_SURFACE_SHAPE_KEY_ICON_HPP

#include "lamna/graphic/surface/elliptical_rounded_rectangle.hpp"
#include "lamna/graphic/surface/rounded_rectangle.hpp"
#include "lamna/graphic/surface/rectangle.hpp"
#include "lamna/graphic/surface/triangle.hpp"
#include "lamna/graphic/surface/color.hpp"
#include "lamna/graphic/surface/object.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace shape {

///////////////////////////////////////////////////////////////////////
///  Class: key_icon
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS key_icon: public object {
public:
    typedef object Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    key_icon
    (tImageInterface& image,
     tObject& handleColor, tObject& bladeColor,
     tObject& lineColor, tObject& borderColor,
     tSize width, tSize height, tSize border)
    : Extends(image, width, height),
      m_handleColor(handleColor), m_bladeColor(bladeColor),
      m_lineColor(lineColor), m_borderColor(borderColor),
      m_border(border), uXTop(1), uXBottom(16), uYTop(1), uYBottom(8),
      uX((width*uXTop)/uXBottom),
      uY((height*uYTop)/uYBottom) {
    }
    virtual ~key_icon() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError Plot(tOffset x, tOffset y);
    virtual eError OnSetSize(tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        uX = ((width*uXTop)/uXBottom);
        uY = ((height*uYTop)/uYBottom);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tObject &m_handleColor, &m_bladeColor, &m_lineColor, &m_borderColor;
    tSize m_border;
    tSize uXTop, uXBottom;
    tSize uYTop, uYBottom;
    tSize uX, uY;
};

} // namespace shape 
} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_SHAPE_KEY_ICON_HPP 
