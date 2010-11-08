#include "itemwidget.h"
#include "ui_itemwidget.h"
#include"QDebug"
#include"QListWidgetItem"

ItemWidget::ItemWidget(SlidingStackedWidget *s_stacked_widget,QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ItemWidget)
{
    ui->setupUi(this);

     setTopicBody();



    connect(ui->next_button,SIGNAL(clicked()),s_stacked_widget,SLOT(slideInNext()));
//        connect(ui->next_button,SIGNAL(clicked()),this,SLOT(myNextItem()));

    connect(ui->back_button,SIGNAL(clicked()),s_stacked_widget,SLOT(slideInPrev()));
    connect(ui->home_button,SIGNAL(clicked()),s_stacked_widget,SLOT(slideHome()));
}

ItemWidget::~ItemWidget()
{
    delete ui;
}

void ItemWidget::getHtml(QString html)
{
    ui->web_View->setHtml(html);
}

void ItemWidget::myNextItem()
{
//    QListWidgetItem *m=new QListWidgetItem;
////    qDebug()<<m_list->currentRow();
//    int row=m_list->currentRow();
//    row++;
//    //    m= m_list->item((m_list->currentRow())++);
//    m=m_list->item(row);
//    qDebug()<<m->text();
}

void ItemWidget::setTopicBody()
{
    ui->web_View->setHtml(description);
//    web_view->setHtml(description);
}


void ItemWidget::setItemWidgetList(QList<ItemWidget *> list)
{
    m_list=list;
}
