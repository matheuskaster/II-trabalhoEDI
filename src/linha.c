#include "linha.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stdbool.h"

typedef struct linha {
    int id;
    double x1, y1, x2, y2;
    char *cor;
} linha;

Linha cria_linha (int id, double x1, double y1, double x2, double y2, char *cor) {
    linha* l = (linha*)malloc(sizeof(linha));
    l->id = id;
    l->x1 = x1;
    l->y1 = y1;
    l->x2 = x2;
    l->y2 = y2;
    l->cor = (char*) malloc(strlen(cor)+1);
    if (l->cor == NULL) {
        printf("Erro na alocação de memória para a cor da linha %d.", l->id);
        exit(1);
    }
    strcpy(l->cor, cor);
    return ((linha*)l);
}

void set_id_linha (Linha l, int id) {
    ((linha*)l)->id = id;
}

int get_id_linha (Linha l) {
    return ((linha*)l)->id;
}

void set_x1_linha (Linha l, double x1) {
    ((linha*)l)->x1 = x1;
}

double get_x1_linha (Linha l) {
    return ((linha*)l)->x1;
}

void set_y1_linha (Linha l, double y1) {
    ((linha*)l)->y1 = y1;
}

double get_y1_linha (Linha l) {
    return ((linha*)l)->y1;
}

void set_x2_linha (Linha l, double x2) {
    ((linha*)l)->x2 = x2;
}

double get_x2_linha (Linha l) {
    return ((linha*)l)->x2;
}

void set_y2_linha (Linha l, double y2) {
    ((linha*)l)->y2 = y2;
}

double get_y2_linha (Linha l) {
    return ((linha*)l)->y2;
}

void set_cor_linha (Linha l, char* cor) {
    strcpy(((linha*)l)->cor, cor);
}

char* get_cor_linha (Linha l) {
    return ((linha*)l)->cor;
}

double calcula_area_linha (Linha l) {
    return 10 * sqrt( pow( ((linha*)l)->y2 - ((linha*)l)->y1, 2) + pow( ((linha*)l)->x2 - ((linha*)l)->x1, 2));
}

double calcula_variacao_x_linha (Linha l) {
    double x1 = get_x1_linha(l);
    double x2 = get_x2_linha(l);
    return (x2 - x1);
}

double calcula_variacao_y_linha (Linha l) {
    double y1 = get_y1_linha(l);
    double y2 = get_y2_linha(l);
    return (y2 - y1);
}

void libera_linha (Linha l) {
    free(((linha*)l)->cor);
    free((linha*)l);
}