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
///   File: elliptical_rounded_rectangle_image.hpp
///
/// Author: $author$
///   Date: 9/9/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_ELLIPTICAL_ROUNDED_RECTANGLE_IMAGE_HPP
#define _LAMNA_GRAPHIC_ELLIPTICAL_ROUNDED_RECTANGLE_IMAGE_HPP

#include "lamna/graphic/elliptical_rounded_rectangle.hpp"
#include "lamna/graphic/base_image.hpp"

namespace lamna {
namespace graphic {

typedef elliptical_rounded_rectanglet
<base_image, image_interface> elliptical_rounded_rectangle_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: elliptical_rounded_rectangle_imaget
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS elliptical_rounded_rectangle_image
: public elliptical_rounded_rectangle_image_extends {
public:
    typedef elliptical_rounded_rectangle_image_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    elliptical_rounded_rectangle_image
    (tImageInterface& image): Extends(image) {
    }
    virtual ~elliptical_rounded_rectangle_image() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef filled_elliptical_rounded_rectanglet
<base_image, image_interface> filled_elliptical_rounded_rectangle_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_elliptical_rounded_rectangle_imaget
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_elliptical_rounded_rectangle_image
: public filled_elliptical_rounded_rectangle_image_extends {
public:
    typedef filled_elliptical_rounded_rectangle_image_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filled_elliptical_rounded_rectangle_image
    (tImageInterface& image): Extends(image) {
    }
    virtual ~filled_elliptical_rounded_rectangle_image() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef hollowed_elliptical_rounded_rectanglet
<base_image, image_interface> hollowed_elliptical_rounded_rectangle_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: hollowed_elliptical_rounded_rectangle_imaget
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS hollowed_elliptical_rounded_rectangle_image
: public hollowed_elliptical_rounded_rectangle_image_extends {
public:
    typedef hollowed_elliptical_rounded_rectangle_image_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    hollowed_elliptical_rounded_rectangle_image
    (tImageInterface& image): Extends(image) {
    }
    virtual ~hollowed_elliptical_rounded_rectangle_image() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_ELLIPTICAL_ROUNDED_RECTANGLE_IMAGE_HPP 
