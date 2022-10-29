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
///   File: iHelloMain.hh
///
/// Author: $author$
///   Date: 10/16/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_APP_GUI_COCOA_IHELLOMAIN_HH
#define _LAMNA_APP_GUI_COCOA_IHELLOMAIN_HH

#include "lamna/gui/cocoa/iWindowMain.hh"
#include "lamna/app/gui/hello/main.hpp"
#include "lamna/graphic/surface/cocoa/pixel.hh"

#define LAMNA_APP_GUI_COCOA_IHELLO_WINDOW_TITLE "ilhello"

namespace lamna {
namespace app {
namespace gui {
namespace hello {
namespace cocoa {

class _EXPORT_CLASS surface;

} // namespace cocoa
} // namespace hello
} // namespace gui 
} // namespace app 
} // namespace lamna 

///////////////////////////////////////////////////////////////////////
/// Interface: iHelloMainView
///////////////////////////////////////////////////////////////////////
@interface iHelloMainView: iMainView {
    lamna::app::gui::hello::cocoa::surface* surface_;
    }
    - (id)init:(lamna::app::gui::hello::cocoa::surface*)surface;
    - (void)drawRect:(iRect)rect;
    - (void)mouseUp:(iEvent*)theEvent;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: iHelloMainWindow
///////////////////////////////////////////////////////////////////////
@interface iHelloMainWindow: iMainWindow {
    lamna::app::gui::hello::cocoa::surface* surface_;
    }
    - (iMainWindow*)initWithRect:(iRect)contentRect
                    argc:(int)argc argv:(char**)argv env:(char**)env
                    surface:(lamna::app::gui::hello::cocoa::surface*)surface;
    - (iView*)createMainView:(int)argc argv:(char**)argv env:(char**)env;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: iHelloMain
///////////////////////////////////////////////////////////////////////
@interface iHelloMain: iWindowMain {
    lamna::app::gui::hello::cocoa::surface* surface_;
    }
    - (id)init:(lamna::gui::main*)main;
    - (iMainWindow*)createMainWindow:(iRect)contentRect
                    argc:(int)argc argv:(char**)argv env:(char**)env;
    - (iRect)contentRect:(int)argc argv:(char**)argv env:(char**)env;
@end

namespace lamna {
namespace app {
namespace gui {
namespace hello {
namespace cocoa {

typedef hello::surfacet<base> surface_extends;
///////////////////////////////////////////////////////////////////////
///  Class: surface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS surface: public surface_extends {
public:
    typedef surface_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    surface
    (int fg_color_red, int fg_color_green, int fg_color_blue)
    : Extends(fg_color_red, fg_color_green, fg_color_blue),
      view_(0) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual iView* set_view(iView* to) {
        view_ = to;
        return view_;
    }
    virtual iView* view() const {
        return view_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void invalidate() {
        if ((view_)) {
            [view_ setNeedsDisplayInRect:[view_ bounds]];
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    iView* view_;
};

} // namespace cocoa
} // namespace hello
} // namespace gui
} // namespace app
} // namespace lamna

#endif // _LAMNA_APP_GUI_COCOA_IHELLOMAIN_HH
