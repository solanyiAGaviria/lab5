#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>

class PacMan : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    PacMan(QGraphicsScene* scene, int (*mapa)[19], int tileSize);
    void keyPressEvent(QKeyEvent *event);


private slots:
    void mover();

private:
    QPixmap spriteSheet;
    QGraphicsScene* scene;
    int (*mapa)[19];
    int TILE_SIZE;


    int direccion; // 0: arriba, 1: abajo, 2: izquierda, 3: derecha
    int frame;     // 0, 1, 2 para animación

    QTimer* timer;

    void actualizarSprite();
    bool puedeMoverse(int dx, int dy);
};

#endif // PACMAN_H
