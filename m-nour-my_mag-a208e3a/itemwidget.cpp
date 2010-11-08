#include "itemwidget.h"
#include "ui_itemwidget.h"

ItemWidget::ItemWidget(SlidingStackedWidget *s_stacked_widget,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemWidget)
{
    ui->setupUi(this);
    connect(ui->next_button,SIGNAL(clicked()),s_stacked_widget,SLOT(slideInNext()));
    connect(ui->back_button,SIGNAL(clicked()),s_stacked_widget,SLOT(slideInPrev()));
    connect(ui->home_button,SIGNAL(clicked()),s_stacked_widget,SLOT(slideHome()));
}

ItemWidget::~ItemWidget()
{
    delete ui;
}



void ItemWidget::setTopicBody(QListWidgetItem *item,QXmlStreamReader *xml,QByteArray data)
{
    QString title=item->text();
    xml->clear();
//    xml->addData(data);
    xml->addData(data);
    while(!xml->atEnd())
    {
        xml->readNext();
        if(xml->isStartElement())
        {
            if(xml->name()=="item")
            {
                while (!((xml->isEndElement())&&(xml->name()=="item")))
                {
                    xml->readNext();
                    int t=selectTag(xml->name().toString());
                    switch (t)
                    {
                    case 0:
                        if (title==xml->readElementText())
                        {
                            while (!((xml->isEndElement())&&(xml->name()=="item")))
                            {
                                xml->readNext();
                                int t2=selectTag(xml->name().toString());
                                switch (t2)
                                {
                                case 2:
                                    ui->web_view->setHtml(xml->readElementText(QXmlStreamReader::IncludeChildElements));
                                    break;
                                default:
                                    break;
                                }
                            }
                        }
                        break;
                        default:
                        break;
                    }
                }
            }
        }
    }
}


//LUT for tags inside XML
int ItemWidget::selectTag(QString tag)
{
    if (tag=="title")
        return 0;
    else if (tag=="link")
        return 1;
    else if (tag=="description")
        return 2;
    else if (tag=="pubDate")
        return 3;
    else if (tag=="encoded")
        return 4;
    else
        return -1;
}
