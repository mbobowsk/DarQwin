#ifndef CARETAKER_H
#define CARETAKER_H

#include "memento.h"
#include <list>

/** Klasa Caretaker implementuje wzorzec projektowy pamiątka - mechanizm historii
  */

class Caretaker
{
public:
    Caretaker();
    ~Caretaker();
    Memento* getUndoMemento(Memento*);
    Memento* getRedoMemento(Memento*);
    std::list<Memento*> undoList;
    std::list<Memento*> redoList;
    /// Licznik inicjalizowany zerem, zwiększany przy redo, zmniejszany przy undo,
    /// zerowany przy save
    /// Pozwala określić, czy obrazek jest inny niż ostatnio zapisany
    int dirtyCounter;
};

#endif // CARETAKER_H
