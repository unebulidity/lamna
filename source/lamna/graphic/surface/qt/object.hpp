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
///   Date: 6/2/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_QT_OBJECT_HPP
#define _LAMNA_GRAPHIC_SURFACE_QT_OBJECT_HPP

#include "lamna/graphic/surface/qt/image.hpp"
#include "lamna/graphic/surface/object.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: objectt
///////////////////////////////////////////////////////////////////////
template
<class TQImageInterface = image_interface,
 class TObject = surface::object,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TObject>

class _EXPORT_CLASS objectt: public TExtends {
public:
    typedef TExtends Extends;

    typedef TQImageInterface tQImageInterface;
    typedef TObject tObject ;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    objectt(tQImageInterface& surfaceQImage)
    : Extends(surfaceQImage), m_surfaceQImage(surfaceQImage) {
    }
    virtual ~objectt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tQImageInterface& SurfaceQImage() const {
        return (tQImageInterface&)m_surfaceQImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tQImageInterface& m_surfaceQImage;
};
typedef objectt<> object;

} // namespace qt
} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_QT_OBJECT_HPP 
