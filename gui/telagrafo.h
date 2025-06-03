#ifndef TELAGRAFO_H
#define TELAGRAFO_H

#include <QWidget>

namespace Ui {
class telagrafo;
}

class telagrafo : public QWidget
{
    Q_OBJECT

public:
    explicit telagrafo(QWidget *parent = nullptr);
    ~telagrafo();

private:
    Ui::telagrafo *ui;
};

#endif // TELAGRAFO_H
