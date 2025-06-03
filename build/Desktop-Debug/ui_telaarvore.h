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

class Ui_telaarvore
{
public:
    QCheckBox *ehCasa;
    QPushButton *btAdd;
    QPushButton *btVoltar;
    QGraphicsView *graphicsViewArvore;
    QLabel *label;
    QLineEdit *lNome;
    QLineEdit *lNum;
    QLabel *label_2;
    QLineEdit *lRemov;
    QPushButton *btRemover;

    void setupUi(QWidget *telaarvore)
    {
        if (telaarvore->objectName().isEmpty())
            telaarvore->setObjectName(QString::fromUtf8("telaarvore"));
        telaarvore->resize(400, 300);
        ehCasa = new QCheckBox(telaarvore);
        ehCasa->setObjectName(QString::fromUtf8("ehCasa"));
        ehCasa->setGeometry(QRect(300, 100, 82, 23));
        btAdd = new QPushButton(telaarvore);
        btAdd->setObjectName(QString::fromUtf8("btAdd"));
        btAdd->setGeometry(QRect(300, 130, 80, 25));
        btVoltar = new QPushButton(telaarvore);
        btVoltar->setObjectName(QString::fromUtf8("btVoltar"));
        btVoltar->setGeometry(QRect(10, 270, 80, 25));
        graphicsViewArvore = new QGraphicsView(telaarvore);
        graphicsViewArvore->setObjectName(QString::fromUtf8("graphicsViewArvore"));
        graphicsViewArvore->setGeometry(QRect(10, 10, 261, 201));
        label = new QLabel(telaarvore);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 10, 54, 17));
        lNome = new QLineEdit(telaarvore);
        lNome->setObjectName(QString::fromUtf8("lNome"));
        lNome->setGeometry(QRect(280, 40, 113, 25));
        lNum = new QLineEdit(telaarvore);
        lNum->setObjectName(QString::fromUtf8("lNum"));
        lNum->setGeometry(QRect(280, 70, 113, 25));
        label_2 = new QLabel(telaarvore);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 170, 71, 17));
        lRemov = new QLineEdit(telaarvore);
        lRemov->setObjectName(QString::fromUtf8("lRemov"));
        lRemov->setGeometry(QRect(280, 200, 113, 25));
        btRemover = new QPushButton(telaarvore);
        btRemover->setObjectName(QString::fromUtf8("btRemover"));
        btRemover->setGeometry(QRect(300, 240, 80, 25));

        retranslateUi(telaarvore);

        QMetaObject::connectSlotsByName(telaarvore);
    } // setupUi

    void retranslateUi(QWidget *telaarvore)
    {
        telaarvore->setWindowTitle(QCoreApplication::translate("telaarvore", "Form", nullptr));
        ehCasa->setText(QCoreApplication::translate("telaarvore", "CheckBox", nullptr));
        btAdd->setText(QCoreApplication::translate("telaarvore", "PushButton", nullptr));
        btVoltar->setText(QCoreApplication::translate("telaarvore", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("telaarvore", "Criar N\303\263:", nullptr));
        label_2->setText(QCoreApplication::translate("telaarvore", "Excluir N\303\263:", nullptr));
        btRemover->setText(QCoreApplication::translate("telaarvore", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class telaarvore: public Ui_telaarvore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAARVORE_H
