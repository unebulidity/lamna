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
///   Date: 3/30/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_READER_EVENTS_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_READER_EVENTS_HPP

#include "lamna/graphic/image/format/tiff/libtiff/libtiff.hpp"
#include "lamna/graphic/image/pixel.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace tiff {
namespace libtiff {

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
    virtual bool on_TIFFPixel
    (lamna::graphic::image::pixel& pixel,
     byte_t* pixelByte, size_t pixelBytes, size_t imageRow, size_t imageCol,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_TRACE("on_TIFFPixel(" << p_to_string(pixelByte) << "," <<  pixelBytes << "," <<  imageRow << "," <<  imageCol << "," <<  imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_TIFFPixel
            (pixel, pixelByte, pixelBytes, imageRow, imageCol,
             imageLength, imageWidth, rowsPerStrip,
             samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_TRACE("...on_TIFFPixel(" << p_to_string(pixelByte) << "," <<  pixelBytes << "," <<  imageRow << "," <<  imageCol << "," <<  imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_TIFFPixel
    (byte_t* pixelByte, size_t pixelBytes, size_t imageRow, size_t imageCol,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_TRACE("on_TIFFPixel(" << p_to_string(pixelByte) << "," <<  pixelBytes << "," <<  imageRow << "," <<  imageCol << "," <<  imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_TIFFPixel
            (pixelByte, pixelBytes, imageRow, imageCol,
             imageLength, imageWidth, rowsPerStrip,
             samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_TRACE("...on_TIFFPixel(" << p_to_string(pixelByte) << "," <<  pixelBytes << "," <<  imageRow << "," <<  imageCol << "," <<  imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_begin_TIFFRow
    (byte_t* rowByte, size_t rowBytes, size_t imageRow,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_begin_TIFFRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  imageRow << "," <<  imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_begin_TIFFRow
            (rowByte, rowBytes, imageRow, imageLength, imageWidth,
             rowsPerStrip, samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_begin_TIFFRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  imageRow << "," <<  imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }
    virtual bool on_end_TIFFRow
    (byte_t* rowByte, size_t rowBytes, size_t imageRow,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_end_TIFFRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  imageRow << "," <<  imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_end_TIFFRow
            (rowByte, rowBytes, imageRow, imageLength, imageWidth,
             rowsPerStrip, samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_end_TIFFRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  imageRow << "," <<  imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }
    virtual bool on_TIFFRow
    (byte_t* rowByte, size_t rowBytes, size_t imageRow,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_TIFFRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  imageRow << "," <<  imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_TIFFRow
            (rowByte, rowBytes, imageRow, imageLength, imageWidth,
             rowsPerStrip, samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_TIFFRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  imageRow << "," <<  imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_begin_TIFFStrip
    (byte_t* stripByte, size_t stripBytes, size_t stripRows, tstrip_t strip,
     size_t imageRow, size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_begin_TIFFStrip(" << p_to_string(stripByte) << "," <<  stripBytes << "," <<  stripRows << "," <<  strip << "," <<  imageRow << "," << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_begin_TIFFStrip
            (stripByte, stripBytes, stripRows, strip,
             imageRow, imageLength, imageWidth, rowsPerStrip,
             samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_begin_TIFFStrip(" << p_to_string(stripByte) << "," <<  stripBytes << "," <<  stripRows << "," <<  strip << "," <<  imageRow << "," << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }
    virtual bool on_end_TIFFStrip
    (byte_t* stripByte, size_t stripBytes, size_t stripRows, tstrip_t strip,
     size_t imageRow, size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_end_TIFFStrip(" << p_to_string(stripByte) << "," <<  stripBytes << "," <<  stripRows << "," <<  strip << "," <<  imageRow << "," << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_end_TIFFStrip
            (stripByte, stripBytes, stripRows, strip,
             imageRow, imageLength, imageWidth, rowsPerStrip,
             samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_end_TIFFStrip(" << p_to_string(stripByte) << "," <<  stripBytes << "," <<  stripRows << "," <<  strip << "," <<  imageRow << "," << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }
    virtual bool on_TIFFStrip
    (byte_t* stripByte, size_t stripBytes, size_t stripRows, tstrip_t strip,
     size_t imageRow, size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_TIFFStrip(" << p_to_string(stripByte) << "," <<  stripBytes << "," <<  stripRows << "," <<  strip << "," <<  imageRow << "," << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_TIFFStrip
            (stripByte, stripBytes, stripRows, strip,
             imageRow, imageLength, imageWidth, rowsPerStrip,
             samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_TIFFStrip(" << p_to_string(stripByte) << "," <<  stripBytes << "," <<  stripRows << "," <<  strip << "," <<  imageRow << "," << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_begin_TIFFImage
    (size_t imageLength, size_t imageWidth,
     size_t rowsPerStrip, size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_begin_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_begin_TIFFImage
            (imageLength, imageWidth, rowsPerStrip, samplesPerPixel,
             bitsPerSample, planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_begin_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }
    virtual bool on_end_TIFFImage
    (size_t imageLength, size_t imageWidth,
     size_t rowsPerStrip, size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_end_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_end_TIFFImage
            (imageLength, imageWidth, rowsPerStrip, samplesPerPixel,
             bitsPerSample, planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_end_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }
    virtual bool on_TIFFImage
    (size_t imageLength, size_t imageWidth,
     size_t rowsPerStrip, size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        reader_eventst* forward_to = tiff_reader_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((forward_to)) {
            success = forward_to->on_TIFFImage
            (imageLength, imageWidth, rowsPerStrip, samplesPerPixel,
             bitsPerSample, planarConfiguration, photometricInterpretation);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual reader_eventst* forward_tiff_reader_events_to(reader_eventst* to) {
        return 0;
    }
    virtual reader_eventst* tiff_reader_events_forward_to() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef reader_eventst<> reader_events;

} // namespace libtiff 
} // namespace tiff 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 


#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_READER_EVENTS_HPP 
        

