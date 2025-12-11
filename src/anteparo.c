#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

Ponto transforma_ponto(double x, double y) {
    ponto* p = (ponto*) malloc(sizeof(ponto));
    if (p == NULL) {
        printf("Erro de memoria em transforma_ponto. \n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
}

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

int get_id_segmento (Segmento s) {
    return (((segmento*)s)->id);
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

void set_cor_segmento (Segmento seg, char* cor) {
    segmento* s = (segmento*) seg;
    if (s->cor != NULL) {
        free(s->cor);
    }
    s->cor = (char*) malloc(strlen(cor) + 1);
    strcpy(s->cor, cor);
}

Segmento clona_segmento (Segmento seg, double dx, double dy, int id) {
    segmento* s = (segmento*) seg;

    return transforma_anteparo(id, s->p1.x + dx, s->p1.y + dy, s->p2.x + dx, s->p2.y + dy, s->tipo, s->cor, s->original);
}

void libera_segmento (Segmento seg) {
    segmento* s = (segmento*) seg;
    if (s == NULL) return;
    free(s->cor);
    free(s);
}