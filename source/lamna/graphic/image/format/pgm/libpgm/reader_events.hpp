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
///   Date: 7/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_PGM_LIBPGM_READER_EVENTS_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_PGM_LIBPGM_READER_EVENTS_HPP

#include "lamna/graphic/image/format/pgm/libpgm/libpgm.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace pgm {
namespace libpgm {

typedef implement_base reader_events_implements;
///////////////////////////////////////////////////////////////////////
///  Class: reader_eventst
///////////////////////////////////////////////////////////////////////
template <class TImplements = reader_events_implements>
class _EXPORT_CLASS reader_eventst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_libpgm_read_image
    (size_t cols, size_t rows, max_t max, gray_t** image) {
        bool success = true;
        LAMNA_LOG_MESSAGE_DEBUG("on_libpgm_read_image(cols = " << cols << ", rows = " << rows << ", max = " << max << ", image = " << pointer_to_string(image) << ")...");
        reader_eventst* events = 0;
        if ((events = libpgm_reader_events_forward_to())) {
            success = events->on_libpgm_read_image(cols, rows, max, image);
        }
        LAMNA_LOG_MESSAGE_DEBUG("..." << bool_to_string(success) << " = on_libpgm_read_image(cols = " << cols << ", rows = " << rows << ", max = " << max << ", image = " << pointer_to_string(image) << ")");
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual reader_eventst* forward_libpgm_reader_events(reader_eventst* to) {
        return 0;
    }
    virtual reader_eventst* libpgm_reader_events_forward_to() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef reader_eventst<> reader_events;

} // namespace libpgm
} // namespace pgm 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_PGM_LIBPGM_READER_EVENTS_HPP 
