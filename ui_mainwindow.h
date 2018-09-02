/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *src_label;
    QLineEdit *src_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *des_label;
    QLineEdit *des_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *rule_comboBox;
    QPushButton *inquireButton;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(604, 377);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        src_label = new QLabel(tab);
        src_label->setObjectName(QStringLiteral("src_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(src_label->sizePolicy().hasHeightForWidth());
        src_label->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(src_label);

        src_lineEdit = new QLineEdit(tab);
        src_lineEdit->setObjectName(QStringLiteral("src_lineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(src_lineEdit->sizePolicy().hasHeightForWidth());
        src_lineEdit->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(src_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        des_label = new QLabel(tab);
        des_label->setObjectName(QStringLiteral("des_label"));
        sizePolicy2.setHeightForWidth(des_label->sizePolicy().hasHeightForWidth());
        des_label->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(des_label);

        des_lineEdit = new QLineEdit(tab);
        des_lineEdit->setObjectName(QStringLiteral("des_lineEdit"));
        sizePolicy3.setHeightForWidth(des_lineEdit->sizePolicy().hasHeightForWidth());
        des_lineEdit->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(des_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        rule_comboBox = new QComboBox(tab);
        rule_comboBox->addItem(QString());
        rule_comboBox->addItem(QString());
        rule_comboBox->addItem(QString());
        rule_comboBox->setObjectName(QStringLiteral("rule_comboBox"));
        sizePolicy3.setHeightForWidth(rule_comboBox->sizePolicy().hasHeightForWidth());
        rule_comboBox->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(rule_comboBox);

        inquireButton = new QPushButton(tab);
        inquireButton->setObjectName(QStringLiteral("inquireButton"));
        sizePolicy3.setHeightForWidth(inquireButton->sizePolicy().hasHeightForWidth());
        inquireButton->setSizePolicy(sizePolicy3);
        inquireButton->setAutoDefault(true);

        horizontalLayout_3->addWidget(inquireButton);


        verticalLayout->addLayout(horizontalLayout_3);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        src_label->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213\347\253\231\357\274\232", nullptr));
        des_label->setText(QApplication::translate("MainWindow", "\347\273\210\347\202\271\347\253\231\357\274\232", nullptr));
        rule_comboBox->setItemText(0, QApplication::translate("MainWindow", "\350\267\235\347\246\273\346\234\200\347\237\255", nullptr));
        rule_comboBox->setItemText(1, QApplication::translate("MainWindow", "\346\227\266\351\227\264\346\234\200\347\237\255", nullptr));
        rule_comboBox->setItemText(2, QApplication::translate("MainWindow", "\346\215\242\344\271\230\346\234\200\345\260\221", nullptr));

        inquireButton->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\347\272\277\350\267\257\346\237\245\350\257\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\347\253\231\347\202\271\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
