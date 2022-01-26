TEMPLATE = app
TARGET = MidiMize

QT = core gui \
    widgets

LIBS += -pthread

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    cSynth.h \
    cmidimize.h \
    cprotectedbuffer.h

SOURCES += \
    cSynth.cpp \
    cmidimize.cpp \
    cprotectedbuffer.cpp
