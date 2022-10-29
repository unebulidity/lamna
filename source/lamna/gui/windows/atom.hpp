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
///   File: atom.hpp
///
/// Author: $author$
///   Date: 6/7/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_WINDOWS_ATOM_HPP
#define _LAMNA_GUI_WINDOWS_ATOM_HPP

#include "lamna/io/logger.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"

namespace lamna {
namespace gui {
namespace windows {

typedef implement_base atom_implement_base;
typedef base atom_base;

typedef xos::base::creatort<atom_implement_base> atom_creator;
typedef xos::base::attachert<ATOM, int, 0, atom_creator> atom_attacher;
typedef xos::base::attachedt
<ATOM, int, 0, atom_attacher, atom_base> atom_attached;
typedef xos::base::createdt
<ATOM, int, 0, atom_attacher, atom_attached> atom_created;

typedef atom_attacher atom_implements;
typedef atom_created atom_extends;
///////////////////////////////////////////////////////////////////////
///  Class: atomt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = atom_implements, class TExtends = atom_extends>

class _EXPORT_CLASS atomt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    atomt(ATOM detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    atomt(const atomt& copy)
    : Extends(copy.attached_to(), copy.is_created()) {
    }
    virtual ~atomt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef atomt<> atom;

} // namespace windows 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_WINDOWS_ATOM_HPP 
