#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    mapa = new Mapa(scene); // pasa la escena al mapa

    view->setScene(scene);
    setCentralWidget(view);
    setFixedSize(600, 600); // ajustar según el tamaño del mapa
    pacman = new PacMan(scene, mapa->getMapa(), 20);
    scene->addItem(pacman);
    pacman->setPos(1 * 20, 1 * 20); // posición inicial

}

MainWindow::~MainWindow() {
    delete mapa;
    delete scene;
    delete view;
}
