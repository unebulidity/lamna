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
///   File: region.hpp
///
/// Author: $author$
///   Date: 9/16/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_REGION_HPP
#define _LAMNA_GUI_X11_REGION_HPP

#include "lamna/gui/x11/rectangle.hpp"
#include "lamna/gui/x11/created.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef xos::base::creatort<implement_base> region_creator;
typedef xos::base::attachert<XRegion, int, 0, region_creator> region_attacher;
typedef xos::base::attachedt<XRegion, int, 0, region_attacher> region_attached;
typedef xos::base::createdt<XRegion, int, 0, region_attacher, region_attached> region_created;
typedef region_attacher region_implements;
typedef region_created region_extends;
///////////////////////////////////////////////////////////////////////
///  Class: regiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = region_implements, class TExtends = region_extends>

class _EXPORT_CLASS regiont: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    regiont
    (XRegion detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~regiont() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        XRegion detached = 0;
        if ((detached = create_attached())) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        XRegion detached = 0;
        if ((detached = this->detach())) {
            if ((this->destroy_detached(detached))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XRegion create_attached() {
        if ((this->destroyed())) {
            XRegion detached = 0;
            if ((detached = create_detached())) {
                this->attach(detached);
                return detached;
            }
        }
        return 0;
    }
    virtual XRegion create_detached() const {
        XRegion detached = 0;
        if ((detached = XCreateRegion())) {
            return detached;
        } else {
            LAMNA_LOG_ERROR("failed 0 == XCreateRegion()");
        }
        return 0;
    }
    virtual bool destroy_detached(XRegion detached) const {
        if ((detached)) {
            XDestroyRegion(detached);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef regiont<> region;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_REGION_HPP 
