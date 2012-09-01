#include "model.h"

Model::Model()
{
}

CVImage* Model::pathFind(QString path) {
    if (this->empty())
        return NULL;
    for ( unsigned i = 0; i < this->size(); ++i ) {
       CVImage* temp = this->at(i);
       if ( path == temp->path )
           return temp;
    }
    return NULL;
}
