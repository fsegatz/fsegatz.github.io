#include "menuwidget.h"

#include <QPushButton>
#include <QHBoxLayout>

MenuWidget::MenuWidget(QWidget *parent)
    : QWidget{parent}
{
    QPushButton *threeDPrintingButton = new QPushButton(this);
    threeDPrintingButton->setText("3D Printing Projects");
    QPushButton *codingButton = new QPushButton(this);
    codingButton->setText("Coding Projects");
    QPushButton *aboutMeButton = new QPushButton(this);
    aboutMeButton->setText("About me");

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(threeDPrintingButton,1);
    layout->addWidget(codingButton,1);
    layout->addWidget(aboutMeButton,1);
    setLayout(layout);
}

MenuWidget::~MenuWidget()
{
}
