#include "caretakermodel.h"

CaretakerModel::CaretakerModel()
{
}

CaretakerModel::~CaretakerModel() {
    for ( std::map<int,Caretaker*>::iterator it = caretakers.begin(); it != caretakers.end(); it++ ) {
        delete it->second;
    }
}
