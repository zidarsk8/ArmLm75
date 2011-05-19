/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed Feb 23 22:49:55 2011
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditAddr;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEditPort;
    QLabel *label_7;
    QPushButton *getTempAllButton;
    QPushButton *clearButton;
    QPushButton *getTempButton;
    QPushButton *getLastTempButton;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QTextEdit *textEdit;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(539, 572);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setAutoFillBackground(false);
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setEnabled(true);
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEditAddr = new QLineEdit(widget_3);
        lineEditAddr->setObjectName(QString::fromUtf8("lineEditAddr"));

        gridLayout_2->addWidget(lineEditAddr, 0, 1, 1, 1);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        lineEditPort = new QLineEdit(widget_3);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout_2->addWidget(lineEditPort, 0, 3, 1, 1);


        gridLayout->addWidget(widget_3, 1, 0, 1, 4);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        getTempAllButton = new QPushButton(widget);
        getTempAllButton->setObjectName(QString::fromUtf8("getTempAllButton"));

        gridLayout->addWidget(getTempAllButton, 5, 2, 1, 1);

        clearButton = new QPushButton(widget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout->addWidget(clearButton, 5, 3, 1, 1);

        getTempButton = new QPushButton(widget);
        getTempButton->setObjectName(QString::fromUtf8("getTempButton"));

        gridLayout->addWidget(getTempButton, 5, 0, 1, 1);

        getLastTempButton = new QPushButton(widget);
        getLastTempButton->setObjectName(QString::fromUtf8("getLastTempButton"));

        gridLayout->addWidget(getLastTempButton, 5, 1, 1, 1);


        verticalLayout_2->addWidget(widget);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setMargin(11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textEdit = new QTextEdit(widget_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(textEdit, 0, 0, 1, 1);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setAutoFillBackground(false);
        verticalLayout_3 = new QVBoxLayout(widget_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalSpacer = new QSpacerItem(406, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);


        gridLayout_3->addWidget(widget_5, 0, 1, 1, 1);


        verticalLayout_2->addWidget(widget_4);


        verticalLayout->addWidget(widget_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 539, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Vaja 5", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Naslov:", 0, QApplication::UnicodeUTF8));
        lineEditAddr->setText(QApplication::translate("MainWindow", "192.168.1.", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Port:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "zahteva:", 0, QApplication::UnicodeUTF8));
        getTempAllButton->setText(QApplication::translate("MainWindow", "Get Temp All", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        getTempButton->setText(QApplication::translate("MainWindow", "Draw Graph", 0, QApplication::UnicodeUTF8));
        getLastTempButton->setText(QApplication::translate("MainWindow", "Get Last Temp", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
