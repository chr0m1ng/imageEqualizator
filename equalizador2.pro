#-------------------------------------------------
#
# Project created by QtCreator 2015-06-19T15:44:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = equalizador2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    carregaimage.cpp \
    qcustomplot.cpp \
    brilho.cpp

HEADERS  += mainwindow.h \
    carregaimage.h \
    qcustomplot.h \
    brilho.h

FORMS    += mainwindow.ui
