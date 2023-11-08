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
    tab->addTab(aboutme, "About Me");
    tab->addTab(menu, "Test");
    tab->setStyleSheet("QTabWidget::tab-bar {alignment: center}");
    tab->setFont(QFont("Helvetica", 18));
    layout->addStretch();
    setLayout(layout);
}

MainWidget::~MainWidget()
{
}
