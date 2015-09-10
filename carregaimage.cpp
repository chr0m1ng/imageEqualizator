#include "carregaimage.h"

carregaImage::carregaImage(QWidget *parent) :
    QWidget(parent)
{


    image = new QLabel;
    image->setBackgroundRole( QPalette::Base );
    image->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    image->setScaledContents( true );

    isImage = false;

}
carregaImage::~carregaImage()
{
    delete image;
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
        isImage = true;
    }
}
