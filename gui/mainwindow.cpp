#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "telaarvore.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_btGrafo_clicked()
{
    if (!winGrafo){ winGrafo = new telaGrafo(this); }
    winGrafo->show();
    winGrafo->raise();
    winGrafo->activateWindow();
}*/

void MainWindow::on_btArvore_clicked()
{
    if (!winArvore) { winArvore = new telaArvore(nullptr); }
    winArvore->show();
    winArvore->raise();
    winArvore->activateWindow();
}


