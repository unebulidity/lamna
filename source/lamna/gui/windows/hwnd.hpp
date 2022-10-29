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
///   File: hwnd.hpp
///
/// Author: $author$
///   Date: 6/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WINDOWS_HWND_HPP
#define _LAMNA_GUI_WINDOWS_HWND_HPP

#include "lamna/gui/windows/handle.hpp"

namespace lamna {
namespace gui {
namespace windows {

typedef implement_base hwnd_implement_base;
typedef base hwnd_base;

typedef xos::base::creatort<hwnd_implement_base> hwnd_creator;
typedef xos::base::attachert<HWND, int, 0, hwnd_creator> hwnd_attacher;
typedef xos::base::attachedt
<HWND, int, 0, hwnd_attacher, hwnd_base> hwnd_attached;
typedef xos::base::createdt
<HWND, int, 0, hwnd_attacher, hwnd_attached> hwnd_created;

///////////////////////////////////////////////////////////////////////
///  Class: hwnd_implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = hwnd_attacher>
class _EXPORT_CLASS hwnd_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HINSTANCE attach_instance(HINSTANCE instance) {
        return 0;
    }
    virtual HINSTANCE attached_to_instance() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef hwnd_implementt<> hwnd_implement;
typedef hwnd_implement hwnd_implements;
typedef hwnd_created hwnd_extends;
///////////////////////////////////////////////////////////////////////
///  Class: hwndt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = hwnd_implements, class TExtends = hwnd_extends>

class _EXPORT_CLASS hwndt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    hwndt(HINSTANCE instance = 0, HWND detached = 0, bool is_created = false)
    : Extends(detached, is_created), instance_(instance) {
    }
    hwndt(const hwndt& copy): Extends(copy) {
    }
    virtual ~hwndt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HWND attach_created
    (HINSTANCE instance, HWND detached, bool is_created = true) {
        Extends::attach_created(detached, is_created);
        instance_ = instance;
        return this->attached_to();
    }
    virtual HWND detach_created(HINSTANCE& instance, bool& is_created) {
        instance = instance_;
        return Extends::detach_created(is_created);
    }
    virtual HWND detach_created(bool& is_created) {
        instance_ = 0;
        return Extends::detach_created(is_created);
    }
    virtual HWND detach() {
        instance_ = 0;
        return Extends::detach();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HINSTANCE attach_instance(HINSTANCE instance) {
        instance_ = instance;
        return instance_;
    }
    virtual HINSTANCE attached_to_instance() const {
        return instance_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    HINSTANCE instance_;
};
typedef hwndt<> hwnd;

} // namespace windows 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WINDOWS_HWND_HPP 
