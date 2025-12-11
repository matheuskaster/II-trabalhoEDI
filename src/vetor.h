#ifndef DIVISORIA_H
#define DIVISORIA_H
#include "anteparo.h"

typedef void* Vetor;

/// @brief Cria um vetor feito para armazenar todos os anteparos, só com anteparos.
/// @return Retorna um vetor para separar, ao agrupar os anteparos.
Vetor cria_vet ();

/// @brief Coloca um anteparo dentro do vetor.
/// @param vet É o ponteiro para o vetor de anteparos.
/// @param a É um ponteiro que aponta para o anteparo que será inserido no vetor.
void insere_vet (Vetor vet, Segmento s);

/// @brief Função que procura no vetor, através do id único de cada anteparo, o anteparo desejado.
/// @param d É o ponteiro para o vetor de anteparos.
/// @param id É o id do anteparo desejado.
/// @return Retorna o anteparo desejado.
Segmento busca_vet (Vetor vet, int id);

/// @brief Retorna o segmento que está na posição do vetor que ele informou que queria.
/// @param vet É o ponteiro para o vetor de anteparos.
/// @param posicao É um número inteiro que indica de qual posição do vetor ele quer que seja retornado.
/// @return Retorna o segmento daquela posição do vetor.
Segmento get_segmento_qualquer(Vetor vet, int posicao);

/// @brief Informa qual que é a quantidade de itens que existem dentro do vetor.
/// @param vet É um ponteiro que aponta para a posição do vetor.
/// @return Retorna o número de elementos que o vetor possui.
int get_qtd_vet(Vetor vet);

/// @brief Libera toda a memória alocada pelo vetor de anteparos novamente a disponibilizando para uso.
/// @param d É o ponteiro para saber acessar o vetor que terá sua memória liberada.
void libera_vet (Vetor vet);

#endif