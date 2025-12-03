#include <stdio.h>
#include "anteparo.h"

typedef struct {
    double x, y;
} ponto;

typedef struct {
    int id;
    ponto p1;
    ponto p2;
    char tipo;
    char* cor; 
    Geometria original;
} segmento;

Segmento transforma_anteparo (int id, double x1, double y1, double x2, double y2, char tipo, char* cor, Geometria g) {
    segmento* s = (segmento*)malloc(sizeof(segmento));
    s->id = id;
    s->p1.x = x1;
    s->p1.y = y1;
    s->p2.x = x2;
    s->p2.y = y2;
    s->tipo = tipo;
    s->cor = (char*) malloc(strlen(cor)+1);
    if (s->cor == NULL) {
        printf("Erro na alocação de memória da cor do segmento %d.\n", s->id);
        exit(1);
    }
    strcpy(s->cor, cor);
    s->original = g;
    return s;
}

double get_x_ponto (Ponto p) {
    return (((ponto*)p)->x);
}

double get_y_ponto (Ponto p) {
    return (((ponto*)p)->y);
}

double get_x_p1 (Segmento s) {
    return (((segmento*)s)->p1.x);
}

double get_x_p2 (Segmento s) {
    return (((segmento*)s)->p2.x);
}

double get_y_p1 (Segmento s) {
    return (((segmento*)s)->p1.y);
}

double get_y_p2 (Segmento s) {
    return (((segmento*)s)->p2.y);
}