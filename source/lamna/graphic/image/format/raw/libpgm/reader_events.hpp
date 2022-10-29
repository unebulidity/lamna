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
///   Date: 7/19/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBPGM_READER_EVENTS_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBPGM_READER_EVENTS_HPP

#include "lamna/graphic/image/format/pgm/libpgm/reader_events.hpp"
#include "lamna/graphic/image/format/raw/bayer/rgb/map.hpp"
#include "lamna/graphic/image/format/raw/bayer/rgb/pattern.hpp"
#include "lamna/graphic/image/format/raw/bayer/rgb/filter.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace raw {
namespace libpgm {

typedef pgm::libpgm::reader_events reader_events_implements;
///////////////////////////////////////////////////////////////////////
///  Class: reader_eventst
///////////////////////////////////////////////////////////////////////
template <class TImplements = reader_events_implements>
class _EXPORT_CLASS reader_eventst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_raw_libpgm_read_image
    (size_t cols, size_t rows, max_t max, gray_t** image,
     const bayer::rgb::pattern& pattern) {
        bool success = true;
        LAMNA_LOG_MESSAGE_DEBUG("on_raw_libpgm_read_image(cols = " << cols << ", rows = " << rows << ", max = " << max << ", image = " << pointer_to_string(image) << ", pattern = " << pattern.name() << ")...");
        reader_eventst* events = 0;
        if ((events = raw_libpgm_reader_events_forward_to())) {
            success = events->on_raw_libpgm_read_image
            (cols, rows, max, image, pattern);
        }
        LAMNA_LOG_MESSAGE_DEBUG("..." << bool_to_string(success) << " = on_raw_libpgm_read_image(cols = " << cols << ", rows = " << rows << ", max = " << max << ", image = " << pointer_to_string(image) << ", pattern = " << pattern.name() << ")");
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual reader_eventst* forward_raw_libpgm_reader_events(reader_eventst* to) {
        return 0;
    }
    virtual reader_eventst* raw_libpgm_reader_events_forward_to() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef reader_eventst<> reader_events;

} // namespace libpgm
} // namespace raw 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBPGM_READER_EVENTS_HPP 
