#ifndef MODEL_H
#define MODEL_H

#include <cvimage.h>
#include <vector>

class Model : public std::vector<CVImage *>
{
public:
    static Model& getInstance() {
        static Model instance;
        return instance;
    }
    CVImage* pathFind(QString path);
private:
    Model();
};

#endif // MODEL_H
