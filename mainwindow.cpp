#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load = new carregaImage; //Create Image module
    bright = new brilho; //Create bright module
    grayScale = new long[256];

    image = load->imageQ.copy(); //Copy of image (QImage)

    imageCopy = load->imageQ.copy(); //Copy of original image (QImage)

    imageL = load->image; //Image in QLabel


    ui->btValidacao->hide(); //Hide Validation

    ui->scrollArea->setWidget(imageL); //Set Image on the box

    ui->customPlot->xAxis->setLabel("Tom"); //Hist
    ui->customPlot->yAxis->setLabel("Quantidade"); //Hist
    ui->customPlot->xAxis->setRange(0, 255); //Hist
    ui->customPlot->yAxis->setRange(0, 1000); //Hist
    ui->customPlot->QCustomPlot::setInteractions(QCP::iRangeZoom); //Hist
    ui->customPlot->setInteraction(QCP::iRangeDrag, true); //Hist

    connect(ui->btLoad, SIGNAL(released()), load, SLOT(carregar())); //Load image

    connect(ui->slider, SIGNAL(valueChanged(int)), this, SLOT(applySets(int))); // Bright change

    connect(ui->btMakeHist, SIGNAL(released()), this, SLOT(makeHist())); //Hist

    connect(ui->btValidacao, SIGNAL(released()), this, SLOT(validacao())); //Validation
}

MainWindow::~MainWindow()
{
    delete bright;
    delete load;
    delete grayScale;
    delete ui;
}

void MainWindow::applySets(int luz) //Luz is received by QSlider
{
    if(load->isImage == true)
        bright->appling(load->isImage, luz, &image, &imageCopy);
    //image will be changed and imageCopy will be the INPUT of a original image
    imageL->setPixmap(QPixmap::fromImage(imageCopy)); //Change imageL to display new image
}

void MainWindow::makeHist()
{
    if(load->isImage == true)
    {
        QVector<double> x(256), y(256);
        cleanScale();
        getScale();
        totalGray = 0;

        for(int i = 0; i < 256; i++)
        {
            x[i] = i;
            y[i] = grayScale[i];
            totalGray += grayScale[i];
        }

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->replot();
        ui->btValidacao->show();
        cleanScale();
    }
}

void MainWindow::validacao()
{
    if (totalGray == load->sizeImage)
    {
        QMessageBox::information(this, tr("Validacao"), tr("O total do histograma e de %1 pixels e a imagem tem %2 pixels. O histograma esta correto").arg(totalGray).arg(load->sizeImage));
        return;
    }
    else
    {
        QMessageBox::information(this, tr("Validacao"), tr("Ops, algo deu errado, a imagem e o histograma nao contem a mesma quantidade de pixels."));
        return;
    }

}


void MainWindow::getScale()
{
    QColor tempColor;
    int grayColor;
    if(image.isGrayscale())
    {
        for(int i = 0; i < image.width(); i++)
        {
            for(int j = 0; j < image.height(); j++)
            {
                tempColor = image.pixel(i, j);
                grayColor = (255 - tempColor.black());
                grayScale[grayColor]++;
            }
        }
    }
}



void MainWindow::cleanScale()
{
    for (int i = 0; i < 256; i++)
        grayScale[i] = 0;
}
