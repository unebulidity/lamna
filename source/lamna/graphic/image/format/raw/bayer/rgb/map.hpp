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
///   File: map.hpp
///
/// Author: $author$
///   Date: 3/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_MAP_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_MAP_HPP

#include "lamna/graphic/image/format/raw/bayer/rgb/filter.hpp"
#include "lamna/base/base.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace raw {
namespace bayer {
namespace rgb {

typedef implement_base map_implements;
typedef base map_extends;
///////////////////////////////////////////////////////////////////////
///  Class: mapt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = map_implements, class TExtends = map_extends>
class _EXPORT_CLASS mapt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    mapt(const filters_which_t& to) {
        set_filters(to);
    }
    mapt(const mapt& copy) {
        set_filters(copy.filters_);
    }
    mapt() {
        set_filters();
    }
    virtual ~mapt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual filters_which_t& set_filters(const filters_which_t& to) {
        for (filter_which_t i = first_filter; i <= last_filter; ++i) {
            filters_[i - first_filter] = to[i - first_filter];
        }
        return filters_;
    }
    virtual filters_which_t& set_filters() {
        for (filter_which_t i = first_filter; i <= last_filter; ++i) {
            filters_[i - first_filter] = i;
        }
        return filters_;
    }
    virtual filters_which_t& filters() const {
        return (filters_which_t&)filters_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual filter_which_t& operator[](filter_which_t filter) const {
        return (filter_which_t&)filters_[filter - first_filter];
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    filters_which_t filters_;
};
typedef mapt<> map;

} // namespace rgb 
} // namespace bayer 
} // namespace raw 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_BAYER_RGB_MAP_HPP 
