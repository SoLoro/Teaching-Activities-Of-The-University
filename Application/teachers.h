#ifndef TEACHERS_H
#define TEACHERS_H

#include <QWidget>

namespace Ui {
class teachers;
}

class teachers : public QWidget
{
    Q_OBJECT

public:
    explicit teachers(QWidget *parent = nullptr);
    ~teachers();

private:
    Ui::teachers *ui;
};

#endif // TEACHERS_H
