#include "model.h"

Model::Model()
{
    idCounter = 0;
}

Model::~Model() {
    for ( std::map<int,CVImage*>::iterator it = images.begin(); it != images.end(); it++ ) {
        delete it->second;
    }
}

int Model::nextId() {
    int newId = idCounter;
    ++idCounter;
    return newId;
}
