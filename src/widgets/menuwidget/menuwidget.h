#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    MenuWidget(QWidget *parent = nullptr);
    ~MenuWidget();
};
#endif // MENUWIDGET_H
