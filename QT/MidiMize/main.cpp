#include <QApplication>

#include "cgui.h"

int main(int argc, char** argv)
{
    QApplication app (argc, argv);

    CGui gui;
    gui.show();

    return app.exec();
}
