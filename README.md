DarQwin
=======
Program prezentujący działanie algorytmów z przetwarzania obrazów. Jest w pełni przenośny między systemami operacyjnymi Linux i Windows.

Testowane konfiguracje:
Ubuntu 12.04 64-bit, gcc 4.4.3, OpenCV v.2.4.0
Windows 7 64-bit, kompilator MSVC 10, OpenCV v.2.4.2

Aby skompilować i uruchomić program ze źródeł potrzeba:
1. Kompilatora C++.
2. Qt SDK.
3. IDE QtCreator.
4. Skompilowanej biblioteki OpenCV.

Konfiguracja Ubuntu:
Wszystkie składniki można zainstalować z pakietów. Jedynym problemem może być zainstalowanie wszystkich pakietów biblioteki OpenCV, gdyż z każdą kolejną wersją zmienia się ich nazewnictwo. Przykładowy proces instalacji dla wersji 2.1 jest opisany tutaj: https://help.ubuntu.com/community/OpenCV
Prostym sposobem na sprawdzenie czy instalacja OpenCV przebiegła pomyślnie jest skompilowanie dołączonych do biblioteki przykładów. Znajdują się one w katalogu usr/share/doc/opencv-doc/examples/c i posiadają plik Makefile.

Konfiguracja Windows:
Dodatkowo należy zainstalować program CMake oraz Visual Studio. Oczywiście można obejść się bez Visual Studio, ale osobiście nie sprawdzałem innych kompilatorów np. MinGW.
Następnie należy postępować zgodnie z tym filmem: http://www.youtube.com/watch?v=kZvjTTK9zTw&feature=related
Należy zaznaczyć, że w kolejnych wersjach OpenCV nazwy wynikowych plików (.lib) uległy zmianie.

Ustawienia pliku projektu (.pro):
Ostatnim krokiem jest uzupełnienie pliku projektu o informacje dotyczące położenia OpenCV.

1. INCLUDEPATH
Linux:  INCLUDEPATH += /usr/include/opencv
Windows: Analogicznie, ale ścieżki zależą od tego gdzie znajdują się pliki OpenCV. Przykładowo:
INCLUDEPATH += C:\opencv\include\opencv \
C:\opencv\include \
C:\opencv\build\x86\vc10\bin <-- Ta linijka zależy od tego, jakiej architektury i kompilatora używa wasz QtCreator

2. LIBS
Linux: Najpierw polecam wpisać w konsoli polecenie: pkg-config --cflags --libs opencv
Jego wynik (np. lcv -lhighgui -lcvaux -lml -lcxcore) należy przypisać do zmiennej LIBS (czyli LIBS += ...).
Windows: LIBS += C:\opencv\lib\Debug\opencv_calib3d242d.lib \
C:\opencv\lib\Debug\opencv_contrib242d.lib \
itd. dla kolejnych plików .lib.

