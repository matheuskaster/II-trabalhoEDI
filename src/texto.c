#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"
#include "texto.h"

typedef struct {
    char *family;
    char *weight;
    char *size;
} estilo;

typedef struct {
    int id;
    double x, y;
    char* corb;
    char* corp;
    char a;
    char* txto;
    Estilo ts;
} texto;

Estilo cria_estilo (char* family, char* weight, char* size) {
    estilo *ts = (estilo*) malloc (sizeof(estilo));
    ts->family = (char*) malloc (strlen(family) + 1);
    if (ts->family == NULL) {
        printf ("Erro na alocação de memória ao criar a família");
        exit(1);
    }
    strcpy (ts->family, family);

    ts->weight = (char*) malloc (strlen(weight) + 1);
    if (ts->weight == NULL) {
        printf ("Erro na alocação de memória ao criar a expessura");
        exit(1);
    }
    strcpy (ts->weight, weight);

    ts->size = (char*) malloc (strlen(size) + 1);
    if (ts->size == NULL) {
        printf ("Erro na alocação de memória ao criar a tamanho");
        exit(1);
    }
    strcpy (ts->size, size);
    return ((estilo*)ts);
}

void set_family_estilo (Estilo ts, char *family) {
    strcpy (((estilo*)ts)->family, family);
}

char* get_family_estilo (Estilo ts) {
    return ((estilo*)ts)->family;
}

void set_weight_estilo (Estilo ts, char *weight) {
    strcpy (((estilo*)ts)->weight, weight);
}

char* get_weight_estilo(Estilo ts) {
    return ((estilo*)ts)->weight;
}

void set_size_estilo(Estilo ts, char *size) {
    strcpy (((estilo*)ts)->size, size);
}

char* get_size_estilo(Estilo ts) {
    return ((estilo*)ts)->size;
}

Texto cria_texto (int id, double x, double y, char* corb, char* corp, char a, char* txto, Estilo ts) {
    texto *t = (texto*) malloc (sizeof(texto));
    t->id = id;
    t->x = x;
    t->y = y;
    t->corb = (char*) malloc (strlen(corb)+1);
    if (t->corb == NULL) {
        printf("Erro na alocação de memória ao criar a cor de borda");
        exit(1);
    }
    strcpy(t->corb, corb);

    t->corp = (char*) malloc (strlen(corp)+1);
    if (t->corp == NULL) {
        printf("Erro na alocação de memória ao criar a cor de preenchimento");
        exit(1);
    }
    strcpy(t->corp, corp);

    t->a = a;
    
    t->txto = (char*) malloc (strlen(txto)+1);
    if (t->txto == NULL) {
        printf("Erro na alocação de memória ao criar o texto");
        exit(1);
    }
    strcpy(t->txto, txto);

    t->ts = cria_estilo(((estilo*)ts)->family, ((estilo*)ts)->weight, ((estilo*)ts)->size);

    return ((texto*)t);
}
void set_id_texto (Texto t, int id) {
    ((texto*)t)->id = id;
}

int get_id_texto (Texto t) {
    return ((texto*)t)->id;
}

void set_x_texto (Texto t, double x) {
    ((texto*)t)->x = x;
}

double get_x_texto (Texto t) {
    return ((texto*)t)->x;
}

void set_y_texto (Texto t, double y) {
    ((texto*)t)->y = y;
}

double get_y_texto (Texto t) {
    return ((texto*)t)->y;
}

void set_corb_texto (Texto t, char* corb) {
    strcpy (((texto*)t)->corb, corb);
}

char* get_corb_texto (Texto t) {
    return ((texto*)t)->corb;
}

void set_corp_texto (Texto t, char* corp) {
    strcpy (((texto*)t)->corp, corp);
}

char* get_corp_texto (Texto t) {
    return ((texto*)t)->corp;
}

void set_a_texto (Texto t, char a) {
    ((texto*)t)->a = a;
}

char get_a_texto (Texto t) {
    return ((texto*)t)->a;
}

void set_txto (Texto t, char *txto) {
    strcpy (((texto*)t)->txto, txto);
}

char* get_txto (Texto t) {
    return ((texto*)t)->txto;
}

void set_estilo_texto (Texto t, Estilo ts) {
    ((texto*)t)->ts = ts;
}

Estilo get_estilo_texto (Texto t) {
    return ((texto*)t)->ts;
}

void transforma_texto_em_linha (Texto t, double *x1, double *y1, double *x2, double *y2) {
    char a = get_a_texto(t);
    char* txto = get_txto(t);
    
    double comp = strlen(txto) * 10.0;
    
    double x = get_x_texto(t);
    double y = get_y_texto(t) + 7.5; 

    *y1 = y;
    *y2 = y;

    if (a == 'i') {
        *x1 = x;
        *x2 = x + comp;
    } else if (a == 'm') {
        *x1 = x - (comp / 2.0);
        *x2 = x + (comp / 2.0);
    } else if (a == 'f') {
        *x1 = x - comp;
        *x2 = x;
    }
}

double calcula_area_texto (Texto t) {
    char* txto = get_txto(t);
    return 20 * strlen(txto);
}

void libera_estilo (Estilo e) {
    free(((estilo*)e)->family);
    free(((estilo*)e)->weight);
    free(((estilo*)e)->size);
    free((estilo*)e);
}

void libera_texto (Texto t) {
    if (t == NULL) return;
    texto* _t = (texto*) t;
    if (_t->corb) free(_t->corb);
    if (_t->corp) free(_t->corp);
    if (_t->txto) free(_t->txto);
    /* libera o estilo associado ao texto (criado/copied em cria_texto) */
    if (_t->ts) libera_estilo(_t->ts);
    free(_t);
}