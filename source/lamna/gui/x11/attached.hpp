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
///   File: attached.hpp
///
/// Author: $author$
///   Date: 9/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_ATTACHED_HPP
#define _LAMNA_GUI_X11_ATTACHED_HPP

#include "lamna/gui/x11/attacher.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef base attached_extends;
///////////////////////////////////////////////////////////////////////
///  Class: attachedt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = int,
 TUnattached VUnattached = 0,
 typename TXDisplay = XDisplay,
 class TImplements = attachert
 <TAttached, TUnattached, VUnattached, TXDisplay, attacher_implements>,
 class TExtends = xos::base::attachedt
 <TAttached, TUnattached, VUnattached, TImplements, attached_extends> >

class _EXPORT_CLASS attachedt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TXDisplay XDisplay;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    attachedt
    (XDisplay* display, attached_t detached = ((attached_t)unattached))
    : Extends(detached), display_(display) {
    }
    attachedt(attached_t detached = ((attached_t)unattached))
    : Extends(detached), display_(0) {
    }
    virtual ~attachedt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t attach(XDisplay* display, attached_t detached) {
        this->display_ = display;
        this->attached_to_ = detached;
        return this->attached_to_;
    }
    virtual attached_t detach(XDisplay*& display) {
        attached_t detached = this->attached_to_;
        display = this->display_;
        this->display_ = 0;
        this->attached_to_ = ((attached_t)unattached);
        return detached;
    }
    virtual attached_t attached_to(XDisplay*& display) const {
        display = this->display_;
        return this->attached_to_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t attach(attached_t detached) {
        this->display_ = 0;
        this->attached_to_ = detached;
        return this->attached_to_;
    }
    virtual attached_t detach() {
        attached_t detached = this->attached_to_;
        this->display_ = 0;
        this->attached_to_ = ((attached_t)unattached);
        return detached;
    }
    virtual attached_t attached_to() const {
        return this->attached_to_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XDisplay* display() const {
        return display_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    XDisplay* display_;
};

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_ATTACHED_HPP 
