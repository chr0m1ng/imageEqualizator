#ifndef ESCALAS_H
#define ESCALAS_H

#include <QWidget>

class Escalas : public QWidget
{
    Q_OBJECT
public:
    explicit Escalas(QWidget *parent = 0);
    ~Escalas();
    void getScale(long *, float *, QImage *);
    void cleanScale(long *, float *);

};

#endif // ESCALAS_H
