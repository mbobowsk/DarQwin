#include "model.h"

Model::Model()
{
}

DarqImage *Model::getActive() {
    for ( std::vector<DarqImage*>::iterator i = images.begin(); i != images.end(); ++i) {
        if ( (*i)->isActiveWindow() )
            return *i;
    }
    return NULL; //niedobrze :(
}

void Model::refresh() {
    for ( std::vector<DarqImage*>::iterator i = images.begin(); i != images.end(); ++i) {
        if ( (*i)->isFinished )
            images.erase(i);
    }
}
