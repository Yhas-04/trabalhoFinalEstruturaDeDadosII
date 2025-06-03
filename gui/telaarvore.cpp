#include "telaarvore.h"
#include "ui_telaarvore.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>

static const int NODE_RADIUS = 30;
static const int VERTICAL_SPACE = 90;
static const int INITIAL_SPACING = 200;

telaArvore::telaArvore(QWidget *parent) :
    QWidget(parent),

  ui(new Ui::telaArvore)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsViewArvore->setScene(scene);

    arvore.criarNo("Raiz", false, 10);
    desenharArvore(arvore.getRaiz(), 400, 20, INITIAL_SPACING);
}

telaArvore::~telaArvore()
{
    delete ui;
}

void telaArvore::desenharArvore(noArvore* no, int x, int y, int espacamento)
{
    if (!no) return;

    scene->addEllipse(x, y, NODE_RADIUS, NODE_RADIUS, QPen(Qt::white), QBrush(Qt::black));


    QGraphicsTextItem* text = scene->addText(QString::fromStdString(no->nome));
    QFont font = text->font();
    font.setPointSize(10);
    text->setFont(font);

    // Calcula o bounding box do texto
    QRectF textRect = text->boundingRect();

    // Margem bem pequena
    const qreal margemX = 6.0;
    const qreal margemY = 2.0;

    // Centraliza o texto acima do círculo
    qreal textX = x + (NODE_RADIUS - textRect.width()) / 2;
    qreal textY = y - textRect.height() - margemY - 3;

    // Retângulo discreto, horizontal, só um pouco maior que o texto
    QRectF rectFundo(
        textX - margemX/2,
        textY - margemY/2,
        35,
        20
        );
    QGraphicsRectItem* fundo = scene->addRect(rectFundo, Qt::NoPen, QBrush(QColor(245, 245, 180, 200))); // amarelo claro, levemente translúcido

    fundo->setZValue(0);
    text->setZValue(1);
    text->setPos(textX, textY);

    QString valorStr = QString::number(no->numCasa); // ou use QString::fromStdString(...) se for string

    QGraphicsTextItem* valorText = scene->addText(valorStr);
    QFont valorFont = valorText->font();
    valorFont.setPointSize(12); // Pode ser maior para destaque
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

void telaArvore::ajustarVisualizacao() {
    QRectF rect = scene->itemsBoundingRect().adjusted(-20, -20, 20, 20);
    ui->graphicsViewArvore->fitInView(rect, Qt::KeepAspectRatio);
}

void telaArvore::mostrarArvore(noArvore* raiz) {
    scene->clear();

    int xInicial = 400;
    int yInicial = 30;
    int espacamentoInicial = 120;
    desenharArvore(raiz, xInicial, yInicial, espacamentoInicial);
    ajustarVisualizacao();
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
}

void telaArvore::on_addEx_clicked()
{
    arvore.inserirExemplos();
    scene->clear();
    mostrarArvore(arvore.getRaiz());
}


void telaArvore::on_btRemover_clicked()
{
    arvore.removerNo(arvore.getRaiz(), ui->lRemov->text().toInt());
    scene->clear();
    mostrarArvore(arvore.getRaiz());
}

