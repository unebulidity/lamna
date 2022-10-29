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
///   Date: 6/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_OBJECT_HPP
#define _LAMNA_GRAPHIC_SURFACE_OBJECT_HPP

#include "lamna/graphic/surface/image.hpp"
#include "lamna/graphic/image_object.hpp"

namespace lamna {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: objectt
///////////////////////////////////////////////////////////////////////
template
<class TImageObject = image_object,
 class TImageInterface = image_interface,
 class TImageBaseInterface = image_base_interface,
 class TSelectedImage = selected_image,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TImageObject>

class _EXPORT_CLASS objectt: public TExtends {
public:
    typedef TExtends Extends;

    typedef objectt tObject;
    typedef TImageObject tImageObject;
    typedef TImageInterface tImageInterface;
    typedef TImageBaseInterface tImageBaseInterface;
    typedef TSelectedImage tSelectedImage;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    objectt
    (tImageInterface& surface_image,
     tSize width = 0, tSize height = 0)
    : Extends(surface_image, width, height),
      surface_image_(surface_image) {
    }
    virtual ~objectt() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tSelectedImage* SurfaceSelectImage(tSelectedImage* image) {
        return surface_image_.SelectImage(image);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageInterface& surface_image_;
};
typedef objectt<> object;

} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_OBJECT_HPP
