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
///   File: handle.hpp
///
/// Author: $author$
///   Date: 6/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WINDOWS_HANDLE_HPP
#define _LAMNA_GUI_WINDOWS_HANDLE_HPP

#include "lamna/io/logger.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"

namespace lamna {
namespace gui {
namespace windows {

typedef implement_base handle_implement_base;
typedef base handle_base;

typedef xos::base::creatort<handle_implement_base> handle_creator;
typedef xos::base::attachert<HANDLE, int, 0, handle_creator> handle_attacher;
typedef xos::base::attachedt
<HANDLE, int, 0, handle_attacher, handle_base> handle_attached;
typedef xos::base::createdt
<HANDLE, int, 0, handle_attacher, handle_attached> handle_created;

typedef handle_attacher handle_implements;
typedef handle_created handle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: handlet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = handle_implements, class TExtends = handle_extends>

class _EXPORT_CLASS handlet: virtual public handle_implements, public handle_extends {
public:
    typedef handle_implements Implements;
    typedef handle_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    handlet(HANDLE detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    handlet(const handlet& copy)
    : Extends(copy.attached_to(), copy.is_created()) {
    }
    virtual ~handlet() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool destroy() {
        HANDLE detached = 0;
        if ((detached = this->detach())) {
            if ((CloseHandle(detached))) {
                return true;
            } else {
                LAMNA_LOG_ERROR("failed on CloseHandle()");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef handlet<> handle;

} // namespace windows 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WINDOWS_HANDLE_HPP 
