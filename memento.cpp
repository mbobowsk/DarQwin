#include "memento.h"

Memento::Memento(const std::list<Transformation *> &list, const cv::Mat &m)
{
    for ( std::list<Transformation*>::const_iterator it = list.begin(); it != list.end(); it++) {
        transforms.push_back((*it)->clone());
    }
    mat = m.clone();
}
