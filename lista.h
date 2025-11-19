#ifndef LISTA_H
#define LISTA_H
#include "geometria.h"

typedef void* Lista;

/// @brief Cria dinâmicamente uma lista vazia, sem elementos.
/// @return Retorna um ponteiro para a lista vazia.
Lista cria_lista();

/// @brief Verifica o tamanho da lista, a quantidade de elementos que ela possui.
/// @param f É um ponteiro que aponta para a lista l.
/// @return Retorna qual é o tamanho da lista.
int tam_lista(Lista l);

/// @brief Insere um novo elemento no fim da lista.
/// @param f É um ponteiro que aponta para a lista l.
/// @param n O conteúdo que será inserido na lista, podendo ser uma variável de qualquer tipo.
void insere_lista(Lista l, Geometria g);

/// @brief Remove o elemento do início da lista
/// @param f É um ponteiro que aponta para a lista l.
Geometria remove_lista (Lista l);

/// @brief Clona uma lista, ou seja cria uma nova lista e faz com que ela tenha o mesmo número de elementos, apontando para o endereço onde os elementos da lista original se encontram.
/// @param f É um ponteiro que aponta para a lista l, a lista que será clonada.
/// @return Retorna a lista clonada.
Lista clona_lista(Lista l);

/// @brief Libera a memória alocada para a lista.
/// @param f É um ponteiro para a lista.
void libera_lista(Lista l);

#endif