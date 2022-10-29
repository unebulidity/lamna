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
///   File: gtk.hpp
///
/// Author: $author$
///   Date: 6/20/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_GTK_GTK_HPP
#define _LAMNA_GUI_GTK_GTK_HPP

#include "lamna/base/base.hpp"
#include <gtk/gtk.h>

#if !defined(G_POINTER)
#define G_POINTER(p) ((gpointer)(p))
#endif // !defined(G_POINTER)

#if ((GTK_MAJOR_VERSION == 3))
#if ((GTK_MINOR_VERSION < 8))
#define gtk_tree_view_set_activate_on_single_click(w, v)
#endif // ((GTK_MINOR_VERSION < 8))
#endif // ((GTK_MAJOR_VERSION == 3))

namespace lamna {
namespace gui {
namespace gtk {

typedef gchar char_t;
typedef xos::base::typest<char_t> chars_t;
typedef xos::base::stringt<char_t> string_t;

typedef xos::base::typest<gchar> gchars;
typedef xos::base::stringt<gchar> gstring;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS gpointer_to_string: public string_t {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    gpointer_to_string(gpointer p) {
        this->append("0x");
        this->appendx(&p, sizeof(gpointer));
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace gtk
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_GTK_GTK_HPP 
