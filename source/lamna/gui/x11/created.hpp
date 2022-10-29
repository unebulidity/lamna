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
///   File: created.hpp
///
/// Author: $author$
///   Date: 9/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_CREATED_HPP
#define _LAMNA_GUI_X11_CREATED_HPP

#include "lamna/gui/x11/attached.hpp"

namespace lamna {
namespace gui {
namespace x11 {

///////////////////////////////////////////////////////////////////////
///  Class: createdt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = int,
 TUnattached VUnattached = 0,
 typename TXDisplay = XDisplay,
 class TImplements = attachert
 <TAttached, TUnattached, VUnattached, TXDisplay, attacher_implements>,
 class TExtendsBase = attachedt
 <TAttached, TUnattached, VUnattached, TXDisplay, TImplements, attached_extends>,
 class TExtends = xos::base::createdt
 <TAttached, TUnattached, VUnattached, TImplements, TExtendsBase> >

class _EXPORT_CLASS createdt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TExtendsBase ExtendsBase;

    typedef TXDisplay XDisplay;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    createdt
    (XDisplay* display = 0,
     attached_t detached = ((attached_t)unattached), bool is_created = false)
    : Extends(detached, is_created) {
        this->display_ = display;
    }
    virtual ~createdt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create(XDisplay* display) {
        attached_t detached = ((attached_t)unattached);
        if ((detached = this->create_attached(display)) != ((attached_t)unattached)) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        XDisplay* display = 0;
        attached_t detached = ((attached_t)unattached);
        if ((detached = detach(display)) != ((attached_t)unattached)) {
            if ((this->destroy_detached(display, detached))) {
                return true;
            }
        }
        return false;
    }
    virtual attached_t create_attached(XDisplay* display) {
        attached_t detached = ((attached_t)unattached);
        if ((this->destroyed())) {
            if ((detached = this->create_detached(display)) != ((attached_t)unattached)) {
                this->attach(display, detached);
            }
        }
        return detached;
    }
    virtual attached_t create_detached(XDisplay* display) const {
        attached_t detached = ((attached_t)unattached);
        return detached;
    }
    virtual bool destroy_detached
    (XDisplay* display, attached_t detached) const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t attach_created
    (XDisplay* display, attached_t detached, bool is_created = true) {
        attached_t attached = this->attach(display, detached);
        this->set_is_created(is_created);
        return attached;
    }
    virtual attached_t detach_created(XDisplay*& display, bool& is_created) {
        attached_t detached = ExtendsBase::detach(display);
        is_created = this->is_created();
        this->set_is_created(false);
        return detached;
    }
    virtual attached_t detach(XDisplay*& display) {
        attached_t detached = ExtendsBase::detach(display);
        this->set_is_created(false);
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_CREATED_HPP 
