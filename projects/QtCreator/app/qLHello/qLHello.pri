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
#   File: qLHello.pri
#
# Author: $author$
#   Date: 10/28/2022
#
# generic QtCreator project .pri file for framework lamna executable qLHello
########################################################################

########################################################################
# qLHello

# qLHello TARGET
#
qLHello_TARGET = qLHello

# qLHello INCLUDEPATH
#
qLHello_INCLUDEPATH += \
$${lamna_INCLUDEPATH} \

# qLHello DEFINES
#
qLHello_DEFINES += \
$${lamna_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# qLHello OBJECTIVE_HEADERS
#
#qLHello_OBJECTIVE_HEADERS += \
#$${LAMNA_SRC}/xos/app/console/qLHello/main.hh \

# qLHello OBJECTIVE_SOURCES
#
#qLHello_OBJECTIVE_SOURCES += \
#$${LAMNA_SRC}/xos/app/console/qLHello/main.mm \

########################################################################
# qLHello HEADERS
#
qLHello_HEADERS += \
$${LAMNA_SRC}/lamna/graphic/surface/qt/color.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/qt/object.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/qt/image.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/qt/context.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/qt/pixel.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/color.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/object.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/image.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/context.hpp \
$${LAMNA_SRC}/lamna/graphic/surface/pixel.hpp \
$${LAMNA_SRC}/lamna/graphic/image_object.hpp \
$${LAMNA_SRC}/lamna/graphic/hollow_midpoint_ellipse.hpp \
$${LAMNA_SRC}/lamna/graphic/hollow_midpoint_circle.hpp \
$${LAMNA_SRC}/lamna/graphic/midpoint_ellipse.hpp \
$${LAMNA_SRC}/lamna/graphic/midpoint_circle.hpp \
$${LAMNA_SRC}/lamna/graphic/triangle.hpp \
$${LAMNA_SRC}/lamna/graphic/bresenham_line_context.hpp \
$${LAMNA_SRC}/lamna/graphic/bresenham_line.hpp \
$${LAMNA_SRC}/lamna/graphic/image.hpp \
$${LAMNA_SRC}/lamna/graphic/image_point.hpp \
$${LAMNA_SRC}/lamna/graphic/image_base.hpp \
$${LAMNA_SRC}/lamna/graphic/list.hpp \
\
$${LAMNA_SRC}/lamna/gui/qt/application/window_main.hpp \
$${LAMNA_SRC}/lamna/gui/qt/application/main.hpp \
$${LAMNA_SRC}/lamna/gui/qt/main.hpp \
$${LAMNA_SRC}/lamna/gui/main.hpp \
\
$${LAMNA_SRC}/lamna/app/gui/qt/hello/main.hpp \
$${LAMNA_SRC}/lamna/app/gui/hello/main.hpp \
\
$${LAMNA_SRC}/lamna/console/main.hpp \
$${LAMNA_SRC}/lamna/console/main_opt.hpp \
$${LAMNA_SRC}/lamna/console/main_main.hpp \

# qLHello SOURCES
#
qLHello_SOURCES += \
$${LAMNA_SRC}/lamna/graphic/surface/qt/color.cpp \
$${LAMNA_SRC}/lamna/graphic/surface/qt/object.cpp \
$${LAMNA_SRC}/lamna/graphic/surface/qt/image.cpp \
$${LAMNA_SRC}/lamna/graphic/surface/qt/context.cpp \
$${LAMNA_SRC}/lamna/graphic/surface/qt/pixel.cpp \
$${LAMNA_SRC}/lamna/graphic/hollow_midpoint_ellipse.cpp \
$${LAMNA_SRC}/lamna/graphic/hollow_midpoint_circle.cpp \
$${LAMNA_SRC}/lamna/graphic/midpoint_ellipse.cpp \
$${LAMNA_SRC}/lamna/graphic/midpoint_circle.cpp \
$${LAMNA_SRC}/lamna/graphic/triangle.cpp \
$${LAMNA_SRC}/lamna/graphic/bresenham_line_context.cpp \
$${LAMNA_SRC}/lamna/graphic/bresenham_line.cpp \
$${LAMNA_SRC}/lamna/graphic/image_point.cpp \
$${LAMNA_SRC}/lamna/graphic/image_base.cpp \
$${LAMNA_SRC}/lamna/graphic/list.cpp \
\
$${LAMNA_SRC}/lamna/gui/qt/application/window_main.cpp \
\
$${LAMNA_SRC}/lamna/app/gui/qt/hello/main.cpp \
\
$${LAMNA_SRC}/lamna/console/main_opt.cpp \
$${LAMNA_SRC}/lamna/console/main_main.cpp \

########################################################################
# qLHello FRAMEWORKS
#
qLHello_FRAMEWORKS += \
$${lamna_FRAMEWORKS} \
$${lamna_qt_FRAMEWORKS} \

# qLHello LIBS
#
qLHello_LIBS += \
$${lamna_LIBS} \
$${lamna_qt_LIBS} \

########################################################################
# NO Qt
#QT -= gui core

