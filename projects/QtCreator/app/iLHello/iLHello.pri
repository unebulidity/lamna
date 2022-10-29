########################################################################
# Copyright (c) 1988-2022 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: iLHello.pri
#
# Author: $author$
#   Date: 10/28/2022
#
# generic QtCreator project .pri file for framework lamna executable iLHello
########################################################################

########################################################################
# iLHello

# iLHello TARGET
#
iLHello_TARGET = iLHello

# iLHello INCLUDEPATH
#
iLHello_INCLUDEPATH += \
$${lamna_INCLUDEPATH} \

# iLHello DEFINES
#
iLHello_DEFINES += \
$${lamna_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
contains(UNAME,Darwin) {

# iLHello OBJECTIVE_HEADERS
#
iLHello_OBJECTIVE_HEADERS += \
$${LAMNA_SRC}/lamna/graphic/surface/cocoa/color.hh \
$${LAMNA_SRC}/lamna/graphic/surface/cocoa/object.hh \
$${LAMNA_SRC}/lamna/graphic/surface/cocoa/image.hh \
$${LAMNA_SRC}/lamna/graphic/surface/cocoa/context.hh \
$${LAMNA_SRC}/lamna/graphic/surface/cocoa/pixel.hh \
\
$${LAMNA_SRC}/lamna/gui/cocoa/iWindowMain.hh \
$${LAMNA_SRC}/lamna/gui/cocoa/iOptMain.hh \
$${LAMNA_SRC}/lamna/gui/cocoa/iMain.hh \
$${LAMNA_SRC}/lamna/gui/cocoa/iCocoa.hh \
$${LAMNA_SRC}/lamna/gui/cocoa/iOs.hh \
$${LAMNA_SRC}/lamna/gui/cocoa/apple/osx/cocoa.hh \
$${LAMNA_SRC}/lamna/gui/cocoa/os/os.hh \
\
$${LAMNA_SRC}/lamna/app/gui/cocoa/iHelloMain.hh \
$${LAMNA_SRC}/lamna/gui/cocoa/apple/osx/main.hh \
$${LAMNA_SRC}/lamna/gui/cocoa/apple/osx/main_main.hh \

# iLHello OBJECTIVE_SOURCES
#
iLHello_OBJECTIVE_SOURCES += \
$${LAMNA_SRC}/lamna/graphic/surface/cocoa/color.mm \
$${LAMNA_SRC}/lamna/graphic/surface/cocoa/object.mm \
$${LAMNA_SRC}/lamna/graphic/surface/cocoa/image.mm \
$${LAMNA_SRC}/lamna/graphic/surface/cocoa/context.mm \
$${LAMNA_SRC}/lamna/graphic/surface/cocoa/pixel.mm \
\
$${LAMNA_SRC}/lamna/gui/cocoa/iWindowMain.mm \
$${LAMNA_SRC}/lamna/gui/cocoa/iOptMain.mm \
$${LAMNA_SRC}/lamna/gui/cocoa/iMain.mm \
$${LAMNA_SRC}/lamna/gui/cocoa/iCocoa.mm \
$${LAMNA_SRC}/lamna/gui/cocoa/iOs.mm \
$${LAMNA_SRC}/lamna/gui/cocoa/apple/osx/cocoa.mm \
$${LAMNA_SRC}/lamna/gui/cocoa/os/os.mm \
\
$${LAMNA_SRC}/lamna/app/gui/cocoa/iHelloMain.mm \
$${LAMNA_SRC}/lamna/gui/cocoa/apple/osx/main.mm \
$${LAMNA_SRC}/lamna/gui/cocoa/apple/osx/main_main.mm \

} else {
} # contains(UNAME,Darwin)

########################################################################
# iLHello HEADERS
#
iLHello_HEADERS += \
$${LAMNA_SRC}/lamna/graphic/surface/color.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/object.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/image.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/context.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/pixel.hpp \
\
$${LAMNA_SRC}/lamna/gui/main.hpp \
\
$${LAMNA_SRC}/lamna/app/gui/hello/main.hpp \
\
$${LAMNA_SRC}/lamna/app/gui/lamna/hello/main.hpp \

# iLHello SOURCES
#
iLHello_SOURCES += \
$${LAMNA_SRC}/lamna/app/gui/lamna/hello/main.cpp \

########################################################################
# iLHello FRAMEWORKS
#
iLHello_FRAMEWORKS += \
$${lamna_FRAMEWORKS} \
$${lamna_cocoa_FRAMEWORKS} \

# iLHello LIBS
#
iLHello_LIBS += \
$${lamna_LIBS} \
$${lamna_cocoa_LIBS} \

########################################################################
# NO Qt
QT -= gui core

