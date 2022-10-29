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
///   File: main.cpp
///
/// Author: $author$
///   Date: 9/23/2015
///////////////////////////////////////////////////////////////////////
#include "lamna/app/gui/wx/hello/main.hpp"

namespace lamna {
namespace app {
namespace gui {
namespace wx {
namespace hello {

///////////////////////////////////////////////////////////////////////
///  Class: frame
///////////////////////////////////////////////////////////////////////
BEGIN_EVENT_TABLE(frame, frame_extends)
    EVT_PAINT   (frame::OnPaintEvent)
    EVT_SIZE    (frame::OnSizeEvent)
    EVT_LEFT_UP (frame::OnLButtonUpEvent)
END_EVENT_TABLE()

///////////////////////////////////////////////////////////////////////
///  Class: app
///////////////////////////////////////////////////////////////////////
wxIMPLEMENT_APP_NO_MAIN(app);

///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
static main the_main;
main& main::the_instance() {
    return hello::the_main;
}

} // namespace hello
} // namespace wx 
} // namespace gui 
} // namespace app 
} // namespace lamna 
