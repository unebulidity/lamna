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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 7/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBPGM_READER_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBPGM_READER_HPP

#include "lamna/graphic/image/format/pgm/libpgm/reader.hpp"
#include "lamna/graphic/image/format/raw/libpgm/reader_events.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace raw {
namespace libpgm {

class _EXPORT_CLASS reader_implements
: virtual public pgm::libpgm::reader_implements,
  virtual public raw::libpgm::reader_events {
public:
};
typedef pgm::libpgm::reader reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = reader_implements, class TExtends = reader_extends>
class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert
    (bayer::rgb::pattern_which_t pattern_which,
     reader_events* raw_libpgm_reader_events_forward_to = 0)
    : Extends(raw_libpgm_reader_events_forward_to),
      raw_libpgm_reader_events_forward_to_(raw_libpgm_reader_events_forward_to),
      pattern_which_(pattern_which) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_libpgm_read_image
    (size_t cols, size_t rows, max_t max, gray_t** image) {
        bool success = true;
        LAMNA_LOG_MESSAGE_DEBUG("on_libpgm_read_image(cols = " << cols << ", rows = " << rows << ", max = " << max << ", image = " << pointer_to_string(image) << ")...");
        if (bayer::rgb::pattern_none != (pattern_.set_which(pattern_which_))) {
            success = this->on_raw_libpgm_read_image
            (cols, rows, max, image, pattern_);
        } else {
            return false;
        }
        LAMNA_LOG_MESSAGE_DEBUG("..." << bool_to_string(success) << " = on_libpgm_read_image(cols = " << cols << ", rows = " << rows << ", max = " << max << ", image = " << pointer_to_string(image) << ")");
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual reader_events* forward_raw_libpgm_reader_events(reader_events* to) {
        raw_libpgm_reader_events_forward_to_ = to;
        return raw_libpgm_reader_events_forward_to_;
    }
    virtual reader_events* raw_libpgm_reader_events_forward_to() const {
        return raw_libpgm_reader_events_forward_to_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    reader_events* raw_libpgm_reader_events_forward_to_;
    bayer::rgb::pattern_which_t pattern_which_;
    bayer::rgb::pattern pattern_;
};
typedef readert<> reader;

namespace gbrg {
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS reader: public libpgm::reader {
public:
    reader(reader_events* raw_libpgm_reader_events_forward_to = 0)
    : libpgm::reader(bayer::rgb::pattern_gbrg, raw_libpgm_reader_events_forward_to) {
    }
};
} // namespace gbrg

} // namespace libpgm
} // namespace raw 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBPGM_READER_HPP 
