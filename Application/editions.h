#ifndef EDITIONS_H
#define EDITIONS_H

#include <QWidget>

namespace Ui {
class editions;
}

class editions : public QWidget
{
    Q_OBJECT

public:
    explicit editions(QWidget *parent = nullptr);
    ~editions();

private:
    Ui::editions *ui;
};

#endif // EDITIONS_H
