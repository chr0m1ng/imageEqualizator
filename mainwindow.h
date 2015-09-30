#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "carregaimage.h"
#include "brilho.h"
#include <QColor>

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
    brilho *bright;
    QImage *image;
    QImage *imageCopy;
    QLabel *imageL;
    void getScale();
    void cleanScale();
    long *grayScale;
    long *grayCumulativeScale;
    long totalGray;
    float average;
    void getCumulativeScale();

private:
    Ui::MainWindow *ui;
public slots:
    void applySets(int luz);
    void makeHist();
    void validacao();
    void realceQuadratico();
    void makeCumulativeHist();
};

#endif // MAINWINDOW_H
