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
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_PGM_LIBPGM_READER_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_PGM_LIBPGM_READER_HPP

#include "lamna/graphic/image/format/pgm/libpgm/reader_events.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace pgm {
namespace libpgm {

typedef reader_events reader_implements;
typedef base reader_extends;
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
    readert(reader_events* libpgm_reader_events_forward_to = 0)
    : libpgm_reader_events_forward_to_(libpgm_reader_events_forward_to) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool read(const char* file) {
        bool success = false;

        if ((file) && (file[0])) {
            xos::io::read::file f;

            LAMNA_LOG_MESSAGE_DEBUG("f.open(\"" << file << "\")...");
            if ((f.open(file))) {
                int cols = 0, rows = 0;
                max_t max = 0; gray_t **image = 0;

                LAMNA_LOG_MESSAGE_DEBUG("pgm_readpgm(f.attached_to() = " << pointer_to_string(f.attached_to()) << ", &cols = " << pointer_to_string(&cols) << ", &rows = " << pointer_to_string(&rows) << ", &max = " << pointer_to_string(&max) << ")...");
                if ((image = pgm_readpgm(f.attached_to(), &cols, &rows, &max)))  {
                    LAMNA_LOG_MESSAGE_DEBUG("...image = " << pointer_to_string(image) << " cols = " << cols << " rows = " << rows << " max = " << max << "");

                    if ((this->on_libpgm_read_image(cols, rows, max, image))) {
                        success = true;
                    }
                    LAMNA_LOG_MESSAGE_DEBUG("pgm_freearray(image = " << pointer_to_string(image) << ", rows = " << rows << ")...");
                    pgm_freearray(image, rows);
                    LAMNA_LOG_MESSAGE_DEBUG("...pgm_freearray(image = " << pointer_to_string(image) << ", rows = " << rows << ")");
                } else {
                    LAMNA_LOG_MESSAGE_DEBUG("...failed on pgm_readpgm(f.attached_to() = " << pointer_to_string(f.attached_to()) << ", &cols = " << pointer_to_string(&cols) << ", &rows = " << pointer_to_string(&rows) << ", &max = " << pointer_to_string(&max) << ")");
                }
                f.close();
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual reader_events* forward_libpgm_reader_events(reader_events* to) {
        libpgm_reader_events_forward_to_ = to;
        return libpgm_reader_events_forward_to_;
    }
    virtual reader_events* libpgm_reader_events_forward_to() const {
        return libpgm_reader_events_forward_to_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    reader_events* libpgm_reader_events_forward_to_;
};
typedef readert<> reader;

} // namespace libpgm
} // namespace pgm 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_PGM_LIBPGM_READER_HPP 
