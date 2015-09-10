#ifndef BRILHO_H
#define BRILHO_H

#include <QWidget>
#include <QLabel>

class brilho : public QWidget
{
    Q_OBJECT
public:
    explicit brilho(QWidget *parent = 0);
    ~brilho();
    void appling(bool, int, QImage *, QImage *);
signals:

public slots:

};

#endif // BRILHO_H
