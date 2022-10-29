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
///   File: main.hpp
///
/// Author: $author$
///   Date: 7/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_CONSOLE_PGM_MAIN_HPP
#define _LAMNA_APP_CONSOLE_PGM_MAIN_HPP

#include "lamna/console/main.hpp"
#include "lamna/graphic/image/format/raw/libpgm/reader.hpp"

namespace lamna {
namespace app {
namespace console {
namespace pgm {

typedef console::main_implements main_implements;
typedef console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        char* arg = 0;

        if ((0 < argc) && (optind < argc) && (arg = argv[optind]) && (arg[0])) {
            lamna::graphic::image::format::raw::libpgm::gbrg::reader r;
            if ((r.read(arg))) {
            }
        } else {
            err = usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace pgm 
} // namespace console 
} // namespace app 
} // namespace lamna 

#endif // _LAMNA_APP_CONSOLE_PGM_MAIN_HPP 
