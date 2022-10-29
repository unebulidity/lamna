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
///   File: attacher.hpp
///
/// Author: $author$
///   Date: 9/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_ATTACHER_HPP
#define _LAMNA_GUI_X11_ATTACHER_HPP

#include "lamna/gui/x11/x11.hpp"
#include "lamna/base/base.hpp"

namespace lamna {
namespace gui {
namespace x11 {

typedef implement_base attacher_implements;
///////////////////////////////////////////////////////////////////////
///  Class: attachert
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = int,
 TUnattached VUnattached = 0,
 typename TXDisplay = XDisplay,
 class TImplementBase = attacher_implements,
 class TImplements = xos::base::attachert
 <TAttached, TUnattached, VUnattached, TImplementBase> >

class _EXPORT_CLASS attachert: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TXDisplay XDisplay;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t attach(XDisplay* display, attached_t detached) {
        return (attached_t)(unattached);
    }
    virtual attached_t detach(XDisplay*& display) {
        display = 0;
        return (attached_t)(unattached);
    }
    virtual attached_t attached_to(XDisplay*& display) const {
        display = 0;
        return (attached_t)(unattached);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XDisplay* display() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_ATTACHER_HPP 
