#include "brilho.h"

brilho::brilho(QWidget *parent) :
    QWidget(parent)
{
}
brilho::~brilho()
{
}
void brilho::appling(bool isImage, int light, QImage *newImage, QImage *imageCopy)
{
    if(isImage)
    {
        QColor tempColor;
        int grayColor = 0;
        QRgb value;
        if(imageCopy->isGrayscale())
        {
            for(long i = 0; i < imageCopy->width(); i++)
            {
                for(long j = 0; j < imageCopy->height(); j++)
                {
                    tempColor = imageCopy->pixel(i, j);
                    grayColor = (255 - tempColor.black());
                    if(light > 126)
                        grayColor += (light / 2);
                    else
                        grayColor -= (light / 2);
                    if (grayColor > 255)
                            grayColor = 255;
                    else if (grayColor < 0)
                            grayColor = 0;

                    value = qRgb(grayColor, grayColor, grayColor);
                    newImage->setPixel(i, j, value);
                }
            }
        }
    }
}
