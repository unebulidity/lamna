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
///   File: main_signals.hpp
///
/// Author: $author$
///   Date: 6/20/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_GTK_APPLICATION_MAIN_SIGNALS_HPP
#define _LAMNA_GUI_GTK_APPLICATION_MAIN_SIGNALS_HPP

#include "lamna/gui/gtk/main.hpp"

namespace lamna {
namespace gui {
namespace gtk {
namespace application {

typedef implement_base main_signals_implements;
///////////////////////////////////////////////////////////////////////
///  Class: main_signalst
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_signals_implements>

class _EXPORT_CLASS main_signalst: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_signal_activate(GtkApplication* application) {
    }
    static void signal_activate_callback
    (GtkApplication* application, main_signalst* main_signals) {
        LAMNA_LOG_MESSAGE_DEBUG("signal_activate_callback()in...");
        if ((application) && (main_signals)) {
            main_signals->on_signal_activate(application);
        } else {
            if ((application)) {
                LAMNA_LOG_ERROR("unexpected main_signals == 0");
            } else {
                LAMNA_LOG_ERROR("unexpected main == 0");
            }
        }
        LAMNA_LOG_MESSAGE_DEBUG("signal_activate_callback()...out");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef main_signalst<> main_signals;

} // namespace application 
} // namespace gtk 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_GTK_APPLICATION_MAIN_SIGNALS_HPP 
