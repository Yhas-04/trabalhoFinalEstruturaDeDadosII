#ifndef TELAARVORE_H
#define TELAARVORE_H

#include <QWidget>
#include <QGraphicsScene>
#include "../src/Arvore.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class telaArvore;
}
QT_END_NAMESPACE

class telaArvore : public QWidget {
    Q_OBJECT

public:
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
};

#endif // TELAARVORE_H
