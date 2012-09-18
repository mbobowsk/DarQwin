#ifndef CARETAKERMODEL_H
#define CARETAKERMODEL_H

#include <map>
#include "caretaker.h"

class CaretakerModel
{
public:
    CaretakerModel();
    ~CaretakerModel();
    static CaretakerModel& getInstance() {
        static CaretakerModel instance;
        return instance;
    }
    std::map<int,Caretaker*> caretakers;
};

#endif // CARETAKERMODEL_H
