#include "pacman.h"
#include <QPixmap>

PacMan::PacMan(QGraphicsScene* scene, int (*mapa)[19], Puntos* puntos, int tileSize)
    : QGraphicsPixmapItem(), scene(scene), mapa(mapa), puntos(puntos), TILE_SIZE(tileSize),
    direccion(3), frame(0) {

    spriteSheet.load(":/sprites/paccman.jpg");

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PacMan::mover);
    timer->start(150);
}

void PacMan::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_W) direccion = 0;
    else if (event->key() == Qt::Key_S) direccion = 1;
    else if (event->key() == Qt::Key_A) direccion = 2;
    else if (event->key() == Qt::Key_D) direccion = 3;
}

void PacMan::mover() {
    int dx = 0, dy = 0;
    switch (direccion) {
    case 0: dy = -TILE_SIZE; break;  // arriba
    case 1: dy = TILE_SIZE;  break;  // abajo
    case 2: dx = -TILE_SIZE; break;  // izquierda
    case 3: dx = TILE_SIZE;  break;  // derecha
    }

    int nuevaX = x() + dx;
    int nuevaY = y() + dy;

    int gridX = x() / TILE_SIZE;
    int gridY = y() / TILE_SIZE;

    const int filaTunel = 9;
    const int columnaIzquierda = 0;
    const int columnaDerecha = 18;

    // 💡 Si estamos en la fila del túnel y nos vamos por el lado izquierdo
    if (gridY == filaTunel && direccion == 2 && gridX == columnaIzquierda) {
        setPos(columnaDerecha * TILE_SIZE, filaTunel * TILE_SIZE);
    }
    // 💡 Si estamos en la fila del túnel y nos vamos por el lado derecho
    else if (gridY == filaTunel && direccion == 3 && gridX == columnaDerecha) {
        setPos(columnaIzquierda * TILE_SIZE, filaTunel * TILE_SIZE);
    }
    // Movimiento normal si no es túnel
    else if (puedeMoverse(dx, dy)) {
        setPos(nuevaX, nuevaY);
    } else {
        return;  // No se puede mover
    }

    // Animación y sprite
    frame = (frame + 1) % 3;
    actualizarSprite();

    // Eliminar punto si hay
    int newGridX = x() / TILE_SIZE;
    int newGridY = y() / TILE_SIZE;

    if (puntos->eliminarPuntoEn(newGridX, newGridY)) {
        emit puntoComido();
    }
}



bool PacMan::puedeMoverse(int dx, int dy) {
    int nuevaX = (x() + dx) / TILE_SIZE;
    int nuevaY = (y() + dy) / TILE_SIZE;

    if (nuevaX < 0 || nuevaX >= 19 || nuevaY < 0 || nuevaY >= 21)
        return false;

    return mapa[nuevaY][nuevaX] != 1;
}

void PacMan::actualizarSprite() {
    int xOffset = 0;
    int yOffset = 0;

    switch (direccion) {
    case 0: // arriba
        xOffset = frame * 32;
        yOffset = 0;
        break;

    case 1: // abajo
        xOffset = (3 + frame) * 32;
        yOffset = 0;
        break;

    case 2: // izquierda
        if (frame == 0)      { xOffset = 192;  yOffset = 0;  }
        else if (frame == 1) { xOffset = 224; yOffset = 0;  }
        else                 { xOffset = 0;   yOffset = 32; }
        break;

    case 3: // derecha
        if (frame == 0)      { xOffset = 32;  yOffset = 32; }
        else if (frame == 1) { xOffset = 64;  yOffset = 32; }
        else                 { xOffset = 98;  yOffset = 32; }
        break;
    }

    setPixmap(spriteSheet.copy(xOffset, yOffset, 32, 32).scaled(TILE_SIZE, TILE_SIZE));
}
