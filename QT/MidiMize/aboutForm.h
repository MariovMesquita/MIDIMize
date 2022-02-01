#ifndef ABOUTFORM_H
#define ABOUTFORM_H

#include "ui_aboutForm.h"


class aboutForm : public QDialog, private Ui::Dialog
{
    Q_OBJECT

public:
    explicit aboutForm(QWidget *parent = nullptr);
    ~aboutForm();

private slots:
    void on_Dialog_accepted();
};


#endif // ABOUT_H_
