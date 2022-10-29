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
///   File: window.hpp
///
/// Author: $author$
///   Date: 6/21/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_GTK_APPLICATION_WINDOW_HPP
#define _LAMNA_GUI_GTK_APPLICATION_WINDOW_HPP

#include "lamna/gui/gtk/widget.hpp"

namespace lamna {
namespace gui {
namespace gtk {
namespace application {

typedef gtk::widget_implements window_implements;
typedef gtk::widget window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: windowt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = window_implements, class TExtends = window_extends>

class _EXPORT_CLASS windowt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    windowt(widget_attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~windowt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_default_size(gint width, gint height) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_window_set_default_size(GTK_WINDOW(detached), width,height);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create(GtkApplication* application) {
        widget_attached_t detached = 0;
        if ((detached = create_attached(application))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual widget_attached_t create_attached(GtkApplication* application) {
        widget_attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(application))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual widget_attached_t create_detached(GtkApplication* application) const {
        widget_attached_t detached = 0;
        if ((application)) {
            if (!(detached = gtk_application_window_new(application))) {
                LAMNA_LOG_ERROR("failed on gtk_application_window_new()");
            }
        }
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef windowt<> window;

} // namespace application 
} // namespace gtk 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_GTK_APPLICATION_WINDOW_HPP 
