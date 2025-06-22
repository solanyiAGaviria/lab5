#include "pacman.h"
#include <QPixmap>


PacMan::PacMan(QGraphicsScene* scene, int (*mapa)[19], int tileSize)
    : QGraphicsPixmapItem(), scene(scene), mapa(mapa), TILE_SIZE(tileSize),
    direccion(3), frame(0) {

    spriteSheet.load(":/sprites/paccman.jpg"); // asegúrate de que esté en los recursos

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
    case 0: dy = -TILE_SIZE; break;
    case 1: dy = TILE_SIZE;  break;
    case 2: dx = -TILE_SIZE; break;
    case 3: dx = TILE_SIZE;  break;
    }

    if (puedeMoverse(dx, dy)) {
        setPos(x() + dx, y() + dy);
        frame = (frame + 1) % 3;
        actualizarSprite();
    }
}

bool PacMan::puedeMoverse(int dx, int dy) {
    int nuevaX = (x() + dx) / TILE_SIZE;
    int nuevaY = (y() + dy) / TILE_SIZE;

    if (nuevaX < 0 || nuevaX >= 19 || nuevaY < 0 || nuevaY >= 21)
        return false;

    return mapa[nuevaY][nuevaX] != 1;
}

/*void PacMan::actualizarSprite() { //sprite bueno, pero aparece el fantasma a la derecha
    int xOffset = 0;
    int yOffset = 0;

    switch (direccion) {
    case 0: xOffset = frame * 32; yOffset = 0; break; // arriba
    case 1: xOffset = (3 + frame) * 32; yOffset = 0; break; // abajo
    case 2:
        if (frame < 2) xOffset = (6 + frame) * 32, yOffset = 0;
        else xOffset = 0, yOffset = 32;
        break;
    case 3: xOffset = (3 + frame) * 32; yOffset = 32; break; // derecha
    }

    setPixmap(spriteSheet.copy(xOffset, yOffset, 32, 32).scaled(TILE_SIZE, TILE_SIZE));
}*/

/*void PacMan::actualizarSprite() { //sprite bueno, pero aparece el fantasma a la derecha
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
        if (frame < 2)
            xOffset = (6 + frame) * 32, yOffset = 0;
        else
            xOffset = 0, yOffset = 32; // boca cerrada mirando izquierda
        break;
    case 3: // ✅ derecha (corregido)
        if (frame == 0) xOffset = 96;
        else if (frame == 1) xOffset = 128;
        else xOffset = 160;
        yOffset = 32;
        break;
    }

    setPixmap(spriteSheet.copy(xOffset, yOffset, 32, 32).scaled(TILE_SIZE, TILE_SIZE));
}*/

/*void PacMan::actualizarSprite() { solo funciona hacia arriba y hacia abjo
    int xOffset = 0;
    int yOffset = 0;

    switch (direccion) {
    case 0: // arriba
        xOffset = frame * 32;      // sprites 0,1,2
        yOffset = 0;
        break;

    case 1: // abajo
        xOffset = (3 + frame) * 32;  // sprites 3,4,5
        yOffset = 0;
        break;

    case 2: // izquierda
        if (frame == 0) { xOffset = 96; yOffset = 0; }      // medio abierta
        else if (frame == 1) { xOffset = 112; yOffset = 0; } // completamente abierta
        else { xOffset = 0; yOffset = 16; }                  // cerrada
        break;

    case 3: // derecha
        if (frame == 0) { xOffset = 80; yOffset = 16; }     // medio abierta
        else if (frame == 1) { xOffset = 96; yOffset = 16; } // completamente abierta
        else { xOffset = 112; yOffset = 16; }                // cerrada
        break;
    }

    setPixmap(spriteSheet.copy(xOffset, yOffset, 32, 32).scaled(TILE_SIZE, TILE_SIZE )); // ← ahora bien escalado
}*/
void PacMan::actualizarSprite() {
    int xOffset = 0;
    int yOffset = 0;

    switch (direccion) {
    case 0: // arriba
        xOffset = frame * 32;       // 0, 16, 32
        yOffset = 0;
        break;

    case 1: // abajo
        xOffset = (3 + frame) * 32; // 48, 64, 80
        yOffset = 0;
        break;

    case 2: // izquierda
        if (frame == 0)      { xOffset = 192;  yOffset = 0;  } // medio abierta (fila 1)
        else if (frame == 1) { xOffset = 224; yOffset = 0;  } // muy abierta   (fila 1)
        else                { xOffset = 0;   yOffset = 32; } // cerrada       (fila 2)
        break;

    case 3: // derecha
        if (frame == 0)      { xOffset = 32;  yOffset = 32; } // medio abierta (fila 2)
        else if (frame == 1) { xOffset = 64;  yOffset = 32; } // muy abierta   (fila 2)
        else                { xOffset = 98; yOffset = 32; } // cerrada       (fila 2)
        break;
    }

    // Se ajusta al tamaño visible del mapa (usualmente 32x32)
    setPixmap(spriteSheet.copy(xOffset, yOffset, 32, 32).scaled(TILE_SIZE, TILE_SIZE));
}
