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
///   File: atom.hpp
///
/// Author: $author$
///   Date: 9/10/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_X11_ATOM_HPP
#define _LAMNA_GUI_X11_ATOM_HPP

#include "lamna/gui/x11/created.hpp"
#include "lamna/gui/x11/attached.hpp"
#include "lamna/gui/x11/attacher.hpp"

#define LAMNA_GUI_X11_ATOM_NAME_WM_PROTOCOLS "WM_PROTOCOLS"
#define LAMNA_GUI_X11_ATOM_NAME_WM_DELETE_WINDOW "WM_DELETE_WINDOW"

namespace lamna {
namespace gui {
namespace x11 {

typedef xos::base::creatort<implement_base> atom_creator;
typedef attachert<XAtom, int, None, XDisplay, atom_creator> atom_attacher;
typedef attachedt<XAtom, int, None, XDisplay, atom_attacher> atom_attached;
typedef createdt<XAtom, int, None, XDisplay, atom_attacher, atom_attached> atom_created;
typedef atom_attacher atom_implements;
typedef atom_created atom_extends;
///////////////////////////////////////////////////////////////////////
///  Class: atomt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = atom_implements, class TExtends = atom_extends>

class _EXPORT_CLASS atomt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    atomt
    (XDisplay* display = 0, XAtom detached = None, bool is_created = false)
    : Extends(display, detached, is_created) {
    }
    virtual ~atomt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (XDisplay& display, const char* name, bool only_exists = false) {
        XAtom detached = None;
        if (None != (detached = create_attached(display, name, only_exists))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        XDisplay* display = 0;
        XAtom detached = None;
        if (None != (this->detach(display))) {
            if ((display)) {
                if ((destroy_detached(*display, detached))) {
                    return true;
                }
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XAtom create_attached
    (XDisplay& display, const char* name, bool only_exists = false) {
        if ((this->destroyed())) {
            XAtom detached = None;
            if (None != (detached = create_detached(display, name, only_exists))) {
                this->attach(&display, detached);
                return detached;
            }
        }
        return None;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual XAtom create_detached
    (XDisplay& display, const char* name, bool only_exists = false) const {
        if ((name)) {
            XAtom detached = None;
            LAMNA_LOG_MESSAGE_DEBUG("XInternAtom(..., name = \"" << name << "\", only_if_exists = " << ((only_exists)?("True"):("False")) << ")...");
            if ((detached = XInternAtom
                 (&display, name, (Bool)((only_exists)?(True):(False))))) {
                LAMNA_LOG_MESSAGE_DEBUG("...XInternAtom(..., name = \"" << name << "\", only_if_exists = " << ((only_exists)?("True"):("False")) << ")");
                return detached;
            } else {
                LAMNA_LOG_ERROR("failed None == XInternAtom(..., name = \"" << name << "\", only_if_exists = " << ((only_exists)?("True"):("False")) << ")");
            }
        }
        return None;
    }
    virtual bool destroy_detached(XDisplay& display, XAtom detached) const {
        if (None != (detached)) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef atomt<> atom;

} // namespace x11 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_X11_ATOM_HPP 
