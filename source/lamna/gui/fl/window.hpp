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
///   File: window.hpp
///
/// Author: $author$
///   Date: 9/30/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_FL_WINDOW_HPP
#define _LAMNA_GUI_FL_WINDOW_HPP

#include "lamna/gui/fl/widget.hpp"

namespace lamna {
namespace gui {
namespace fl {

typedef widget_implements window_implements;
typedef widgett<Fl_Window, window_implements> window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: windowt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = window_implements, class TExtends = window_extends>

class _EXPORT_CLASS windowt: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    windowt(int width, int height): Extends(width, height) {
    }
    windowt() {
    }
    virtual ~windowt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef windowt<> window;

} // namespace fl 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_FL_WINDOW_HPP 
