#include "model.h"

Model::Model()
{
}

CVImage* Model::pathFind(QString path) {
    if (empty())
        return NULL;
    for ( unsigned i = 0; i < size(); ++i ) {
       CVImage *temp = at(i);
       if ( path == temp->path )
           return temp;
    }
    return NULL;
}
