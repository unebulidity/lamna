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
///   File: pixel.hpp
///
/// Author: $author$
///   Date: 4/1/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_PIXEL_HPP
#define _LAMNA_GRAPHIC_IMAGE_PIXEL_HPP

#include "lamna/graphic/image/color_channels.hpp"

namespace lamna {
namespace graphic {
namespace image {

typedef implement_base pixel_implements;
typedef base pixel_extends;
///////////////////////////////////////////////////////////////////////
///  Class: pixelt
///////////////////////////////////////////////////////////////////////
template
<typename TColorSample = size_t,
 typename TColorChannels = color_channels_t,
 typename TColorChannelsWhich = color_channels_which_t,
 typename TColorChannelsChannels = color_channels_channels_t,
 TColorChannelsChannels VMaxColorChannelsChannels = max_color_channels_channels,
 class TImplements = pixel_implements, class TExtends = pixel_extends>

class _EXPORT_CLASS pixelt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TColorSample color_sample_t;
    typedef TColorChannels color_channels_t;
    typedef TColorChannelsWhich color_channels_which_t;
    typedef TColorChannelsChannels color_channels_channels_t;
    enum { max_color_channels_channels = VMaxColorChannelsChannels};

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pixelt(color_channels_which_t which, color_sample_t max, ...)
    : color_channels_(which) {
        va_list va;
        clear();
        va_start(va, max);
        assign(max, va);
        va_end(va);
    }
    virtual ~pixelt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual pixelt& assign(color_sample_t max, va_list va) {
        color_channels_channels_t channels = color_channels_.channels();
        for (color_channels_channels_t c = 0; c < channels; ++c) {
            color_sample_[c] = va_arg(va, color_sample_t);
        }
        color_sample_[max_color_channels_channels] = max;
        color_sample_[max_color_channels_channels + 1] = max;
        return *this;
    }
    virtual pixelt& clear() {
        for (color_channels_channels_t c = 0; c < max_color_channels_channels; ++c) {
            color_sample_[c] = 0;
        }
        color_sample_[max_color_channels_channels] = 0;
        color_sample_[max_color_channels_channels + 1] = 0;
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual color_sample_t red() const {
        return color_sample_[color_channels_rgb_red]; }
    virtual color_sample_t green() const {
        return color_sample_[color_channels_rgb_green]; }
    virtual color_sample_t blue() const {
        return color_sample_[color_channels_rgb_blue]; }
    virtual color_sample_t alpha() const {
        return color_sample_[max_color_channels_channels]; }
    virtual color_sample_t max() const {
        return color_sample_[max_color_channels_channels + 1]; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    color_channels_t color_channels_;
    color_sample_t color_sample_[max_color_channels_channels + 2];
};
typedef pixelt<> pixel;

namespace rgb {
///////////////////////////////////////////////////////////////////////
///  Class: pixel
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS pixel: public image::pixel {
public:
    typedef image::pixel Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pixel
    (color_sample_t red, color_sample_t green,
     color_sample_t blue, color_sample_t max)
    : Extends(color_channels_rgb, max, red, green, blue) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace rgb

namespace rgba {
///////////////////////////////////////////////////////////////////////
///  Class: pixel
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS pixel: public image::pixel {
public:
    typedef image::pixel Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pixel
    (color_sample_t red, color_sample_t green,
     color_sample_t blue, color_sample_t alpha, color_sample_t max)
    : Extends(color_channels_rgba, max, red, green, blue, alpha) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace rgba

} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_PIXEL_HPP 
        

