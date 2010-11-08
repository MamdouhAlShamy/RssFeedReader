/********************************************************************************
** Form generated from reading UI file 'itemwidget.ui'
**
** Created: Tue Nov 2 15:30:28 2010
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
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_ItemWidget
{
public:
    QGridLayout *gridLayout;
    QWebView *web_view;
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
        web_view = new QWebView(ItemWidget);
        web_view->setObjectName(QString::fromUtf8("web_view"));
        web_view->setUrl(QUrl("about:blank"));

        gridLayout->addWidget(web_view, 0, 0, 1, 3);

        back_button = new QPushButton(ItemWidget);
        back_button->setObjectName(QString::fromUtf8("back_button"));

        gridLayout->addWidget(back_button, 1, 0, 1, 1);

        home_button = new QPushButton(ItemWidget);
        home_button->setObjectName(QString::fromUtf8("home_button"));

        gridLayout->addWidget(home_button, 1, 1, 1, 1);

        next_button = new QPushButton(ItemWidget);
        next_button->setObjectName(QString::fromUtf8("next_button"));

        gridLayout->addWidget(next_button, 1, 2, 1, 1);


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
