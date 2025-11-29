#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>
#include "geometria.h"

typedef void* Lista;

/// @brief Cria dinâmicamente uma lista vazia, sem elementos.
/// @return Retorna um ponteiro para a lista vazia.
Lista cria_lista();

/// @brief O ponteiro que vai percorrer a lista, começará apontando pro início da fila.
/// @param l É um ponteiro que aponta para a lista l.
void percorrer_do_inicio_lista(Lista l);

/// @brief Verifica ainda tem algum elemento da lista para ser percorrido.
/// @param l É um ponteiro que aponta para a lista l.
/// @return Retorna um bool, true se tem outros elementos para percorrer, ou false, caso contrário.
bool tem_proximo_lista(Lista l);

/// @brief Se existir, entrega próximo elemento da lista desde a última vez que essa função foi chamada, sem de fato remover da lista, só serve para
/// observar quem está na lista.
/// @param l É um ponteiro que aponta para a lista l.
/// @return Retorna a geometria que deseja observar, para poder fazer algo, sem "marcar como concluído" na lista.
Geometria get_proximo_lista(Lista l);

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
