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
///   Date: 3/18/2016
///////////////////////////////////////////////////////////////////////
#if !defined(_LAMNA_IMAGE_READER_EVENTS_HPP)

namespace lamna {
namespace image {

typedef implement_base reader_events_implements;
///////////////////////////////////////////////////////////////////////
///  Class: reader_events
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS reader_events: virtual public reader_events_implements {
public:
    typedef reader_events_implements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_reader_events_read_image_pixel(pixel_t& pixel, size_t col, size_t row, size_t plane, byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_read_image_pixel(" << pixel << "," <<  col << "," <<  row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_read_image_pixel(pixel, col, row, plane, bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_read_image_pixel(" << pixel << "," <<  col << "," <<  row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")");
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_reader_events_read_image_col(size_t col, size_t row, size_t plane, byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_read_image_col(" << col << "," <<  row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_read_image_col(col, row, plane, bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_read_image_col(" << col << "," <<  row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")");
        return true;
    }
    virtual bool on_reader_events_begin_read_image_col(size_t col, size_t row, size_t plane, byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_begin_read_image_col(" << col << "," <<  row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_begin_read_image_col(col, row, plane, bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_begin_read_image_col(" << col << "," <<  row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")");
        return true;
    }
    virtual bool on_reader_events_end_read_image_col(size_t col, size_t row, size_t plane, byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_end_read_image_col(" << col << "," <<  row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_end_read_image_col(col, row, plane, bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_end_read_image_col(" << col << "," <<  row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")");
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_reader_events_read_image_row
    (size_t row, size_t plane, byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_read_image_row(" << row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_read_image_row(row, plane, bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_read_image_row(" << row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")");
        return true;
    }
    virtual bool on_reader_events_begin_read_image_row
    (size_t row, size_t plane, byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_begin_read_image_row(" << row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_begin_read_image_row(row, plane, bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_begin_read_image_row(" << row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")");
        return true;
    }
    virtual bool on_reader_events_end_read_image_row
    (size_t row, size_t plane, byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_end_read_image_row(" << row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_end_read_image_row(row, plane, bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_end_read_image_row(" << row << "," <<  plane << "," <<  bytes << "," <<  size << "," <<  info << ")");
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_reader_events_read_image_plane
    (size_t plane, byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_read_image_plane(" << plane << "," <<  bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_read_image_plane(plane, bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_read_image_plane(" << plane << "," <<  bytes << "," <<  size << "," <<  info << ")");
        return true;
    }
    virtual bool on_reader_events_begin_read_image_plane
    (size_t plane, byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_begin_read_image_plane(" << plane << "," <<  bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_begin_read_image_plane(plane, bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_begin_read_image_plane(" << plane << "," <<  bytes << "," <<  size << "," <<  info << ")");
        return true;
    }
    virtual bool on_reader_events_end_read_image_plane
    (size_t plane, byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_end_read_image_plane(" << plane << "," <<  bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_end_read_image_plane(plane, bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_end_read_image_plane(" << plane << "," <<  bytes << "," <<  size << "," <<  info << ")");
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_reader_events_read_image
    (byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_read_image(" << bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_read_image(bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_read_image(" << bytes << "," <<  size << "," <<  info << ")");
        return true;
    }
    virtual bool on_reader_events_begin_read_image
    (byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_begin_read_image(" << bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_begin_read_image(bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_begin_read_image(" << bytes << "," <<  size << "," <<  info << ")");
        return true;
    }
    virtual bool on_reader_events_end_read_image
    (byte_t*& bytes, size_t& size, info_t& info) {
        reader_events* forward_to = reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_reader_events_end_read_image(" << bytes << "," <<  size << "," <<  info << ")...");
        if ((forward_to)) {
            return forward_to->on_reader_events_end_read_image(bytes, size, info);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_reader_events_end_read_image(" << bytes << "," <<  size << "," <<  info << ")");
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual reader_events* forward_reader_events_to(reader_events* to) {
        return 0;
    }
    virtual reader_events* reader_events_forward_to() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} //namespace image
} //namespace lamna

#endif // !defined(_LAMNA_IMAGE_READER_EVENTS_HPP)
