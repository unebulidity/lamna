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
///   File: image.hpp
///
/// Author: $author$
///   Date: 10/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_SURFACE_FL_IMAGE_HPP
#define _LAMNA_GRAPHIC_SURFACE_FL_IMAGE_HPP

#include "lamna/graphic/surface/fl/context.hpp"
#include "lamna/graphic/surface/image.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace fl {

///////////////////////////////////////////////////////////////////////
///  Class: image_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = context_interface,
 class TImageInterface = surface::image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TImageInterface>

class _EXPORT_CLASS image_interfacet: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TContextInterface tContextInterface;
    typedef TImageInterface tImageInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tContextInterface& SurfaceContext() const = 0;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef image_interfacet<> image_interface;

///////////////////////////////////////////////////////////////////////
///  Class: imaget
///////////////////////////////////////////////////////////////////////
template
<class TImageInterface = image_interface,
 class TImage = surface::image,
 class TContextInterface = context_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TImageInterface, class TExtends = TImage>

class _EXPORT_CLASS imaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TImageInterface tImageInterface;
    typedef TContextInterface tContextInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    imaget
    (tContextInterface& surfaceContext, tImageInterface* image = 0)
    : Extends(surfaceContext, image), m_surfaceContext(surfaceContext) {
    }
    virtual ~imaget() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tContextInterface& SurfaceContext() const {
        return (tContextInterface&)m_surfaceContext;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tContextInterface& m_surfaceContext;
};
typedef imaget<> image;

} // namespace fl 
} // namespace surface 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_SURFACE_FL_IMAGE_HPP 
