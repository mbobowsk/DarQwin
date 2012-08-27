#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "darqimage.h"

class Model
{
public:
    Model();
    std::vector<DarqImage*> images;
    DarqImage *getActive();
    void refresh();
};

#endif // MODEL_H
