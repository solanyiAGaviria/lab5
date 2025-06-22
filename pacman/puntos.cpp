// puntos.cpp
#include "puntos.h"
#include <QBrush>

Puntos::Puntos(QGraphicsScene *scene, int mapa[21][19], int filas, int columnas, int tileSize)
    : scene(scene), mapa(mapa), FILAS(filas), COLUMNAS(columnas), TILE_SIZE(tileSize) {
    puntos.resize(FILAS, std::vector<QGraphicsEllipseItem*>(COLUMNAS, nullptr));
}

void Puntos::generarPuntos() {
    for (int y = 0; y < FILAS; ++y) {
        for (int x = 0; x < COLUMNAS; ++x) {
            if (mapa[y][x] == 0) { // Si es camino
                QGraphicsEllipseItem *punto = new QGraphicsEllipseItem(
                    x * TILE_SIZE + TILE_SIZE / 3,
                    y * TILE_SIZE + TILE_SIZE / 3,
                    TILE_SIZE / 3,
                    TILE_SIZE / 3);
                punto->setBrush(QBrush(Qt::white));
                punto->setPen(Qt::NoPen);
                scene->addItem(punto);
                puntos[y][x] = punto;
            }
        }
    }
}

void Puntos::eliminarPuntoEn(int x, int y) {
    if (x >= 0 && x < COLUMNAS && y >= 0 && y < FILAS && puntos[y][x]) {
        scene->removeItem(puntos[y][x]);
        delete puntos[y][x];
        puntos[y][x] = nullptr;
    }
}

