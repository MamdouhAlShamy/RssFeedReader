/********************************************************************************
** Form generated from reading UI file 'itemwidget.ui'
**
** Created: Mon Nov 8 14:03:39 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMWIDGET_H
#define UI_ITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_ItemWidget
{
public:
    QGridLayout *gridLayout;
    QWebView *web_View;
    QHBoxLayout *horizontalLayout;
    QPushButton *back_button;
    QPushButton *home_button;
    QPushButton *next_button;

    void setupUi(QWidget *ItemWidget)
    {
        if (ItemWidget->objectName().isEmpty())
            ItemWidget->setObjectName(QString::fromUtf8("ItemWidget"));
        ItemWidget->resize(400, 300);
        gridLayout = new QGridLayout(ItemWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        web_View = new QWebView(ItemWidget);
        web_View->setObjectName(QString::fromUtf8("web_View"));
        web_View->setUrl(QUrl("about:blank"));

        gridLayout->addWidget(web_View, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        back_button = new QPushButton(ItemWidget);
        back_button->setObjectName(QString::fromUtf8("back_button"));

        horizontalLayout->addWidget(back_button);

        home_button = new QPushButton(ItemWidget);
        home_button->setObjectName(QString::fromUtf8("home_button"));

        horizontalLayout->addWidget(home_button);

        next_button = new QPushButton(ItemWidget);
        next_button->setObjectName(QString::fromUtf8("next_button"));

        horizontalLayout->addWidget(next_button);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(ItemWidget);

        QMetaObject::connectSlotsByName(ItemWidget);
    } // setupUi

    void retranslateUi(QWidget *ItemWidget)
    {
        ItemWidget->setWindowTitle(QApplication::translate("ItemWidget", "Form", 0, QApplication::UnicodeUTF8));
        back_button->setText(QApplication::translate("ItemWidget", "<", 0, QApplication::UnicodeUTF8));
        home_button->setText(QApplication::translate("ItemWidget", "Home", 0, QApplication::UnicodeUTF8));
        next_button->setText(QApplication::translate("ItemWidget", ">", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ItemWidget: public Ui_ItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMWIDGET_H
