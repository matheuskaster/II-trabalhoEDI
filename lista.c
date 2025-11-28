#include "stdio.h"
#include "stdlib.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "geometria.h"
#include "lista.h"

typedef struct elemento {
    Geometria chave;
    struct elemento *prox;
} elemento;

typedef struct elemento* pont;

typedef struct {
    int tam;
    pont inicio;
    pont fim;
    pont percorre;
} lista;

Lista cria_lista () {
    lista* l = (lista*)malloc(sizeof(lista));
    if (l == NULL) {
        printf("[ERRO] não foi possível alocar memória para criar lista. \n");
        exit(1);
    }
    l->inicio = NULL;
    l->fim = NULL;
    l->percorre = NULL;
    l->tam = 0;
    return ((lista*)l);
}

void percorrer_do_inicio_lista (Lista l) {
    ((lista*)l)->percorre = ((lista*)l)->inicio;
}

bool tem_proximo_lista (Lista l) {
    if (((lista*)l)->percorre != NULL) return true;
    else return false;
}

Geometria get_proximo_lista (Lista l) {
    if (((lista*)l)->percorre == NULL) {
        printf("[ERRO] Não tem um próximo elemento. \n");
        exit(1);
    }
    Geometria proximo = ((lista*)l)->percorre->chave;
    ((lista*)l)->percorre = ((lista*)l)->percorre->prox;
    return proximo;
}

int tam_lista (Lista l) {
    return ((lista*)l)->tam;
}

void insere_lista (Lista l, Geometria g) {
    elemento* novo = (elemento*)malloc(sizeof(elemento));
    if (novo == NULL) {
        printf("[ERRO] não foi possível alocar memória para inserir um novo elemento na lista. \n");
        exit(1);
    }
    novo->chave = g;
    novo->prox = NULL;

    if (((lista*)l)->inicio == NULL) {
            ((lista*)l)->inicio = novo;
    } else {
        ((lista*)l)->fim->prox = novo;
    }
    
    ((lista*)l)->fim = novo;
    ((lista*)l)->tam++;
}

Geometria remove_lista (Lista l) {
    if (((lista*)l)->inicio == NULL) {
        printf("Tentativa falha de pegar um elemento da lista. \n");
        exit (1);
    }
    pont ant = NULL;
    pont atual = ((lista*)l)->inicio;

//    while (atual != NULL && atual->chave != g) {
//        ant = atual;
//        atual = atual->prox;
//    }

    if (atual == NULL) {
        printf("Não foi possível encontrar o elemento desejado da lista. \n");
        return;
    }

    if (ant == NULL) ((lista*)l)->inicio = atual->prox;
//    else ant->prox = atual->prox;
    Geometria chave = atual->chave;
    free(atual);
    ((lista*)l)->tam--;
    return chave;
}

Lista clona_lista (Lista l) {
    lista* clone = cria_lista();

    pont atual = ((lista*)l)->inicio;
    while (atual != NULL) {
        insere_lista (clone, atual->chave);
        atual = atual->prox;
    }
    return clone;
}

void libera_lista (Lista l) {
    if (l ==  NULL) {
        printf("Falha na tentativa de liberar uma lista, pois esta, é nula. \n");
        return;
    }
    pont atual = ((lista*)l)->inicio;
    while (atual != NULL) {
        pont proximo = ((pont)atual)->prox;

        if (atual->chave != NULL) {
            libera_forma (atual->chave);
        }
        free (atual);
        atual = proximo;
    }
    free (l);
}
