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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 5/30/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_CONSOLE_MAIN_OPT_HPP
#define _LAMNA_CONSOLE_MAIN_OPT_HPP

#include "lamna/base/base.hpp"
#include "xos/base/getopt/main.hpp"
#include "xos/base/getopt/main_opt.hpp"

#define LAMNA_MAIN_LOGGING_OPTVAL_C XOS_MAIN_LOGGING_OPTVAL_C
#define LAMNA_MAIN_LOGGING_OPTARG XOS_MAIN_LOGGING_OPTARG
#define LAMNA_MAIN_LOGGING_OPTUSE XOS_MAIN_LOGGING_OPTUSE

#define LAMNA_MAIN_HELP_OPTVAL_C XOS_MAIN_HELP_OPTVAL_C
#define LAMNA_MAIN_HELP_OPTARG XOS_MAIN_HELP_OPTARG
#define LAMNA_MAIN_HELP_OPTUSE XOS_MAIN_HELP_OPTUSE

#define LAMNA_MAIN_OPTIONS_CHARS XOS_MAIN_OPTIONS_CHARS
#define LAMNA_MAIN_OPTIONS_OPTIONS XOS_MAIN_OPTIONS_OPTIONS

enum {
    LAMNA_MAIN_OPT_ARGUMENT_NONE     = XOS_MAIN_OPT_ARGUMENT_NONE,
    LAMNA_MAIN_OPT_ARGUMENT_REQUIRED = XOS_MAIN_OPT_ARGUMENT_REQUIRED,
    LAMNA_MAIN_OPT_ARGUMENT_OPTIONAL = XOS_MAIN_OPT_ARGUMENT_OPTIONAL
};

namespace lamna {
namespace console {

typedef int main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = LAMNA_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = LAMNA_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = LAMNA_MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace console

namespace app {
namespace console {

typedef lamna::console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = lamna::console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = lamna::console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = lamna::console::MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace console
} // namespace app
} // namespace lamna

#endif // _LAMNA_CONSOLE_MAIN_OPT_HPP 
