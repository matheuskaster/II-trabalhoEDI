#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvore.h"
#include "sobreposicao.h"

typedef struct elemento {
    Segmento chave;
    struct elemento* esq;
    struct elemento* dir;
} elemento;

typedef struct elemento* pont;

typedef struct {
    pont raiz;
} arvore;


Segmento segmento_mais_proximo (Arvore segmentos_ativos) {
    arvore* a = (arvore*)segmentos_ativos;
    pont raiz = a->raiz;
    if (raiz == NULL) return NULL;
    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz->chave;
}

Arvore cria_arvore () {
    arvore* a = (arvore*)malloc(sizeof(arvore));
    if (a == NULL) {
        printf("[ERRO] não foi possível alocar memória para criar lista. \n");
        exit(1);
    }
    a->raiz = NULL;
    return a;
}


pont insere_recursivo (pont raiz, Segmento s) {
    if (raiz == NULL) {
        elemento* novo = (elemento*)malloc(sizeof(elemento));
        if (novo == NULL) {
            printf("[ERRO] não foi possível alocar memória para inserir um novo elemento na árvore. \n");
            exit(1);
        }
        novo->chave = s;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    
    double d = lado_ponto_relacao_segmento(raiz->chave, s);
    if (d == 0)
        d = lado_ponto_relacao_segmento2(raiz->chave, s);
    
    if (d > 0) {
        raiz->esq = insere_recursivo(raiz->esq, s);
    } else {
        raiz->dir = insere_recursivo(raiz->dir, s);
    }
    return raiz;
}

void insere_arvore (Arvore segmentos_ativos, Segmento s) {
    arvore* a = (arvore*) segmentos_ativos;
    a->raiz = insere_recursivo (a->raiz, s);
}

pont filho_sucessor (pont raiz) {
    pont atual = raiz;
    while (atual && atual->esq != NULL)
    atual = atual->esq;
    return atual;
}

pont remove_recursivo(pont raiz, Segmento s) {
    if (raiz == NULL) return raiz;
    if (raiz->chave == s) {
        if (raiz->esq == NULL) {
            pont aux = raiz->dir;
            free(raiz);
            return aux;
        } else if (raiz->dir == NULL) {
            pont aux = raiz->esq;
            free(raiz);
            return aux;
        }
        pont aux = filho_sucessor (raiz->dir);
        raiz->chave = aux->chave;
        raiz->dir = remove_recursivo(raiz->dir, aux->chave);
    }
    else {
        double d = lado_ponto_relacao_segmento(raiz->chave, s);
        if (d == 0)
            d = lado_ponto_relacao_segmento2(raiz->chave, s);
            
        if (d > 0) {
            raiz->esq = remove_recursivo(raiz->esq, s);
        } else {
            raiz->dir = remove_recursivo(raiz->dir, s);
        }
    }
    return raiz;
}

void remove_arvore(Arvore segmentos_ativos, Segmento s) {
    arvore* a = (arvore*) segmentos_ativos;
    a->raiz = remove_recursivo(a->raiz, s);
}

void libera_recursivo(pont raiz) {
    if (raiz == NULL) return;
    libera_recursivo(raiz->esq);
    libera_recursivo(raiz->dir);
    free(raiz);
}

void libera_arvore(Arvore segmentos_ativos) {
    if (segmentos_ativos == NULL) {
        printf("Era para ele estar liberando a árvore, mas não aconteceu isso. \n");
        return;
    }
    arvore* a = (arvore*) segmentos_ativos;
    libera_recursivo(a->raiz);
    free(a);
}