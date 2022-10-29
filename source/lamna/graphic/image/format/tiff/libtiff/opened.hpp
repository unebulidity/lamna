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
///   File: opened.hpp
///
/// Author: $author$
///   Date: 3/29/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_OPENED_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_OPENED_HPP

#include "lamna/graphic/image/format/tiff/libtiff/libtiff.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace tiff {
namespace libtiff {

typedef TIFF* attached_t;
typedef xos::base::opener opener;
typedef xos::base::attachert<attached_t, int, 0, opener> attacher;
typedef xos::base::attachedt<attached_t, int, 0, attacher, base> attached;
typedef xos::base::openedt<attached_t, int, 0, attacher, attached> opened_extend;
typedef opener opened_implements;
typedef opened_extend opened_extends;
///////////////////////////////////////////////////////////////////////
///  Class: openedt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = opened_implements, class TExtends = opened_extends>
class _EXPORT_CLASS openedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef openedt tiff_error_handler_signals;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    openedt
    (attached_t detached = 0, bool is_open = false)
    : Extends(detached, is_open), old_opened_(the_opened(this)) {
        the_opened(this)  = this;
        old_TIFFWarning_ = TIFFSetWarningHandler(TIFFWarning);
        old_TIFFError_ = TIFFSetErrorHandler(TIFFError);
        old_TIFFWarningExt_ = TIFFSetWarningHandlerExt(TIFFWarningExt);
        old_TIFFErrorExt_ = TIFFSetErrorHandlerExt(TIFFErrorExt);
    }
    virtual ~openedt() {
        if (this == (the_opened(this))) {
            the_opened(this) = old_opened_;
            TIFFSetWarningHandler(old_TIFFWarning_);
            TIFFSetErrorHandler(old_TIFFError_);
            TIFFSetWarningHandlerExt(old_TIFFWarningExt_);
            TIFFSetErrorHandlerExt(old_TIFFErrorExt_);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open
    (const char* file_name,
     const char* file_mode = XOS_NADIR_XOS_IO_FILE_MODE_READ_BINARY) {
        attached_t detached = 0;
        if ((detached = open_attached(file_name, file_mode))) {
            return true;
        }
        return false;
    }
    virtual attached_t open_attached
    (const char* file_name,
     const char* file_mode = XOS_NADIR_XOS_IO_FILE_MODE_READ_BINARY) {
        attached_t detached = 0;
        if ((detached = open_detached(file_name, file_mode))) {
            this->attach_opened(detached);
        }
        return detached;
    }
    virtual attached_t open_detached
    (const char* file_name,
     const char* file_mode = XOS_NADIR_XOS_IO_FILE_MODE_READ_BINARY) const {
        attached_t detached = 0;

        if ((file_name) && (file_mode)) {

            LAMNA_LOG_MESSAGE_DEBUG("TIFFOpen(file_name = \"" << file_name << "\", file_mode = \"" << file_mode << "\")...");
            if ((detached = TIFFOpen(file_name, file_mode))) {
                LAMNA_LOG_MESSAGE_DEBUG("...TIFFOpen(file_name = \"" << file_name << "\", file_mode = \"" << file_mode << "\")");
                return detached;
            } else {
                LAMNA_LOG_MESSAGE_ERROR("...failed on TIFFOpen(file_name = \"" << file_name << "\", file_mode = \"" << file_mode << "\")");
            }
        } else {
            LAMNA_LOG_ERROR("...unexpected open_detached(const char* file_name = \"" << ((file_name)?(file_name):("")) << "\", const char* file_mode = \"" << ((file_mode)?(file_mode):("")) << "\")");
        }
        return detached;
    }
    virtual bool close_detached(attached_t detached)  const {
        bool success = true;
        if ((detached)) {
            LAMNA_LOG_MESSAGE_DEBUG("TIFFClose(detached)...");
            TIFFClose(detached);
            LAMNA_LOG_MESSAGE_DEBUG("...TIFFClose(detached)");
        } else {
            LAMNA_LOG_ERROR("...unexpected TIFFClose(detached = 0)");
            success = false;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadEncodedStrip
    (tstrip_t strip, tdata_t buf, tsize_t size) const {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            return TIFFReadEncodedStrip(detached, strip, buf, size);
        }
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ComputeStrip(uint32_t row, tsample_t sample) const {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            return TIFFComputeStrip(detached, row, sample);
        }
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t StripSize() const {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            return TIFFStripSize(detached);
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ColorMapSpanned
    (size_t& bitsPerColor,
     uint16_t*& red, uint16_t*& green, uint16_t*& blue, size_t bitsPerSample) const {
        ssize_t count = 0;
        if (0 < (count = ColorMap(red, green, blue, bitsPerSample))) {
            uint16_t r = 0, g = 0, b = 0;
            size_t color = 0;

            for (bitsPerColor = 8, color = 0; color < count; ++color) {

                r = red[color]; g = green[color]; b = blue[color];

                if ((((r) > 255)) || (((g) > 255)) || (((b) > 255))) {
                    bitsPerColor = 16;
                    break;
                }
            }
            return count;
        }
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ColorMap
    (uint16_t*& red, uint16_t*& green, uint16_t*& blue, size_t bitsPerSample) const {
        if ((ColorMap(red, green, blue))) {
            size_t count = (1 << bitsPerSample);
            return count;
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ScanlineSize() const {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            return TIFFScanlineSize(detached);
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int32_t SetImageLength(uint32_t to) {
        if ((SetField(TIFFTAG_IMAGELENGTH, &to))) {
            return to;
        }
        return -1;
    }
    virtual int32_t ImageLength() const {
        int32_t field = 0;
        if ((GetField(TIFFTAG_IMAGELENGTH, &field))) {
            return field;
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int32_t SetImageWidth(uint32_t to) {
        if ((SetField(TIFFTAG_IMAGEWIDTH, &to))) {
            return to;
        }
        return -1;
    }
    virtual int32_t ImageWidth() const {
        int32_t field = 0;
        if ((GetField(TIFFTAG_IMAGEWIDTH, &field))) {
            return field;
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int32_t SetRowsPerStrip(uint32_t to) {
        if ((SetField(TIFFTAG_ROWSPERSTRIP, &to))) {
            return to;
        }
        return -1;
    }
    virtual int32_t RowsPerStrip() const {
        int32_t field = 0;
        if ((GetField(TIFFTAG_ROWSPERSTRIP, &field))) {
            return field;
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int16_t SetSamplesPerPixel(uint16_t to) {
        if ((SetField(TIFFTAG_SAMPLESPERPIXEL, &to))) {
            return to;
        }
        return -1;
    }
    virtual int16_t SamplesPerPixel() const {
        int16_t field = 0;
        if ((GetField(TIFFTAG_SAMPLESPERPIXEL, &field))) {
            return field;
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int16_t SetBitsPerSample(uint16_t to) {
        if ((SetField(TIFFTAG_BITSPERSAMPLE, &to))) {
            return to;
        }
        return -1;
    }
    virtual int16_t BitsPerSample() const {
        int16_t field = 0;
        if ((GetField(TIFFTAG_BITSPERSAMPLE, &field))) {
            return field;
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int16_t SetPlanarConfiguration(uint16_t to) {
        if ((SetField(TIFFTAG_PLANARCONFIG, &to))) {
            return to;
        }
        return -1;
    }
    virtual int16_t PlanarConfiguration() const {
        int16_t field = 0;
        if ((GetField(TIFFTAG_PLANARCONFIG, &field))) {
            return field;
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int16_t SetPhotometricInterpretation(uint16_t to) {
        if ((SetField(TIFFTAG_PHOTOMETRIC, &to))) {
            return to;
        }
        return -1;
    }
    virtual int16_t PhotometricInterpretation() const {
        int16_t field = 0;
        if ((GetField(TIFFTAG_PHOTOMETRIC, &field))) {
            return field;
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetColorMap
    (uint16_t* red, uint16_t* green, uint16_t* blue) {
        if ((SetField(TIFFTAG_COLORMAP, &red, &green, &blue))) {
            return true;
        }
        return false;
    }
    virtual bool ColorMap
    (uint16_t*& red, uint16_t*& green, uint16_t*& blue) const {
        if ((GetField(TIFFTAG_COLORMAP, &red, &green, &blue))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetField(ttag_t tag, ...) {
        bool success = false;
        va_list va;
        va_start(va, tag);
        success = VSetField(tag, va);
        va_end(va);
        return success;
    }
    virtual bool VSetField(ttag_t tag, va_list va) {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            LAMNA_LOG_MESSAGE_DEBUG("TIFFVSetField(detached, tag = " << tag << ", va)...");
            if ((TIFFVSetField(detached, tag, va))) {
                LAMNA_LOG_MESSAGE_DEBUG("...TIFFVSetField(detached, tag = " << tag << ", va)");
                return true;
            } else {
                LAMNA_LOG_ERROR("...failed on TIFFVSetField(detached, tag = " << tag << ", va)");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetField(ttag_t tag, ...) const {
        bool success = false;
        va_list va;
        va_start(va, tag);
        success = VGetField(tag, va);
        va_end(va);
        return success;
    }
    virtual bool VGetField(ttag_t tag, va_list va) const {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            LAMNA_LOG_MESSAGE_DEBUG("TIFFVGetField(detached, tag = " << tag << ", va)...");
            if ((TIFFVGetField(detached, tag, va))) {
                LAMNA_LOG_MESSAGE_DEBUG("...TIFFVGetField(detached, tag = " << tag << ", va)");
                return true;
            } else {
                LAMNA_LOG_ERROR("...failed on TIFFVGetField(detached, tag = " << tag << ", va)");
            }
        }
        return false;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_TIFFError
    (const char* module, const char* format, va_list va) {
        tiff_error_handler_signals* to = 0;
        LAMNA_LOG_MESSAGE_DEBUG("on_TIFFError(const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)...");
        if ((to = tiff_error_handler_signals_foward_to())) {
            to->on_TIFFError(module, format, va);
        } else {
            LAMNA_LOG_MESSAGE_ERRORMFV("Error in module: " << module << ": ", format, va);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_TIFFError(const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)");
    }
    virtual void on_TIFFWarning
    (const char* module, const char* format, va_list va) {
        tiff_error_handler_signals* to = 0;
        LAMNA_LOG_MESSAGE_DEBUG("on_TIFFWarning(const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)...");
        if ((to = tiff_error_handler_signals_foward_to())) {
            to->on_TIFFWarning(module, format, va);
        } else {
            LAMNA_LOG_MESSAGE_WARNMFV("Warning in module: " << module << ": ", format, va);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_TIFFWarning(const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_TIFFErrorExt
    (thandle_t handle, const char* module, const char* format, va_list va) {
        tiff_error_handler_signals* to = 0;
        LAMNA_LOG_MESSAGE_DEBUG("on_TIFFErrorExt(thandle_t handle, const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)...");
        if ((to = tiff_error_handler_signals_foward_to())) {
            to->on_TIFFErrorExt(handle, module, format, va);
        } else {
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_TIFFErrorExt(thandle_t handle, const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)");
    }
    virtual void on_TIFFWarningExt
    (thandle_t handle, const char* module, const char* format, va_list va) {
        tiff_error_handler_signals* to = 0;
        LAMNA_LOG_MESSAGE_DEBUG("on_TIFFWarningExt(thandle_t handle, const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)...");
        if ((to = tiff_error_handler_signals_foward_to())) {
            to->on_TIFFWarningExt(handle, module, format, va);
        } else {
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_TIFFWarningExt(thandle_t handle, const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)");
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tiff_error_handler_signals*
    forward_tiff_error_handler_signals_to(tiff_error_handler_signals* to) {
        return 0;
    }
    virtual tiff_error_handler_signals* tiff_error_handler_signals_foward_to() {
        return 0;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static void TIFFError
    (const char* module, const char* format, va_list va) {
        openedt* opened = 0;
        LAMNA_LOG_MESSAGE_DEBUG("TIFFError(const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)...");
        if ((opened = the_opened(opened))) {
            opened->on_TIFFError(module, format, va);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...TIFFError(const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)");
    }
    static void TIFFWarning
    (const char* module, const char* format, va_list va) {
        openedt* opened = 0;
        LAMNA_LOG_MESSAGE_DEBUG("TIFFWarning(const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)...");
        if ((opened = the_opened(opened))) {
            opened->on_TIFFWarning(module, format, va);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...TIFFWarning(const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static void TIFFErrorExt
    (thandle_t handle, const char* module, const char* format, va_list va) {
        openedt* opened = 0;
        LAMNA_LOG_MESSAGE_DEBUG("TIFFErrorExt(thandle_t handle, const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)...");
        if ((opened = the_opened(opened))) {
            opened->on_TIFFErrorExt(handle, module, format, va);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...TIFFErrorExt(thandle_t handle, const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)");
    }
    static void TIFFWarningExt
    (thandle_t handle, const char* module, const char* format, va_list va) {
        openedt* opened = 0;
        LAMNA_LOG_MESSAGE_DEBUG("TIFFWarningExt(thandle_t handle, const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)...");
        if ((opened = the_opened(opened))) {
            opened->on_TIFFWarningExt(handle, module, format, va);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...TIFFWarningExt(thandle_t handle, const char* module = \"" << ((module)?(module):("")) << "\", const char* format = \"" << ((format)?(format):("")) << "\", va_list va)");
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static openedt*& the_opened(const openedt*) {
        static openedt* the_opened = 0;
        return the_opened;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    openedt* old_opened_;
    TIFFErrorHandler old_TIFFWarning_, old_TIFFError_;
    TIFFErrorHandlerExt old_TIFFWarningExt_, old_TIFFErrorExt_;
};
typedef openedt<> opened;

} // namespace libtiff 
} // namespace tiff 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_OPENED_HPP
