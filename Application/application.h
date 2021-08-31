#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>

namespace Ui {
class application;
}

class application : public QWidget
{
    Q_OBJECT

public:
    explicit application(QWidget *parent = nullptr);
    ~application();

private:
    Ui::application *ui;
};

#endif // APPLICATION_H
