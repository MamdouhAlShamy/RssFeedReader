#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include"item.h"

//Nour try

//item *new_item_pointer;

//MMS try
ItemWidget *new_item_pointer[10];

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //adjust the Mother Widget
    QGridLayout *mother=new QGridLayout(ui->centralWidget);

    //WEB
    communicateWithWeb();

    //adjust layout of Stacked Widgets
    sstacked_widget=new SlidingStackedWidget(ui->centralWidget);

    mother->addWidget(sstacked_widget);

    //set setting 4 SlidingStackedWidget
    sstacked_widget->setSpeed(500);
    sstacked_widget->setAnimation(QEasingCurve::InCubic);

    //instant topics
    //    for(int i=0;i<no_of_rss_topics;i++){
    //        //create Widgets

    //        //insert Widgets in sstacked_widget

    //        //apply grids

    //        //apply Wev View
    //    }

    //I<<Widget of Home of Topics
    QWidget *home_page=new QWidget;
    QGridLayout *grid0=new QGridLayout(home_page);
    list=new QListWidget(home_page);
    grid0->addWidget(list,0,0);
    //inserting home of topics and topics in Stacked Widget
    sstacked_widget->insertWidget(0,home_page);


    //XML instance
    //    Xml *xml=new Xml;

    //    //draw Topic Widget
    //    drawWidget();






    /*
    //I<<Widget of Home of Topics
    QWidget *home_page=new QWidget;
    QGridLayout *grid0=new QGridLayout(home_page);
    list=new QListWidget(home_page);
    grid0->addWidget(list,0,0);

*/

    /*
//   //II<<Topic Widget -only one topic-
//    QWidget *page1=new QWidget;
//    QGridLayout *grid1=new QGridLayout(page1);

    //structure of each topic
    ///////
//    ////II-A<<the web page
//    web_view=new QWebView(page1);
//    grid1->addWidget(web_view,0,0);

//    ////II-B<<navigation
//    QHBoxLayout *hlayout=new QHBoxLayout();
//    grid1->addLayout(hlayout,1,0);

//    QPushButton *back_button=new QPushButton("Back",page1);
//    QPushButton *next_button=new QPushButton("Nxt",page1);
//    QPushButton *home_button=new QPushButton("Home",page1);

//    hlayout->addWidget(back_button);
//    hlayout->addWidget(home_button);
//    hlayout->addWidget(next_button);
//    ////////
//    sstacked_widget->insertWidget(1,page1);

    //second Topic

//    QWidget *page2=new QWidget;
//    QGridLayout *grid2=new QGridLayout(page2);

//    //the web page
//    grid2->addWidget(web_view,0,0);

//    //nav
//    grid2->addLayout(hlayout,1,0);


//    hlayout->addWidget(back_button);
//    hlayout->addWidget(home_button);
//    hlayout->addWidget(next_button);

    //


//    grid0->setMargin(0);
//    grid1->setMargin(0);


*/


    //connection
    connect(rep, SIGNAL(finished()), this, SLOT(rss_render()));
    connect(rep,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(errorInConnection()));
    //    connect(rep,SIGNAL(finished()),this,SLOT(drawAll()));

    connect(list, SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(full_screen(QListWidgetItem*)));
    connect(list, SIGNAL(itemClicked(QListWidgetItem*)),sstacked_widget, SLOT(slideInNext()));

}

void MainWindow::communicateWithWeb()
{
    //Enable Flash
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);

    url="http://scobleizer.com/feed/";
    //    url="http://androidforums.com/external.php?type=RSS2";

    mgr=new QNetworkAccessManager(this);
    req.setUrl(url);
    rep=mgr->get(req);

    QWebView *web_v=new QWebView;
    web_v->setUrl(url);
    icon=new QIcon;
    *icon=web_v->icon();
}

