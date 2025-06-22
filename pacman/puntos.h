// puntos.h
#ifndef PUNTOS_H
#define PUNTOS_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <vector>

class Puntos {
public:
    Puntos(QGraphicsScene *scene, int mapa[21][19], int filas, int columnas, int tileSize);
    void generarPuntos();
    void eliminarPuntoEn(int x, int y);

private:
    QGraphicsScene *scene;
    std::vector<std::vector<QGraphicsEllipseItem*>> puntos;
    int (*mapa)[19];
    int FILAS;
    int COLUMNAS;
    int TILE_SIZE;
};

#endif // PUNTOS_H
