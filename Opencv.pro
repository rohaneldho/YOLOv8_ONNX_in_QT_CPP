QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    inference.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    inference.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../cpp/YouTube/opencv/build/x64/vc16/lib/ -lopencv_world4100
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../cpp/YouTube/opencv/build/x64/vc16/lib/ -lopencv_world4100
INCLUDEPATH += $$PWD/../../../../../../../cpp/YouTube/opencv/build/include
DEPENDPATH += $$PWD/../../../../../../../cpp/YouTube/opencv/build/include


# win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../opencv/OpenCV-MinGW-Build-OpenCV-4.5.5-x64/x64/mingw/lib/-llibopencv_core455.dll

# else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../opencv/OpenCV-MinGW-Build-OpenCV-4.5.5-x64/x64/mingw/lib/-llibopencv_core455.dll
# else:unix: LIBS += -L$$PWD/../../opencv/OpenCV-MinGW-Build-OpenCV-4.5.5-x64/x64/mingw/ -llibopencv_core455.dll

# INCLUDEPATH += $$PWD/../../opencv/OpenCV-MinGW-Build-OpenCV-4.5.5-x64/include
# DEPENDPATH += $$PWD/../../opencv/OpenCV-MinGW-Build-OpenCV-4.5.5-x64/include
