#ifndef PULPITS_H
#define PULPITS_H

#include <QWidget>

namespace Ui {
class pulpits;
}

class pulpits : public QWidget
{
    Q_OBJECT

public:
    explicit pulpits(QWidget *parent = nullptr);
    ~pulpits();

private:
    Ui::pulpits *ui;
};

#endif // PULPITS_H
