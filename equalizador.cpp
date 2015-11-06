#include "equalizador.h"

Equalizador::Equalizador(QWidget *parent) : QWidget(parent)
{

}

Equalizador::~Equalizador()
{

}

void Equalizador::Equalizar(QImage *image, long *grayScale, long *sizeImage)
{
    QColor tempColor;
    float gt = 0.0;
    float pt = 0.0;
    long g = 0;
    QRgb value;
    for(long i = 0; i < image->width(); i++)
    {
        for(long j = 0; j < image->height(); j++)
        {
            tempColor = image->pixel(i, j);
            g = 255 - tempColor.black();
            pt = (g*g) / (float)(*sizeImage);
            gt = (pt * (float)g) + ((float)grayScale[g]/(float) *sizeImage) + g;
            if(gt > 255)
                gt = 255;
            else if(gt < 0)
                gt = 0;
            value = qRgb(gt, gt, gt);
            image->setPixel(i , j, value);
        }
    }
}

