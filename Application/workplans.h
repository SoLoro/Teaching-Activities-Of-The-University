#ifndef WORKPLANS_H
#define WORKPLANS_H

#include <QWidget>

namespace Ui {
class workplans;
}

class workplans : public QWidget
{
    Q_OBJECT

public:
    explicit workplans(QWidget *parent = nullptr);
    ~workplans();

private:
    Ui::workplans *ui;
};

#endif // WORKPLANS_H
