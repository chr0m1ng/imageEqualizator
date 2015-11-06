#ifndef EQUALIZADOR_H
#define EQUALIZADOR_H

#include <QWidget>

class Equalizador : public QWidget
{
    Q_OBJECT
public:
    explicit Equalizador(QWidget *parent = 0);
    ~Equalizador();
    void Equalizar(QImage *, long *, long *);
};

#endif // EQUALIZADOR_H
