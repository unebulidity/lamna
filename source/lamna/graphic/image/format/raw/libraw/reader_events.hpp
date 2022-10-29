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
///   File: reader_events.hpp
///
/// Author: $author$
///   Date: 3/28/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_READER_EVENTS_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_READER_EVENTS_HPP

#include "lamna/graphic/image/format/raw/libraw/filter.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace raw {
namespace libraw {

namespace rgb {
typedef implement_base reader_events_implements;
///////////////////////////////////////////////////////////////////////
///  Class: reader_eventst
///////////////////////////////////////////////////////////////////////
template <class TImplements = reader_events_implements>
class _EXPORT_CLASS reader_eventst: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef filter filter_t;
    typedef filter::pattern_t pattern_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_libraw_unpack_image
    (size_t height, size_t width, size_t stride,
     ushort* image, pattern_t& pattern, imgdata_t& imgdata) {
        bool success = false;
        reader_eventst* events = 0;
        if ((events = libraw_reader_events_forward_to())) {
            success = events->on_libraw_unpack_image
            (height, width, stride, image, pattern, imgdata);
        }
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual reader_eventst* forward_libraw_reader_events(reader_eventst* to) {
        return 0;
    }
    virtual reader_eventst* libraw_reader_events_forward_to() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef reader_eventst<> reader_events;
} // namespace rgb

} // namespace libraw
} // namespace raw 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_READER_EVENTS_HPP 
