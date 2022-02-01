#include "aboutForm.h"
#include <QWidget>


aboutForm::aboutForm(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
}

aboutForm::~aboutForm(){}


void aboutForm::on_Dialog_accepted()
{
    done(0);
}
