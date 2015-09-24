#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "carregaimage.h"
#include "brilho.h"


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
    long totalGray;

private:
    Ui::MainWindow *ui;
public slots:
    void applySets(int luz);
    void makeHist();
    void validacao();
};

#endif // MAINWINDOW_H
