#include "model.h"

Model::Model()
{
    idCounter = 0;
}

CVImage* Model::idFind(int id) {
    if (empty())
        return NULL;
    for ( unsigned i = 0; i < size(); ++i ) {
       CVImage *temp = at(i);
       if ( id == temp->id )
           return temp;
    }
    return NULL;
}

int Model::nextId() {
    int newId = idCounter;
    ++idCounter;
    return newId;
}
