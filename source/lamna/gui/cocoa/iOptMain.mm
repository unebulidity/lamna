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
///   File: iOptMain.mm
///
/// Author: $author$
///   Date: 10/15/2015
///////////////////////////////////////////////////////////////////////
#include "lamna/gui/cocoa/iOptMain.hh"

namespace lamna {
namespace gui {
namespace cocoa {

} // namespace cocoa 
} // namespace gui 
} // namespace lamna 

///////////////////////////////////////////////////////////////////////
/// Implentation: iOptMain
///////////////////////////////////////////////////////////////////////
@implementation iOptMain
    @synthesize main = _main;
    - (id)init:(lamna::gui::main*)main {
        [super init];
        _main = main;
        return self;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (int)usage:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        err = _main->__usage(argc, argv, env);
        return err;
    }
    - (int)onOption:(int)optval optarg:(const char*)optarg optname:(const char*)optname optind:(int)optind argc:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        switch(optval) {
        default:
            err = _main->__on_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        }
        return err;
    }
    - (int)onArgument:(const char*)arg argind:(int)argind argc:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        switch(argind) {
        default:
            err = _main->__on_argument(arg, argind, argc, argv, env);
            break;
        }
        return err;
    }
    - (const char*)optionUsage:(const char*&)optarg longopt:(const struct option*)longopt {
        const char* chars = "";
        switch(longopt->val) {
        default:
            chars = _main->__option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    - (const char*)options:(const struct option*&)longopts {
        static struct option optstruct[] = {{0, 0, 0, 0}};
        const char* chars = "";
        longopts = optstruct;
        chars = _main->__options(longopts);
        return chars;
    }
    - (const char*)arguments:(const char**&)args {
        const char* chars = 0;
        args = 0;
        chars = _main->__arguments(args);
        return chars;
    }
@end

