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
///   Date: 3/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_HPP

#include "lamna/io/logger.hpp"

#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_BITS 2
#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_MASK 3

#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NONE  -1
#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_RED    0
#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_GREEN  1
#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_BLUE   2
#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_GREEN2 3

#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_NONE   ""
#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_RED    "R"
#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_GREEN  "G"
#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_BLUE   "B"
#define LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_GREEN2 "G2"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace raw {
namespace bayer {
namespace rgb {

///////////////////////////////////////////////////////////////////////
/// Enum: filter_which_t
///////////////////////////////////////////////////////////////////////
typedef int filter_which_t;
enum {
    filter_none   = LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NONE,

    filter_red    = LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_RED,
    filter_green  = LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_GREEN,
    filter_blue   = LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_BLUE,
    filter_green2 = LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_GREEN2,

    next_filter,
    first_filter = filter_red,
    last_filter = filter_green2,
    filters = (last_filter - first_filter + 1)
};
enum {
    filter_bits = LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_BITS,
    filter_mask = LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_MASK,
};
typedef filter_which_t filters_which_t[filters];

typedef implement_base filter_implements;
typedef base filter_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filtert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = filter_implements, class TExtends = filter_extends>
class _EXPORT_CLASS filtert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filtert() {
    }
    virtual ~filtert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static const char* name_of(filter_which_t of) {
        static const char* name[filters] = {
            LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_RED,
            LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_GREEN,
            LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_BLUE,
            LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_GREEN2};
        if ((of >= first_filter) && (of <= last_filter)) {
            return name[(of - first_filter) & filter_mask];
        } else {
            LAMNA_LOG_ERROR("...unexpected name(filter_which_t of = " << of << ")");
        }
        return LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_NAME_NONE;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef filtert<> filter;

} // namespace rgb
} // namespace bayer 
} // namespace raw 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_FILTER_HPP 
