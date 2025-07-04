
// Modificaciones en mapa.h

#ifndef MAPA_H
#define MAPA_H

#include <QGraphicsScene>
#include "puntos.h"

class Mapa {
public:
    Mapa(QGraphicsScene *scene);
    void generarMapa();
    int (*getMapa())[19]; // devuelve puntero al arreglo de 19 columnas
    Puntos* getPuntos();


private:
    QGraphicsScene *scene;
    const int TILE_SIZE = 20;
    const int FILAS = 21;
    const int COLUMNAS = 19;

    int mapa[21][19] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,1,1,0,1},
        {1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
        {1,0,1,0,1,1,1,1,0,0,0,1,1,1,1,0,1,0,1},
        {1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
        {1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1},
        {1,1,1,1,0,1,1,1,0,0,0,1,1,1,0,1,1,1,1},
        {0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0},
        {1,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,1},
        {1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
        {1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1},
        {1,1,1,1,0,1,1,1,0,0,0,1,1,1,0,1,1,1,1},
        {1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
        {1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
        {1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,1,1,0,1},
        {1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    Puntos *puntos;
};
#endif

