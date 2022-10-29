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
///   File: color.hpp
///
/// Author: $author$
///   Date: 4/2/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_COLOR_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_COLOR_HPP

#include "lamna/graphic/image/format/png/libpng/png.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {

typedef png_colorp color_attached_t;
typedef xos::base::creator color_creator;
typedef xos::base::attachert<color_attached_t, int, 0, color_creator> color_attacher;
typedef xos::base::attachedt<color_attached_t, int, 0, color_attacher, base> color_attached;
typedef xos::base::createdt<color_attached_t, int, 0, color_attacher, color_attached> color_created_extend;
typedef color_creator color_implements;
typedef color_created_extend color_extends;
///////////////////////////////////////////////////////////////////////
///  Class: colort
///////////////////////////////////////////////////////////////////////
template
<class TImplements = color_implements, class TExtends = color_extends>
class _EXPORT_CLASS colort: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef color_attached_t attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    colort
    (attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~colort() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_detached() const {
        attached_t detached = 0;
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef colort<> color;

} // namespace libpng 
} // namespace png 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_COLOR_HPP 
