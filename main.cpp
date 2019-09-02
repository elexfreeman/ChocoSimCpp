#include <QCoreApplication>
#include <QMapIterator>
#include <iostream>
#include <QDebug>
#include <Objects/Sys/errorsys.h>
#include "./Objects/Sys/core.h"
#include "./Objects/Sys/baseobject.h"
#include "./Objects/Sys/eventmaker.h"

using namespace std;
using namespace ChocoSim;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ErrorSys *errorSys = new ErrorSys();
    errorSys->error("myerr1", "myerr1");
    errorSys->error("myerr2", "myerr2");

    QMapIterator<QString, QString> i(errorSys->fGetErrorList());

    qDebug() << "Test ErrorSys...";

    while (i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": " << i.value() << endl;
    }



    EventMaker *eventMaker = new EventMaker();
    Core *core = new Core(eventMaker, errorSys);

    BaseObject *obj1 = new BaseObject(core->errorSys);
    BaseObject *obj2 = new BaseObject(core->errorSys);
    BaseObject *obj3 = new BaseObject(core->errorSys);

    obj1->sCaption = "Cat";
    obj2->sCaption = "Dog";
    obj3->sCaption = "Mouse";

    core->fAdd(obj1);
    core->fAdd(obj2);
    core->fAdd(obj3);

    core->fTick();



    delete core;
    delete errorSys;
    return a.exec();
}
