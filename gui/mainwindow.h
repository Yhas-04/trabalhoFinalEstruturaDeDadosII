#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "telaarvore.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   // void on_btGrafo_clicked();

    void on_btArvore_clicked();

private:
    Ui::MainWindow *ui;
    telaArvore *winArvore = nullptr;
};
#endif // MAINWINDOW_H
