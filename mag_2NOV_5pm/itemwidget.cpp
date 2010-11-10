#include "itemwidget.h"
#include "ui_itemwidget.h"
#include"QDebug"
#include"QListWidgetItem"

ItemWidget::ItemWidget(SlidingStackedWidget *s_stacked_widget,QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ItemWidget)
{
    ui->setupUi(this);
    //    setTopicBody();

    Here=0;
    //save Stacked Widget inside
    s_Stacked_Widget=s_stacked_widget;

    qDebug()<<s_stacked_widget->count();

    //where is am
    //done


    //    //who is next
    //    s_stacked_widget->insertWidget(Here++,item_widget_pointer[Here++]);

    //    //who is prev
    //    s_stacked_widget->insertWidget(Here--,item_widget_pointer[Here--]);


    //prepare next button by putting next item



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
    ////    qDebug()<<m_list->clrentRow();
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


//void ItemWidget::setItemWidgetList(QList<ItemWidget *> list)
//{
//    m_list=list;
//}

void ItemWidget::setItemWidgetPointer(ItemWidget *list[]){

    //who is next
    s_Stacked_Widget->insertWidget((Here+2),list[Here+1]);
    qDebug()<<list[Here+1]->description;

    if(Here!=0)
    {
        //who is prev
        s_Stacked_Widget->insertWidget(Here,list[Here-1]);
        qDebug()<<list[Here-1]->description;
    }
}

void ItemWidget::whereIam(int here)
{
    Here=here;
}


//Gestures
void ItemWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint p_start=this->mapFromGlobal(QCursor::pos());

    //after time check new p.x
    for(int i=0;i<9000;i++)
        for(int j=0;j<9000;j++);

    QPoint p_end=this->mapFromGlobal(QCursor::pos());

    int x_end=p_end.x();
    int x_start=p_start.x();

    int y_start=p_start.y();
    int y_end=p_end.y();

    //next
    if(x_end>x_start)
        ui->next_button->click();

    //back
    else if(x_start>x_end)
        ui->back_button->click();

    //home
    else
        ui->home_button->click();

    //    if(y_start>y_end&&(x_start-x_end)<)

}
