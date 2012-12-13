#ifndef CVIMAGE_H
#define CVIMAGE_H
#include <cv.h>
#include "darqimage.h"
#include "transformation.h"
#include <list>
#include "memento.h"

/** Klasa CVImage przechowuje dane o obrazie w formacie biblioteki OpenCV (Mat)
  * Na niej opiera się wykonywanie transformacji, zapis pliku etc.
  */


class CVImage
{
public:
    /// Konstruktory
    CVImage();
    CVImage(QString fileName);
    ~CVImage();
    /// Nie jest to pełny konstruktor kopiujący
    /// Kopiuje tyle ile jest potrzebne do wykonania preview
    CVImage(const CVImage& cvimage);
    /// Zwraca głęboką kopię listy transformacji
    std::list<Transformation*> transformationListClone();
    /// Wysyła żądanie odrysowania obrazka
    void notify();
    /// Zwraca listę stringów opisujących przekształcenia obrazka
    QStringList transformStringList();
    /// Zapisuje obraz pod podaną ścieżką
    /// Zwraca 0 przy poprawnym zapisie, 1 przy błędzie
    int save(QString);
    /// Tworzy obiekt pamiątki dla aktualnego stanu
    Memento* createMemento();
    /// Aktualny obraz
    cv::Mat mat;
    /// Pomocnicza kopia czarnobiałego obrazu w RGB
    /// (Qt do odrysowania potrzebuje kolorowego obrazka)
    cv::Mat rgb;
    /// Ścieżka do pliku
    QString path;
    /// Lista przekształceń obrazka
    std::list<Transformation*> transforms;
    /// Setter
    void setObserver(DarqImage*);
private:
    /// Wskazanie na obiekt obserwatora
    DarqImage *observer;

};

#endif // CVIMAGE_H
