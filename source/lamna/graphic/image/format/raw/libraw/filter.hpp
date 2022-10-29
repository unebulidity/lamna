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
///   File: filter.hpp
///
/// Author: $author$
///   Date: 3/28/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_FILTER_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_FILTER_HPP

#include "lamna/graphic/image/format/raw/libraw/libraw.hpp"
#include "lamna/graphic/image/format/raw/bayer/rgb/filter.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace raw {
namespace libraw {

namespace rgb {
typedef implement_base filter_implements;
typedef base filter_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filtert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = filter_implements, class TExtends = filter_extends>
class _EXPORT_CLASS filtert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef int which_t;
    enum {
        none = -1,

        red    = 0,
        green  = 1,
        blue   = 2,
        green2 = 3,

        first = red,
        last  = green2,
        count = (last - first + 1)
    };
    typedef which_t pattern_t[count];
    typedef const char_t* name_t;
    typedef name_t names_t[count];

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filtert() {
    }
    virtual ~filtert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static name_t name_of(which_t of) {
        name_t name = LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_NONE;
        if ((first <= of) && (last >= of)) {
            name = names()[of - first];
        } else {
            LAMNA_LOG_ERROR("...unexpected name_of(which_t of = " << of << ")");
        }
        return name;
    }
    static names_t& names() {
        static names_t names
        = {LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_RED,
           LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_GREEN,
           LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_BLUE,
           LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_GREEN2};
        return names;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef filtert<> filter;
} // namespace rgb 

} // namespace libraw 
} // namespace raw 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_FILTER_HPP 
