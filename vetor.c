#include <stdio.h>
#include "vetor.h"

typedef struct {
    Segmento* anteparos;
    int qtd;
    int cap;
} vetor;

Vetor cria_vet () {
    vetor* v = (vetor*)malloc(sizeof(vetor));
    if (v == NULL) {
        printf("Erro na tentativa de alocar memória para a estrutura.\n");
        exit(1);
    }
    v->anteparos = (Segmento*)malloc(sizeof(Segmento) * 10);
    v->qtd = 0;
    v->cap = 10;
    return v;
}

void insere_vet (Vetor vet, Segmento s) {
    vetor* v = (vetor*) vet;

    if (v->qtd == v->cap) {
        v->cap *= 2;
        v->anteparos = (Segmento*)realloc(v->anteparos, sizeof(Segmento) * v->cap);
    }

    v->anteparos[v->qtd] = s;
    v->qtd++;
}

Segmento busca_vet (Vetor vet, int id) {
    vetor* v = (vetor*) vet;
    Segmento s;
    for (int i = 0; i < v->qtd; i++) {
        s = v->anteparos[i];
        if (get_id_segmento(s) == id) return s;
    }
    printf("Não existe um anteparo com o id solicitado. \n");
    exit(1);
}

Segmento get_segmento_qualquer (Vetor vet, int posicao) {
    return ((vetor*)vet)->anteparos[posicao];
}

int get_qtd_vet (Vetor vet) {
    return ((vetor*)vet)->qtd;
}

void libera_vet (Vetor vet) {
    if (vet == NULL) return;
    vetor* v = (vetor*) vet;
    Segmento s; 
    for (int i = 0 ; i < v->qtd; i++) libera_memoria_segmento(v->anteparos[i]);
    free(v->anteparos);
    free(v);
}