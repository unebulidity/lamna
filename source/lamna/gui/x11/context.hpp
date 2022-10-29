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
///   File: context.hpp
///
/// Author: $author$
///   Date: 9/10/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_CONTEXT_HPP
#define _LAMNA_GUI_X11_CONTEXT_HPP

#include "lamna/gui/x11/created.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef xos::base::creatort<implement_base> context_creator;
typedef attachert<XContext, int, None, XDisplay, context_creator> context_attacher;
typedef attachedt<XContext, int, None, XDisplay, context_attacher> context_attached;
typedef createdt<XContext, int, None, XDisplay, context_attacher, context_attached> context_created;
typedef context_attacher context_implements;
typedef context_created context_extends;
///////////////////////////////////////////////////////////////////////
///  Class: contextt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = context_implements, class TExtends = context_extends>

class _EXPORT_CLASS contextt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    contextt
    (XDisplay* display = 0, XContext detached = None, bool is_created = false)
    : Extends(display, detached, is_created) {
    }
    virtual ~contextt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create(XDisplay& display) {
        XContext detached = None;
        if (None != (detached = create_attached(display))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        XDisplay* display = 0;
        XContext detached = None;
        if (None != (detached = this->detach(display))) {
            if ((display)) {
                if ((destroy_detached(*display, detached))) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual XContext create_attached(XDisplay& display) {
        XContext detached = None;
        if (None != (detached = create_detached(display))) {
            this->attach(&display, detached);
            return detached;
        }
        return None;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XContext create_detached(XDisplay& display) const {
        XContext detached = None;
        if (None != (detached = XUniqueContext())) {
            return detached;
        } else {
            LAMNA_LOG_ERROR("failed None == XUniqueContext()");
        }
        return None;
    }
    virtual bool destroy_detached
    (XDisplay& display, XContext detached) const {
        if (None != (detached)) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef contextt<> context;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_CONTEXT_HPP 
