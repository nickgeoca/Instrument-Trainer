/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Mar 30 15:36:31 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *controlLayout;
    QLabel *label;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QSpinBox *spinBox_micNum;
    QGridLayout *plotLayout;
    QHBoxLayout *dataLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *eventText;
    QLabel *eventText_2;
    QLabel *eventText_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(673, 299);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        controlLayout = new QVBoxLayout();
        controlLayout->setSpacing(6);
        controlLayout->setObjectName(QString::fromUtf8("controlLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        controlLayout->addWidget(label);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        controlLayout->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        controlLayout->addItem(verticalSpacer);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        controlLayout->addWidget(label_3);

        spinBox_micNum = new QSpinBox(centralWidget);
        spinBox_micNum->setObjectName(QString::fromUtf8("spinBox_micNum"));
        spinBox_micNum->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(30);
        sizePolicy2.setHeightForWidth(spinBox_micNum->sizePolicy().hasHeightForWidth());
        spinBox_micNum->setSizePolicy(sizePolicy2);
        spinBox_micNum->setMinimumSize(QSize(0, 35));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        spinBox_micNum->setFont(font);

        controlLayout->addWidget(spinBox_micNum);


        gridLayout->addLayout(controlLayout, 0, 0, 3, 1);

        plotLayout = new QGridLayout();
        plotLayout->setSpacing(6);
        plotLayout->setObjectName(QString::fromUtf8("plotLayout"));

        gridLayout->addLayout(plotLayout, 2, 2, 1, 1);

        dataLayout = new QHBoxLayout();
        dataLayout->setSpacing(20);
        dataLayout->setObjectName(QString::fromUtf8("dataLayout"));
        dataLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        dataLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        dataLayout->addItem(horizontalSpacer_3);

        eventText = new QLabel(centralWidget);
        eventText->setObjectName(QString::fromUtf8("eventText"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(eventText->sizePolicy().hasHeightForWidth());
        eventText->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        eventText->setFont(font1);

        dataLayout->addWidget(eventText);

        eventText_2 = new QLabel(centralWidget);
        eventText_2->setObjectName(QString::fromUtf8("eventText_2"));
        sizePolicy3.setHeightForWidth(eventText_2->sizePolicy().hasHeightForWidth());
        eventText_2->setSizePolicy(sizePolicy3);
        eventText_2->setFont(font1);

        dataLayout->addWidget(eventText_2);

        eventText_3 = new QLabel(centralWidget);
        eventText_3->setObjectName(QString::fromUtf8("eventText_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(eventText_3->sizePolicy().hasHeightForWidth());
        eventText_3->setSizePolicy(sizePolicy4);
        eventText_3->setFont(font1);

        dataLayout->addWidget(eventText_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        dataLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(dataLayout, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 673, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Control Menu", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Mic Number", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        eventText->setText(QApplication::translate("MainWindow", "Note", 0, QApplication::UnicodeUTF8));
        eventText_2->setText(QApplication::translate("MainWindow", "Tune", 0, QApplication::UnicodeUTF8));
        eventText_3->setText(QApplication::translate("MainWindow", "Amplitude", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
