/********************************************************************************
** Form generated from reading UI file 'MidiMizeForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIDIMIZEFORM_H
#define UI_MIDIMIZEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MidiMizeForm
{
public:
    QWidget *centralwidget;
    QFrame *hLine1;
    QFrame *vLine4;
    QFrame *vLine3;
    QFrame *vLine2;
    QFrame *vLine1;
    QFrame *hLine2;
    QWidget *osc1ChorusWidget;
    QLabel *osc1ChorusNrLabel;
    QLabel *osc1ChorusDepthLabel;
    QLabel *osc1ChorusSpeedLabel;
    QLabel *osc1ChorusLvlLabel;
    QPushButton *osc1ChorusEnable;
    QLabel *osc1ChorusEnableLabel;
    QDial *osc1ChorusDepth;
    QDial *osc1ChorusSpeed;
    QDial *osc1ChorusLvl;
    QDial *osc1ChorusNr;
    QWidget *osc2ReverbWidget;
    QLabel *osc2ReverbWidthLabel;
    QLabel *osc2ReverbRoomLabel;
    QLabel *osc2ReverbLvlLabel;
    QLabel *osc2ReverbDampLabel;
    QPushButton *osc2ReverbEnable;
    QLabel *osc2ReverbEnableLabel;
    QDial *osc2ReverbRoom;
    QDial *osc2ReverbLvl;
    QDial *osc2ReverbDamp;
    QDial *osc2ReverbWidth;
    QWidget *osc2ChorusWidget;
    QLabel *osc2ChorusNrLabel;
    QLabel *osc2ChorusDepthLabel;
    QLabel *osc2ChorusSpeedLabel;
    QLabel *osc2ChorusLvlLabel;
    QPushButton *osc2ChorusEnable;
    QLabel *osc2ChorusEnableLabel;
    QDial *osc2ChorusDepth;
    QDial *osc2ChorusSpeed;
    QDial *osc2ChorusLvl;
    QDial *osc2ChorusNr;
    QWidget *noteTouchWidget;
    QWidget *pitchTouchWidget;
    QWidget *osc1ReverbWidget;
    QLabel *osc1ReverbWidthLabel;
    QLabel *osc1ReverbRoomLabel;
    QLabel *osc1ReverbLvlLabel;
    QLabel *osc1ReverbDampLabel;
    QPushButton *osc1ReverbEnable;
    QLabel *osc1ReverbEnableLabel;
    QDial *osc1ReverbRoom;
    QDial *osc1ReverbLvl;
    QDial *osc1ReverbDamp;
    QDial *osc1ReverbWidth;
    QWidget *osc2Widget;
    QLabel *osc2Label;
    QWidget *osc2Wave;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *osc2SineRbutton;
    QRadioButton *osc2TriRbutton;
    QRadioButton *osc2SawRbutton;
    QPushButton *osc2Pbutton;
    QWidget *osc1Widget;
    QWidget *osc1Wave;
    QVBoxLayout *verticalLayout;
    QRadioButton *osc1SineRbutton;
    QRadioButton *osc1TriRbutton;
    QRadioButton *osc1SawRbutton;
    QPushButton *osc1Pbutton;
    QLabel *osc1Label;
    QWidget *gainWidget;
    QLabel *gainLabel;
    QDial *gainDial;
    QWidget *soloMidiSelect;
    QHBoxLayout *horizontalLayout;
    QRadioButton *soloRbutton;
    QRadioButton *midiRbutton;
    QWidget *logoWidget;
    QPushButton *aboutButton;
    QLabel *label;
    QLabel *logo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MidiMizeForm)
    {
        if (MidiMizeForm->objectName().isEmpty())
            MidiMizeForm->setObjectName(QString::fromUtf8("MidiMizeForm"));
        MidiMizeForm->setWindowModality(Qt::ApplicationModal);
        MidiMizeForm->setEnabled(true);
        MidiMizeForm->resize(1024, 600);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(80, 209, 198, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(155, 255, 247, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(117, 232, 222, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(40, 104, 99, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(53, 139, 132, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(167, 232, 226, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        MidiMizeForm->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Syntha Nova"));
        MidiMizeForm->setFont(font);
        MidiMizeForm->setMouseTracking(false);
        MidiMizeForm->setContextMenuPolicy(Qt::NoContextMenu);
        MidiMizeForm->setAcceptDrops(false);
        MidiMizeForm->setAutoFillBackground(true);
        MidiMizeForm->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MidiMizeForm->setAnimated(true);
        MidiMizeForm->setTabShape(QTabWidget::Rounded);
        MidiMizeForm->setDockNestingEnabled(false);
        MidiMizeForm->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(MidiMizeForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hLine1 = new QFrame(centralwidget);
        hLine1->setObjectName(QString::fromUtf8("hLine1"));
        hLine1->setGeometry(QRect(0, 210, 910, 21));
        hLine1->setFrameShape(QFrame::HLine);
        hLine1->setFrameShadow(QFrame::Sunken);
        vLine4 = new QFrame(centralwidget);
        vLine4->setObjectName(QString::fromUtf8("vLine4"));
        vLine4->setGeometry(QRect(900, 0, 21, 440));
        vLine4->setFrameShape(QFrame::VLine);
        vLine4->setFrameShadow(QFrame::Sunken);
        vLine3 = new QFrame(centralwidget);
        vLine3->setObjectName(QString::fromUtf8("vLine3"));
        vLine3->setGeometry(QRect(600, 0, 21, 440));
        vLine3->setFrameShape(QFrame::VLine);
        vLine3->setFrameShadow(QFrame::Sunken);
        vLine2 = new QFrame(centralwidget);
        vLine2->setObjectName(QString::fromUtf8("vLine2"));
        vLine2->setGeometry(QRect(300, 0, 21, 440));
        vLine2->setFrameShape(QFrame::VLine);
        vLine2->setFrameShadow(QFrame::Sunken);
        vLine1 = new QFrame(centralwidget);
        vLine1->setObjectName(QString::fromUtf8("vLine1"));
        vLine1->setGeometry(QRect(170, 0, 21, 440));
        vLine1->setFrameShape(QFrame::VLine);
        vLine1->setFrameShadow(QFrame::Sunken);
        hLine2 = new QFrame(centralwidget);
        hLine2->setObjectName(QString::fromUtf8("hLine2"));
        hLine2->setGeometry(QRect(0, 430, 1031, 21));
        hLine2->setFrameShadow(QFrame::Sunken);
        hLine2->setFrameShape(QFrame::HLine);
        osc1ChorusWidget = new QWidget(centralwidget);
        osc1ChorusWidget->setObjectName(QString::fromUtf8("osc1ChorusWidget"));
        osc1ChorusWidget->setGeometry(QRect(610, 0, 301, 221));
        osc1ChorusNrLabel = new QLabel(osc1ChorusWidget);
        osc1ChorusNrLabel->setObjectName(QString::fromUtf8("osc1ChorusNrLabel"));
        osc1ChorusNrLabel->setGeometry(QRect(135, 184, 61, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Syntha Nova"));
        font1.setPointSize(10);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setKerning(false);
        osc1ChorusNrLabel->setFont(font1);
        osc1ChorusNrLabel->setAlignment(Qt::AlignCenter);
        osc1ChorusDepthLabel = new QLabel(osc1ChorusWidget);
        osc1ChorusDepthLabel->setObjectName(QString::fromUtf8("osc1ChorusDepthLabel"));
        osc1ChorusDepthLabel->setGeometry(QRect(214, 184, 71, 20));
        osc1ChorusDepthLabel->setFont(font1);
        osc1ChorusDepthLabel->setAlignment(Qt::AlignCenter);
        osc1ChorusSpeedLabel = new QLabel(osc1ChorusWidget);
        osc1ChorusSpeedLabel->setObjectName(QString::fromUtf8("osc1ChorusSpeedLabel"));
        osc1ChorusSpeedLabel->setGeometry(QRect(122, 79, 71, 20));
        osc1ChorusSpeedLabel->setFont(font1);
        osc1ChorusSpeedLabel->setAlignment(Qt::AlignCenter);
        osc1ChorusLvlLabel = new QLabel(osc1ChorusWidget);
        osc1ChorusLvlLabel->setObjectName(QString::fromUtf8("osc1ChorusLvlLabel"));
        osc1ChorusLvlLabel->setGeometry(QRect(214, 79, 71, 20));
        osc1ChorusLvlLabel->setFont(font1);
        osc1ChorusLvlLabel->setAlignment(Qt::AlignCenter);
        osc1ChorusEnable = new QPushButton(osc1ChorusWidget);
        osc1ChorusEnable->setObjectName(QString::fromUtf8("osc1ChorusEnable"));
        osc1ChorusEnable->setGeometry(QRect(40, 90, 40, 40));
        osc1ChorusEnable->setCheckable(true);
        osc1ChorusEnableLabel = new QLabel(osc1ChorusWidget);
        osc1ChorusEnableLabel->setObjectName(QString::fromUtf8("osc1ChorusEnableLabel"));
        osc1ChorusEnableLabel->setGeometry(QRect(20, 70, 81, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Syntha Nova"));
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(false);
        osc1ChorusEnableLabel->setFont(font2);
        osc1ChorusEnableLabel->setAlignment(Qt::AlignCenter);
        osc1ChorusDepth = new QDial(osc1ChorusWidget);
        osc1ChorusDepth->setObjectName(QString::fromUtf8("osc1ChorusDepth"));
        osc1ChorusDepth->setGeometry(QRect(209, 114, 82, 75));
        osc1ChorusDepth->setMaximum(210);
        osc1ChorusDepth->setNotchesVisible(true);
        osc1ChorusSpeed = new QDial(osc1ChorusWidget);
        osc1ChorusSpeed->setObjectName(QString::fromUtf8("osc1ChorusSpeed"));
        osc1ChorusSpeed->setGeometry(QRect(120, 10, 81, 75));
        osc1ChorusSpeed->setMinimum(1);
        osc1ChorusSpeed->setMaximum(50);
        osc1ChorusSpeed->setNotchesVisible(true);
        osc1ChorusLvl = new QDial(osc1ChorusWidget);
        osc1ChorusLvl->setObjectName(QString::fromUtf8("osc1ChorusLvl"));
        osc1ChorusLvl->setGeometry(QRect(209, 10, 82, 75));
        osc1ChorusLvl->setMaximum(80);
        osc1ChorusLvl->setNotchesVisible(true);
        osc1ChorusNr = new QDial(osc1ChorusWidget);
        osc1ChorusNr->setObjectName(QString::fromUtf8("osc1ChorusNr"));
        osc1ChorusNr->setGeometry(QRect(120, 114, 81, 75));
        osc1ChorusNr->setMaximum(2);
        osc1ChorusNr->setNotchesVisible(true);
        osc2ReverbWidget = new QWidget(centralwidget);
        osc2ReverbWidget->setObjectName(QString::fromUtf8("osc2ReverbWidget"));
        osc2ReverbWidget->setGeometry(QRect(310, 220, 301, 221));
        osc2ReverbWidthLabel = new QLabel(osc2ReverbWidget);
        osc2ReverbWidthLabel->setObjectName(QString::fromUtf8("osc2ReverbWidthLabel"));
        osc2ReverbWidthLabel->setGeometry(QRect(124, 184, 71, 20));
        osc2ReverbWidthLabel->setFont(font1);
        osc2ReverbWidthLabel->setAlignment(Qt::AlignCenter);
        osc2ReverbRoomLabel = new QLabel(osc2ReverbWidget);
        osc2ReverbRoomLabel->setObjectName(QString::fromUtf8("osc2ReverbRoomLabel"));
        osc2ReverbRoomLabel->setGeometry(QRect(214, 184, 71, 20));
        osc2ReverbRoomLabel->setFont(font1);
        osc2ReverbRoomLabel->setAlignment(Qt::AlignCenter);
        osc2ReverbLvlLabel = new QLabel(osc2ReverbWidget);
        osc2ReverbLvlLabel->setObjectName(QString::fromUtf8("osc2ReverbLvlLabel"));
        osc2ReverbLvlLabel->setGeometry(QRect(124, 79, 71, 20));
        osc2ReverbLvlLabel->setFont(font1);
        osc2ReverbLvlLabel->setAlignment(Qt::AlignCenter);
        osc2ReverbDampLabel = new QLabel(osc2ReverbWidget);
        osc2ReverbDampLabel->setObjectName(QString::fromUtf8("osc2ReverbDampLabel"));
        osc2ReverbDampLabel->setGeometry(QRect(214, 79, 71, 20));
        osc2ReverbDampLabel->setFont(font1);
        osc2ReverbDampLabel->setAlignment(Qt::AlignCenter);
        osc2ReverbEnable = new QPushButton(osc2ReverbWidget);
        osc2ReverbEnable->setObjectName(QString::fromUtf8("osc2ReverbEnable"));
        osc2ReverbEnable->setGeometry(QRect(40, 90, 40, 40));
        osc2ReverbEnable->setCheckable(true);
        osc2ReverbEnableLabel = new QLabel(osc2ReverbWidget);
        osc2ReverbEnableLabel->setObjectName(QString::fromUtf8("osc2ReverbEnableLabel"));
        osc2ReverbEnableLabel->setGeometry(QRect(20, 70, 81, 21));
        osc2ReverbEnableLabel->setFont(font2);
        osc2ReverbEnableLabel->setAlignment(Qt::AlignCenter);
        osc2ReverbRoom = new QDial(osc2ReverbWidget);
        osc2ReverbRoom->setObjectName(QString::fromUtf8("osc2ReverbRoom"));
        osc2ReverbRoom->setGeometry(QRect(209, 114, 82, 75));
        osc2ReverbRoom->setMaximum(10);
        osc2ReverbRoom->setNotchesVisible(true);
        osc2ReverbLvl = new QDial(osc2ReverbWidget);
        osc2ReverbLvl->setObjectName(QString::fromUtf8("osc2ReverbLvl"));
        osc2ReverbLvl->setGeometry(QRect(120, 10, 81, 75));
        osc2ReverbLvl->setMaximum(5);
        osc2ReverbLvl->setNotchesVisible(true);
        osc2ReverbDamp = new QDial(osc2ReverbWidget);
        osc2ReverbDamp->setObjectName(QString::fromUtf8("osc2ReverbDamp"));
        osc2ReverbDamp->setGeometry(QRect(209, 10, 82, 75));
        osc2ReverbDamp->setMaximum(10);
        osc2ReverbDamp->setNotchesVisible(true);
        osc2ReverbWidth = new QDial(osc2ReverbWidget);
        osc2ReverbWidth->setObjectName(QString::fromUtf8("osc2ReverbWidth"));
        osc2ReverbWidth->setGeometry(QRect(120, 114, 81, 75));
        osc2ReverbWidth->setMaximum(100);
        osc2ReverbWidth->setNotchesVisible(true);
        osc2ChorusWidget = new QWidget(centralwidget);
        osc2ChorusWidget->setObjectName(QString::fromUtf8("osc2ChorusWidget"));
        osc2ChorusWidget->setGeometry(QRect(610, 220, 301, 221));
        osc2ChorusNrLabel = new QLabel(osc2ChorusWidget);
        osc2ChorusNrLabel->setObjectName(QString::fromUtf8("osc2ChorusNrLabel"));
        osc2ChorusNrLabel->setGeometry(QRect(135, 184, 51, 20));
        osc2ChorusNrLabel->setFont(font1);
        osc2ChorusNrLabel->setAlignment(Qt::AlignCenter);
        osc2ChorusDepthLabel = new QLabel(osc2ChorusWidget);
        osc2ChorusDepthLabel->setObjectName(QString::fromUtf8("osc2ChorusDepthLabel"));
        osc2ChorusDepthLabel->setGeometry(QRect(214, 184, 71, 20));
        osc2ChorusDepthLabel->setFont(font1);
        osc2ChorusDepthLabel->setAlignment(Qt::AlignCenter);
        osc2ChorusSpeedLabel = new QLabel(osc2ChorusWidget);
        osc2ChorusSpeedLabel->setObjectName(QString::fromUtf8("osc2ChorusSpeedLabel"));
        osc2ChorusSpeedLabel->setGeometry(QRect(122, 79, 71, 20));
        osc2ChorusSpeedLabel->setFont(font1);
        osc2ChorusSpeedLabel->setAlignment(Qt::AlignCenter);
        osc2ChorusLvlLabel = new QLabel(osc2ChorusWidget);
        osc2ChorusLvlLabel->setObjectName(QString::fromUtf8("osc2ChorusLvlLabel"));
        osc2ChorusLvlLabel->setGeometry(QRect(214, 79, 71, 20));
        osc2ChorusLvlLabel->setFont(font1);
        osc2ChorusLvlLabel->setAlignment(Qt::AlignCenter);
        osc2ChorusEnable = new QPushButton(osc2ChorusWidget);
        osc2ChorusEnable->setObjectName(QString::fromUtf8("osc2ChorusEnable"));
        osc2ChorusEnable->setGeometry(QRect(40, 90, 40, 40));
        osc2ChorusEnable->setCheckable(true);
        osc2ChorusEnableLabel = new QLabel(osc2ChorusWidget);
        osc2ChorusEnableLabel->setObjectName(QString::fromUtf8("osc2ChorusEnableLabel"));
        osc2ChorusEnableLabel->setGeometry(QRect(20, 70, 81, 21));
        osc2ChorusEnableLabel->setFont(font2);
        osc2ChorusEnableLabel->setAlignment(Qt::AlignCenter);
        osc2ChorusDepth = new QDial(osc2ChorusWidget);
        osc2ChorusDepth->setObjectName(QString::fromUtf8("osc2ChorusDepth"));
        osc2ChorusDepth->setGeometry(QRect(209, 114, 82, 75));
        osc2ChorusDepth->setMaximum(210);
        osc2ChorusDepth->setPageStep(10);
        osc2ChorusDepth->setNotchesVisible(true);
        osc2ChorusSpeed = new QDial(osc2ChorusWidget);
        osc2ChorusSpeed->setObjectName(QString::fromUtf8("osc2ChorusSpeed"));
        osc2ChorusSpeed->setGeometry(QRect(120, 10, 81, 75));
        osc2ChorusSpeed->setMinimum(1);
        osc2ChorusSpeed->setMaximum(50);
        osc2ChorusSpeed->setNotchesVisible(true);
        osc2ChorusLvl = new QDial(osc2ChorusWidget);
        osc2ChorusLvl->setObjectName(QString::fromUtf8("osc2ChorusLvl"));
        osc2ChorusLvl->setGeometry(QRect(209, 10, 82, 75));
        osc2ChorusLvl->setMaximum(80);
        osc2ChorusLvl->setInvertedAppearance(false);
        osc2ChorusLvl->setNotchesVisible(true);
        osc2ChorusNr = new QDial(osc2ChorusWidget);
        osc2ChorusNr->setObjectName(QString::fromUtf8("osc2ChorusNr"));
        osc2ChorusNr->setGeometry(QRect(120, 114, 81, 75));
        osc2ChorusNr->setMaximum(2);
        osc2ChorusNr->setNotchesVisible(true);
        noteTouchWidget = new QWidget(centralwidget);
        noteTouchWidget->setObjectName(QString::fromUtf8("noteTouchWidget"));
        noteTouchWidget->setGeometry(QRect(-1, 439, 1024, 161));
        noteTouchWidget->setFont(font);
        pitchTouchWidget = new QWidget(centralwidget);
        pitchTouchWidget->setObjectName(QString::fromUtf8("pitchTouchWidget"));
        pitchTouchWidget->setGeometry(QRect(910, 0, 115, 441));
        osc1ReverbWidget = new QWidget(centralwidget);
        osc1ReverbWidget->setObjectName(QString::fromUtf8("osc1ReverbWidget"));
        osc1ReverbWidget->setGeometry(QRect(310, 0, 301, 221));
        osc1ReverbWidthLabel = new QLabel(osc1ReverbWidget);
        osc1ReverbWidthLabel->setObjectName(QString::fromUtf8("osc1ReverbWidthLabel"));
        osc1ReverbWidthLabel->setGeometry(QRect(124, 184, 71, 20));
        osc1ReverbWidthLabel->setFont(font1);
        osc1ReverbWidthLabel->setAlignment(Qt::AlignCenter);
        osc1ReverbRoomLabel = new QLabel(osc1ReverbWidget);
        osc1ReverbRoomLabel->setObjectName(QString::fromUtf8("osc1ReverbRoomLabel"));
        osc1ReverbRoomLabel->setGeometry(QRect(214, 184, 71, 20));
        osc1ReverbRoomLabel->setFont(font1);
        osc1ReverbRoomLabel->setAlignment(Qt::AlignCenter);
        osc1ReverbLvlLabel = new QLabel(osc1ReverbWidget);
        osc1ReverbLvlLabel->setObjectName(QString::fromUtf8("osc1ReverbLvlLabel"));
        osc1ReverbLvlLabel->setGeometry(QRect(124, 79, 71, 20));
        osc1ReverbLvlLabel->setFont(font1);
        osc1ReverbLvlLabel->setAlignment(Qt::AlignCenter);
        osc1ReverbDampLabel = new QLabel(osc1ReverbWidget);
        osc1ReverbDampLabel->setObjectName(QString::fromUtf8("osc1ReverbDampLabel"));
        osc1ReverbDampLabel->setGeometry(QRect(214, 79, 71, 20));
        osc1ReverbDampLabel->setFont(font1);
        osc1ReverbDampLabel->setAlignment(Qt::AlignCenter);
        osc1ReverbEnable = new QPushButton(osc1ReverbWidget);
        osc1ReverbEnable->setObjectName(QString::fromUtf8("osc1ReverbEnable"));
        osc1ReverbEnable->setGeometry(QRect(40, 90, 40, 40));
        osc1ReverbEnable->setCheckable(true);
        osc1ReverbEnableLabel = new QLabel(osc1ReverbWidget);
        osc1ReverbEnableLabel->setObjectName(QString::fromUtf8("osc1ReverbEnableLabel"));
        osc1ReverbEnableLabel->setGeometry(QRect(20, 70, 81, 21));
        osc1ReverbEnableLabel->setFont(font2);
        osc1ReverbEnableLabel->setAlignment(Qt::AlignCenter);
        osc1ReverbRoom = new QDial(osc1ReverbWidget);
        osc1ReverbRoom->setObjectName(QString::fromUtf8("osc1ReverbRoom"));
        osc1ReverbRoom->setGeometry(QRect(209, 114, 82, 75));
        osc1ReverbRoom->setMaximum(10);
        osc1ReverbRoom->setNotchesVisible(true);
        osc1ReverbLvl = new QDial(osc1ReverbWidget);
        osc1ReverbLvl->setObjectName(QString::fromUtf8("osc1ReverbLvl"));
        osc1ReverbLvl->setGeometry(QRect(120, 10, 81, 75));
        osc1ReverbLvl->setMaximum(5);
        osc1ReverbLvl->setWrapping(false);
        osc1ReverbLvl->setNotchesVisible(true);
        osc1ReverbDamp = new QDial(osc1ReverbWidget);
        osc1ReverbDamp->setObjectName(QString::fromUtf8("osc1ReverbDamp"));
        osc1ReverbDamp->setGeometry(QRect(209, 10, 82, 75));
        osc1ReverbDamp->setMaximum(10);
        osc1ReverbDamp->setNotchesVisible(true);
        osc1ReverbWidth = new QDial(osc1ReverbWidget);
        osc1ReverbWidth->setObjectName(QString::fromUtf8("osc1ReverbWidth"));
        osc1ReverbWidth->setGeometry(QRect(120, 110, 81, 75));
        osc1ReverbWidth->setMaximum(100);
        osc1ReverbWidth->setPageStep(10);
        osc1ReverbWidth->setNotchesVisible(true);
        osc1ReverbLvl->raise();
        osc1ReverbDamp->raise();
        osc1ReverbWidth->raise();
        osc1ReverbRoom->raise();
        osc1ReverbWidthLabel->raise();
        osc1ReverbRoomLabel->raise();
        osc1ReverbLvlLabel->raise();
        osc1ReverbDampLabel->raise();
        osc1ReverbEnable->raise();
        osc1ReverbEnableLabel->raise();
        osc2Widget = new QWidget(centralwidget);
        osc2Widget->setObjectName(QString::fromUtf8("osc2Widget"));
        osc2Widget->setGeometry(QRect(179, 219, 131, 221));
        osc2Label = new QLabel(osc2Widget);
        osc2Label->setObjectName(QString::fromUtf8("osc2Label"));
        osc2Label->setGeometry(QRect(35, 0, 61, 41));
        osc2Label->setFont(font2);
        osc2Label->setAlignment(Qt::AlignCenter);
        osc2Wave = new QWidget(osc2Widget);
        osc2Wave->setObjectName(QString::fromUtf8("osc2Wave"));
        osc2Wave->setGeometry(QRect(30, 80, 91, 141));
        verticalLayout_2 = new QVBoxLayout(osc2Wave);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        osc2SineRbutton = new QRadioButton(osc2Wave);
        osc2SineRbutton->setObjectName(QString::fromUtf8("osc2SineRbutton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/waveIcons/cosmic.png"), QSize(), QIcon::Normal, QIcon::Off);
        osc2SineRbutton->setIcon(icon);
        osc2SineRbutton->setIconSize(QSize(35, 35));
        osc2SineRbutton->setChecked(true);

        verticalLayout_2->addWidget(osc2SineRbutton);

        osc2TriRbutton = new QRadioButton(osc2Wave);
        osc2TriRbutton->setObjectName(QString::fromUtf8("osc2TriRbutton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/waveIcons/ambiance.png"), QSize(), QIcon::Normal, QIcon::Off);
        osc2TriRbutton->setIcon(icon1);
        osc2TriRbutton->setIconSize(QSize(35, 35));

        verticalLayout_2->addWidget(osc2TriRbutton);

        osc2SawRbutton = new QRadioButton(osc2Wave);
        osc2SawRbutton->setObjectName(QString::fromUtf8("osc2SawRbutton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/waveIcons/saw2.png"), QSize(), QIcon::Normal, QIcon::Off);
        osc2SawRbutton->setIcon(icon2);
        osc2SawRbutton->setIconSize(QSize(35, 35));

        verticalLayout_2->addWidget(osc2SawRbutton);

        osc2Pbutton = new QPushButton(osc2Widget);
        osc2Pbutton->setObjectName(QString::fromUtf8("osc2Pbutton"));
        osc2Pbutton->setEnabled(true);
        osc2Pbutton->setGeometry(QRect(45, 30, 40, 40));
        osc2Pbutton->setCheckable(true);
        osc2Pbutton->setAutoDefault(false);
        osc2Pbutton->setFlat(false);
        osc1Widget = new QWidget(centralwidget);
        osc1Widget->setObjectName(QString::fromUtf8("osc1Widget"));
        osc1Widget->setGeometry(QRect(179, 0, 131, 221));
        osc1Wave = new QWidget(osc1Widget);
        osc1Wave->setObjectName(QString::fromUtf8("osc1Wave"));
        osc1Wave->setGeometry(QRect(30, 80, 81, 141));
        verticalLayout = new QVBoxLayout(osc1Wave);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        osc1SineRbutton = new QRadioButton(osc1Wave);
        osc1SineRbutton->setObjectName(QString::fromUtf8("osc1SineRbutton"));
        osc1SineRbutton->setIcon(icon);
        osc1SineRbutton->setIconSize(QSize(35, 35));
        osc1SineRbutton->setChecked(true);

        verticalLayout->addWidget(osc1SineRbutton);

        osc1TriRbutton = new QRadioButton(osc1Wave);
        osc1TriRbutton->setObjectName(QString::fromUtf8("osc1TriRbutton"));
        osc1TriRbutton->setIcon(icon1);
        osc1TriRbutton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(osc1TriRbutton);

        osc1SawRbutton = new QRadioButton(osc1Wave);
        osc1SawRbutton->setObjectName(QString::fromUtf8("osc1SawRbutton"));
        osc1SawRbutton->setIcon(icon2);
        osc1SawRbutton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(osc1SawRbutton);

        osc1Pbutton = new QPushButton(osc1Widget);
        osc1Pbutton->setObjectName(QString::fromUtf8("osc1Pbutton"));
        osc1Pbutton->setEnabled(true);
        osc1Pbutton->setGeometry(QRect(45, 30, 40, 40));
        osc1Pbutton->setCheckable(true);
        osc1Pbutton->setAutoDefault(false);
        osc1Pbutton->setFlat(false);
        osc1Label = new QLabel(osc1Widget);
        osc1Label->setObjectName(QString::fromUtf8("osc1Label"));
        osc1Label->setGeometry(QRect(35, 0, 61, 41));
        osc1Label->setFont(font2);
        osc1Label->setAlignment(Qt::AlignCenter);
        gainWidget = new QWidget(centralwidget);
        gainWidget->setObjectName(QString::fromUtf8("gainWidget"));
        gainWidget->setGeometry(QRect(0, 220, 181, 221));
        gainLabel = new QLabel(gainWidget);
        gainLabel->setObjectName(QString::fromUtf8("gainLabel"));
        gainLabel->setGeometry(QRect(40, 0, 101, 41));
        gainLabel->setFont(font2);
        gainLabel->setAlignment(Qt::AlignCenter);
        gainDial = new QDial(gainWidget);
        gainDial->setObjectName(QString::fromUtf8("gainDial"));
        gainDial->setGeometry(QRect(15, 40, 150, 131));
        gainDial->setMaximum(100);
        gainDial->setSingleStep(1);
        gainDial->setValue(0);
        gainDial->setTracking(true);
        gainDial->setInvertedAppearance(false);
        gainDial->setInvertedControls(false);
        gainDial->setWrapping(false);
        gainDial->setNotchTarget(2.000000000000000);
        gainDial->setNotchesVisible(true);
        soloMidiSelect = new QWidget(gainWidget);
        soloMidiSelect->setObjectName(QString::fromUtf8("soloMidiSelect"));
        soloMidiSelect->setGeometry(QRect(0, 180, 181, 41));
        horizontalLayout = new QHBoxLayout(soloMidiSelect);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        soloRbutton = new QRadioButton(soloMidiSelect);
        soloRbutton->setObjectName(QString::fromUtf8("soloRbutton"));
        soloRbutton->setFont(font);
        soloRbutton->setChecked(true);

        horizontalLayout->addWidget(soloRbutton);

        midiRbutton = new QRadioButton(soloMidiSelect);
        midiRbutton->setObjectName(QString::fromUtf8("midiRbutton"));
        midiRbutton->setFont(font);

        horizontalLayout->addWidget(midiRbutton);

        logoWidget = new QWidget(centralwidget);
        logoWidget->setObjectName(QString::fromUtf8("logoWidget"));
        logoWidget->setGeometry(QRect(0, 0, 181, 221));
        aboutButton = new QPushButton(logoWidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setGeometry(QRect(65, 0, 61, 23));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Syntha Nova"));
        font3.setPointSize(9);
        aboutButton->setFont(font3);
        label = new QLabel(logoWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 67, 17));
        logo = new QLabel(logoWidget);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(-10, 40, 200, 140));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Syntha Nova"));
        font4.setStyleStrategy(QFont::PreferAntialias);
        logo->setFont(font4);
        logo->setAutoFillBackground(false);
        logo->setPixmap(QPixmap(QString::fromUtf8(":/new/logos/Black&Red_all.png")));
        logo->setScaledContents(true);
        MidiMizeForm->setCentralWidget(centralwidget);
        osc1ReverbWidget->raise();
        hLine1->raise();
        vLine4->raise();
        vLine3->raise();
        vLine2->raise();
        vLine1->raise();
        hLine2->raise();
        osc1ChorusWidget->raise();
        osc2ReverbWidget->raise();
        osc2ChorusWidget->raise();
        noteTouchWidget->raise();
        pitchTouchWidget->raise();
        osc2Widget->raise();
        osc1Widget->raise();
        gainWidget->raise();
        logoWidget->raise();
        statusbar = new QStatusBar(MidiMizeForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setEnabled(true);
        MidiMizeForm->setStatusBar(statusbar);

        retranslateUi(MidiMizeForm);

        osc2Pbutton->setDefault(false);
        osc1Pbutton->setDefault(false);


        QMetaObject::connectSlotsByName(MidiMizeForm);
    } // setupUi

    void retranslateUi(QMainWindow *MidiMizeForm)
    {
        MidiMizeForm->setWindowTitle(QCoreApplication::translate("MidiMizeForm", "MainWindow", nullptr));
        osc1ChorusNrLabel->setText(QCoreApplication::translate("MidiMizeForm", "Nr", nullptr));
        osc1ChorusDepthLabel->setText(QCoreApplication::translate("MidiMizeForm", "Depth", nullptr));
        osc1ChorusSpeedLabel->setText(QCoreApplication::translate("MidiMizeForm", "Speed", nullptr));
        osc1ChorusLvlLabel->setText(QCoreApplication::translate("MidiMizeForm", "Level", nullptr));
        osc1ChorusEnable->setText(QString());
        osc1ChorusEnableLabel->setText(QCoreApplication::translate("MidiMizeForm", "CHORUS", nullptr));
        osc2ReverbWidthLabel->setText(QCoreApplication::translate("MidiMizeForm", "Width", nullptr));
        osc2ReverbRoomLabel->setText(QCoreApplication::translate("MidiMizeForm", "Room", nullptr));
        osc2ReverbLvlLabel->setText(QCoreApplication::translate("MidiMizeForm", "Level", nullptr));
        osc2ReverbDampLabel->setText(QCoreApplication::translate("MidiMizeForm", "Damp", nullptr));
        osc2ReverbEnable->setText(QString());
        osc2ReverbEnableLabel->setText(QCoreApplication::translate("MidiMizeForm", "REVERB", nullptr));
        osc2ChorusNrLabel->setText(QCoreApplication::translate("MidiMizeForm", "Nr", nullptr));
        osc2ChorusDepthLabel->setText(QCoreApplication::translate("MidiMizeForm", "Depth", nullptr));
        osc2ChorusSpeedLabel->setText(QCoreApplication::translate("MidiMizeForm", "Speed", nullptr));
        osc2ChorusLvlLabel->setText(QCoreApplication::translate("MidiMizeForm", "Level", nullptr));
        osc2ChorusEnable->setText(QString());
        osc2ChorusEnableLabel->setText(QCoreApplication::translate("MidiMizeForm", "CHORUS", nullptr));
        osc1ReverbWidthLabel->setText(QCoreApplication::translate("MidiMizeForm", "Width", nullptr));
        osc1ReverbRoomLabel->setText(QCoreApplication::translate("MidiMizeForm", "Room", nullptr));
        osc1ReverbLvlLabel->setText(QCoreApplication::translate("MidiMizeForm", "Level", nullptr));
        osc1ReverbDampLabel->setText(QCoreApplication::translate("MidiMizeForm", "Damp", nullptr));
        osc1ReverbEnable->setText(QString());
        osc1ReverbEnableLabel->setText(QCoreApplication::translate("MidiMizeForm", "REVERB", nullptr));
        osc2Label->setText(QCoreApplication::translate("MidiMizeForm", "OSC2", nullptr));
        osc2SineRbutton->setText(QString());
        osc2TriRbutton->setText(QString());
        osc2SawRbutton->setText(QString());
        osc2Pbutton->setText(QString());
        osc1SineRbutton->setText(QString());
        osc1TriRbutton->setText(QString());
        osc1SawRbutton->setText(QString());
        osc1Pbutton->setText(QString());
        osc1Label->setText(QCoreApplication::translate("MidiMizeForm", "OSC1", nullptr));
        gainLabel->setText(QCoreApplication::translate("MidiMizeForm", "VOLUME", nullptr));
        soloRbutton->setText(QCoreApplication::translate("MidiMizeForm", "SOLO", nullptr));
        midiRbutton->setText(QCoreApplication::translate("MidiMizeForm", "MIDI", nullptr));
        aboutButton->setText(QCoreApplication::translate("MidiMizeForm", "ABOUT", nullptr));
        label->setText(QString());
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MidiMizeForm: public Ui_MidiMizeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIDIMIZEFORM_H
