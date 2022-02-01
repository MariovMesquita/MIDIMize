TEMPLATE = app
TARGET = MidiMize

QT = core gui \
    widgets

LIBS += -pthread -lfluidsynth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    MidiMizeForm.h \
    cSynth.h \
    cmidimize.h \
    cprotectedbuffer.h \
    tled.h \
    ui_midimizeform.h

SOURCES += \
    MidiMizeForm.cpp \
    cSynth.cpp \
    cmidimize.cpp \
    cprotectedbuffer.cpp \
    main.cpp \
    tled.cpp

FORMS += ../UI/MidiMizeForm.ui \

RESOURCES += \
    resources.qrc
