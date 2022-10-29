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
#   File: lamna.pri
#
# Author: $author$
#   Date: 10/28/2022
#
# build specific QtCreator project .pri file for framework lamna
########################################################################
# Depends: xosnadir;xosrostra

contains(BUILD_OS,Uname) {
UNAME = $$system(uname)

contains(UNAME,Darwin) {
BUILD_OS = macosx
} else {
contains(UNAME,Linux) {
BUILD_OS = linux
} else {
contains(UNAME,Windows) {
BUILD_OS = windows
} else {
BUILD_OS = os
} # contains(UNAME,Windows)
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)
} else {
contains(BUILD_OS,LAMNA_OS) {
} else {
BUILD_OS = os
} # contains(BUILD_OS,LAMNA_OS)
} # contains(BUILD_OS,Uname)

#BUILD_CPP_VERSION = 11

########################################################################
# xosnadir
#
# pkg-config --cflags --libs xosnadir
#

# build xosnadir INCLUDEPATH
#
build_xosnadir_INCLUDEPATH += \

# build xosnadir DEFINES
#
build_xosnadir_DEFINES += \

# build xosnadir FRAMEWORKS
#
build_xosnadir_FRAMEWORKS += \

# build xosnadir LIBS
#
build_xosnadir_LIBS += \

########################################################################
# xosrostra
#
# pkg-config --cflags --libs xosrostra
#

# build xosrostra INCLUDEPATH
#
build_xosrostra_INCLUDEPATH += \

# build xosrostra DEFINES
#
build_xosrostra_DEFINES += \

# build xosrostra FRAMEWORKS
#
build_xosrostra_FRAMEWORKS += \

# build xosrostra LIBS
#
build_xosrostra_LIBS += \

########################################################################
# lamna

# build lamna INCLUDEPATH
#
build_lamna_INCLUDEPATH += \
$${build_xosrostra_INCLUDEPATH} \
$${build_xosnadir_INCLUDEPATH} \


# build lamna DEFINES
#
build_lamna_DEFINES += \
$${build_xosnadir_DEFINES} \
$${build_xosrostra_DEFINES} \


# build lamna FRAMEWORKS
#
build_lamna_FRAMEWORKS += \
$${build_xosrostra_FRAMEWORKS} \
$${build_xosnadir_FRAMEWORKS} \


# build lamna LIBS
#
build_lamna_LIBS += \
$${build_xosrostra_LIBS} \
$${build_xosnadir_LIBS} \

########################################################################
