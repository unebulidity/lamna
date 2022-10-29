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
///   File: os.hh
///
/// Author: $author$
///   Date: 10/15/2015, 11/27/2020
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_COCOA_OS_OS_HH
#define _LAMNA_GUI_COCOA_OS_OS_HH

#if defined(__APPLE__)
#include <TargetConditionals.h>
#include <Availability.h>
#if (TARGET_OS_IPHONE)
#if !defined(APPLE_IOS)
#define APPLE_IOS
#endif // !defined(APPLE_IOS)
#else // (TARGET_OS_IPHONE)
#if defined(APPLE_IOS)
#error APPLE_IOS already defined
#endif // defined(APPLE_IOS)
#endif // (TARGET_OS_IPHONE)
#else // defined(__APPLE__)
#error Unsupported Os
#endif // defined(__APPLE__)

namespace lamna {
namespace gui {
namespace cocoa {
namespace apple {
namespace ios { }
namespace osx { }
} // namespace apple
namespace os {

#if defined(APPLE_IOS)
namespace os = apple::ios;
#else // defined(APPLE_IOS)
namespace os = apple::osx;
#endif // defined(APPLE_IOS)

} // namespace os
} // namespace cocoa 
} // namespace gui 
} // namespace lamna 

#endif // _LAMNA_GUI_COCOA_OS_OS_HH 
