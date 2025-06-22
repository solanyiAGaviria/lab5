#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pacman.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "mapa.h"



    class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    PacMan* pacman;
    QGraphicsView *view;
    QGraphicsScene *scene;
    Mapa *mapa;
};

#endif // MAINWINDOW_H
