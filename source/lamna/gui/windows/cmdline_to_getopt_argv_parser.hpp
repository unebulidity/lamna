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
///   File: cmdline_to_getopt_argv_parser.hpp
///
/// Author: $author$
///   Date: 6/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WINDOWS_CMDLINE_TO_GETOPT_ARGV_PARSER_HPP
#define _LAMNA_GUI_WINDOWS_CMDLINE_TO_GETOPT_ARGV_PARSER_HPP

#include "lamna/gui/windows/cmdline_parser_events.hpp"

namespace lamna {
namespace gui {
namespace windows {

typedef cmdline_parser_events cmdline_to_getopt_argv_parser_implements;
typedef base cmdline_to_getopt_argv_parser_extends;
///////////////////////////////////////////////////////////////////////
///  Class: cmdline_to_getopt_argv_parsert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = int, TEnd VEnd = 0,
 typename TString = xos::base::stringt<TChar>,
 class TArgv = xos::base::argvt<TChar>,
 class TImplements = cmdline_to_getopt_argv_parser_implements, 
 class TExtends = cmdline_to_getopt_argv_parser_extends>

class _EXPORT_CLASS cmdline_to_getopt_argv_parsert
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef cmdline_to_getopt_argv_parsert Derives;

    typedef TArgv argv_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum  { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    cmdline_to_getopt_argv_parsert
    (argv_t &argv, const char_t *arg0, 
     const char_t *chars, size_t length)
    : on_end_(0), on_char_(0), argv_(argv) {
         this->parse(arg0, chars, length);
    }
    cmdline_to_getopt_argv_parsert(argv_t& argv)
    : on_end_(0), on_char_(0), argv_(argv) {
    }
    cmdline_to_getopt_argv_parsert
    (const cmdline_to_getopt_argv_parsert &copy)
    : on_end_(0), on_char_(0), argv_(copy.argv_) {
    }
    virtual ~cmdline_to_getopt_argv_parsert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool parse
    (const char_t *arg0, const char_t *chars, size_t length) {
        if ((arg0) && (chars)) {
            arg0_.assign(arg0);
            if ((this->on_cmdline_parser_events(chars, length))) {
                return true;
            }
        }
        return false;
    }

protected:
    typedef bool (Derives::*on_t)();
    typedef bool (Derives::*on_char_t)(char_t c);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_cmdline_parser_events_arg(const char_t *c, size_t length) {
        if ((c == argn_.chars()) && (length == argn_.length())) {
            if (0 < (length)) {
                argv_.append(&c, 1);
            }
            return true;
        }
        return false;
    }
    virtual bool on_cmdline_parser_events_char(char_t c) {
        if ((this->on_char_)) {
            if ((this->*on_char_)(c)) {
                return true;
            }
        }
        return false;
    }
    virtual bool on_cmdline_parser_events_begin() {
        const char_t *arg = arg0_.chars();
        argv_.assign(&arg, 1);
        on_end_ = &Derives::on_true;
        on_char_ = &Derives::on_char;
        return true;
    }
    virtual bool on_cmdline_parser_events_end() {
        bool success = false;
        if ((this->on_end_)) {
            if ((this->*on_end_)()) {
                success = true;
            }
        }
        on_end_ = 0;
        on_char_ = 0;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_arg() {
        bool success = true;
        if (!(this->on_cmdline_parser_events_arg(argn_.chars(), argn_.length()))) {
            success = false;
        }
        argn_.clear();
        on_end_ = &Derives::on_true;
        on_char_ = &Derives::on_char;
        return success;
    }
    virtual bool on_true() {
        return true;
    }
    virtual bool on_false() {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_char(char_t c) {
        bool success = true;
        char cc = ((char)c);
        switch (cc) {
        case ' ':
        case '\t':
            on_end_ = &Derives::on_true;
            on_char_ = &Derives::on_char_sp;
            break;
        case '\'':
            on_end_ = &Derives::on_arg;
            on_char_ = &Derives::on_char_apos;
            break;
        case '"':
            on_end_ = &Derives::on_arg;
            on_char_ = &Derives::on_char_quot;
            break;
        default:
            argn_.append(&c, 1);
            on_end_ = &Derives::on_arg;
            on_char_ = &Derives::on_char_2;
            break;
        }
        return success;
    }
    virtual bool on_char_2(char_t c) {
        bool success = true;
        char cc = ((char)c);
        switch (cc) {
        case ' ':
        case '\t':
            success = on_arg();
            break;
        case '\'':
            success = on_arg();
            on_end_ = &Derives::on_arg;
            on_char_ = &Derives::on_char_apos;
            break;
        case '"':
            success = on_arg();
            on_end_ = &Derives::on_arg;
            on_char_ = &Derives::on_char_quot;
            break;
        default:
            argn_.append(&c, 1);
            break;
        }
        return success;
    }
    virtual bool on_char_sp(char_t c) {
        bool success = true;
        char cc = ((char)c);
        switch (cc) {
        case ' ':
        case '\t':
            break;
        case '\'':
            on_end_ = &Derives::on_arg;
            on_char_ = &Derives::on_char_apos;
            break;
        case '"':
            on_end_ = &Derives::on_arg;
            on_char_ = &Derives::on_char_quot;
            break;
        default:
            argn_.append(&c, 1);
            on_end_ = &Derives::on_arg;
            on_char_ = &Derives::on_char_2;
            break;
        }
        return success;
    }
    virtual bool on_char_apos(char_t c) {
        bool success = true;
        char cc = ((char)c);
        switch (cc) {
        case '\'':
            success = on_arg();
            break;
        default:
            argn_.append(&c, 1);
            break;
        }
        return success;
    }
    virtual bool on_char_quot(char_t c) {
        bool success = true;
        char cc = ((char)c);
        switch (cc) {
        case '"':
            success = on_arg();
            break;
        default:
            argn_.append(&c, 1);
            break;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    on_t on_end_;
    on_char_t on_char_;
    argv_t &argv_;
    string_t arg0_, argn_;
};
typedef cmdline_to_getopt_argv_parsert<> cmdline_to_getopt_argv_parser;

} // namespace windows 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WINDOWS_CMDLINE_TO_GETOPT_ARGV_PARSER_HPP 
