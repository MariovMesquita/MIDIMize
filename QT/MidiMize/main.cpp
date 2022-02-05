#include <QApplication>
#include <QTime>
#include "MidiMizeForm.h"
#include "cmidimize.h"

int main(int argc, char** argv)
{
    QApplication app (argc, argv);
    app.setStyle("fusion");

    MidiMizeForm gui;
    gui.show();

    return app.exec();
}
