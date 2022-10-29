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
///   File: pixbuf.hpp
///
/// Author: $author$
///   Date: 10/8/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_GDK_PIXBUF_HPP
#define _LAMNA_GUI_GDK_PIXBUF_HPP

#include "lamna/gui/gdk/gdk.hpp"
#include "lamna/io/logger.hpp"

namespace lamna {
namespace gui {
namespace gdk {

typedef GdkPixbuf* pixbuf_attached_t;
typedef xos::base::creatort<implement_base> pixbuf_creator;
typedef xos::base::attachert<pixbuf_attached_t, int, 0, pixbuf_creator> pixbuf_attacher;
typedef xos::base::attachedt<pixbuf_attached_t, int, 0, pixbuf_attacher, base> pixbuf_attached;
typedef xos::base::createdt<pixbuf_attached_t, int, 0, pixbuf_attacher, pixbuf_attached> pixbuf_created;
typedef pixbuf_attacher pixbuf_implements;
typedef pixbuf_created pixbuf_extends;
///////////////////////////////////////////////////////////////////////
///  Class: pixbuft
///////////////////////////////////////////////////////////////////////
template
<class TImplements = pixbuf_implements, class TExtends = pixbuf_extends>

class _EXPORT_CLASS pixbuft: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::attached_t attached_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pixbuft(attached_t detached = 0, bool is_created = false)
    : Extends(detached, is_created) {
    }
    virtual ~pixbuft() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create(const char* filename) {
        attached_t detached = 0;
        if ((detached = create_attached(filename))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        attached_t detached = 0;
        if ((detached = this->detach())) {
            if ((destroy_detached(detached))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t create_attached(const char* filename) {
        attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(filename))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t create_detached(const char* filename) const {
        attached_t detached = 0;
        if ((filename)) {
            GError* error = 0;
            string error_string;
            if (!(detached = gdk_pixbuf_new_from_file(filename, &error))) {
                if ((error)) {
                    error_string.append_int(error->code);
                    error_string.appendl(" (\"", ((error->message)?(error->message):("")), "\")", NULL);
                }
                LAMNA_LOG_ERROR("failed " << error_string << " on gdk_pixbuf_new_from_file(\"" << filename << "\",...)");
            }
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        bool success = false;
        if ((detached)) {
            g_object_unref(detached);
            success = true;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator attached_t () const {
        return this->attached_to();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef pixbuft<> pixbuf;

} // namespace gdk 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_GDK_PIXBUF_HPP 
