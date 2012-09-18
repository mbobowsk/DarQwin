#include "caretaker.h"

Caretaker::Caretaker()
{
}
Caretaker::~Caretaker() {
    for ( std::list<Memento*>::iterator it = undoList.begin(); it != undoList.end(); it++ ) {
        delete *it;
    }
    for ( std::list<Memento*>::iterator it = redoList.begin(); it != redoList.end(); it++ ) {
        delete *it;
    }
}

Memento* Caretaker::getUndoMemento(Memento *current) {
    Memento* last = undoList.back();
    redoList.push_back(current);
    undoList.pop_back();
    return last;
}

Memento* Caretaker::getRedoMemento(Memento *current) {
    Memento* last = redoList.back();
    undoList.push_back(current);
    redoList.pop_back();
    return last;
}
