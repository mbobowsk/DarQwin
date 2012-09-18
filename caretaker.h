#ifndef CARETAKER_H
#define CARETAKER_H

#include "memento.h"
#include <list>

class Caretaker
{
public:
    Caretaker();
    ~Caretaker();
    Memento* getUndoMemento(Memento*);
    Memento* getRedoMemento(Memento*);
    std::list<Memento*> undoList;
    std::list<Memento*> redoList;
};

#endif // CARETAKER_H
