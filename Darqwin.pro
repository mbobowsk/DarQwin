# #####################################################################
# Automatically generated by qmake (2.01a) sob. maj 12 22:17:20 2012
# #####################################################################
TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += /usr/include/opencv

# Input
HEADERS += brightnessdialog.h \
    darqimage.h \
    mainwindow.h \
    imageprocessor.h \
    sizehinttabwidget.h \
    cvimage.h \
    model.h \
    transformation.h \
    transbrightness.h \
    mdisubwindow.h \
    transaverage.h \
    transmedian.h \
    memento.h \
    caretaker.h \
    caretakermodel.h \
    transgaussian.h \
    transbilateral.h \
    bilateraldialog.h \
    transerode.h \
    transdilate.h \
    transopen.h \
    transclose.h \
    transgradient.h \
    thresholddialog.h \
    transthresh.h \
    transsobel.h \
    translaplacian.h \
    transscharr.h \
    transcanny.h \
    cannydialog.h \
    transconversion.h \
    transequalize.h
FORMS += brightnessdialog.ui \
    mainwindow.ui \
    bilateraldialog.ui \
    thresholddialog.ui \
    cannydialog.ui
SOURCES += brightnessdialog.cpp \
    darqimage.cpp \
    main.cpp \
    mainwindow.cpp \
    imageprocessor.cpp \
    cvimage.cpp \
    model.cpp \
    transbrightness.cpp \
    mdisubwindow.cpp \
    transaverage.cpp \
    transmedian.cpp \
    memento.cpp \
    caretaker.cpp \
    caretakermodel.cpp \
    transgaussian.cpp \
    transbilateral.cpp \
    bilateraldialog.cpp \
    transerode.cpp \
    transdilate.cpp \
    transopen.cpp \
    transclose.cpp \
    transgradient.cpp \
    transformation.cpp \
    thresholddialog.cpp \
    transthresh.cpp \
    transsobel.cpp \
    translaplacian.cpp \
    transscharr.cpp \
    transcanny.cpp \
    cannydialog.cpp \
    transconversion.cpp \
    transequalize.cpp
RESOURCES += icons.qrc

# LIBS += `pkg-config --cflags --libs opencv`
CXXFLAGS += O2
CFLAGS += O2
LIBS += -lm \
    -lcv \
    -lhighgui \
    -lcvaux \
    -lml \
    -lcxcore
