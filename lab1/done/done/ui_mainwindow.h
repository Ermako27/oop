/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_5;
    QLabel *label_9;
    QLineEdit *lineEdit_8;
    QLabel *label_10;
    QLineEdit *lineEdit_9;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_4;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 800);
        MainWindow->setMinimumSize(QSize(1000, 800));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(390, 10, 600, 600));
        graphicsView->setMinimumSize(QSize(600, 600));
        gridLayoutWidget_4 = new QWidget(centralWidget);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 10, 371, 426));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_9 = new QLabel(gridLayoutWidget_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 1, 2, 1, 1);

        lineEdit_8 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout_5->addWidget(lineEdit_8, 2, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_5->addWidget(label_10, 1, 3, 1, 1);

        lineEdit_9 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout_5->addWidget(lineEdit_9, 2, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 1, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 0, 1, 1, 1);

        lineEdit_10 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout_5->addWidget(lineEdit_10, 2, 3, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_5->addWidget(pushButton_4, 3, 1, 1, 3);


        gridLayout_4->addLayout(gridLayout_5, 4, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_5 = new QLabel(gridLayoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 1, 2, 1, 1);

        lineEdit_5 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_3->addWidget(lineEdit_5, 2, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 1, 3, 1, 1);

        lineEdit_6 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_3->addWidget(lineEdit_6, 2, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 1, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 0, 1, 1, 1);

        lineEdit_7 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_3->addWidget(lineEdit_7, 2, 3, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 3, 1, 1, 3);


        gridLayout_4->addLayout(gridLayout_3, 3, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(gridLayoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 2, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 2, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 3, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_4);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 2, 3, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 3, 1, 1, 3);


        gridLayout_4->addLayout(gridLayout_2, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(gridLayoutWidget_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Z:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "X:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265:", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Z:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "X:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265:", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Z:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "X:", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265:", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
