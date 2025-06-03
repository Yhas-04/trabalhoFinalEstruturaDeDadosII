/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btArvore;
    QPushButton *btHuffman;
    QGraphicsView *graphicsViewMain;
    QLabel *label;
    QTextBrowser *textBrowserCodificacao;
    QLineEdit *lDestino;
    QLineEdit *lOrigem;
    QTextEdit *textEditResultado;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(733, 400);
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Kufi Arabic Medium"));
        font.setPointSize(11);
        font.setBold(false);
        MainWindow->setFont(font);
        MainWindow->setMouseTracking(true);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::GoHome")));
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btArvore = new QPushButton(centralwidget);
        btArvore->setObjectName(QString::fromUtf8("btArvore"));
        btArvore->setGeometry(QRect(420, 350, 191, 31));
        btArvore->setMouseTracking(true);
        btHuffman = new QPushButton(centralwidget);
        btHuffman->setObjectName(QString::fromUtf8("btHuffman"));
        btHuffman->setGeometry(QRect(90, 130, 81, 31));
        graphicsViewMain = new QGraphicsView(centralwidget);
        graphicsViewMain->setObjectName(QString::fromUtf8("graphicsViewMain"));
        graphicsViewMain->setGeometry(QRect(270, 20, 451, 321));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-10, 0, 101, 31));
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        textBrowserCodificacao = new QTextBrowser(centralwidget);
        textBrowserCodificacao->setObjectName(QString::fromUtf8("textBrowserCodificacao"));
        textBrowserCodificacao->setGeometry(QRect(20, 280, 231, 101));
        lDestino = new QLineEdit(centralwidget);
        lDestino->setObjectName(QString::fromUtf8("lDestino"));
        lDestino->setGeometry(QRect(60, 80, 131, 25));
        lOrigem = new QLineEdit(centralwidget);
        lOrigem->setObjectName(QString::fromUtf8("lOrigem"));
        lOrigem->setGeometry(QRect(60, 40, 131, 25));
        textEditResultado = new QTextEdit(centralwidget);
        textEditResultado->setObjectName(QString::fromUtf8("textEditResultado"));
        textEditResultado->setGeometry(QRect(20, 180, 231, 91));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btArvore->setText(QCoreApplication::translate("MainWindow", "arvore", nullptr));
        btHuffman->setText(QCoreApplication::translate("MainWindow", "Codificar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Menu:", nullptr));
#if QT_CONFIG(whatsthis)
        lDestino->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        lDestino->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        lDestino->setPlaceholderText(QCoreApplication::translate("MainWindow", "destino", nullptr));
        lOrigem->setPlaceholderText(QCoreApplication::translate("MainWindow", "origem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
