#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <unordered_map>
#include "../src/Grafo.h"
#include "telaarvore.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class telaArvore;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btArvore_clicked();

    void on_btHuffman_clicked();

private:
    Arvore arvore;
    telaArvore *winArvore = nullptr;
    Ui::MainWindow *ui;
    Grafo grafo;
    void desenharGrafo();
    QGraphicsScene *sceneGrafo;


};

#endif // MAINWINDOW_H
