#ifndef TELAARVORE_H
#define TELAARVORE_H

#include <QWidget>
#include <QGraphicsScene>
#include "../src/Arvore.h"
#include "../src/Grafo.h"
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class telaArvore;
}
QT_END_NAMESPACE

class MainWindow;

class telaArvore : public QWidget {
    Q_OBJECT

public:

    Arvore* getArvore() { return &arvore; }
    MainWindow *mainW;
    void mostrarArvore(noArvore* raiz);
    explicit telaArvore(QWidget *parent = nullptr);
    ~telaArvore();


private slots:
    void on_btAdd_clicked();

    void on_addEx_clicked();

    void on_btRemover_clicked();

private:

    Ui::telaArvore *ui;
    QGraphicsScene *scene;
    Arvore arvore;


    void desenharArvore(noArvore* no, int x, int y, int espacamento);
    void ajustarVisualizacao();

signals:
    void arvoreAtualizada();

};


#endif // TELAARVORE_H
