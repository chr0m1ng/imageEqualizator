#include "carregaimage.h"

carregaImage::carregaImage(QWidget *parent) :
    QWidget(parent)
{


    image = new QLabel;
    image->setBackgroundRole( QPalette::Base );
    image->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    image->setScaledContents( true );

    isImage = false;

    grayScale = new long[256];

    scale = new Escalas;

    equal = new Equalizador;

    bright = new brilho;

}
carregaImage::~carregaImage()
{
    delete image;
    delete grayScale;
    delete scale;
    delete equal;
    delete bright;
}

void carregaImage::carregar()
{
    QString fileName = QFileDialog::getOpenFileName(this , tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty())
    {
        QImage tempImage(fileName);
        if (tempImage.isNull())
        {
            QMessageBox::information(this, tr("Image Viewer"), tr("Cannot Load %1").arg(fileName));
            return;
        }
        image->setPixmap(QPixmap::fromImage(tempImage));
        image->adjustSize();
        sizeImage = tempImage.width() * tempImage.height();
        imageQ = tempImage.copy();
        imageQOriginal = tempImage.copy();
        scale->cleanScale(grayScale, &average);
        scale->getScale(grayScale, &average, &imageQ);
        isImage = true;
    }
}

void carregaImage::equalizar()
{
    equal->Equalizar(&imageQ, grayScale, &sizeImage);
    image->setPixmap(QPixmap::fromImage(imageQ));
}

void carregaImage::aplicarBrilho(int *luz)
{
    bright->appling(*luz, &imageQ, &imageQOriginal);
}
