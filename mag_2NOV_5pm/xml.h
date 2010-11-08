#ifndef XML_H
#define XML_H

#include"QListWidgetItem"
#include"QXmlStreamReader"

class Xml
{
public:
    Xml();

    //FUNC
    void rss_render();
    int select_tag(QString tag);
};

#endif // XML_H
