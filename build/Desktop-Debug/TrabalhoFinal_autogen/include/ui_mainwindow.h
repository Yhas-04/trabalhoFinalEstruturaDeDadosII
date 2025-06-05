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
    QLineEdit *lDestino;
    QLineEdit *lOrigem;
    QTextEdit *textEditResultado;
    QLabel *lBOrigem;
    QLabel *lBDestino;
    QPushButton *btAGM;
    QTextEdit *teAGM;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(729, 435);
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
        btArvore->setGeometry(QRect(420, 390, 191, 31));
        btArvore->setMouseTracking(true);
        btHuffman = new QPushButton(centralwidget);
        btHuffman->setObjectName(QString::fromUtf8("btHuffman"));
        btHuffman->setGeometry(QRect(120, 140, 61, 31));
        btHuffman->setAutoDefault(false);
        btHuffman->setFlat(false);
        graphicsViewMain = new QGraphicsView(centralwidget);
        graphicsViewMain->setObjectName(QString::fromUtf8("graphicsViewMain"));
        graphicsViewMain->setGeometry(QRect(310, 90, 401, 291));
        graphicsViewMain->viewport()->setProperty("cursor", QVariant(QCursor(Qt::OpenHandCursor)));
        graphicsViewMain->setAutoFillBackground(false);
        graphicsViewMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsViewMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsViewMain->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        QBrush brush(QColor(20, 28, 45, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsViewMain->setBackgroundBrush(brush);
        graphicsViewMain->setInteractive(true);
        lDestino = new QLineEdit(centralwidget);
        lDestino->setObjectName(QString::fromUtf8("lDestino"));
        lDestino->setGeometry(QRect(90, 100, 141, 25));
        lOrigem = new QLineEdit(centralwidget);
        lOrigem->setObjectName(QString::fromUtf8("lOrigem"));
        lOrigem->setGeometry(QRect(90, 60, 141, 25));
        textEditResultado = new QTextEdit(centralwidget);
        textEditResultado->setObjectName(QString::fromUtf8("textEditResultado"));
        textEditResultado->setGeometry(QRect(310, 10, 401, 71));
        textEditResultado->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditResultado->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lBOrigem = new QLabel(centralwidget);
        lBOrigem->setObjectName(QString::fromUtf8("lBOrigem"));
        lBOrigem->setGeometry(QRect(60, 60, 61, 21));
        lBDestino = new QLabel(centralwidget);
        lBDestino->setObjectName(QString::fromUtf8("lBDestino"));
        lBDestino->setGeometry(QRect(60, 100, 61, 21));
        btAGM = new QPushButton(centralwidget);
        btAGM->setObjectName(QString::fromUtf8("btAGM"));
        btAGM->setGeometry(QRect(110, 390, 80, 25));
        teAGM = new QTextEdit(centralwidget);
        teAGM->setObjectName(QString::fromUtf8("teAGM"));
        teAGM->setGeometry(QRect(30, 180, 251, 201));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 211, 31));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        btHuffman->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btArvore->setText(QCoreApplication::translate("MainWindow", "\303\201rvore", nullptr));
        btHuffman->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
#if QT_CONFIG(whatsthis)
        lDestino->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        lDestino->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        lDestino->setPlaceholderText(QCoreApplication::translate("MainWindow", "destino", nullptr));
        lOrigem->setPlaceholderText(QCoreApplication::translate("MainWindow", "origem", nullptr));
        textEditResultado->setPlaceholderText(QCoreApplication::translate("MainWindow", "Caminho m\303\255nimo de Dijkstra", nullptr));
        lBOrigem->setText(QString());
        lBDestino->setText(QString());
        btAGM->setText(QCoreApplication::translate("MainWindow", "AGM", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Buscar Caminho M\303\255nimo:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
