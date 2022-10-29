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
///   File: object.hpp
///
/// Author: $author$
///   Date: 9/27/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_WX_OBJECT_HPP
#define _LAMNA_GRAPHIC_SURFACE_WX_OBJECT_HPP

#include "lamna/graphic/surface/wx/image.hpp"
#include "lamna/graphic/surface/object.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace wx {

///////////////////////////////////////////////////////////////////////
///  Class: objectt
///////////////////////////////////////////////////////////////////////
template
<class TImageInterface = image_interface,
 class TObject = surface::object,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TObject>

class _EXPORT_CLASS objectt: public TExtends {
public:
    typedef TExtends Extends;
    typedef TImageInterface tImageInterface;
    typedef TObject tObject ;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    objectt(tImageInterface& surfaceImage)
    : Extends(surfaceImage), m_surfaceImage(surfaceImage) {
    }
    virtual ~objectt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageInterface& SurfaceImage() const {
        return (tImageInterface&)m_surfaceImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageInterface& m_surfaceImage;
};
typedef objectt<> object;

} // namespace wx
} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_WX_OBJECT_HPP 
