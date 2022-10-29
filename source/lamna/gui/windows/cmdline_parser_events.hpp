///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: cmdline_parser_events.hpp
///
/// Author: $author$
///   Date: 6/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WINDOWS_CMDLINE_PARSER_EVENTS_HPP
#define _LAMNA_GUI_WINDOWS_CMDLINE_PARSER_EVENTS_HPP

#include "lamna/io/logger.hpp"
#include "lamna/base/base.hpp"

namespace lamna {
namespace gui {
namespace windows {

typedef implement_base cmdline_parser_events_implements;
///////////////////////////////////////////////////////////////////////
///  Class: cmdline_parser_eventst
///////////////////////////////////////////////////////////////////////
template 
<typename TChar = char, typename TEnd = int, TEnd VEnd = 0,
 class TImplements = cmdline_parser_events_implements>

class _EXPORT_CLASS cmdline_parser_eventst: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TChar char_t;
    typedef TEnd end_t;
    enum  { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_cmdline_parser_events(const char_t *c, size_t length) {
        cmdline_parser_eventst* forward_to = cmdline_parser_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_cmdline_parser_events(" << chars_to_string(c, length) << ", " << length << ")...");
        if ((forward_to)) {
            return forward_to->on_cmdline_parser_events(c, length);
        } else {
            bool success = false;
            if ((success = this->on_cmdline_parser_events_begin())) {
                if ((c) && (length)) {
                    do {
                        if (!(this->on_cmdline_parser_events_char(*c))) {
                            success = false;
                            break;
                        }
                        ++c; --length;
                    } while (0 < (length));
                }
                if (!(this->on_cmdline_parser_events_end())) {
                    success = false;
                }
            }
            return success;
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_cmdline_parser_events(" << chars_to_string(c, length) << ", " << length << ")");
        return true;
    }
    virtual bool on_cmdline_parser_events_arg(const char_t *c, size_t length) {
        cmdline_parser_eventst* forward_to = cmdline_parser_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_cmdline_parser_events_arg(" << chars_to_string(c, length) << ", " << length << ")...");
        if ((forward_to)) {
            return forward_to->on_cmdline_parser_events_arg(c, length);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_cmdline_parser_events_arg(" << chars_to_string(c, length) << ", " << length << ")");
        return true;
    }
    virtual bool on_cmdline_parser_events_char(char_t c) {
        cmdline_parser_eventst* forward_to = cmdline_parser_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_cmdline_parser_events_char(" << char_to_string(c) << ")...");
        if ((forward_to)) {
            return forward_to->on_cmdline_parser_events_char(c);
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_cmdline_parser_events_char(" << char_to_string(c) << ")");
        return true;
    }
    virtual bool on_cmdline_parser_events_begin() {
        cmdline_parser_eventst* forward_to = cmdline_parser_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_cmdline_parser_events_begin()...");
        if ((forward_to)) {
            return forward_to->on_cmdline_parser_events_begin();
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_cmdline_parser_events_begin()");
        return true;
    }
    virtual bool on_cmdline_parser_events_end() {
        cmdline_parser_eventst* forward_to = cmdline_parser_events_forward_to();
        LAMNA_LOG_MESSAGE_DEBUG("on_cmdline_parser_events_end()...");
        if ((forward_to)) {
            return forward_to->on_cmdline_parser_events_end();
        }
        LAMNA_LOG_MESSAGE_DEBUG("...on_cmdline_parser_events_end()");
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual cmdline_parser_eventst* 
    forward_cmdline_parser_events_to(cmdline_parser_eventst* to) {
        return 0;
    }
    virtual cmdline_parser_eventst* cmdline_parser_events_forward_to() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef cmdline_parser_eventst<> cmdline_parser_events;

} // namespace windows 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WINDOWS_CMDLINE_PARSER_EVENTS_HPP 
