#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    mapa = new Mapa(scene); // pasa la escena al mapa

    view->setScene(scene);
    setCentralWidget(view);
    setFixedSize(600, 600); // ajustar según el tamaño del mapa

    pacman = new PacMan(scene, mapa->getMapa(), mapa->getPuntos(), 20);
    scene->addItem(pacman);
    pacman->setPos(1 * 20, 1 * 20); // posición inicial
    score = 0;
    textoScore = new QGraphicsTextItem("Score: 0");
    textoScore->setDefaultTextColor(Qt::black);
    textoScore->setFont(QFont("Georgia", 16));
    textoScore->setPos(10, 600 - 30);  // Ajusta posición según necesidad
    scene->addItem(textoScore);
    connect(pacman, &PacMan::puntoComido, this, [=]() {
        score += 10;
        textoScore->setPlainText("Score: " + QString::number(score));
    });

}

MainWindow::~MainWindow() {
    delete mapa;
    delete scene;
    delete view;
}



