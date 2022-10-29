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
///   File: pattern.hpp
///
/// Author: $author$
///   Date: 7/31/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_CAIRO_PATTERN_HPP
#define _LAMNA_GUI_CAIRO_PATTERN_HPP

#include "lamna/gui/cairo/cairo.hpp"

namespace lamna {
namespace gui {
namespace cairo {

typedef cairo_pattern_t* pattern_attached_t;
typedef xos::base::creatort<implement_base> pattern_creator;
typedef xos::base::attachert<pattern_attached_t, int, 0, pattern_creator> pattern_attacher;
typedef xos::base::attachedt<pattern_attached_t, int, 0, pattern_attacher, base> pattern_attached;
typedef xos::base::createdt<pattern_attached_t, int, 0, pattern_attacher, pattern_attached> pattern_created;
typedef pattern_attacher pattern_implements;
typedef pattern_created pattern_extends;
///////////////////////////////////////////////////////////////////////
///  Class: patternt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = pattern_implements, class TExtends = pattern_extends>

class _EXPORT_CLASS patternt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    patternt(pattern_attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created){
    }
    patternt(double r, double g, double b, double a = -1) {
        if (!(create(r,g,b,a))) {
            LAMNA_LOG_ERROR("failed on create(r,g,b,a) throwing failed_to_create...");
            xos::base::creator_exception e = xos::base::failed_to_create;
            throw(e);
        }
    }
    virtual ~patternt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create(double r, double g, double b, double a = -1) {
        pattern_attached_t detached = 0;
        if ((detached = create_attached(r,g,b,a))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual pattern_attached_t create_attached
    (double r, double g, double b, double a = -1) {
        pattern_attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(r,g,b,a))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual pattern_attached_t create_detached
    (double r, double g, double b, double a = -1) const {
        pattern_attached_t detached = 0;
        if ((a < 0)) {
            if (!(detached = cairo_pattern_create_rgb(r,g,b))) {
                LAMNA_LOG_ERROR("failed on cairo_pattern_create_rgb()");
            }
        } else {
            if (!(a > 1)) {
                if (!(detached = cairo_pattern_create_rgba(r,g,b,a))) {
                    LAMNA_LOG_ERROR("failed on cairo_pattern_create_rgba()");
                }
            }
        }
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool destroy() {
        pattern_attached_t detached = 0;
        if ((detached = this->detach())) {
            return destroy_detached(detached);
        }
        return false;
    }
    virtual bool destroy_detached(pattern_attached_t detached) const {
        if ((detached)) {
            cairo_pattern_destroy(detached);
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator pattern_attached_t() const {
        return this->attached_to();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef patternt<> pattern;

} // namespace cairo 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_CAIRO_PATTERN_HPP 
