#include "xml.h"

Xml::Xml()
{
}

////render and fill Home List
//void Xml::rss_render()
//{
//    int count=0;
//    data=rep->readAll();
//    xml.addData(data);
//    while(!xml.atEnd())
//    {
//        xml.readNext();
//        if(xml.isStartElement())
//        {
//            if(xml.name()=="item")
//            {
//                count++;
//                QListWidgetItem *item = new QListWidgetItem;
//                item->setIcon(*icon);
//                while (!((xml.isEndElement())&&(xml.name()=="item")))
//                {
//                    xml.readNext();
//                    int t=select_tag(xml.name().toString());
//                    switch (t)
//                    {
//                    case 0:
//                        item->setText(xml.readElementText(QXmlStreamReader::IncludeChildElements));
//                        list->addItem(item);
//                        list->setWordWrap(1);
//                        list->setUniformItemSizes(1);
//                        list->setSpacing(2);
//                        break;
//                    default:
//                        break;
//                    }
//                }
//            }
//        }
//    }

//    no_of_rss_topics =count+1;
//}


//LUT for tags inside XML
int Xml::select_tag(QString tag)
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


