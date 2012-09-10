#include "model.h"

Model::Model()
{
    idCounter = 0;
}

int Model::nextId() {
    int newId = idCounter;
    ++idCounter;
    return newId;
}
