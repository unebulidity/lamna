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
///   File: rectangle_image.hpp
///
/// Author: $author$
///   Date: 9/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_RECTANGLE_IMAGE_HPP
#define _LAMNA_GRAPHIC_RECTANGLE_IMAGE_HPP

#include "lamna/graphic/rectangle.hpp"
#include "lamna/graphic/base_image.hpp"

namespace lamna {
namespace graphic {

typedef rectanglet
<base_image, image_interface> rectangle_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: rectangle_imaget
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS rectangle_image
: public rectangle_image_extends {
public:
    typedef rectangle_image_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    rectangle_image
    (tImageInterface& image): Extends(image) {
    }
    virtual ~rectangle_image() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef filled_rectanglet
<base_image, image_interface> filled_rectangle_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_rectangle_imaget
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_rectangle_image
: public filled_rectangle_image_extends {
public:
    typedef filled_rectangle_image_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filled_rectangle_image
    (tImageInterface& image): Extends(image) {
    }
    virtual ~filled_rectangle_image() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_RECTANGLE_IMAGE_HPP 
