#include "circulo.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

typedef struct circulo {
    int id;
    double x, y, r;
    char *corb, *corp;
} circulo;

Circulo cria_circulo (int id, double x, double y, double r, char *corb, char *corp) {
    circulo *c = (circulo*) malloc (sizeof(circulo));
    c->id = id;
    c->x = x;
    c->y = y;
    c->r = r;
    c->corb = (char*) malloc(strlen(corb)+1);
    if (c->corb == NULL) {
        printf("Erro na alocação de memória para a cor de borda do circulo %d.", c->id);
        exit(1);
    }
    strcpy(c->corb, corb);
    c->corp = (char*)malloc (strlen(corp)+1);
    if (c->corp == NULL) {
        printf("Erro na alocação de memória para a cor de preenchimento do circulo %d.", c->id);
        exit(1);
    }
    strcpy(c->corp, corp);

    return ((circulo*)c);
}

void set_id_circulo (Circulo c, int id) {
    ((circulo*)c)->id = id;
}

int get_id_circulo (Circulo c) {
    return ((circulo*)c)->id;
}

void set_x_circulo (Circulo c, double x) {
    ((circulo*)c)->x = x;
}

double get_x_circulo (Circulo c) {
    return ((circulo*)c)->x;
}

void set_y_circulo (Circulo c, double y) {
    ((circulo*)c)->y = y;
}

double get_y_circulo (Circulo c) {
    return ((circulo*)c)->y;
}

void set_r_circulo (Circulo c, double r) {
    ((circulo*)c)->r = r;
}

double get_r_circulo (Circulo c) {
    return ((circulo*)c)->r;
}

void set_corb_circulo (Circulo c, char* corb) {
    strcpy (((circulo*)c)->corb, corb);
}

char* get_corb_circulo (Circulo c) {
    return ((circulo*)c)->corb;
}

void set_corp_circulo (Circulo c, char* corp) {
    strcpy (((circulo*)c)->corp, corp);
}

char* get_corp_circulo (Circulo c) {
    return ((circulo*)c)->corp;
}

double calcula_area_circulo (Circulo c) {
    return PI* pow(((circulo*)c)->r, 2);
}

void libera_circulo (Circulo c){
    free(((circulo*)c)->corb);
    free(((circulo*)c)->corp);
    free((circulo*)c);
}