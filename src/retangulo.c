#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "retangulo.h"

typedef struct retangulo {
    int id;
    double x, y, w, h;
    char *corb, *corp;
} retangulo;


Retangulo cria_retangulo (int id, double x, double y, double w, double h, char *corb, char *corp) {
    retangulo *r = malloc(sizeof(retangulo));
    r->id = id;
    r->x = x;
    r->y = y;
    r->w = w;
    r->h = h;
    r->corb = (char*) malloc (strlen(corb)+1);
    if (r->corb == NULL) {
        printf("Erro na alocação de memória para a cor de borda do retangulo %d.", r->id);
        exit(1);
    }
    strcpy(r->corb, corb);
    r->corp = (char*) malloc (strlen(corp)+1);
    if (r->corp == NULL) {
        printf("Erro na alocação de memória para a cor de preenchimento do retangulo %d.", r->id);
        exit(1);
    }
    strcpy(r->corp, corp);
    return ((retangulo*) r);
}

void set_id_retangulo (Retangulo r, int id) {
    ((retangulo*)r)->id = id;
}

int get_id_retangulo (Retangulo r) {
    return ((retangulo*)r)->id;
}

void set_x_retangulo (Retangulo r, double x) {
    ((retangulo*)r)->x = x;
}

double get_x_retangulo (Retangulo r) {
    return ((retangulo*)r)->x;
}

void set_y_retangulo (Retangulo r, double y) {
    ((retangulo*)r)->y = y;
}

double get_y_retangulo (Retangulo r) {
    return ((retangulo*)r)->y;
}

void set_w_retangulo (Retangulo r, double w) {
    ((retangulo*)r)->w = w;
}

double get_w_retangulo (Retangulo r) {
    return ((retangulo*)r)->w;
}

void set_h_retangulo (Retangulo r, double h) {
    ((retangulo*)r)->h = h;
}

double get_h_retangulo (Retangulo r) {
    return ((retangulo*)r)->h;
}

void set_corp_retangulo (Retangulo r, char* corp) {
    strcpy (((retangulo*)r)->corp, corp);
}

char* get_corp_retangulo (Retangulo r) {
    return ((retangulo*)r)->corp;
}

void set_corb_retangulo (Retangulo r, char* corb) {
    strcpy (((retangulo*)r)->corb, corb);
}

char* get_corb_retangulo (Retangulo r) {
    return ((retangulo*)r)->corb;
}

double calcula_area_retangulo (Retangulo r) {
    return (((retangulo*)r)->w) * (((retangulo*)r)->h);
}

void libera_retangulo (Retangulo r) {
    free(((retangulo*)r)->corb);
    free(((retangulo*)r)->corp);
    free((retangulo*)r);
}