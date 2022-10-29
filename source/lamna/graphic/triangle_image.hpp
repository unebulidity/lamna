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
///   File: triangle_image.hpp
///
/// Author: $author$
///   Date: 9/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_TRIANGLE_IMAGE_HPP
#define _LAMNA_GRAPHIC_TRIANGLE_IMAGE_HPP

#include "lamna/graphic/triangle.hpp"
#include "lamna/graphic/base_image.hpp"

namespace lamna {
namespace graphic {

typedef trianglet
<base_image, image_interface> triangle_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: triangle_imaget
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS triangle_image
: public triangle_image_extends {
public:
    typedef triangle_image_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    triangle_image
    (tImageInterface& image): Extends(image) {
    }
    virtual ~triangle_image() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef filled_trianglet
<base_image, image_interface> filled_triangle_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_triangle_imaget
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_triangle_image
: public filled_triangle_image_extends {
public:
    typedef filled_triangle_image_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filled_triangle_image
    (tImageInterface& image): Extends(image) {
    }
    virtual ~filled_triangle_image() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_TRIANGLE_IMAGE_HPP 

