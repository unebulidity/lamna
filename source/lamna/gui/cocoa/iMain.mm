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
///   File: iMain.mm
///
/// Author: $author$
///   Date: 10/15/2015
///////////////////////////////////////////////////////////////////////
#include "lamna/gui/cocoa/iMain.hh"

namespace lamna {
namespace gui {
namespace cocoa {

} // namespace cocoa 
} // namespace gui 
} // namespace lamna 

///////////////////////////////////////////////////////////////////////
/// Implentation: iRunMain
///////////////////////////////////////////////////////////////////////
@implementation iRunMain
    - (int)run:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        LAMNA_LOG_TRACE("in...");
        LAMNA_LOG_TRACE("...out");
        return err;
    }
    - (int)beforeRun:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        LAMNA_LOG_TRACE("in...");
        LAMNA_LOG_TRACE("...out");
        return err;
    }
    - (int)afterRun:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        LAMNA_LOG_TRACE("in...");
        LAMNA_LOG_TRACE("...out");
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (int)main:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        LAMNA_LOG_TRACE("in...");
        if (!(err = [self beforeRun:argc argv:argv env:env])) {
            int err2 = 0;
            if ((err = [self run:argc argv:argv env:env]))
                LAMNA_LOG_TRACE("...error " << err << " on [run]");
            if ((err2 = [self afterRun:argc argv:argv env:env])) {
                LAMNA_LOG_TRACE("...error " << err << " on [afterRun]");
                if (!err) err = err2;
            }
        } else {
            LAMNA_LOG_TRACE("...error " << err << " on [beforeRun]");
        }
        LAMNA_LOG_TRACE("...out");
        return err;
    }
    - (int)beforeMain:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        LAMNA_LOG_TRACE("in...");
        LAMNA_LOG_TRACE("...out");
        return err;
    }
    - (int)afterMain:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        LAMNA_LOG_TRACE("in...");
        LAMNA_LOG_TRACE("...out");
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)destroy {
    }
@end
