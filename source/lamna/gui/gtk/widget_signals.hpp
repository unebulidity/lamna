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
///   File: widget_signals.hpp
///
/// Author: $author$
///   Date: 6/20/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_GTK_WIDGET_SIGNALS_HPP
#define _LAMNA_GUI_GTK_WIDGET_SIGNALS_HPP

#include "lamna/gui/gtk/mouse/button.hpp"
#include "lamna/gui/gtk/gtk.hpp"
#include "lamna/io/logger.hpp"

namespace lamna {
namespace gui {
namespace gtk {

typedef GCallback widget_signal_callback_t;
typedef gint widget_signal_event_mask_t;
typedef implement_base widget_signals_implements;
///////////////////////////////////////////////////////////////////////
///  Class: widget_signalst
///////////////////////////////////////////////////////////////////////
template
<class TImplements = widget_signals_implements>

class _EXPORT_CLASS widget_signalst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_destroy(GtkWidget* widget) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_destroy(widget);
        }
    }
    static void signal_destroy_callback
    (GtkWidget* widget, widget_signalst* widget_signals) {
        if ((widget) && (widget_signals)) {
            widget_signals->on_signal_destroy(widget);
        } else {
            if ((widget)) {
                LAMNA_LOG_ERROR("unexpected widget_signals == 0");
            } else {
                LAMNA_LOG_ERROR("unexpected widget == 0");
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_draw(GtkWidget* widget, cairo_t* cr) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_draw(widget, cr);
        }
    }
    static gboolean signal_draw_callback
    (GtkWidget* widget, cairo_t* cr, widget_signalst* widget_signals) {
        gboolean handled = FALSE;
        if ((widget) && (widget_signals)) {
            widget_signals->on_signal_draw(widget, cr);
        } else {
            if ((widget)) {
                LAMNA_LOG_ERROR("unexpected widget_signals == 0");
            } else {
                LAMNA_LOG_ERROR("unexpected widget == 0");
            }
        }
        return handled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_left_1button_press_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_left_1button_press_event(widget, event);
        }
    }
    virtual void on_signal_right_1button_press_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_right_1button_press_event(widget, event);
        }
    }
    virtual void on_signal_middle_1button_press_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_middle_1button_press_event(widget, event);
        }
    }
    virtual void on_signal_which_1button_press_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        switch(mouse::button::which(event)) {
        case gui::mouse::button_left:
            on_signal_left_1button_press_event(widget, event);
            break;
        case gui::mouse::button_right:
            on_signal_right_1button_press_event(widget, event);
            break;
        case gui::mouse::button_middle:
            on_signal_middle_1button_press_event(widget, event);
            break;
        }
        if ((to = widget_signals_forward_to())) {
            to->on_signal_which_1button_press_event(widget, event);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_left_1button_release_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_left_1button_release_event(widget, event);
        }
    }
    virtual void on_signal_right_1button_release_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_right_1button_release_event(widget, event);
        }
    }
    virtual void on_signal_middle_1button_release_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_middle_1button_release_event(widget, event);
        }
    }
    virtual void on_signal_which_1button_release_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        switch(mouse::button::which(event)) {
        case gui::mouse::button_left:
            on_signal_left_1button_release_event(widget, event);
            break;
        case gui::mouse::button_right:
            on_signal_right_1button_release_event(widget, event);
            break;
        case gui::mouse::button_middle:
            on_signal_middle_1button_release_event(widget, event);
            break;
        }
        if ((to = widget_signals_forward_to())) {
            to->on_signal_which_1button_release_event(widget, event);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_1button_press_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        on_signal_which_1button_press_event(widget, event);
        if ((to = widget_signals_forward_to())) {
            to->on_signal_button_press_event(widget, event);
        }
    }
    virtual void on_signal_2button_press_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_button_press_event(widget, event);
        }
    }
    virtual void on_signal_3button_press_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_button_press_event(widget, event);
        }
    }
    virtual void on_signal_button_press_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_button_press_event(widget, event);
        }
    }
    static gboolean signal_button_press_event_callback
    (GtkWidget* widget, GdkEvent* event, widget_signalst* widget_signals) {
        gboolean handled = FALSE;
        if ((widget) && (widget_signals)) {
            widget_signals->on_signal_button_press_event(widget, event);
            if (GDK_3BUTTON_PRESS != event->type) {
                if (GDK_2BUTTON_PRESS != event->type) {
                    widget_signals->on_signal_1button_press_event(widget, event);
                } else {
                    widget_signals->on_signal_2button_press_event(widget, event);
                }
            } else {
                widget_signals->on_signal_3button_press_event(widget, event);
            }
        } else {
            if ((widget)) {
                LAMNA_LOG_ERROR("unexpected widget_signals == 0");
            } else {
                LAMNA_LOG_ERROR("unexpected widget == 0");
            }
        }
        return handled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_nbutton_release_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_nbutton_release_event(widget, event);
        }
    }
    virtual void on_signal_1button_release_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        on_signal_which_1button_release_event(widget, event);
        if ((to = widget_signals_forward_to())) {
            to->on_signal_1button_release_event(widget, event);
        }
    }
    virtual void on_signal_2button_release_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_2button_release_event(widget, event);
        }
    }
    virtual void on_signal_3button_release_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_3button_release_event(widget, event);
        }
    }
    virtual void on_signal_button_release_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        on_signal_nbutton_release_event(widget, event);
        if ((to = widget_signals_forward_to())) {
            to->on_signal_button_release_event(widget, event);
        }
    }
    static gboolean signal_button_release_event_callback
    (GtkWidget* widget, GdkEvent* event, widget_signalst* widget_signals) {
        gboolean handled = FALSE;
        if ((widget) && (widget_signals)) {
            widget_signals->on_signal_button_release_event(widget, event);
        } else {
            if ((widget)) {
                LAMNA_LOG_ERROR("unexpected widget_signals == 0");
            } else {
                LAMNA_LOG_ERROR("unexpected widget == 0");
            }
        }
        return handled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_configure
    (GtkWidget* widget, GdkWindow *window, gint x,gint y,
     gint width,gint height, gboolean sent_explicitly) {
        widget_signalst* to = 0;
        if ((to = widget_signals_forward_to())) {
            to->on_signal_configure
            (widget, window, x,y, width,height, sent_explicitly);
        }
    }
    virtual void on_signal_configure_event(GtkWidget* widget, GdkEvent* event) {
        widget_signalst* to = 0;
        if ((event)) {
            GdkEventConfigure configure = event->configure;
            on_signal_configure
            (widget, configure.window, configure.x,configure.y,
             configure.width,configure.height, configure.send_event);
        }
        if ((to = widget_signals_forward_to())) {
            to->on_signal_configure_event(widget, event);
        }
    }
    static gboolean signal_configure_event_callback
    (GtkWidget* widget, GdkEvent* event, widget_signalst* widget_signals) {
        gboolean handled = FALSE;
        if ((widget) && (widget_signals)) {
            widget_signals->on_signal_configure_event(widget, event);
        } else {
            if ((widget)) {
                LAMNA_LOG_ERROR("unexpected widget_signals == 0");
            } else {
                LAMNA_LOG_ERROR("unexpected widget == 0");
            }
        }
        return handled;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual widget_signalst* forward_widget_signals(widget_signalst* to) {
        return 0;
    }
    virtual widget_signalst* widget_signals_forward_to() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef widget_signalst<> widget_signals;

} // namespace gtk 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_GTK_WIDGET_SIGNALS_HPP 
