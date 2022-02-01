TEMPLATE = app
TARGET = MidiMize

QT = core gui \
    widgets

LIBS += -pthread -lfluidsynth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    MidiMizeForm.h \
    aboutForm.h \
    cSynth.h \
    cmidimize.h \
    cprotectedbuffer.h \
    tled.h \
    ui_MidiMizeForm.h \
    ui_aboutForm.h

SOURCES += \
    MidiMizeForm.cpp \
    aboutForm.cpp \
    cSynth.cpp \
    cmidimize.cpp \
    cprotectedbuffer.cpp \
    main.cpp \
    tled.cpp

FORMS += ../UI/MidiMizeForm.ui \ \
    ../UI/aboutForm.ui

RESOURCES += \
    resources.qrc
