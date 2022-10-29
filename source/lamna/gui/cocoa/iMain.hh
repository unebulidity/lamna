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
///   File: iMain.hh
///
/// Author: $author$
///   Date: 10/15/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_COCOA_IMAIN_HH
#define _LAMNA_GUI_COCOA_IMAIN_HH

#include "lamna/gui/cocoa/iCocoa.hh"
#include "lamna/gui/main.hpp"

namespace lamna {
namespace gui {
namespace cocoa {

} // namespace cocoa
} // namespace gui
} // namespace lamna

///////////////////////////////////////////////////////////////////////
/// Protocol: iDestroy
///////////////////////////////////////////////////////////////////////
@protocol iDestroy
    - (void)destroy;
@end

///////////////////////////////////////////////////////////////////////
/// Protocol: iMain
///////////////////////////////////////////////////////////////////////
@protocol iMain <iDestroy>
    - (int)main:(int)argc argv:(char**)argv env:(char**)env;
    - (int)beforeMain:(int)argc argv:(char**)argv env:(char**)env;
    - (int)afterMain:(int)argc argv:(char**)argv env:(char**)env;
@end

///////////////////////////////////////////////////////////////////////
/// Protocol: iRun
///////////////////////////////////////////////////////////////////////
@protocol iRun
    - (int)run:(int)argc argv:(char**)argv env:(char**)env;
    - (int)beforeRun:(int)argc argv:(char**)argv env:(char**)env;
    - (int)afterRun:(int)argc argv:(char**)argv env:(char**)env;
@end

///////////////////////////////////////////////////////////////////////
/// Protocol: iRunMain
///////////////////////////////////////////////////////////////////////
@protocol iRunMain <iMain, iRun>
@end

///////////////////////////////////////////////////////////////////////
/// Interface: iRunMain
///////////////////////////////////////////////////////////////////////
@interface iRunMain: iObject <iRunMain> {
    }
    - (int)run:(int)argc argv:(char**)argv env:(char**)env;
    - (int)beforeRun:(int)argc argv:(char**)argv env:(char**)env;
    - (int)afterRun:(int)argc argv:(char**)argv env:(char**)env;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (int)main:(int)argc argv:(char**)argv env:(char**)env;
    - (int)beforeMain:(int)argc argv:(char**)argv env:(char**)env;
    - (int)afterMain:(int)argc argv:(char**)argv env:(char**)env;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)destroy;
@end

#endif // _LAMNA_GUI_COCOA_IMAIN_HH
        

