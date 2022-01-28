TEMPLATE = app
TARGET = MidiMize

QT = core gui \
    widgets

LIBS += -pthread -lfluidsynth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    cSynth.h \
    cgui.h \
    cmidimize.h \
    cprotectedbuffer.h \
    tled.h

SOURCES += \
    cSynth.cpp \
    cgui.cpp \
    cmidimize.cpp \
    cprotectedbuffer.cpp \
    main.cpp \
    tled.cpp

FORMS += \
    ../UI/MidiMize.ui

RESOURCES += \
    resources.qrc
