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
///   File: iCocoa.hh
///
/// Author: $author$
///   Date: 10/15/2015
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_COCOA_ICOCOA_HH
#define _LAMNA_GUI_COCOA_ICOCOA_HH

#include "lamna/gui/cocoa/iOs.hh"
#if defined(APPLE_IOS)
#include "lamna/gui/cocoa/apple/ios/cocoa.hh"
#else // defined(APPLE_IOS)
#include "lamna/gui/cocoa/apple/osx/cocoa.hh"
#endif // defined(APPLE_IOS)
#include "lamna/io/logger.hpp"

namespace lamna {
namespace gui {
namespace cocoa {

} // namespace cocoa 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_COCOA_ICOCOA_HH
