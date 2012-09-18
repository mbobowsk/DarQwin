#ifndef MODEL_H
#define MODEL_H

#include <cvimage.h>
#include <map>

class Model
{
public:
    static Model& getInstance() {
        static Model instance;
        return instance;
    }
    int idCounter;
    int nextId();
    std::map<int,CVImage *> images;
    ~Model();
private:
    Model();
};

#endif // MODEL_H
