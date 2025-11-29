#include <stdio.h>
#include "anteparo.h"

typedef struct {
    double x, y;
} ponto;

typedef struct {
    ponto p1;
    ponto p2;
    Geometria original;
} segmento;

Segmento transforma_anteparo (double x1, double y1, double x2, double y2, Geometria g) {
    segmento* s = (segmento*)malloc(sizeof(segmento));
    s->p1.x = x1;
    s->p1.y = y1;
    s->p2.x = x2;
    s->p2.y = y2;
    s->original = g;
    return s;
}