#ifndef POLIGONO_H
#define POLIGONO_H
#include <stdbool.h>
#include "anteparo.h"
#include "sobreposicao.h"

typedef void* Poligono;

/// @brief Função para alocar memória para a criação do polígono.
/// @return Retorna o void pointer para o polígono.
Poligono cria_poligono();

/// @brief Adiciona um ponto ao polígono.
/// @param poly É o ponteiro para o vetor de pontos.
/// @param ponto É o ponto que deseja inserir no polígono.
void insere_ponto_poligono(Poligono poly, Ponto ponto);

/// @brief Pega um ponto do polígono.
/// @param poly É o ponteiro para o vetor de pontos.
/// @param i É a posição do vetor que vai ser retirado o ponto.
/// @return Retorna o ponto que está naquela posição desse índice do vetor.
Ponto get_ponto_poligono(Poligono poly, int i);

/// @brief Informa a quantidade de pontos que tem dentro do polígono.
/// @param poly É o ponteiro para o vetor de pontos.
/// @return Retorna um número inteiro correspondente ao número de pontos dentro do polígono.
int get_qtd_pontos_poligono(Poligono poly);

/// @brief Muda por referência os valores mínimos e máximos do limite do polígono, os pontos necessários para determinar a bounding box.
/// @param x_min É o ponto que tem o menor valor no eixo 'x'.
/// @param y_min É o ponto que tem o menor valor no eixo 'y'.
/// @param x_max É o ponto que tem o maior valor no eixo 'x'.
/// @param y_max É o ponto que tem o maior valor no eixo 'y'.
/// @param poly É o ponteiro para o vetor de pontos.
void limites_poligono(Poligono poly, double* x_min, double* y_min, double* x_max, double* y_max);

/// @brief Recebe um ponto e verifica se ele está dentro do polígono.
/// @param poly É o ponteiro para o vetor de pontos.
/// @param x É a posição que se encontra o ponto no eixo 'x'.
/// @param y É a posição que se encontra o ponto no eixo 'y'.
/// @return Retorna "true" se estiver dentro do polígono e "false" se não tiver.
bool esta_dentro_poligono(Poligono poly, double x, double y);

/// @brief Libera todas a memória reservada e alocada para a utilização do polígono. Deixa-as diponíveis para uso novamente.
/// @param poly É o ponteiro para o vetor de pontos.
void libera_poligono(Poligono poly);

#endif

