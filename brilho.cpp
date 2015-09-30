#include "brilho.h"

brilho::brilho(QWidget *parent) :
    QWidget(parent)
{
}
brilho::~brilho()
{
}
#include <iostream>
using namespace std;
void brilho::appling(bool isImage, int light, QImage *newImage, QImage *imageCopy)
{
    if(isImage)
    {
        QColor tempColor;
        int grayColor = 0;
        QRgb value;
        if(imageCopy->isGrayscale())
        {
            for(int i = 0; i < imageCopy->width(); i++)
            {
                for(int j = 0; j < imageCopy->height(); j++)
                {
                    tempColor = imageCopy->pixel(i, j);
                    grayColor = 255 - tempColor.black();
                    grayColor += (light / 2);
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
