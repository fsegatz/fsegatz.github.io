#include "mainwidget.h"
#include "menuwidget.h"
#include <QPushButton>
#include <QHBoxLayout>

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    MenuWidget *menu = new MenuWidget(this);
    QPushButton *pushButton = new QPushButton(this);
    pushButton->setText("Push me");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(menu, Qt::AlignTop);
    layout->addWidget(pushButton);
    layout->addStretch();
    setLayout(layout);
}

MainWidget::~MainWidget()
{
}
