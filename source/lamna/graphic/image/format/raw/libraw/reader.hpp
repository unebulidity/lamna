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
///   Date: 3/28/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_READER_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_READER_HPP

#include "lamna/graphic/image/format/raw/libraw/reader_events.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace raw {
namespace libraw {

typedef rgb::reader_events reader_implements;
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

    typedef rgb::filter filter_t;
    typedef rgb::filter::pattern_t pattern_t;
    typedef rgb::reader_events reader_events;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert
    (reader_events* libraw_reader_events_forward_to = 0)
    : libraw_reader_events_forward_to_(libraw_reader_events_forward_to) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool read(const char* file) {
        bool success = false;
        int err = 0;
        if ((file)) {
            LAMNA_LOG_MESSAGE_DEBUG("libraw_.open_file(file = \"" << file << "\")...");
            if (LIBRAW_SUCCESS == (err = libraw_.open_file(file))) {
                LAMNA_LOG_MESSAGE_DEBUG("...libraw_.open_file(file = \"" << file << "\")");
                if ((success = on_open())) {
                    return true;
                }
                LAMNA_LOG_MESSAGE_DEBUG("libraw_.recycle()...");
                libraw_.recycle();
            } else {
                LAMNA_LOG_MESSAGE_ERROR
                ("...failed " << err << " (\"" << libraw_.strerror(err) << "\") on libraw_.open_file(file = \"" << file << "\")");
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_open() {
        bool success = false;
        int err = 0;
        LAMNA_LOG_MESSAGE_DEBUG("libraw_.unpack()...");
        if (LIBRAW_SUCCESS == (libraw_.unpack())) {
            LAMNA_LOG_MESSAGE_DEBUG("...libraw_.unpack()");
            success = on_unpack();
        } else {
            LAMNA_LOG_MESSAGE_ERROR
            ("...failed " << err << " (\"" << libraw_.strerror(err) << "\") on libraw_.unpack()");
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_unpack() {
        bool success = false;
        int err = 0;
        libraw_data_t& imgdata = libraw_.imgdata;
        libraw_rawdata_t& rawdata = imgdata.rawdata;
        size_t height = rawdata.sizes.raw_height,
               width = rawdata.sizes.raw_width,
               stride = rawdata.sizes.raw_pitch;
        ushort* image = rawdata.raw_image;
        filter_t filter;
        pattern_t pattern;

        LAMNA_LOG_MESSAGE_DEBUG("height = " << height << ", width = " << width << ", stride = " << stride << "");
        for (int by = 0; by < 2; ++by) {
            for (int bx = 0; bx < 2; ++bx) {
                filter_t::which_t c = libraw_.COLOR(by, bx);
                LAMNA_LOG_MESSAGE_DEBUG("COLOR(row = " << by << ", col = " << bx << ") [" << by << "," << bx << "] = " << c << " (" << (filter.name_of(c)) << ")");
                pattern[((by << 1) | bx)] = (c != filter_t::green2)?(c):(filter_t::green);
            }
        }
        if ((image)) {
            success = this->on_libraw_unpack_image
            (height, width, stride, image, pattern, imgdata);
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual reader_events* forward_libraw_reader_events(reader_events* to) {
        libraw_reader_events_forward_to_ = to;
        return libraw_reader_events_forward_to_;
    }
    virtual reader_events* libraw_reader_events_forward_to() const {
        return libraw_reader_events_forward_to_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    reader_events* libraw_reader_events_forward_to_;
    LibRaw libraw_;
};
typedef readert<> reader;

} // namespace libraw
} // namespace raw 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_READER_HPP 
