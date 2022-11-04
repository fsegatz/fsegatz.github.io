#include "mainwidget.h"
#include "aboutmewidget.h"
#include "menuwidget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QTabWidget>

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    QTabWidget *tab = new QTabWidget(this);

    MenuWidget *menu = new MenuWidget(this);
    AboutMeWidget *aboutme = new AboutMeWidget(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tab, Qt::AlignTop);
    tab->addTab(aboutme, "ABOUT ME");
    tab->addTab(menu, "TEST");
    layout->addStretch();
    setLayout(layout);
}

MainWidget::~MainWidget()
{
}
