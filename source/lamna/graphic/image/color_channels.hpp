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
///   File: color_channels.hpp
///
/// Author: $author$
///   Date: 4/1/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_COLOR_CHANNELS_HPP
#define _LAMNA_GRAPHIC_IMAGE_COLOR_CHANNELS_HPP

#include "lamna/base/base.hpp"

namespace lamna {
namespace graphic {
namespace image {

///////////////////////////////////////////////////////////////////////
/// Enum: color_channels_rgb_which_t
///////////////////////////////////////////////////////////////////////
typedef int color_channels_rgb_which_t;
enum {
    color_channels_rgb_red,
    color_channels_rgb_green,
    color_channels_rgb_blue,

    first_color_channels_rgb = color_channels_rgb_red,
    last_color_channels_rgb = color_channels_rgb_blue,
    color_channels_rgb_channels = (last_color_channels_rgb - first_color_channels_rgb + 1)
};

///////////////////////////////////////////////////////////////////////
/// Enum: color_channels_which_t
///////////////////////////////////////////////////////////////////////
typedef int color_channels_which_t;
enum {
    color_channels_rgb,
    color_channels_bgr,

    color_channels_rgba,
    color_channels_bgra,

    color_channels_argb,
    color_channels_abgr,

    first_color_channels = color_channels_rgb,
    last_color_channels = color_channels_abgr,

    first_3color_channels = color_channels_rgb,
    last_3color_channels = color_channels_bgr,

    max_color_channels_channels = 4
};
typedef color_channels_which_t color_channels_channels_t;

typedef implement_base color_channels_implements;
typedef base color_channels_extends;
///////////////////////////////////////////////////////////////////////
///  Class: color_channelst
///////////////////////////////////////////////////////////////////////
template
<class TImplements = color_channels_implements, class TExtends = color_channels_extends>
class _EXPORT_CLASS color_channelst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef color_channels_which_t which_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    color_channelst(which_t which): which_(which) {
    }
    color_channelst(const color_channelst& copy): which_(copy.which_) {
    }
    virtual ~color_channelst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual which_t set_which(which_t to) {
        return which_;
    }
    virtual which_t which() const {
        return which_;
    }
    virtual operator which_t() const {
        return which_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual color_channels_channels_t channels() const {
        if ((which_ >= first_3color_channels)
            && (which_ <= last_3color_channels)) {
            return 3;
        }
        return 4;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    which_t which_;
};
typedef color_channelst<> color_channels_t;

} // namespace image
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_COLOR_CHANNELS_HPP 
