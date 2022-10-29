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
///   File: widget.hpp
///
/// Author: $author$
///   Date: 6/20/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_GTK_WIDGET_HPP
#define _LAMNA_GUI_GTK_WIDGET_HPP

#include "lamna/gui/gtk/widget_signals.hpp"
#include "lamna/gui/gtk/gtk.hpp"

namespace lamna {
namespace gui {
namespace gtk {

typedef GtkWidget* widget_attached_t;
typedef xos::base::creatort<implement_base> widget_creator;
typedef xos::base::attachert<widget_attached_t, int, 0, widget_creator> widget_attacher;
typedef xos::base::attachedt<widget_attached_t, int, 0, widget_attacher, base> widget_attached;
typedef xos::base::createdt<widget_attached_t, int, 0, widget_attacher, widget_attached> widget_created;
typedef widget_attacher widget_implements;
typedef widget_created widget_extends;
///////////////////////////////////////////////////////////////////////
///  Class: widgett
///////////////////////////////////////////////////////////////////////
template
<class TImplements = widget_implements, class TExtends = widget_extends>

class _EXPORT_CLASS widgett
: virtual public widget_signals,
  virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    widgett(widget_attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created),
      widget_signals_forward_to_(0),
      was_button_pressed2_(false),
      was_button_pressed3_(false) {
    }
    virtual ~widgett() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        widget_attached_t detached = 0;
        if ((detached = create_attached())) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual widget_attached_t create_attached() {
        widget_attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached())) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual widget_attached_t create_detached() const {
        widget_attached_t detached = 0;
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool destroy() {
        widget_attached_t detached = 0;
        if ((detached = this->detach())) {
            return destroy_detached(detached);
        }
        return false;
    }
    virtual bool destroy_detached(widget_attached_t detached) const {
        if ((detached)) {
            gtk_widget_destroy(detached);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool container_add(widgett& widget) {
        widget_attached_t detached = widget.attached_to();
        if ((detached)) {
            return container_add(detached);
        }
        return false;
    }
    virtual bool container_add(widget_attached_t widget) {
        if ((widget)) {
            widget_attached_t detached = 0;
            if ((detached = this->attached_to())) {
                gtk_container_add(GTK_CONTAINER(detached), widget);
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool container_add_to(widget_attached_t container) {
        if ((container)) {
            widget_attached_t detached = 0;
            if ((detached = this->attached_to())) {
                gtk_container_add(GTK_CONTAINER(container), detached);
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool show_all() {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_show_all(detached);
            return true;
        }
        return false;
    }
    virtual bool show() {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_show(detached);
            return true;
        }
        return false;
    }
    virtual bool hide() {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_hide(detached);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool queue_draw() {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_queue_draw(detached);
            return true;
        }
        return false;
    }
    virtual bool queue_draw_area(gint x,gint y, gint width,gint height) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_queue_draw_area(detached, x,y, width,height);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_size_request(gint width, gint height) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_set_size_request(detached, width,height);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_parent(widget_attached_t to) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_set_parent(detached, to);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_sensitive(gboolean to = TRUE) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_set_sensitive(detached, to);
            return true;
        }
        return false;
    }
    virtual bool get_sensitive(gboolean& is_true) const {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            is_true = gtk_widget_get_sensitive(detached);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_halign(GtkAlign align) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_set_halign(detached, align);
            return true;
        }
        return false;
    }
    virtual bool get_halign(GtkAlign& align) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            align = gtk_widget_get_halign(detached);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_valign(GtkAlign align) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_set_valign(detached, align);
            return true;
        }
        return false;
    }
    virtual bool get_valign(GtkAlign& align) {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            align = gtk_widget_get_valign(detached);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool get_size(gint& width, gint& height) const {
        GtkAllocation allocation;
        if ((get_allocation(&allocation))) {
            width = allocation.width;
            height = allocation.height;
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool get_allocation(GtkAllocation* allocation) const {
        widget_attached_t detached = 0;
        if ((detached = this->attached_to())) {
            gtk_widget_get_allocation(detached, allocation);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal_destroy() {
        const char* signal_name = "destroy";
        return connect_signal
        (signal_name, (widget_signal_callback_t)
         (widget_signals::signal_destroy_callback));
    }
    virtual bool disconnect_signal_destroy() {
        return disconnect_signal
        ((widget_signal_callback_t)(widget_signals::signal_destroy_callback));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal_draw() {
        const char* signal_name = "draw";
        return connect_signal
        (signal_name, (widget_signal_callback_t)
         (widget_signals::signal_draw_callback));
    }
    virtual bool disconnect_signal_draw() {
        return disconnect_signal
        ((widget_signal_callback_t)(widget_signals::signal_draw_callback));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal_configure_event() {
        const char* signal_name = "configure-event";
        return connect_signal
        (signal_name, (widget_signal_callback_t)
         (widget_signals::signal_configure_event_callback),
         GDK_STRUCTURE_MASK);
    }
    virtual bool disconnect_signal_configure_event() {
        return disconnect_signal
        ((widget_signal_callback_t)(widget_signals::signal_configure_event_callback));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal_button_events() {
        if ((connect_signal_button_press_event())) {
            if ((connect_signal_button_release_event())) {
                return true;
            }
            disconnect_signal_button_press_event();
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal_button_press_event() {
        const char* signal_name = "button-press-event";
        return connect_signal
        (signal_name, (widget_signal_callback_t)
         (widget_signals::signal_button_press_event_callback),
         GDK_BUTTON_PRESS_MASK);
    }
    virtual bool disconnect_signal_button_press_event() {
        return disconnect_signal
        ((widget_signal_callback_t)(widget_signals::signal_button_press_event_callback));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal_button_release_event() {
        const char* signal_name = "button-release-event";
        return connect_signal
        (signal_name, (widget_signal_callback_t)
         (widget_signals::signal_button_release_event_callback),
         GDK_BUTTON_RELEASE_MASK);
    }
    virtual bool disconnect_signal_button_release_event() {
        return disconnect_signal
        ((widget_signal_callback_t)(widget_signals::signal_button_release_event_callback));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool connect_signal
    (const char* signal_name,
     widget_signal_callback_t signal_callback,
     widget_signal_event_mask_t signal_event_mask = 0) {
        if ((signal_name) && (signal_callback)) {
            widget_attached_t detached = 0;
            if ((detached = this->attached_to())) {
                gulong handler_id = 0;
                if ((handler_id = g_signal_connect
                     (detached, signal_name,
                      G_CALLBACK(signal_callback),
                      G_POINTER((widget_signals*)this)))) {
                    if ((signal_event_mask)) {
                        gtk_widget_add_events(detached, signal_event_mask);
                    }
                    return true;
                } else {
                    LAMNA_LOG_ERROR("failed on g_signal_connect(..., \"" << signal_name << "\")");
                }
            }
        }
        return false;
    }
    virtual bool disconnect_signal
    (widget_signal_callback_t signal_callback) {
        if ((signal_callback)) {
            widget_attached_t detached = 0;
            if ((detached = this->attached_to())) {
                guint handlers = 0;
                if ((handlers = g_signal_handlers_disconnect_by_func
                     (detached,
                      G_POINTER(signal_callback),
                      G_POINTER((widget_signals*)this)))) {
                    return true;
                } else {
                    LAMNA_LOG_ERROR("failed on g_signal_handlers_disconnect_by_func()");
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual widget_signals* forward_widget_signals(widget_signals* to) {
        widget_signals_forward_to_ = to;
        return widget_signals_forward_to_;
    }
    virtual widget_signals* widget_signals_forward_to() const {
        return widget_signals_forward_to_;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_2button_press_event(GtkWidget* widget, GdkEvent* event) {
        GdkEventButton* bevent = ((GdkEventButton*)event);
        widget_signalst* to = 0;
        button_pressed2_ = bevent->button;
        was_button_pressed2_ = true;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_button_press_event(widget, event);
        }
    }
    virtual void on_signal_3button_press_event(GtkWidget* widget, GdkEvent* event) {
        GdkEventButton* bevent = ((GdkEventButton*)event);
        widget_signalst* to = 0;
        button_pressed3_ = bevent->button;
        was_button_pressed3_ = true;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_button_press_event(widget, event);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_nbutton_release_event(GtkWidget* widget, GdkEvent* event) {
        GdkEventButton* bevent = ((GdkEventButton*)event);
        widget_signalst* to = 0;
        if (!(was_button_pressed2_ || was_button_pressed3_)) {
            on_signal_1button_release_event(widget, event);
        }
        if (was_button_pressed2_ && (button_pressed2_ == (bevent->button))) {
            on_signal_2button_release_event(widget, event);
        }
        was_button_pressed2_ = false;
        if (was_button_pressed3_ && (button_pressed3_ == (bevent->button))) {
            on_signal_3button_release_event(widget, event);
        }
        was_button_pressed3_ = false;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_nbutton_release_event(widget, event);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    widget_signals* widget_signals_forward_to_;
    bool was_button_pressed2_, was_button_pressed3_;
    guint button_pressed2_, button_pressed3_;
};
typedef widgett<> widget;

} // namespace gtk 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_GTK_WIDGET_HPP 
