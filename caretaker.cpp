#include "caretaker.h"

Caretaker::Caretaker()
{
}

Memento* Caretaker::getUndoMemento() {
    Memento* last = undoList.back();
    redoList.push_back(last);
    undoList.pop_back();
    return last;
}

Memento* Caretaker::getRedoMemento() {
    Memento* last = redoList.back();
    undoList.push_back(last);
    redoList.pop_back();
    return last;
}
