#-------------------------------------------------
#
# Project created by QtCreator 2012-06-30T16:47:14
#
#-------------------------------------------------

QT       += core gui \
         += multimedia \
         += opengl
TARGET = Instrument_Trainer
TEMPLATE = app

OTHER_FILES += \
    .hg/00changelog.i

CONFIG += qwt
RESOURCES +=

HEADERS += \
    mainwindow.h \
    dywapitchtrack.h \
    audioengine.h \
    trace.h \
    common.h \
    plot.h \
    signaldata.h \
    curvedata.h

SOURCES += \
    mainwindow.cpp \
    main.cpp \
    dywapitchtrack.cpp \
    audioengine.cpp \
    trace.cpp \
    plot.cpp \
    signaldata.cpp \
    curvedata.cpp

FORMS += \
    mainwindow.ui

UI_DIR = ../qt
