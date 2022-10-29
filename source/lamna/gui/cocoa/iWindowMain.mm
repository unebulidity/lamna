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
///   File: iWindowMain.mm
///
/// Author: $author$
///   Date: 10/16/2015
///////////////////////////////////////////////////////////////////////
#include "lamna/gui/cocoa/iWindowMain.hh"

namespace lamna {
namespace gui {
namespace cocoa {

} // namespace cocoa 
} // namespace gui 
} // namespace lamna 

///////////////////////////////////////////////////////////////////////
/// Implentation: iMainView
///////////////////////////////////////////////////////////////////////
@implementation iMainView
    - (void)drawRect:(iRect)rect {
        [[iColor LAMNA_GUI_COCOA_IWINDOWMAIN_VIEW_BG_COLOR] set];
        iRectFill([self bounds]);
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: iMainWindow
///////////////////////////////////////////////////////////////////////
@implementation iMainWindow
    - (iMainWindow*)initWithRect:(iRect)contentRect argc:(int)argc argv:(char**)argv env:(char**)env {
        iWindowStyleMask style = LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_STYLE;
        iBackingStoreType backing = (iBackingStoreType)LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_BACKING;
        BOOL defer = LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_DEFER;
        mainView_ = 0;
        app_ = 0;
        [super initWithContentRect:contentRect styleMask:style backing:backing defer:defer];
        [self setDelegate:self];
        return self;
    }
    - (iString*)setMainTitle:(int)argc argv:(char**)argv env:(char**)env {
        iString* mainTitle = [iString stringWithUTF8String:[self mainTitleUTF8String:argc argv:argv env:env]];
        [self setTitle:mainTitle];
        return mainTitle;
    }
    - (iView*)createMainView:(int)argc argv:(char**)argv env:(char**)env {
        mainView_ = [[iMainView alloc] init];
        return mainView_;
    }
    - (const char*)mainTitleUTF8String:(int)argc argv:(char**)argv env:(char**)env {
        return LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_TITLE;
    }
    - (iApplication*)setApplication:(iApplication*)app {
        app_ = app;
        return app_;
    }
    - (iApplication*)application {
        return app_;
    }
    -(void)windowWillClose:(iNotification*)notification {
        iApplication* app;
        if ((app = [self application]))
            [app stop:self];
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: iWindowMain
///////////////////////////////////////////////////////////////////////
@implementation iWindowMain
    - (id)init:(lamna::gui::main*)main {
        [super init:main];
        mainWindow_ = 0;
        app_ = 0;
        pool_ = 0;
        return self;
    }
    - (iMainWindow*)createMainWindow:(iRect)contentRect argc:(int)argc argv:(char**)argv env:(char**)env {
        iMainWindow* mainWindow = [[iMainWindow alloc] initWithRect:contentRect argc:argc argv:argv env:env];
        return mainWindow;
    }
    - (iRect)contentRect:(int)argc argv:(char**)argv env:(char**)env {
        int x = LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_X,
            y = LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_Y,
            width = LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_WIDTH,
            height = LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_HEIGHT;
        iRect contentRect = iMakeRect(x,y, width,height);
        return contentRect;
    }
    - (int)runApplication:(iApplication*)app argc:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        [app run];
        return err;
    }
    - (int)beforeRunApplication:(iApplication*)app argc:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        return err;
    }
    - (int)run:(int)argc argv:(char**)argv env:(char**)env {
        iRect contentRect = [self contentRect:argc  argv:argv env:env];
        iView* mainView;
        int err = 0;
        LAMNA_LOG_TRACE("in...");
        if ((pool_ = [[iAutoreleasePool alloc] init])) {
            if ((app_ = [iApplication sharedApplication])) {
                if ((mainWindow_ = [self createMainWindow:contentRect argc:argc argv:argv env:env])) {
                    [mainWindow_ setMainTitle:argc argv:argv env:env];
                    if ((mainView = [mainWindow_ createMainView:argc argv:argv env:env])) {
                        [mainWindow_ setApplication:app_];
                        [mainWindow_ setContentView:mainView];
                        [mainWindow_ makeKeyAndOrderFront: nil];
                        if (!(err = [self beforeRunApplication:app_ argc:argc argv:argv env:env])) {
                            err = [self runApplication:app_ argc:argc argv:argv env:env];
                        }
                    } else {
                        LAMNA_LOG_ERROR("failed on [mainWindow_ createMainView:...]");
                        [mainWindow_ release];
                        mainWindow_ = 0;
                    }
                } else {
                    LAMNA_LOG_ERROR("failed on [self createMainWindow...]");
                }
                app_ = 0;
            } else {
                LAMNA_LOG_ERROR("failed on [iApplication sharedApplication]");
            }
            [pool_ release];
            pool_ = 0;
        } else {
            LAMNA_LOG_ERROR("failed on [[iAutoreleasePool alloc] init]");
        }
        LAMNA_LOG_TRACE("...out");
        return err;
    }
@end
