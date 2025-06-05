#include "telaarvore.h"
#include "ui_telaarvore.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include "../src/Grafo.h"
#include "mainwindow.h"

static const int NODE_RADIUS = 30;
static const int VERTICAL_SPACE = 90;
static const int INITIAL_SPACING = 200;


telaArvore::telaArvore(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::telaArvore)

{
    ui->setupUi(this);

     mainW = qobject_cast<MainWindow*>(parent);
    ui->addEx->setStyleSheet("background-color:#F0EAD6; color: black;");
    ui->btAdd->setStyleSheet("background-color:#F0EAD6; color: black;");
    ui->btRemover->setStyleSheet("background-color:#F0EAD6; color: black;");
    ui->lNum->setStyleSheet("background-color:#141c2d; color: white;");
    ui->lNome->setStyleSheet("background-color:#141c2d; color: white;");
    ui->graphicsViewArvore->setStyleSheet("background-color:#141c2d; color: white;");
    ui->lRemov->setStyleSheet("background-color:#141c2d; color: white;");

    scene = new QGraphicsScene(this);
    ui->graphicsViewArvore->setScene(scene);

    arvore.criarNo("Raiz", true, 50);
    desenharArvore(arvore.getRaiz(), 400, 20, INITIAL_SPACING);
}

telaArvore::~telaArvore()
{
    delete ui;
}

void telaArvore::desenharArvore(noArvore* no, int x, int y, int espacamento)
{
    if (!no) return;

    QBrush brushNo;
    if (no->ehCasa) { brushNo = QBrush(Qt::red); }
    scene->addEllipse(x, y, NODE_RADIUS, NODE_RADIUS, QPen(Qt::white), brushNo);

    QGraphicsTextItem* text = scene->addText(QString::fromStdString(no->nome));
    QFont font = text->font();
    font.setPointSize(10);
    text->setFont(font);

    QRectF textRect = text->boundingRect();

    qreal textX = x + (NODE_RADIUS - textRect.width()) / 2;
    qreal textY = y - textRect.height();

    text->setZValue(1);
    text->setPos(textX, textY);

    QString valorStr = QString::number(no->numCasa);
    QGraphicsTextItem* valorText = scene->addText(valorStr);
    QFont valorFont = valorText->font();
    valorFont.setPointSize(12);
    valorFont.setBold(true);
    valorText->setFont(valorFont);

    QRectF valorRect = valorText->boundingRect();
    qreal valorX = x + (NODE_RADIUS - valorRect.width()) / 2;
    qreal valorY = y + (NODE_RADIUS - valorRect.height()) / 2;
    valorText->setDefaultTextColor(Qt::white);
    valorText->setPos(valorX, valorY);
    valorText->setZValue(1);

    if (no->esquerdo) {
        scene->addLine(x + NODE_RADIUS/2, y + NODE_RADIUS, x - espacamento + NODE_RADIUS/2, y + VERTICAL_SPACE);
        desenharArvore(no->esquerdo, x - espacamento, y + VERTICAL_SPACE, espacamento / 2);
    }
    if (no->direito) {
        scene->addLine(x + NODE_RADIUS/2, y + NODE_RADIUS, x + espacamento + NODE_RADIUS/2, y + VERTICAL_SPACE);
        desenharArvore(no->direito, x + espacamento, y + VERTICAL_SPACE, espacamento / 2);
    }
}

void telaArvore::mostrarArvore(noArvore* raiz) {
    scene->clear();

    int xInicial = 400;
    int yInicial = 30;
    int espacamentoInicial = 120;
    desenharArvore(raiz, xInicial, yInicial, espacamentoInicial);

}

void telaArvore::on_btAdd_clicked()
{
    bool ok;
    int numCasa = ui->lNum->text().toInt(&ok);
    if (!ok) {
        qDebug() << "Valor inválido!";
        return;
    }

    QString nome = ui->lNome->text();
    if (nome.isEmpty()) {
        qDebug() << "Nome vazio!";
        return;
    }

    bool ehCasa = ui->ehCasa->isChecked();

    arvore.criarNo(nome.toStdString(), ehCasa, numCasa);

    scene->clear();
    desenharArvore(arvore.getRaiz(), 400, 20, INITIAL_SPACING);

    ui->lNum->clear();
    ui->lNome->clear();
    ui->ehCasa->setChecked(false);

    emit arvoreAtualizada();
}

void telaArvore::on_addEx_clicked()
{
    arvore.inserirExemplos();
    scene->clear();
    mostrarArvore(arvore.getRaiz());
   emit arvoreAtualizada();
}

void telaArvore::on_btRemover_clicked()
{
    QString nomeQt = ui->lRemov->text();
    if (nomeQt.isEmpty()) {
        qDebug() << "Nome vazio!";
        return;
    }
    std::string nome = nomeQt.toStdString();

    noArvore* no = arvore.buscarPorNome(arvore.getRaiz(), nome);
    if (!no) {
        qDebug() << "Nó não encontrado!";
        return;
    }

    if (no->ehCasa && mainW) {
        mainW->grafo.removerVertice(no->nome);
    }

    bool removido = arvore.removerPorNome(nome);
    if (!removido) {
        qDebug() << "Falha ao remover o nó!";
        return;
    }

    scene->clear();
    mostrarArvore(arvore.getRaiz());
    emit arvoreAtualizada();
}