//rendering the xml after connection ends
void MainWindow::rss_render()
{
    count=0;
    //get data from conn. reply
    data=rep->readAll();
    //put it in xml
    xml.addData(data);
    //count no of items
    while(!xml.atEnd())
    {
        xml.readNext();
        if(xml.isStartElement())
        {
            if(xml.name()=="item")
            {
                count++;
            }
        }
    }

    //Nour try
    for(int i=0;i<count;i++)
    {
        //make objects for items
        ItemWidget *new_item=new ItemWidget(sstacked_widget);

//        sstacked_widget->insertWidget((i++),new_item);

        //pointer to use with the items
        new_item_pointer[i]=new_item;

    }

    //mms try
    //create ITemsWidget with number of topics in XML and put them in Stacked View
    ////    for (int i=0;i<count;i++)
    ////    {
    //        //create instance of IteWidget
    //        ItemWidget *new_item=new ItemWidget(sstacked_widget);

    //        //put it in Stacked Widget
    //        sstacked_widget->insertWidget(1,new_item);

    //        //append it in list_of_itemsWidget which will have all ItemWidget inside it
    //        list_of_itemsWidget << new_item;
    //    }


    //adding data again to render it
    xml.clear();
    xml.addData(data);
    int i=0;
    //render
    while(!xml.atEnd())
    {
        xml.readNext();
        if(xml.isStartElement())
        {
            if(xml.name()=="item")
            {
                QListWidgetItem *list_item = new QListWidgetItem;
                list_item->setIcon(*icon);
                while (!((xml.isEndElement())&&(xml.name()=="item")))
                {
                    xml.readNext();
                    int t=select_tag(xml.name().toString());
                    switch (t)
                    {
                    case 0://title tag
                        new_item_pointer[i]->title=xml.readElementText(QXmlStreamReader::IncludeChildElements);
                        //adjusting list
                        list_item->setText(new_item_pointer[i]->title);
                        //add Item
                        list->addItem(list_item);
                        list->setWordWrap(1);
                        list->setUniformItemSizes(1);
                        list->setSpacing(2);
                        break;
                    case 1://link tag
                        new_item_pointer[i]->link=new QUrl(xml.readElementText(QXmlStreamReader::IncludeChildElements));
                        break;
                    case 2://description tag
                        new_item_pointer[i]->description=xml.readElementText(QXmlStreamReader::IncludeChildElements);
                        break;
                    case 3://pub date tag
                        new_item_pointer[i]->pub_date=xml.readElementText(QXmlStreamReader::IncludeChildElements);
                        break;
                    default:
                        break;
                    }
                }
                i++;
            }
        }
    }
}

//LUT for tags inside XML
int MainWindow::select_tag(QString tag)
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

//void MainWindow::setTopicBody(QListWidgetItem* item)
//{
//    qDebug()<<list->currentRow();
//    QString title=item->text();
//    xml.clear();
//    xml.addData(data);
//    while(!xml.atEnd())
//    {
//        xml.readNext();
//        if(xml.isStartElement())
//        {
//            if(xml.name()=="item")
//            {
//                while (!((xml.isEndElement())&&(xml.name()=="item")))
//                {
//                    xml.readNext();
//                    int t=select_tag(xml.name().toString());
//                    switch (t)
//                    {
//                    case 0:
//                        if (title==xml.readElementText())
//                        {
//                            while (!((xml.isEndElement())&&(xml.name()=="item")))
//                            {
//                                xml.readNext();
//                                int t2=select_tag(xml.name().toString());
//                                switch (t2)
//                                {
//                                case 2:
//                                    nm->getHtml(xml.readElementText(QXmlStreamReader::IncludeChildElements));
//                                    //                                   web_view->setHtml(xml.readElementText(QXmlStreamReader::IncludeChildElements));
//                                    break;
//                                default:
//                                    break;
//                                }
//                            }
//                        }
//                        break;
//                        default:
//                        break;
//                    }
//                }
//            }
//        }
//    }


//}

MainWindow::~MainWindow()
{
    //    delete[] new_item_pointer;
    delete ui;
}



//make instance of ItemWidget and put it in SStacked Widget and show it
void MainWindow::drawWidget(int i)
{
    //create instance of itemWidget Widget
    //    nm=new ItemWidget(sstacked_widget,list);

    //set itemWidget Widget in slidingStackedWidget
    sstacked_widget->insertWidget(i,nm);

    //show
    //    nm->show();

}

void MainWindow::errorInConnection()
{
    qDebug("Erorr in Connection");
}

//draw all widgets for Items
void MainWindow::drawAll()
{
    for(int i=1;i<no_of_rss_topics;i++)
    {
        drawWidget(i);
    }
}

void MainWindow::full_screen(QListWidgetItem* list_item)
{
    //    new_item_pointer[list->currentIndex().row()].setTopicBody();
    //    new_item_pointer[1].show();
    new_item_pointer[list->currentIndex().row()]->setTopicBody();
//    new_item_pointer[list->currentIndex().row()]->show();

    sstacked_widget->insertWidget(list->currentIndex().row(),new_item_pointer[list->currentIndex().row()]);

//    //setTopicBody for clicked topic
//    list_of_itemsWidget[list->currentIndex().row()]->setTopicBody();
//    //show it
//    list_of_itemsWidget[list->currentIndex().row()]->show();

}
