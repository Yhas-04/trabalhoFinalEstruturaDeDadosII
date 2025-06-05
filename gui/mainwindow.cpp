#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "telaarvore.h"
#include "../src/AGM.h"
#include "../src/Arvore.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include <cmath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lBOrigem->setFixedSize(20, 20);
    ui->lBOrigem->setStyleSheet("border-radius: 10px; background-color:#880808;");

    ui->lBDestino->setFixedSize(20, 20);
    ui->lBDestino->setStyleSheet("border-radius: 10px; background-color:#42a607;");

    ui->btAGM->setStyleSheet("background-color:#E2DFD2; color: black;");
    ui->btArvore->setStyleSheet("background-color:#F0EAD6; color: black;");
    ui->btHuffman->setStyleSheet("background-color:#F0EAD6; color: black;");
    ui->textEditResultado->setStyleSheet("background-color:#141c2d; color: white;");
    ui->lDestino->setStyleSheet("background-color:#141c2d; color: white;");
    ui->lOrigem->setStyleSheet("background-color:#141c2d; color: white;");
    ui->label->setStyleSheet("background-color:#141c2d; color: white;");
    ui->teAGM->setStyleSheet("background-color:#141c2d; color: white;");

    sceneGrafo = new QGraphicsScene(this);
    ui->graphicsViewMain->setScene(sceneGrafo);

    desenharGrafo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::desenharGrafo() {
    sceneGrafo->clear();

    QPixmap fundo("/media/yhas/hd_interno/Downloads/Picsart_25-06-03_18-29-17-213 (2).png");

    fundo = fundo.scaled(531, 321, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    sceneGrafo->setSceneRect(0, 0, fundo.width(), fundo.height());
    QGraphicsPixmapItem* fundoItem = sceneGrafo->addPixmap(fundo);
    fundoItem->setZValue(-1);
    fundoItem->setPos(0, 0);

    const QRectF sceneRect = sceneGrafo->sceneRect();
    QPointF center = sceneRect.center();
    int radius = std::min(sceneRect.width(), sceneRect.height()) / 2 - 50;

    const auto& casas = grafo.getCasas();
    const auto& arestas = grafo.getArestas();

    if (casas.empty()) {
        qDebug() << "Sem casas";
        return;
    }

    std::unordered_map<std::string, QPointF> posicoes;

    std::string raizNome;
    if (winArvore && winArvore->getArvore()) {
        noArvore* raizNo = winArvore->getArvore()->getRaiz();
        if (raizNo) {
            raizNome = raizNo->nome;
            posicoes[raizNome] = center;
        }

    std::vector<std::string> outrasCasas;
    for (const auto& casa : casas) {
        if (casa != raizNome) outrasCasas.push_back(casa);
    }

    int nodeCount = (int)outrasCasas.size();
    for (int i = 0; i < nodeCount; ++i) {
        double angle = (2 * M_PI * i) / nodeCount;
        double x = center.x() + radius * cos(angle);
        double y = center.y() + radius * sin(angle);
        posicoes[outrasCasas[i]] = QPointF(x, y);
    }

    for (const auto& a : arestas) {
        auto it1 = posicoes.find(a.casa1);
        auto it2 = posicoes.find(a.casa2);
        if (it1 == posicoes.end() || it2 == posicoes.end()) {
            qDebug() << "casa nao encontrada"
                     << QString::fromStdString(a.casa1) << QString::fromStdString(a.casa2);
            continue;
        }

        QPointF p1 = it1->second;
        QPointF p2 = it2->second;

        sceneGrafo->addLine(QLineF(p1, p2), QPen(Qt::black));

        QPointF meio = (p1 + p2) / 2;
        QString pesoStr = QString::number(a.peso);
        QGraphicsTextItem* pesoTexto = sceneGrafo->addText(pesoStr);
        pesoTexto->setPos(meio.x(), meio.y() - 10);
        pesoTexto->setDefaultTextColor(Qt::white);
        QFont fonte = pesoTexto->font();
        fonte.setPointSize(10);
        pesoTexto->setFont(fonte);
    }

    for (const auto& [nome, ponto] : posicoes) {
        sceneGrafo->addEllipse(ponto.x() - 10, ponto.y() - 10, 20, 20, QPen(Qt::black), QBrush(Qt::white));
        QGraphicsTextItem* textItem = sceneGrafo->addText(QString::fromStdString(nome));
        textItem->setPos(ponto.x() + 12, ponto.y() - 12);
    }

    posicoesNos = posicoes;
    ui->graphicsViewMain->centerOn(center);
    }
}

void MainWindow::on_btArvore_clicked()
{
    if (!winArvore) { winArvore = new telaArvore(nullptr); }

    connect(winArvore, &telaArvore::arvoreAtualizada, this, [this]() {
        grafo = Grafo(winArvore->getArvore());
        sceneGrafo->clear();
        desenharGrafo();
    });

    winArvore->show();
    winArvore->raise();
    winArvore->activateWindow();
}

void MainWindow::on_btHuffman_clicked()
{
    QString origemQt = ui->lOrigem->text();
    QString destinoQt = ui->lDestino->text();

    if (origemQt.isEmpty() || destinoQt.isEmpty()) {
        ui->textEditResultado->setPlainText("Informe a origem e o destino.");
        return;
    }

    std::string origem = origemQt.toStdString();
    std::string destino = destinoQt.toStdString();

    auto caminho = grafo.caminhoMinimo(origem, destino);

    if (caminho.empty()) {
        ui->textEditResultado->setPlainText("Caminho não encontrado.");
        return;
    }

    QString resultado = "<b>Caminho mínimo: </b>";
    for (const auto& casa : caminho) {
        resultado += QString::fromStdString(casa) + " &rarr; ";
    }
    resultado.chop(7);

    int custoTotal = 0;
    for (size_t i = 0; i + 1 < caminho.size(); ++i) {
        for (const auto& a : grafo.getArestas()) {
            if ((a.casa1 == caminho[i] && a.casa2 == caminho[i+1]) ||
                (a.casa2 == caminho[i] && a.casa1 == caminho[i+1])) {
                custoTotal += a.peso;
                break;
            }
        }
    }
    resultado += QString("<br><b>Custo total:</b> %1").arg(custoTotal);

    ui->textEditResultado->setHtml(resultado);

    for (const auto& [nome, ponto] : posicoesNos) {
        QColor cor = Qt::white;

        if (!caminho.empty()) {
            if (nome == caminho.front()) {
                cor = QColor("#D22B2B");
            } else if (nome == caminho.back()) {
                cor = QColor("#66b238");
            } else if (std::find(caminho.begin(), caminho.end(), nome) != caminho.end()) {
                cor = QColor(100, 180, 255);
            }
        }

        sceneGrafo->addEllipse(
            ponto.x() - 10, ponto.y() - 10, 20, 20,
            QPen(Qt::black), QBrush(cor)
            );

        QGraphicsTextItem* textItem = sceneGrafo->addText(QString::fromStdString(nome));
        textItem->setPos(ponto.x() + 12, ponto.y() - 12);
    }

}

void MainWindow::on_btAGM_clicked()
{
        auto agm = AGM::calcular(grafo);

        QString resultado = "<b>Árvore Geradora Mínima:</b><br>";
        int custoTotal = 0;

        for (const auto& a : agm) {
            resultado += QString::fromStdString(a.casa1) + " &harr; " + QString::fromStdString(a.casa2) +
                         QString(" (peso: %1)<br>").arg(a.peso);
            custoTotal += a.peso;
        }
        resultado += QString("<br><b>Custo total da AGM:</b> %1").arg(custoTotal);

        ui->teAGM->setHtml(resultado);
}

