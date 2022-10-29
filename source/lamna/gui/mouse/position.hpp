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
///   File: position.hpp
///
/// Author: $author$
///   Date: 6/5/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_MOUSE_POSITION_HPP
#define _LAMNA_GUI_MOUSE_POSITION_HPP

#include "lamna/base/base.hpp"

namespace lamna {
namespace gui {
namespace mouse {

///////////////////////////////////////////////////////////////////////
///  Class: positiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = implement_base, class TExtends = base>

class _EXPORT_CLASS positiont: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    positiont(ssize_t x, ssize_t y): x_(x), y_(y) {
    }
    positiont(): x_(0), y_(0) {
    }
    positiont(const positiont& copy): x_(copy.x_), y_(copy.y_) {
    }
    virtual ~positiont() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t x() const { return x_; }
    virtual ssize_t y() const { return y_; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    ssize_t x_, y_;
};
typedef positiont<> position;

} // namespace mouse 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_MOUSE_POSITION_HPP 
