/********************************************************************************
** Form generated from reading UI file 'telaarvore.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELAARVORE_H
#define UI_TELAARVORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_telaArvore
{
public:
    QCheckBox *ehCasa;
    QPushButton *btAdd;
    QGraphicsView *graphicsViewArvore;
    QLabel *label;
    QLineEdit *lNome;
    QLineEdit *lNum;
    QLabel *label_2;
    QLineEdit *lRemov;
    QPushButton *btRemover;
    QPushButton *addEx;
    QLabel *label_3;

    void setupUi(QWidget *telaArvore)
    {
        if (telaArvore->objectName().isEmpty())
            telaArvore->setObjectName(QString::fromUtf8("telaArvore"));
        telaArvore->resize(543, 359);
        ehCasa = new QCheckBox(telaArvore);
        ehCasa->setObjectName(QString::fromUtf8("ehCasa"));
        ehCasa->setGeometry(QRect(430, 100, 82, 23));
        btAdd = new QPushButton(telaArvore);
        btAdd->setObjectName(QString::fromUtf8("btAdd"));
        btAdd->setGeometry(QRect(430, 130, 80, 25));
        graphicsViewArvore = new QGraphicsView(telaArvore);
        graphicsViewArvore->setObjectName(QString::fromUtf8("graphicsViewArvore"));
        graphicsViewArvore->setGeometry(QRect(10, 10, 381, 251));
        label = new QLabel(telaArvore);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(440, 10, 54, 17));
        lNome = new QLineEdit(telaArvore);
        lNome->setObjectName(QString::fromUtf8("lNome"));
        lNome->setGeometry(QRect(410, 40, 113, 25));
        lNum = new QLineEdit(telaArvore);
        lNum->setObjectName(QString::fromUtf8("lNum"));
        lNum->setGeometry(QRect(410, 70, 113, 25));
        label_2 = new QLabel(telaArvore);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(440, 170, 71, 17));
        lRemov = new QLineEdit(telaArvore);
        lRemov->setObjectName(QString::fromUtf8("lRemov"));
        lRemov->setGeometry(QRect(410, 200, 113, 25));
        btRemover = new QPushButton(telaArvore);
        btRemover->setObjectName(QString::fromUtf8("btRemover"));
        btRemover->setGeometry(QRect(430, 240, 80, 25));
        addEx = new QPushButton(telaArvore);
        addEx->setObjectName(QString::fromUtf8("addEx"));
        addEx->setGeometry(QRect(160, 310, 41, 25));
        label_3 = new QLabel(telaArvore);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 280, 121, 17));

        retranslateUi(telaArvore);

        QMetaObject::connectSlotsByName(telaArvore);
    } // setupUi

    void retranslateUi(QWidget *telaArvore)
    {
        telaArvore->setWindowTitle(QCoreApplication::translate("telaArvore", "Form", nullptr));
        ehCasa->setText(QCoreApplication::translate("telaArvore", "CheckBox", nullptr));
        btAdd->setText(QCoreApplication::translate("telaArvore", "Adicionar", nullptr));
        label->setText(QCoreApplication::translate("telaArvore", "Criar N\303\263:", nullptr));
        label_2->setText(QCoreApplication::translate("telaArvore", "Excluir N\303\263:", nullptr));
        btRemover->setText(QCoreApplication::translate("telaArvore", "Remover", nullptr));
        addEx->setText(QCoreApplication::translate("telaArvore", "add", nullptr));
        label_3->setText(QCoreApplication::translate("telaArvore", "Adicionar Exemplos:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class telaArvore: public Ui_telaArvore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAARVORE_H
