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
///   File: libtiff.hpp
///
/// Author: $author$
///   Date: 3/29/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_LIBTIFF_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_LIBTIFF_HPP

#include "lamna/io/logger.hpp"
#include "lamna/base/base.hpp"
#include <tiffio.h>

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace tiff {
namespace libtiff {

///////////////////////////////////////////////////////////////////////
/// Class: p_to_stringt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char_t, class TExtends = xos::base::stringt<TChar> >
class _EXPORT_CLASS p_to_stringt: public TExtends {
public:
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    p_to_stringt(const void* p) {
        this->append("0x");
        this->appendx(&p, sizeof(p));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef p_to_stringt<> p_to_string;

} // namespace libtiff 
} // namespace tiff 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_LIBTIFF_HPP 
