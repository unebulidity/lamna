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
///   Date: 3/30/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_READER_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_READER_HPP

#include "lamna/graphic/image/format/tiff/libtiff/reader_events.hpp"
#include "lamna/graphic/image/format/tiff/libtiff/opened.hpp"

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace tiff {
namespace libtiff {

typedef reader_events reader_implements;
typedef opened reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = reader_implements, class TExtends = reader_extends>
class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef readert Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert
    (reader_events* tiff_reader_events_forward_to = 0)
    : tiff_reader_events_forward_to_(tiff_reader_events_forward_to),
      paletteRed_(0), paletteGreen_(0), paletteBlue_(0),
      paletteColors_(0), paletteBitsPerColor_(0),
      bytesPerStrip_(0), bytesPerRow_(0), bytesPerPixel_(0),
      on_TIFFPixel_(0), stripByte_(0), stripBytes_(0) {
    }
    virtual ~readert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool read(const char* file) {
        bool success = false;
        if ((success = this->open(file))) {
            if (!(on_read(file))) {
                success = false;
            }
            if (!(this->close())) {
                success = false;
            }
        }
        return success;
    }
    virtual bool on_read(const char* file) {
        bool success = false;
        ssize_t imageLength, imageWidth, rowsPerStrip,
                samplesPerPixel, bitsPerSample;
        int16_t planarConfiguration, photometricInterpretation;

        if (0 < (imageLength = this->ImageLength())) {
            if (0 < (imageWidth = this->ImageWidth())) {
                if (0 < (rowsPerStrip = this->RowsPerStrip())) {
                    if (0 < (samplesPerPixel = this->SamplesPerPixel())) {
                        if (0 < (bitsPerSample = this->BitsPerSample())) {
                            if (0 < (planarConfiguration = this->PlanarConfiguration())) {
                                if (0 < (photometricInterpretation = this->PhotometricInterpretation())) {
                                    if ((this->on_TIFFImage
                                         (imageLength, imageWidth, rowsPerStrip,
                                          samplesPerPixel, bitsPerSample,
                                          planarConfiguration, photometricInterpretation))) {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::on_TIFFPixel;
    virtual bool on_16BitPalette16Bit_TIFFPixel
    (byte_t* pixelByte, size_t pixelBytes, size_t imageRow, size_t imageCol,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_8BitPalette16Bit_TIFFPixel
    (byte_t* pixelByte, size_t pixelBytes, size_t imageRow, size_t imageCol,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_16BitPalette8Bit_TIFFPixel
    (byte_t* pixelByte, size_t pixelBytes, size_t imageRow, size_t imageCol,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_8BitPalette8Bit_TIFFPixel
    (byte_t* pixelByte, size_t pixelBytes, size_t imageRow, size_t imageCol,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_32BitRGB_TIFFPixel
    (byte_t* pixelByte, size_t pixelBytes, size_t imageRow, size_t imageCol,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_24BitRGB_TIFFPixel
    (byte_t* pixelByte, size_t pixelBytes, size_t imageRow, size_t imageCol,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        lamna::graphic::image::rgb::pixel pixel
        (pixelByte[0], pixelByte[1], pixelByte[2], 255);
        success = this->on_TIFFPixel
        (pixel, pixelByte, pixelBytes, imageRow, imageCol,
         imageLength, imageWidth, rowsPerStrip,
         samplesPerPixel, bitsPerSample,
         planarConfiguration, photometricInterpretation);
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_TIFFPixel
    (byte_t* pixelByte, size_t pixelBytes, size_t imageRow, size_t imageCol,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = false;
        if ((on_TIFFPixel_)) {
            success = (this->*on_TIFFPixel_)
            (pixelByte, pixelBytes, imageRow, imageCol,
             imageLength, imageWidth, rowsPerStrip,
             samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation);
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_TIFFRow
    (byte_t* rowByte, size_t rowBytes, size_t imageRow,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        if ((success = this->on_begin_TIFFRow
            (rowByte, rowBytes, imageRow, imageLength, imageWidth,
             rowsPerStrip, samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation))) {

            size_t imageCol = 0, pixelBytes = bytesPerPixel_;
            byte_t* pixelByte = 0;

            for (pixelByte = rowByte, imageCol = 0;
                 imageCol < imageWidth; ++imageCol, pixelByte += pixelBytes) {
                if (!(this->on_TIFFPixel
                      (pixelByte, pixelBytes, imageRow, imageCol,
                       imageLength, imageWidth, rowsPerStrip,
                       samplesPerPixel, bitsPerSample,
                       planarConfiguration, photometricInterpretation))) {
                    success = false;
                    break;
                }
            }
            if (!(this->on_end_TIFFRow
                (rowByte, rowBytes, imageRow, imageLength, imageWidth,
                 rowsPerStrip, samplesPerPixel, bitsPerSample,
                 planarConfiguration, photometricInterpretation))) {
                success = false;
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_TIFFStrip
    (byte_t* stripByte, size_t stripBytes, size_t stripRows, tstrip_t strip,
     size_t imageRow, size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        if ((success = this->on_begin_TIFFStrip
            (stripByte, stripBytes, stripRows, strip,
             imageRow, imageLength, imageWidth, rowsPerStrip,
             samplesPerPixel, bitsPerSample,
             planarConfiguration, photometricInterpretation))) {

            size_t stripRow = 0, rowBytes = bytesPerRow_;
            byte_t* rowByte = 0;

            for (rowByte = stripByte, stripRow = 0;
                 stripRow < stripRows; ++stripRow, rowByte += rowBytes, ++imageRow) {
                if (!(this->on_TIFFRow
                      (rowByte, rowBytes, imageRow, imageLength, imageWidth,
                       rowsPerStrip, samplesPerPixel, bitsPerSample,
                       planarConfiguration, photometricInterpretation))) {
                    success = false;
                    break;
                }
            }
            if (!(this->on_end_TIFFStrip
                (stripByte, stripBytes, stripRows, strip,
                 imageRow, imageLength, imageWidth, rowsPerStrip,
                 samplesPerPixel, bitsPerSample,
                 planarConfiguration, photometricInterpretation))) {
                success = false;
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_PLANARCONFIG_CONTIG_TIFFImage
    (size_t imageLength, size_t imageWidth,
     size_t rowsPerStrip, size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        ssize_t length = 0;
        LAMNA_LOG_MESSAGE_DEBUG("on_PLANARCONFIG_CONTIG_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        LAMNA_LOG_MESSAGE_DEBUG("switch(bitsPerSample = " << bitsPerSample << ")...");
        switch(bitsPerSample) {
        case 8:
            LAMNA_LOG_MESSAGE_DEBUG("...switch(bitsPerSample = " << bitsPerSample << ") case 8:");
            bytesPerStrip_ = rowsPerStrip
            * (bytesPerRow_ = (imageWidth
               * (bytesPerPixel_ = samplesPerPixel)));

            LAMNA_LOG_MESSAGE_DEBUG("switch(photometricInterpretation = " << photometricInterpretation << ")...");
            switch(photometricInterpretation) {
            case PHOTOMETRIC_RGB:
                LAMNA_LOG_MESSAGE_DEBUG("...switch(photometricInterpretation = " << photometricInterpretation << ") case PHOTOMETRIC_RGB:");
                on_TIFFPixel_ = &Derives::on_24BitRGB_TIFFPixel;
                break;

            case PHOTOMETRIC_PALETTE:
                LAMNA_LOG_MESSAGE_DEBUG("...switch(photometricInterpretation = " << photometricInterpretation << ") case PHOTOMETRIC_PALETTE:");
                if (0 < (length = this->ColorMapSpanned
                    (paletteBitsPerColor_, paletteRed_, paletteGreen_, paletteBlue_, bitsPerSample))) {
                    paletteColors_ = length;

                    LAMNA_LOG_MESSAGE_DEBUG("switch(paletteBitsPerColor_ = " << paletteBitsPerColor_ << ")...");
                    switch(paletteBitsPerColor_) {
                    case 8:
                        LAMNA_LOG_MESSAGE_DEBUG("...switch(paletteBitsPerColor_ = " << paletteBitsPerColor_ << ") case 8:");
                        on_TIFFPixel_ = &Derives::on_8BitPalette8Bit_TIFFPixel;
                        break;

                    case 16:
                        LAMNA_LOG_MESSAGE_DEBUG("...switch(paletteBitsPerColor_ = " << paletteBitsPerColor_ << ") case 16:");
                        on_TIFFPixel_ = &Derives::on_16BitPalette8Bit_TIFFPixel;
                        break;

                    default:
                        LAMNA_LOG_MESSAGE_ERROR("...unimplemented paletteBitsPerColor_ = " << paletteBitsPerColor_ << " on_PLANARCONFIG_CONTIG_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
                        success = false;
                        break;
                    }
                } else {
                    LAMNA_LOG_ERROR("...unexpected " << length << "on his->ColorMapSpanned(paletteBitsPerColor_, paletteRed_, paletteGreen_, paletteBlue_, bitsPerSample)");
                    success = false;
                }
                break;
            default:
                LAMNA_LOG_MESSAGE_ERROR("...unimplemented on_PLANARCONFIG_CONTIG_TIFFImage(..., uint16_t photometricInterpretation = " <<  photometricInterpretation << ")");
                success = false;
                break;
            }
            break;
        default:
            LAMNA_LOG_MESSAGE_DEBUG("...switch(bitsPerSample = " << bitsPerSample << ") default:");
            bytesPerPixel_ = (samplesPerPixel*bitsPerSample+7)/8;
            bytesPerRow_ = (imageWidth*samplesPerPixel*bitsPerSample+7)/8;
            bytesPerStrip_ = bytesPerRow_*rowsPerStrip;
            break;
        }
        if ((success)) {
            if (0 < (stripBytes_ = this->StripSize())) {
                if (stripBytes_ <= (length = stripBuffer_.set_length(stripBytes_))) {
                    if ((stripByte_ = stripBuffer_.elements())) {
                        for (size_t row = 0; row < imageLength; row += rowsPerStrip) {
                            size_t stripRows = (row + rowsPerStrip > imageLength)
                                               ?(imageLength - row):(rowsPerStrip),
                                   strip = (0 <= (length = this->ComputeStrip(row, 0)))
                                                 ?((size_t)(length)):(0);

                            LAMNA_LOG_MESSAGE_DEBUG("this->ReadEncodedStrip(strip = " << strip << ", stripByte_ = " << p_to_string(stripByte_) << ", stripBytes_ = " << stripBytes_ << ") stripRows = " << stripRows << "...");
                            if (0 < (length = this->ReadEncodedStrip(strip, stripByte_, stripBytes_))) {
                                LAMNA_LOG_MESSAGE_DEBUG("...length = " << length << " on this->ReadEncodedStrip(strip = " << strip << ", stripByte_ = " << p_to_string(stripByte_) << ", stripBytes_ = " << stripBytes_ << ") stripRows = " << stripRows << "");
                                if (!(this->on_TIFFStrip
                                      (stripByte_, stripBytes_, stripRows, strip,
                                       row, imageLength, imageWidth, rowsPerStrip,
                                       samplesPerPixel, bitsPerSample,
                                       planarConfiguration, photometricInterpretation))) {
                                    success = false;
                                    break;
                                }
                            } else {
                                LAMNA_LOG_MESSAGE_ERROR("...failed length = " << length << " on this->ReadEncodedStrip(strip = " << strip << ", stripByte_ = " << p_to_string(stripByte_) << ", stripBytes_ = " << stripBytes_ << ") stripRows = " << stripRows << "");
                            }
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_PLANARCONFIG_CONTIG_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_PLANARCONFIG_SEPARATE_TIFFImage
    (size_t imageLength, size_t imageWidth,
     size_t rowsPerStrip, size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = false;
        //LAMNA_LOG_MESSAGE_DEBUG("on_PLANARCONFIG_SEPARATE_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        LAMNA_LOG_MESSAGE_ERROR("...unimplemented on_PLANARCONFIG_SEPARATE_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        //LAMNA_LOG_MESSAGE_DEBUG("...on_PLANARCONFIG_SEPARATE_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_TIFFImage
    (size_t imageLength, size_t imageWidth,
     size_t rowsPerStrip, size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation) {
        bool success = true;
        LAMNA_LOG_MESSAGE_DEBUG("on_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")...");
        if ((success = this->on_begin_TIFFImage
             (imageLength, imageWidth, rowsPerStrip, samplesPerPixel,
              bitsPerSample, planarConfiguration, photometricInterpretation))) {

            switch (planarConfiguration) {
            case PLANARCONFIG_CONTIG:
                success = on_PLANARCONFIG_CONTIG_TIFFImage
                (imageLength, imageWidth, rowsPerStrip,
                 samplesPerPixel, bitsPerSample,
                 planarConfiguration, photometricInterpretation);
                break;
            case PLANARCONFIG_SEPARATE:
                success = on_PLANARCONFIG_SEPARATE_TIFFImage
                (imageLength, imageWidth, rowsPerStrip,
                 samplesPerPixel, bitsPerSample,
                 planarConfiguration, photometricInterpretation);
                break;
            default:
                LAMNA_LOG_ERROR("...unexpected on_TIFFImage(..., uint16_t planarConfiguration = " << planarConfiguration << ",...)");
                success = false;
                break;
            }
            if (!(this->on_end_TIFFImage
                 (imageLength, imageWidth, rowsPerStrip, samplesPerPixel,
                  bitsPerSample, planarConfiguration, photometricInterpretation))) {
                success = false;
            }
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_TIFFImage(" << imageLength << "," <<  imageWidth << "," <<  rowsPerStrip << "," <<  samplesPerPixel << "," <<  bitsPerSample << "," <<  planarConfiguration << "," <<  photometricInterpretation << ")");
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual reader_events* forward_tiff_reader_events_to(reader_events* to) {
        tiff_reader_events_forward_to_ = to;
        return tiff_reader_events_forward_to_;
    }
    virtual reader_events* tiff_reader_events_forward_to() const {
        return tiff_reader_events_forward_to_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef bool (Derives::*on_TIFFPixel_t)
    (byte_t* pixelByte, size_t pixelBytes, size_t imageRow, size_t imageCol,
     size_t imageLength, size_t imageWidth, size_t rowsPerStrip,
     size_t samplesPerPixel, size_t bitsPerSample,
     uint16_t planarConfiguration, uint16_t photometricInterpretation);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    reader_events* tiff_reader_events_forward_to_;
    uint16_t *paletteRed_, *paletteGreen_, *paletteBlue_;
    size_t paletteColors_, paletteBitsPerColor_,
           bytesPerStrip_, bytesPerRow_, bytesPerPixel_;
    on_TIFFPixel_t on_TIFFPixel_;
    byte_t* stripByte_;
    size_t stripBytes_;
    byte_array stripBuffer_;
};
typedef readert<> reader;

} // namespace libtiff 
} // namespace tiff 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_TIFF_LIBTIFF_READER_HPP 
        

