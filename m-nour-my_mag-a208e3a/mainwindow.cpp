#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"itemwidget.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //adjust the Mother Widget
    QGridLayout *mother=new QGridLayout(ui->centralWidget);

    //Func
    communicateWithWeb();

    //adjust layout of Stacked Widgets
    sstacked_widget=new SlidingStackedWidget(ui->centralWidget);

    mother->addWidget(sstacked_widget);

    //set setting 4 SlidingStackedWidget
    sstacked_widget->setSpeed(500);
    sstacked_widget->setAnimation(QEasingCurve::InCubic);

    //instant topics
    for(int i=0;i<no_of_rss_topics;i++){
        //create Widgets

        //insert Widgets in sstacked_widget

        //apply grids

        //apply Wev View
    }

    //I<<Widget of Home of Topics
    QWidget *home_page=new QWidget;
    QGridLayout *grid0=new QGridLayout(home_page);
    list=new QListWidget(home_page);
    grid0->addWidget(list,0,0);
    //inserting home of topics and topics in Stacked Widget
    sstacked_widget->insertWidget(0,home_page);

//    //draw Topic Widget
//    drawWidget();





    /*
    //I<<Widget of Home of Topics
    QWidget *home_page=new QWidget;
    QGridLayout *grid0=new QGridLayout(home_page);
    list=new QListWidget(home_page);
    grid0->addWidget(list,0,0);




//   //II<<Topic Widget -only one topic-
//    QWidget *page1=new QWidget;
//    QGridLayout *grid1=new QGridLayout(page1);

//    //structure of each topic
//    ///////
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
    //////////

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


    connect(list, SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(drawWidget(QListWidgetItem*)));
    connect(list, SIGNAL(itemClicked(QListWidgetItem*)),sstacked_widget, SLOT(slideInNext()));

}

void MainWindow::communicateWithWeb()
{
    //Enable Flash
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);

    url="http://scobleizer.com/feed/";
//    url="http://labs.qt.nokia.com/feed/";

    mgr=new QNetworkAccessManager(this);
    req.setUrl(url);
    rep=mgr->get(req);

    QWebView *web_v=new QWebView;
    web_v->setUrl(url);
    icon=new QIcon;
    *icon=web_v->icon();
}

//render and fill Home List
void MainWindow::rss_render()
{
    int count=0;
    data=rep->readAll();
    qDebug()<<data;
//    qDebug()<<xml->device();
    xml->addData(data);

    while(!xml->atEnd())
    {
        xml->readNext();
        if(xml->isStartElement())
        {
            if(xml->name()=="item")
            {
                count++;
                QListWidgetItem *item = new QListWidgetItem;
                item->setIcon(*icon);
                while (!((xml->isEndElement())&&(xml->name()=="item")))
                {
                    xml->readNext();
                    int t=selectTag(xml->name().toString());
                    switch (t)
                    {
                    case 0:
                        item->setText(xml->readElementText(QXmlStreamReader::IncludeChildElements));
                        list->addItem(item);
                        list->setWordWrap(1);
                        list->setUniformItemSizes(1);
                        list->setSpacing(2);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    no_of_rss_topics =count+1;
}

//LUT for tags inside XML
 int MainWindow::selectTag(QString tag)
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

/*void MainWindow::setTopicBody(QListWidgetItem* item)
//{
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
//                    int t=selectTag(xml.name().toString());
//                    switch (t)
//                    {
//                    case 0:
//                        if (title==xml.readElementText())
//                        {
//                            while (!((xml.isEndElement())&&(xml.name()=="item")))
//                            {
//                                xml.readNext();
//                                int t2=selectTag(xml.name().toString());
//                                switch (t2)
//                                {
//                                case 2:
//                                    web_view->setHtml(xml.readElementText(QXmlStreamReader::IncludeChildElements));
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

 */

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::drawWidget(QListWidgetItem* item)
{
    //create instance of itemWidget Widget
    ItemWidget *nm=new ItemWidget(sstacked_widget);

    //set itemWidget Widget in slidingStackedWidget
    sstacked_widget->insertWidget(1,nm);

//    nm->setTopicBody(item,xml,data);




    nm->show();

}

void MainWindow::errorInConnection()
{
    qDebug("Error in Connection");
}
