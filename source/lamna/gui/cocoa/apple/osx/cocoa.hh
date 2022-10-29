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
///   File: cocoa.hh
///
/// Author: $author$
///   Date: 10/15/2015, 11/27/2020
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GUI_COCOA_APPLE_OSX_COCOA_HH
#define _LAMNA_GUI_COCOA_APPLE_OSX_COCOA_HH

#include <Cocoa/Cocoa.h>
#include "lamna/base/base.hpp"

namespace lamna {
namespace gui {
namespace cocoa {
namespace apple {
namespace osx {

} // namespace osx 
} // namespace apple 
} // namespace cocoa 
} // namespace gui 
} // namespace lamna 

#define iMakeRect NSMakeRect
#define iMakeSize NSMakeSize
#define iMakePoint NSMakePoint
#define iApp NSApp

typedef NSArray iArray;
typedef CGFloat iAxis;
typedef NSRect iRect;
typedef NSSize iSize;
typedef NSPoint iPoint;
typedef NSString iString;
typedef NSObject iObject;
typedef NSColor iColor;
typedef NSEvent iEvent;
typedef NSEventType iEventType;
enum {
    iLeftMouseDown = NSLeftMouseDown,
    iLeftMouseUp = NSLeftMouseUp,
    iLeftMouseDragged = NSLeftMouseDragged,
    iRightMouseDown = NSRightMouseDown,
    iRightMouseUp = NSRightMouseUp,
    iRightMouseDragged = NSRightMouseDragged,
};
typedef NSView iView;
typedef NSWindow iWindow;
@protocol iWindowDelegate <NSWindowDelegate>
@end
typedef NSApplication iApplication;
typedef NSAutoreleasePool iAutoreleasePool;
typedef NSProcessInfo iProcessInfo;
typedef NSUInteger iWindowStyleMask;
typedef NSBackingStoreType iBackingStoreType;
typedef NSNotification iNotification;
typedef NSTabView iTabView;
typedef NSOpenGLView iOpenGLView;

typedef NSOpenGLPixelFormat iOpenGLPixelFormat;
typedef NSOpenGLPixelFormatAttribute iOpenGLPixelFormatAttribute;
typedef NSOpenGLContext iOpenGLContext;
typedef NSGraphicsContext iGraphicsContext;
typedef CGFloat iCGFloat;
typedef CGContextRef iCGContextRef;
typedef CGColorSpaceRef iCGColorSpaceRef;
typedef CGImageRef iCGImageRef;
typedef CGDataProviderRef iCGDataProviderRef;
typedef CGInterpolationQuality  iCGInterpolationQuality;
#define iCGColorSpaceCreateDeviceRGB CGColorSpaceCreateDeviceRGB
#define iCGColorSpaceRelease CGColorSpaceRelease
#define iCGImageRelease CGImageRelease
#define iCGDataProviderRelease CGDataProviderRelease
#define iCGDataProviderCreateWithData CGDataProviderCreateWithData
#define iCGImageCreate CGImageCreate
#define iCGContextSaveGState CGContextSaveGState
#define iCGContextRestoreGState CGContextRestoreGState
#define iCGContextSetShouldAntialias CGContextSetShouldAntialias
#define iCGContextSetInterpolationQuality CGContextSetInterpolationQuality
#define iCGContextTranslateCTM CGContextTranslateCTM
#define iCGContextScaleCTM CGContextScaleCTM
#define iCGContextDrawImage CGContextDrawImage

typedef NSBox iBox;
typedef NSMenu iMenu;
typedef NSMenuItem iMenuItem;
typedef NSTextField iTextField;
typedef NSButton iPushButton;
typedef NSComboBox iComboBox;
typedef NSPopUpButton iPopUpButton;
typedef NSProgressIndicator iProgressIndicator;
typedef NSLevelIndicator iLevelIndicator;
#define iDiscreteCapacityLevelIndicatorStyle NSDiscreteCapacityLevelIndicatorStyle
#define iContinuousCapacityLevelIndicatorStyle NSContinuousCapacityLevelIndicatorStyle
#define iRatingLevelIndicatorStyle NSRatingLevelIndicatorStyle
#define iRelevancyLevelIndicatorStyle NSRelevancyLevelIndicatorStyle
typedef NSCell iCell;
typedef NSSlider iSlider;
typedef NSMenuItem iMenuItem;
typedef NSStepper iStepper;
typedef NSPasteboard iPasteboard;
#define iFilenamesPboardType NSFilenamesPboardType
typedef NSDragOperation iDragOperation;
@protocol iDraggingInfo <NSDraggingInfo>
@end
enum {
    iDragOperationNone = NSDragOperationNone,
    iDragOperationCopy = NSDragOperationCopy,
    iDragOperationLink = NSDragOperationLink,
    iDragOperationGeneric = NSDragOperationGeneric,
    iDragOperationPrivate = NSDragOperationPrivate,
    iDragOperationAll_Obsolete = NSDragOperationAll_Obsolete,
    iDragOperationMove = NSDragOperationMove,
    iDragOperationDelete = NSDragOperationDelete,
    iDragOperationEvery = NSDragOperationEvery
};

enum {
    iProgressIndicatorBarStyle = NSProgressIndicatorBarStyle
};

#define iRadioButton NSRadioButton
#define iSwitchButton NSSwitchButton
#define iRoundedBezelStyle NSRoundedBezelStyle

enum {
    iMixedState = NSMixedState,
    iOffState   = NSOffState,
    iOnState    = NSOnState
};

enum {
    iTitledWindowMask = NSTitledWindowMask,
    iClosableWindowMask = NSClosableWindowMask,
    iMiniaturizableWindowMask = NSMiniaturizableWindowMask,
    iResizableWindowMask = NSResizableWindowMask
};

enum {
    iDefaultDesktopWindowMask
    = iTitledWindowMask | iClosableWindowMask
    | iMiniaturizableWindowMask | iResizableWindowMask
};

enum {
    iBackingStoreBuffered = NSBackingStoreBuffered
};

enum {
    iDefaultDesktopWindowBacking = iBackingStoreBuffered
};

#define iRectFill NSRectFill
#define iRectFillUsingOperation NSRectFillUsingOperation
typedef NSCompositingOperation iCompositingOperation;
enum {
    iCompositeClear = NSCompositeClear, // (R = 0)
    iCompositeCopy = NSCompositeCopy, // (R = S)
    iCompositeSourceOver = NSCompositeSourceOver, // (R = S + D*(1 - Sa))
    iCompositeSourceIn = NSCompositeSourceIn, // (R = S*Da)
    iCompositeSourceOut = NSCompositeSourceOut, // (R = S*(1 - Da))
    iCompositeSourceAtop = NSCompositeSourceAtop, // (R = S*Da + D*(1 - Sa))
    iCompositeDestinationOver = NSCompositeDestinationOver, // (R = S*(1 - Da) + D)
    iCompositeDestinationIn = NSCompositeDestinationIn, // (R = D*Sa)
    iCompositeDestinationOut = NSCompositeDestinationOut, // (R = D*(1 - Sa))
    iCompositeDestinationAtop = NSCompositeDestinationAtop, // (R = S*(1 - Da) + D*Sa)
    iCompositeXOR = NSCompositeXOR, // (R = S*(1 - Da) + D*(1 - Sa))
    iCompositePlusDarker = NSCompositePlusDarker, // (R = MAX(0, (1 - D) + (1 - S)))
    iCompositePlusLighter = NSCompositePlusLighter, // (R = MIN(1, S + D))
};

#endif // _LAMNA_GUI_COCOA_APPLE_OSX_COCOA_HH
