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
///   File: main.hpp
///
/// Author: $author$
///   Date: 5/30/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_CONSOLE_MAIN_HPP
#define _LAMNA_CONSOLE_MAIN_HPP

#include "lamna/console/main_opt.hpp"
#include "lamna/io/logger.hpp"
#include "lamna/base/base.hpp"
#include "xos/base/getopt/main.hpp"
#include "xos/base/main.hpp"

namespace lamna {
namespace console {

typedef xos::base::getopt::main_implement main_implements;
typedef xos::base::getopt::main main;

} // namespace console
namespace app {
namespace console {

typedef lamna::console::main_implements main_implements;
typedef lamna::console::main main;

} // namespace console
} // namespace app
} // namespace lamna

#endif // _LAMNA_CONSOLE_MAIN_HPP 
