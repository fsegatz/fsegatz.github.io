#include "aboutmewidget.h"

#include <QLabel>
#include <QPixmap>
#include <QFrame>
#include <QRegion>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFont>

AboutMeWidget::AboutMeWidget(QWidget *parent)
    : QWidget{parent}
{
    Q_INIT_RESOURCE(resources);
    QPixmap *pixmap = new QPixmap(":/data/profilepicture.jpg");

    QLabel *picture = new QLabel(this);
    picture->setPixmap(*pixmap);
    picture->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    picture->setFixedSize(160, 160);
    picture->setScaledContents(true);
    picture->setMask(QRegion(0,0, picture->width(), picture->height(), QRegion::Ellipse));

    QLabel *name = new QLabel(this);
    name->setText("Fabian Segatz");
    name->setFont(QFont("Helvetica", 28));
    name->setAlignment(Qt::AlignHCenter);
    QLabel *description = new QLabel(this);
    description->setTextFormat(Qt::MarkdownText);
    description->setText(
                "Master's student for Embedded Systems at [KTH Royal Institute of Technology](https://www.kth.se/en)<br />"
                "Embedded Software Engineer at [Cobolt AB](https://www.linkedin.com/company/cobolt-ab/)"
        );
    description->setFont(QFont("Helvetica", 12));
    description->setAlignment(Qt::AlignHCenter);
    description->setTextInteractionFlags(Qt::TextBrowserInteraction);
    description->setOpenExternalLinks(true);
    QPushButton *contact = new QPushButton(this);
    contact->setText("Contact me");
    contact->setFont(QFont("Helvetica", 12));
    contact->setFixedWidth(100);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(picture, 0, Qt::AlignHCenter);
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
