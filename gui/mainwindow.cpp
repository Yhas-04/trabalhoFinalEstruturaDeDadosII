#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "telaarvore.h"
#include "../src/Huffman.h"
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

    ui->setupUi(this);  // <-- inicializa baseado na árvore vazia


    connect(ui->btHuffman, &QPushButton::clicked, [this]() {
        std::unordered_map<std::string, int> freq;

        for (const auto& nomeCasa : grafo.getCasas()) {
            freq[nomeCasa]++;  // ou usar algum critério de peso
        }

        Huffman huff;
        auto codigos = huff.construir(freq);

        for (const auto& [simbolo, codigo] : codigos) {
            qDebug() << "Casa:" << QString::fromStdString(simbolo)
            << "Código Huffman:" << QString::fromStdString(codigo);
        }
    });

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

    QPixmap fundo("/media/yhas/hd_interno/Images/SaveClip.App_323829564_567680148167915_6061575412047587523_n.jpg");
    fundo = fundo.scaled(531, 321, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    sceneGrafo->setSceneRect(0, 0, fundo.width(), fundo.height());
    QGraphicsPixmapItem* fundoItem = sceneGrafo->addPixmap(fundo);
    fundoItem->setZValue(-1);
    fundoItem->setPos(0, 0);
    sceneGrafo->setSceneRect(0, 0, fundo.width(), fundo.height());

    // Centro baseado na cena
    const QRectF sceneRect = sceneGrafo->sceneRect();
    QPointF center = sceneRect.center();

    // Raio menor para caber dentro da cena
    int radius = std::min(sceneRect.width(), sceneRect.height()) / 2 - 50;

    const auto& casas = grafo.getCasas();
    const auto& arestas = grafo.getArestas();

    std::unordered_map<std::string, QPointF> posicoes;
    int nodeCount = casas.size();

    // Distribui os nós circularmente em torno do centro da cena
    for (int i = 0; i < nodeCount; ++i) {
        double angle = (2 * M_PI * i) / nodeCount;
        double x = center.x() + radius * cos(angle);
        double y = center.y() + radius * sin(angle);
        posicoes[casas[i]] = QPointF(x, y);
    }

    for (const auto& a : arestas) {
        QPointF p1 = posicoes[a.casa1];
        QPointF p2 = posicoes[a.casa2];
        sceneGrafo->addLine(QLineF(p1, p2), QPen(Qt::black));

        QPointF meio = (p1 + p2) / 2;

        // cria texto com o peso
        QString pesoStr = QString::number(a.peso);

        // cria o item texto para mostrar peso
        QGraphicsTextItem* pesoTexto = sceneGrafo->addText(pesoStr);

        // desloca o texto um pouco para cima (exemplo: 0, -10)
        pesoTexto->setPos(meio.x(), meio.y() - 10);

        // opcional: ajustar cor, fonte
        pesoTexto->setDefaultTextColor(Qt::blue);
        QFont fonte = pesoTexto->font();
        fonte.setPointSize(10);
        pesoTexto->setFont(fonte);
    }

    // Desenha os nós (círculos e texto)
    for (const auto& [nome, ponto] : posicoes) {
        sceneGrafo->addEllipse(ponto.x() - 10, ponto.y() - 10, 20, 20, QPen(Qt::black), QBrush(Qt::yellow));
        QGraphicsTextItem* textItem = sceneGrafo->addText(QString::fromStdString(nome));
        textItem->setPos(ponto.x() + 12, ponto.y() - 12);
    }

    // Centraliza a visão no centro da cena
    ui->graphicsViewMain->centerOn(center);

    // Ajusta a escala para caber tudo (opcional)
    ui->graphicsViewMain->fitInView(sceneGrafo->sceneRect(), Qt::KeepAspectRatio);
}


void MainWindow::on_btArvore_clicked()
{

    if (!winArvore) { winArvore = new telaArvore(nullptr); }

    connect(winArvore, &telaArvore::arvoreAtualizada, this, [this]() {  // <- atualiza grafo com árvore modificada
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

    QString resultado = "<b>Caminho mínimo:</b><br>";
    for (const auto& casa : caminho) {
        resultado += QString::fromStdString(casa) + " &rarr; ";
    }
    resultado.chop(7); // Remove a última seta " → "

    // Opcional: calcular custo total
    int custoTotal = 0;
    for (size_t i = 0; i + 1 < caminho.size(); ++i) {
        for (const auto& a : grafo.getArestas()) {
            if ((a.casa1 == caminho[i] && a.casa2 == caminho[i+1]) || (a.casa2 == caminho[i] && a.casa1 == caminho[i+1])) {
                custoTotal += a.peso;
                break;
            }
        }
    }
    resultado += QString("<br><b>Custo total:</b> %1").arg(custoTotal);

    ui->textEditResultado->setHtml(resultado);

    std::unordered_map<std::string, int> freq;

    for (const auto& nomeCasa : grafo.getCasas()) {
        freq[nomeCasa]++;
    }

    Huffman huff;
    auto codigos = huff.construir(freq);

    // Limpa o texto antigo
    ui->textBrowserCodificacao->clear();

    // Formata e insere os códigos no QTextBrowser
    for (const auto& [simbolo, codigo] : codigos) {
        QString linha = QString("Casa: <b>%1</b> - Código Huffman: <span style='color:blue;'>%2</span><br>")
                            .arg(QString::fromStdString(simbolo))
                            .arg(QString::fromStdString(codigo));
        ui->textBrowserCodificacao->insertHtml(linha);
    }
}

