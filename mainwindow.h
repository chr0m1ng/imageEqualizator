#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "carregaimage.h"
#include <QColor>
#include <QScrollArea>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    carregaImage *load;
    QImage *image;
    QImage *imageCopy;
    QLabel *imageL;
    long *grayScale;
    long totalGray;
    float *average;
    void mouseMoveEvent(QMouseEvent *);
    int inPosY;
    int inPosX;
    bool isInside;
    long sizeImage;
    void mousePressEvent(QMouseEvent *);

private:
    Ui::MainWindow *ui;
public slots:
    void applySets(int);
    void makeHist();
    void validacao();
    void salvar();
    void carregar();
};

#endif // MAINWINDOW_H
