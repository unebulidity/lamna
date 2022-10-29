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
///   Date: 8/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_CAIRO_CONTEXT_HPP
#define _LAMNA_GUI_CAIRO_CONTEXT_HPP

#include "lamna/gui/cairo/cairo.hpp"

namespace lamna {
namespace gui {
namespace cairo {

typedef cairo_t* context_attached_t;
typedef xos::base::creatort<implement_base> context_creator;
typedef xos::base::attachert<context_attached_t, int, 0, context_creator> context_attacher;
typedef xos::base::attachedt<context_attached_t, int, 0, context_attacher, base> context_attached;
typedef xos::base::createdt<context_attached_t, int, 0, context_attacher, context_attached> context_created;
typedef context_attacher context_implements;
typedef context_created context_extends;
///////////////////////////////////////////////////////////////////////
///  Class: contextt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = context_implements, class TExtends = context_extends>

class _EXPORT_CLASS contextt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    contextt(context_attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~contextt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool destroy() {
        context_attached_t detached = 0;
        if ((detached = this->detach())) {
            return destroy_detached(detached);
        }
        return false;
    }
    virtual bool destroy_detached(context_attached_t detached) const {
        if ((detached)) {
            cairo_destroy(detached);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator context_attached_t() const {
        return this->attached_to();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef contextt<> context;

} // namespace cairo 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_CAIRO_CONTEXT_HPP 
