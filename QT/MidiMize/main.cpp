#include <QApplication>
#include <QTime>
#include "MidiMizeForm.h"
#include "aboutForm.h"
#include "cmidimize.h"

void delay2()
{
    QTime dieTime= QTime::currentTime().addSecs(2);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void delay10()
{
    QTime dieTime= QTime::currentTime().addSecs(10);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void delay5()
{
    QTime dieTime= QTime::currentTime().addSecs(10);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

int main(int argc, char** argv)
{
    QApplication app (argc, argv);
    //QtWrapper QtWrap;

    app.setStyle("fusion");

    //CMidiMize* MIDImize = CMidiMize::getInstance(QtWrap);

    aboutForm about;
    MidiMizeForm gui;
    gui.show();

//    QtWrap.synth[0]->setGain(4);
//    QtWrap.synth[0]->oscillator=SINE;
//    QtWrap.synth[0]->setOscillator();

//    QtWrap.synth[0]->noteOn(1, 55, 100);
//    delay5();
//    QtWrap.synth[0]->oscillator=SAW;
//    QtWrap.synth[0]->setOscillator();
//    delay5();
//    QtWrap.synth[0]->noteOn(1, 56, 100);
//    delay2();
//    QtWrap.synth[0]->noteOn(2, 57, 100);
//    delay10();
//    QtWrap.synth[0]->reverb.lvl=0.8;
//    QtWrap.synth[0]->reverb.room=0.8;
//    QtWrap.synth[0]->reverb.damp=0.8;
//    QtWrap.synth[0]->reverb.width=70;
//    QtWrap.synth[0]->reverb.active=1;
//    QtWrap.synth[0]->setReverb();
//    delay10();

//    QtWrap.synth[0]->noteOff(1, 55);
//    delay10();
//    QtWrap.synth[1]->noteOff(1, 56);
//    delay10();
//    QtWrap.synth[0]->noteOff(2, 57);


    return app.exec();
}
