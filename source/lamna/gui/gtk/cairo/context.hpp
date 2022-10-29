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
#ifndef _LAMNA_GUI_GTK_CAIRO_CONTEXT_HPP
#define _LAMNA_GUI_GTK_CAIRO_CONTEXT_HPP

#include "lamna/gui/gtk/gtk.hpp"
#include "lamna/gui/cairo/context.hpp"

namespace lamna {
namespace gui {
namespace gtk {
namespace cairo {

typedef gui::cairo::context_implements context_implements;
typedef gui::cairo::context context_extends;
///////////////////////////////////////////////////////////////////////
///  Class: contextt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = context_implements, class TExtends = context_extends>

class _EXPORT_CLASS contextt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef gui::cairo::context_attached_t context_attached_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    contextt(GtkWidget* widget) {
        if ((widget)) {
            if (!(create(widget))) {
                xos::base::creator_exception e = xos::base::failed_to_create;
                LAMNA_LOG_ERROR("failed on create(widget) throw(failed_to_create)...");
                throw(e);
            }
        }
    }
    contextt(GdkWindow* window) {
        if ((window)) {
            if (!(create(window))) {
                xos::base::creator_exception e = xos::base::failed_to_create;
                LAMNA_LOG_ERROR("failed on create(window) throw(failed_to_create)...");
                throw(e);
            }
        }
    }
    contextt
    (context_attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~contextt() {
        if (!(this->destroyed())) {
            xos::base::creator_exception e = xos::base::failed_to_destroy;
            LAMNA_LOG_ERROR("failed on destroyed() throw(failed_to_destroy)...");
            throw(e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create(GtkWidget* widget) {
        context_attached_t detached = 0;
        if ((detached = create_attached(widget))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool create(GdkWindow* window) {
        context_attached_t detached = 0;
        if ((detached = create_attached(window))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual context_attached_t create_attached(GtkWidget* widget) {
        context_attached_t detached = 0;
        if ((detached = create_detached(widget))) {
            this->attach(detached);
            return detached;
        }
        return 0;
    }
    virtual context_attached_t create_attached(GdkWindow* window) {
        context_attached_t detached = 0;
        if ((detached = create_detached(window))) {
            this->attach(detached);
            return detached;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual context_attached_t create_detached(GtkWidget* widget) const {
        if ((widget)) {
            GdkWindow* window = 0;
            if ((window = gtk_widget_get_window(widget))) {
                return create_detached(window);
            } else {
                LAMNA_LOG_ERROR("failed on gtk_widget_get_window(widget)");
            }
        }
        return 0;
    }
    virtual context_attached_t create_detached(GdkWindow* window) const {
        if ((window)) {
            context_attached_t detached = 0;
            if (!(detached = gdk_cairo_create(window))) {
                LAMNA_LOG_ERROR("failed on gdk_cairo_create(window)");
            }
            return detached;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef contextt<> context;

} // namespace cairo 
} // namespace gtk 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_GTK_CAIRO_CONTEXT_HPP 
