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
///   File: base.hpp
///
/// Author: $author$
///   Date: 5/25/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_BASE_BASE_HPP
#define _LAMNA_BASE_BASE_HPP

#include "xos/base/base.hpp"
#include "xos/base/array.hpp"
#include "xos/base/string.hpp"
#include "xos/base/date.hpp"
#include "xos/base/types.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/opener.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/base/wrapped.hpp"
#include "xos/base/to_string.hpp"
#include "xos/base/argv.hpp"

namespace lamna {

typedef xos::base::implement_base implement_base;
typedef xos::base::base base;

typedef xos::base::byte_array byte_array;
typedef xos::base::word_array word_array;

typedef xos::base::string string;
typedef xos::base::tstring tstring;
typedef xos::base::wstring wstring;

typedef xos::base::char_to_string char_to_string;
typedef xos::base::chars_to_string chars_to_string;
typedef xos::base::pointer_to_string pointer_to_string;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS bool_to_string: public string {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    bool_to_string(bool is_true) {
        this->append((is_true)?("true"):("false"));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace lamna

#endif // _LAMNA_BASE_BASE_HPP 
