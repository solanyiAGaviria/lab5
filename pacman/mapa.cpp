// Modificaciones en mapa.cpp
#include "mapa.h"
#include <QBrush>
#include <QGraphicsRectItem>


Mapa::Mapa(QGraphicsScene *scene) : scene(scene) {
    puntos = new Puntos(scene, mapa, FILAS, COLUMNAS, TILE_SIZE);
    generarMapa();
    puntos->generarPuntos();
}

int (*Mapa::getMapa())[19] {
    return mapa;
}


void Mapa::generarMapa() {
    for (int y = 0; y < FILAS; ++y) {
        for (int x = 0; x < COLUMNAS; ++x) {
            QGraphicsRectItem *tile = new QGraphicsRectItem(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
            if (mapa[y][x] == 1) {
                tile->setBrush(QBrush(Qt::blue)); // pared
            } else {
                tile->setBrush(QBrush(Qt::black)); // camino
            }
            tile->setPen(Qt::NoPen);
            scene->addItem(tile);
        }
    }
}
