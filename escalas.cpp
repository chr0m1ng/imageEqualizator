#include "escalas.h"

Escalas::Escalas(QWidget *parent) : QWidget(parent)
{

}

Escalas::~Escalas()
{

}

void Escalas::getScale(long *grayScale, float *average, QImage *image)
{
    QColor tempColor;
    int grayColor;
    for(int i = 0; i < image->width(); i++)
    {
        for(int j = 0; j < image->height(); j++)
        {
            tempColor = image->pixel(i, j);
            grayColor = (255 - tempColor.black());
            grayScale[grayColor]++;
            *average += grayColor;
         }
     }
     *average /= (float)(image->width() * image->height());
}



void Escalas::cleanScale(long *grayScale, float *average)
{
    for (int i = 0; i < 256; i++)
        grayScale[i] = 0;
    *average = 0;
}
