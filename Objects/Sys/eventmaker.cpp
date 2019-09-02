#include "eventmaker.h"


ChocoSim::EventMaker::EventMaker()
{

}

ChocoSim::EventMaker::~EventMaker()
{
    for (int i = 0; i < objects.length(); i++) {
        // очищаем объекты
        delete objects[i];
        objects.remove(i);
    }
}

void ChocoSim::EventMaker::fAdd(ChocoSim::BaseObject *item)
{
    objects.push_back(item);
}

void ChocoSim::EventMaker::fTick()
{
    for (int i = 0; i < objects.length(); i++) {
        // если объект удаленый
        if (objects[i]->fIsDeleted()) {
            delete objects[i];
            objects.remove(i);
        } else {
            // обрабатываем тик
            objects[i]->fTick();
        }
    }
}

void ChocoSim::EventMaker::fPrint()
{
    for (int i = 0; i < objects.length(); i++) {
        objects[i]->fPrint();
    }
}
