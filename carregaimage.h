#ifndef CARREGAIMAGE_H
#define CARREGAIMAGE_H

#include <QWidget>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include "escalas.h"
#include "equalizador.h"
#include "brilho.h"

class carregaImage : public QWidget
{
    Q_OBJECT
public:
    explicit carregaImage(QWidget *parent = 0);
    ~carregaImage();
    Escalas *scale;
    Equalizador *equal;
    brilho *bright;
    QLabel *image;
    QImage imageQ;
    QImage imageQOriginal;
    bool isImage;
    long sizeImage;
    void carregar();
    float average;
    long *grayScale;
    void aplicarBrilho(int *);

public slots:
    void equalizar();

};

#endif // CARREGAIMAGE_H
