# Copyright (c) 2025 Gregory Filatov
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts

CONFIG += c++20
QMAKE_CXXFLAGS += -Wno-deprecated-copy


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MyClasses/myClassesData.cpp \
    MyDict/dict_IIS.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    MyClasses/myClassesData.h \
    MyDict/dict_IIS.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
