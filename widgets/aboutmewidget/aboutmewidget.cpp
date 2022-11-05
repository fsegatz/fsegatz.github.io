#include "aboutmewidget.h"

#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFont>

AboutMeWidget::AboutMeWidget(QWidget *parent)
    : QWidget{parent}
{
    Q_INIT_RESOURCE(resources);
    QLabel *picture = new QLabel(this);
    picture->setAlignment(Qt::AlignHCenter);
    QPixmap *pixmap = new QPixmap(":/data/profilepicture.jpg");
    *pixmap = pixmap->scaledToWidth(160, Qt::FastTransformation);
    picture->setPixmap(*pixmap);

    QLabel *name = new QLabel(this);
    name->setText("Fabian Segatz");
    name->setFont(QFont("Helvetica", 28));
    name->setAlignment(Qt::AlignHCenter);
    QLabel *description = new QLabel(this);
    description->setText(
                "Master's student for Embedded Systems at KTH Royal Institute of Technology\n"
                "Embedded Software Engineer at Cobolt AB"
        );
    description->setFont(QFont("Helvetica", 12));
    description->setAlignment(Qt::AlignHCenter);
    QPushButton *contact = new QPushButton(this);
    contact->setText("Contact me");
    contact->setFont(QFont("Helvetica", 12));
    contact->setFixedWidth(100);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(picture, 0, Qt::AlignTop);
    layout->addWidget(name);
    layout->addWidget(description);
    layout->addWidget(contact, 0,Qt::AlignHCenter);
    layout->addStretch();
    setLayout(layout);
}

AboutMeWidget::~AboutMeWidget()
{
    Q_CLEANUP_RESOURCE(resources);
}
