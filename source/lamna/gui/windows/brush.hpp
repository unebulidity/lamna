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
///   File: brush.hpp
///
/// Author: $author$
///   Date: 9/6/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WINDOWS_BRUSH_HPP
#define _LAMNA_GUI_WINDOWS_BRUSH_HPP

#include "lamna/base/base.hpp"

namespace lamna {
namespace gui {
namespace windows {

typedef HBRUSH brush_attached_t;
typedef xos::base::creatort<implement_base> brush_creator;
typedef xos::base::attachert<brush_attached_t, int, 0, brush_creator> brush_attacher;
typedef xos::base::attachedt<brush_attached_t, int, 0, brush_attacher, base> brush_attached;
typedef xos::base::createdt<brush_attached_t, int, 0, brush_attacher, brush_attached> brush_created;
typedef brush_attacher brush_implements;
typedef brush_created brush_extends;
///////////////////////////////////////////////////////////////////////
///  Class: brusht
///////////////////////////////////////////////////////////////////////
template
<class TImplements = brush_implements, class TExtends = brush_extends>

class _EXPORT_CLASS brusht: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    brusht(brush_attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    brusht(const COLORREF& crColor) {
        if (!(create(crColor))) {
            LAMNA_LOG_ERROR("failed on create(crColor)) throwing failed_to_create...");
            xos::base::creator_exception e = xos::base::failed_to_create;
            throw(e);
        }
    }
    virtual ~brusht() {
        if (!(this->destroyed())) {
            LAMNA_LOG_ERROR("failed on this->destroyed()) throwing failed_to_destroy...");
            xos::base::creator_exception e = xos::base::failed_to_destroy;
            throw(e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create(const COLORREF& crColor) {
        brush_attached_t detached = 0;
        if ((detached = create_attached(crColor))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        brush_attached_t detached = 0;
        if ((detached = this->detach())) {
            if ((destroy_detached(detached))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual brush_attached_t create_attached(const COLORREF& crColor) {
        brush_attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(crColor))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual brush_attached_t create_detached(const COLORREF& crColor) const {
        brush_attached_t detached = 0;
        if (!(detached = CreateSolidBrush(crColor))) {
            LAMNA_LOG_ERROR("failed " << GetLastError() << " on CreateSolidBrush()");
        }
        return detached;
    }
    virtual bool destroy_detached(brush_attached_t detached) const {
        HGDIOBJ hObject = 0;
        if ((hObject = ((HGDIOBJ)detached))) {
            if ((DeleteObject(hObject))) {
                return true;
            } else {
                LAMNA_LOG_ERROR("failed " << GetLastError() << " on DeleteObject()");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef brusht<> brush;

} // namespace windows 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WINDOWS_BRUSH_HPP 
