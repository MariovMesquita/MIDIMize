TEMPLATE = app
TARGET = MidiMize

QT = core gui \
    widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
