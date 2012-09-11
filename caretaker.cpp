#include "caretaker.h"

Caretaker::Caretaker()
{
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
