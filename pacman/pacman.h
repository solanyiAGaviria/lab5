#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QPixmap>
#include "puntos.h"  // Para acceder a los puntos

class PacMan : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    PacMan(QGraphicsScene* scene, int (*mapa)[19], Puntos* puntos, int tileSize);
    void keyPressEvent(QKeyEvent *event);

signals:
    void puntoComido();  // ← Señal emitida cuando se come un punto

private slots:
    void mover();

private:
    QGraphicsScene* scene;
    int (*mapa)[19];
    Puntos* puntos;
    const int TILE_SIZE;
    int direccion;
    int frame;
    QTimer* timer;
    QPixmap spriteSheet;

    bool puedeMoverse(int dx, int dy);
    void actualizarSprite();
};

#endif
