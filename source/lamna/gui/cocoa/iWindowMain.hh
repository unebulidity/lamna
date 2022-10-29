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
///   File: iWindowMain.hh
///
/// Author: $author$
///   Date: 10/16/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_COCOA_IWINDOWMAIN_HH
#define _LAMNA_GUI_COCOA_IWINDOWMAIN_HH

#include "lamna/gui/cocoa/iOptMain.hh"

#define LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_TITLE "iWindowMain"
#define LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_X 0
#define LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_Y 2048
#define LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_WIDTH 256
#define LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_HEIGHT 256

#define LAMNA_GUI_COCOA_IWINDOWMAIN_VIEW_BG_COLOR whiteColor

#define LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_STYLE iDefaultDesktopWindowMask
#define LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_BACKING iDefaultDesktopWindowBacking
#define LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_DEFER NO

namespace lamna {
namespace gui {
namespace cocoa {

} // namespace cocoa 
} // namespace gui 
} // namespace lamna 

///////////////////////////////////////////////////////////////////////
/// Interface: iMainView
///////////////////////////////////////////////////////////////////////
@interface iMainView: iView {
    }
    - (void)drawRect:(iRect)rect;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: iMainWindow
///////////////////////////////////////////////////////////////////////
@interface iMainWindow: iWindow <iWindowDelegate> {
    iView* mainView_;
    iApplication* app_;
    }
    - (iMainWindow*)initWithRect:(iRect)contentRect argc:(int)argc argv:(char**)argv env:(char**)env;
    - (iString*)setMainTitle:(int)argc argv:(char**)argv env:(char**)env;
    - (iView*)createMainView:(int)argc argv:(char**)argv env:(char**)env;
    - (const char*)mainTitleUTF8String:(int)argc argv:(char**)argv env:(char**)env;
    - (iApplication*)setApplication:(iApplication*)app;
    - (iApplication*)application;
    - (void)windowWillClose:(iNotification*)notification;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: iWindowMain
///////////////////////////////////////////////////////////////////////
@interface iWindowMain: iOptMain <iOptMain> {
    iMainWindow* mainWindow_;
    iApplication* app_;
    iAutoreleasePool* pool_;
    }
    - (id)init:(lamna::gui::main*)main;
    - (iMainWindow*)createMainWindow:(iRect)contentRect argc:(int)argc argv:(char**)argv env:(char**)env;
    - (iRect)contentRect:(int)argc argv:(char**)argv env:(char**)env;
    - (int)runApplication:(iApplication*)app argc:(int)argc argv:(char**)argv env:(char**)env;
    - (int)beforeRunApplication:(iApplication*)app argc:(int)argc argv:(char**)argv env:(char**)env;
    - (int)run:(int)argc argv:(char**)argv env:(char**)env;
@end

#endif // _LAMNA_GUI_COCOA_IWINDOWMAIN_HH
        

