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
///   File: window_main.hpp
///
/// Author: $author$
///   Date: 5/30/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_QT_APPLICATION_WINDOW_MAIN_HPP
#define _LAMNA_GUI_QT_APPLICATION_WINDOW_MAIN_HPP

#include "lamna/gui/qt/application/main.hpp"

namespace lamna {
namespace gui {
namespace qt {
namespace application {

typedef lamna::gui::qt::application::main_implements window_main_implements;
typedef lamna::gui::qt::application::main window_main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: window_main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS window_main
: virtual public window_main_implements, public window_main_extends {
public:
    typedef window_main_implements Implements;
    typedef window_main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    window_main(): qMainWindow_(0) {
    }
    virtual ~window_main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual QMainWindow* create_main_window
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        QMainWindow* qMainWindow = 0;
        if ((qMainWindow = new QMainWindow())) {
            return qMainWindow;
        } else {
            LAMNA_LOG_ERROR("failed on new QMainWindow()");
        }
        return 0;
    }
    virtual bool before_create_main_window
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool after_create_main_window
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool destroy_main_window
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        if ((qMainWindow) && (qMainWindow == (qMainWindow_))) {
            bool success = true;
            delete qMainWindow;
            return success;
        } else {
            LAMNA_LOG_ERROR("unexpected (!qMainWindow) || (qMainWindow != (qMainWindow_))");
        }
        return false;
    }
    virtual bool show_main_window
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        if ((qMainWindow)) {
            LAMNA_LOG_MESSAGE_DEBUG("qMainWindow_->show()...");
            qMainWindow->show();
            return true;
        }
        return false;
    }
    virtual bool before_show_main_window
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool after_show_main_window
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_exec
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        int err = 1;

        LAMNA_LOG_MESSAGE_DEBUG("before_create_main_window()...");
        if ((before_create_main_window(qApplication, argc, argv, env))) {

            LAMNA_LOG_MESSAGE_DEBUG("create_main_window()...");
            if ((qMainWindow_ = create_main_window(qApplication, argc, argv, env))) {

                LAMNA_LOG_MESSAGE_DEBUG("after_create_main_indow()...");
                if ((after_create_main_window(qMainWindow_, qApplication, argc, argv, env))) {

                    LAMNA_LOG_MESSAGE_DEBUG("before_show_main_indow()...");
                    if ((before_show_main_window(qMainWindow_, qApplication, argc, argv, env))) {

                        LAMNA_LOG_MESSAGE_DEBUG("show_main_indow()...");
                        if ((show_main_window(qMainWindow_, qApplication, argc, argv, env))) {

                            LAMNA_LOG_MESSAGE_DEBUG("after_show_main_indow()...");
                            if ((after_show_main_window(qMainWindow_, qApplication, argc, argv, env))) {
                                return err = 0;
                            } else {
                                LAMNA_LOG_ERROR("failed on after_show_main_window()");
                            }
                        } else {
                            LAMNA_LOG_ERROR("failed on show_main_window()");
                        }
                    } else {
                        LAMNA_LOG_ERROR("failed on before_show_main_window()");
                    }
                } else {
                    LAMNA_LOG_ERROR("failed on after_create_main_window()");
                }
                LAMNA_LOG_MESSAGE_DEBUG("destroy_main_window()...");
                if (!(destroy_main_window(qMainWindow_, qApplication, argc, argv, env))) {
                    LAMNA_LOG_ERROR("failed on destroy_main_window()");
                }
                qMainWindow_ = 0;
            } else {
                LAMNA_LOG_ERROR("failed on create_main_window()");
            }
        } else {
            LAMNA_LOG_ERROR("failed on before_main_window()");
        }
        return err;
    }
    virtual int after_exec
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        int err = 1;
        if ((qMainWindow_)) {
            LAMNA_LOG_MESSAGE_DEBUG("destroy_main_window()...");
            if ((destroy_main_window(qMainWindow_, qApplication, argc, argv, env))) {
                err = 0;
            } else {
                LAMNA_LOG_ERROR("failed on destroy_main_window()");
            }
            qMainWindow_ = 0;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    QMainWindow* qMainWindow_;
};

} // namespace application
} // namespace qt 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_QT_APPLICATION_WINDOW_MAIN_HPP 
