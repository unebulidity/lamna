///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: image_object.hpp
///
/// Author: $author$
///   Date: 6/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_OBJECT_HPP
#define _LAMNA_GRAPHIC_IMAGE_OBJECT_HPP

#include "lamna/graphic/image.hpp"
#include "lamna/graphic/list.hpp"

namespace lamna {
namespace graphic {

class _EXPORT_CLASS image_object_interface;
class _EXPORT_CLASS image_object_item;

typedef list_itemt<image_object_item> image_object_item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: image_object_item
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS image_object_item: public image_object_item_extends {
public:
    typedef image_object_item_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    image_object_item(image_object_interface& imageObject)
    : m_imageObject(imageObject) {
    }
    virtual ~image_object_item() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    image_object_interface& m_imageObject;
};

///////////////////////////////////////////////////////////////////////
///  Class: image_object_interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS image_object_interface: virtual public image_interface {
public:
    typedef image_interface Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageInterface* SelectAsImage() {
        tImageInterface* prevImage = 0;
        return prevImage;
    }
    virtual tImageInterface* SetAsImage() {
        tImageInterface* prevImage = 0;
        return prevImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageInterface* SetImage(tImageInterface* image) {
        tImageInterface* prevImage = Image();
        return prevImage;
    }
    virtual tImageInterface* Image() const {
        tImageInterface* image = 0;
        return image;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetSize(tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError OnSetSize(tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tSize Width() const {
        return 0;
    }
    virtual tSize Height() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef image_object_interface image_object_implements;
typedef base image_object_extends;
///////////////////////////////////////////////////////////////////////
///  Class: image_object
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS image_object
: virtual public image_object_implements, private image_object_extends {
public:
    typedef image_object_implements Implements;
    typedef image_object_extends Extends;

    image_object_item m_item;
    image_interface& m_image;
    image_interface* m_selectedImage;
    tSize m_width, m_height;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    image_object
    (image_interface& image,
     tSize width = 0, tSize height = 0,
     image_interface* selectedImage = 0)
    : m_item(*this),
      m_image(image),
      m_width(width),
      m_height(height),
      m_selectedImage(selectedImage) {
    }
    virtual ~image_object() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageInterface* SelectAsImage() {
        tImageInterface* prevImage = 0;
        prevImage = m_image.SelectImage(this);
        return prevImage;
    }
    virtual tImageInterface* SetAsImage() {
        tImageInterface* prevImage = 0;
        prevImage = m_image.SetImage(this);
        return prevImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageInterface* SetImage(tImageInterface* image) {
        tImageInterface* prevImage = Image();
        m_selectedImage = image;
        return prevImage;
    }
    virtual tImageInterface* Image() const {
        tImageInterface* image = 0;
        image = m_selectedImage;
        return image;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError SetSize(tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        m_width = width;
        m_height = height;
        error = OnSetSize(width, height);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tSize Width() const {
        return m_width;
    }
    virtual tSize Height() const {
        return m_height;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_OBJECT_HPP 
        

