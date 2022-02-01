#ifndef MIDIMIZEFORM_H
#define MIDIMIZEFORM_H

#include "ui_midimizeform.h"


class MidiMizeForm : public QMainWindow, private Ui::MidiMizeForm
{
    Q_OBJECT

public:
    explicit MidiMizeForm(QWidget *parent = nullptr);
    ~MidiMizeForm();

private slots:

};


#endif // MIDIMIZEFORM_H
