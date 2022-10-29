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
///   File: iHelloMain.mm
///
/// Author: $author$
///   Date: 10/16/2015
///////////////////////////////////////////////////////////////////////
#include "lamna/app/gui/cocoa/iHelloMain.hh"
#include "lamna/graphic/surface/cocoa/color.hh"

namespace lamna {
namespace app {
namespace gui {
namespace cocoa {

} // namespace cocoa 
} // namespace gui 
} // namespace app 
} // namespace lamna 

///////////////////////////////////////////////////////////////////////
/// Implentation: iHelloMainView
///////////////////////////////////////////////////////////////////////
@implementation iHelloMainView
    - (id)init:(lamna::app::gui::hello::cocoa::surface*)surface {
        [super init];
        surface_ = surface;
        return self;
    }
    - (void)drawRect:(iRect)rect {
        iRect bounds = [self bounds];
        int x = (bounds.size.width/2), y = (bounds.size.height/2);
        [super drawRect:rect];
        if (((surface_->border()+2) <= (x)) && ((surface_->border()+2) <= (y))) {
            lamna::graphic::surface::cocoa::pixel pixel
            (surface_->fg_color_red(), surface_->fg_color_green(), surface_->fg_color_blue());
            lamna::graphic::surface::cocoa::context gc(self);
            lamna::graphic::surface::cocoa::image im(gc);
            lamna::graphic::surface::cocoa::color px
            (im, surface_->fg_color_red(), surface_->fg_color_green(), surface_->fg_color_blue());
            im.SelectImage(&px);
            surface_->paint(im, x,y, x,y);
        }
    }
    - (void)mouseUp:(iEvent*)theEvent {
        iEventType type = [theEvent type];
        switch(type) {
        case iLeftMouseUp: {
            iPoint point = [theEvent locationInWindow];
            int x = point.x, y = point.y;
            lamna::gui::mouse::position p(x,y);
            lamna::gui::mouse::button b(lamna::gui::mouse::button_left);
            lamna::gui::mouse::event e(lamna::gui::mouse::event_button_release, b, p);
            surface_->on_mouse_release_event(e);
            LAMNA_LOG_MESSAGE_DEBUG("mouseUp:(iEvent*)theEvent...");
            break; }
        }
    }
@end

//////////////////////////////////////////////////////////////////////
/// Implentation: iHelloMainWindow
///////////////////////////////////////////////////////////////////////
@implementation iHelloMainWindow
    - (iHelloMainWindow*)initWithRect:(iRect)contentRect
                         argc:(int)argc argv:(char**)argv env:(char**)env
                         surface:(lamna::app::gui::hello::cocoa::surface*)surface {
        [super initWithRect:contentRect argc:argc argv:argv env:env];
        surface_ = surface;
        return self;
    }
    - (iView*)createMainView:(int)argc argv:(char**)argv env:(char**)env {
        /*if ((mainView_ = [[iHelloMainView alloc] init:surface_])) {
            surface_->set_view(mainView_);
        }*/
        iHelloMainView* mainView = 0;
        if ((mainView_ = (mainView = [iHelloMainView alloc]))) {
            if ([mainView  init:surface_]) {
                surface_->set_view(mainView_);
            }
        }
        return mainView_;
    }
    - (const char*)mainTitleUTF8String:(int)argc argv:(char**)argv env:(char**)env {
        return LAMNA_APP_GUI_COCOA_IHELLO_WINDOW_TITLE;
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: iHelloMain
///////////////////////////////////////////////////////////////////////
@implementation iHelloMain
    - (id)init:(lamna::gui::main*)main {
        [super init:main];
        surface_ = new lamna::app::gui::hello::cocoa::surface
        (LAMNA_APP_GUI_HELLO_FG_COLOR_RED,
         LAMNA_APP_GUI_HELLO_FG_COLOR_GREEN,
         LAMNA_APP_GUI_HELLO_FG_COLOR_BLUE);
        return self;
    }
    - (iMainWindow*)createMainWindow:(iRect)contentRect
                    argc:(int)argc argv:(char**)argv env:(char**)env {
        iMainWindow* mainWindow = [[iHelloMainWindow alloc]
                                   initWithRect:contentRect
                                   argc:argc argv:argv env:env surface:surface_];
        return mainWindow;
    }
    - (iRect)contentRect:(int)argc argv:(char**)argv env:(char**)env {
        int x = LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_X,
            y = LAMNA_GUI_COCOA_IWINDOWMAIN_WINDOW_Y,
            width = LAMNA_APP_GUI_HELLO_WIDTH,
            height = LAMNA_APP_GUI_HELLO_HEIGHT;
        iRect contentRect = iMakeRect(x,y, width, height);
        return contentRect;
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: iMain
///////////////////////////////////////////////////////////////////////
@implementation iMain
    + (id<iOptMain>)create:(lamna::gui::main*)main {
        return [[iHelloMain alloc] init:main];
    }
@end
