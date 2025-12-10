#include <stdio.h>
#include <stdlib.h>
#include "poligono.h"
#include "geometria.h"

typedef struct {
    Ponto* pontos;
    int qtd_pontos;
    int capacidade;
} poligono;

Poligono cria_poligono() {
    poligono* p = (poligono*)malloc(sizeof(poligono));
    if (p == NULL) return NULL;
    
    p->capacidade = 100;
    p->qtd_pontos = 0;
    p->pontos = (Ponto*)malloc(p->capacidade * sizeof(Ponto));
    
    if (p->pontos == NULL) {
        printf("[ERRO] falha na tentativa de alocar memória de um ponto do polígono. \n");
        free(p);
        return NULL;
    }
    
    return (Poligono)p;
}

void insere_ponto_poligono(Poligono poly, Ponto ponto) {
    poligono* p = (poligono*)poly;
    if (p->qtd_pontos >= p->capacidade) {
        int nova_capacidade = p->capacidade * 2;
        Ponto* aux = (Ponto*)realloc(p->pontos, nova_capacidade * sizeof(Ponto));
        
        if (aux == NULL) {
            printf("[ERRO] Falha ao redimensionar polígono.\n");
            return;
        }
        
        p->pontos = aux;
        p->capacidade = nova_capacidade;
    }
    p->pontos[p->qtd_pontos] = ponto;
    p->qtd_pontos++;
}

Ponto get_ponto_poligono (Poligono poly, int i) {
    poligono* p = (poligono*)poly;
    return p->pontos[i];
}

int get_qtd_pontos_poligono(Poligono poly) {
    poligono* p = (poligono*)poly;
    return p->qtd_pontos;
}

void limites_poligono(Poligono poly) {
    poligono* p = (poligono*)poly;
    if (p->qtd_pontos == 0) return;

    double *x_min, *y_min, *x_max, *y_max;

    for (int i = 0; i < p->qtd_pontos; i++) {

        double px = get_x_ponto(p->pontos[i]); 
        double py = get_y_ponto(p->pontos[i]);

        if (px < *x_min) *x_min = px;
        if (px > *x_max) *x_max = px;
        if (py < *y_min) *y_min = py;
        if (py > *y_max) *y_max = py;
    }
}

bool esta_dentro_poligono (Poligono poly, double x, double y) {
    poligono* p = (poligono*) poly;
    if (p == NULL) return;
    int i, j;
    int qtd = get_qtd_pontos_poligono(p);
    for (int i = 0; i < qtd; i++) {

    }
}

bool esta_dentro_poligono(Poligono poly, double x, double y) {
    bool c = false;
    int i, j;
    int qtd = get_qtd_pontos_poly(poly);
    for (i = 0, j = qtd - 1; i < qtd; j = i++) {
        Ponto pi = get_ponto_poly(poly, i);
        Ponto pj = get_ponto_poly(poly, j);
        double xi = get_x_ponto(pi);
        double yi = get_y_ponto(pi);
        double xj = get_x_ponto(pj);
        double yj = get_y_ponto(pj);
        if ( ((yi > y) != (yj > y)) && (x < (xj - xi) * (y - yi) / (yj - yi) + xi) ) {
            c = !c;
        }
    }
    return c;
}


void libera_poligono(Poligono poly) {
    if (!poly) return;
    poligono* p = (poligono*)poly;
    for (int i = 0; i < p->qtd_pontos; i++) {
        free(p->pontos[i]); 
    }
    free(p->pontos);
    free(p);
}