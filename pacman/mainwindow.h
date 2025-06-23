#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pacman.h"
#include <QGraphicsTextItem>
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
    QGraphicsTextItem* textoScore;
    int score;

};

#endif // MAINWINDOW_H
