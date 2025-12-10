#ifndef ARVORE_H
#define ARVORE_H
#include "anteparo.h"

typedef void* Arvore;

/// @brief Função para pegar o segmento mais próximo da bomba, no caso o mais próximo entre os segmentos ativos vai ser o responsável por formar o biombo.
/// @param segmentos_ativos É o ponteiro para a árvore que armazena e organiza todos os segmentos ativos.
/// @return Retorna o segmento ativo mais próximo da bomba.
Segmento segmento_mais_proximo(Arvore segmentos_ativos);

/// @brief Cria o void pointer para a árvore e aloca memória para a arvore e inicializa a raiz.
/// @return Retorna o void pointer que aponta para a árvore.
Arvore cria_arvore();

/// @brief É a função para inserir na árvore, verifica se o novo segmento está a direita ou esquerda do atual e o insere do lado da árvore correspondente.
/// @param segmentos_ativos É o ponteiro para a árvore que armazena e organiza todos os segmentos ativos.
/// @param s É o segmento ativo que fará parte da árvore.
/// @param bx É a posição no plano cartesiano onde a bomba se encontra, no eixo 'x'.
/// @param by É a posição no plano cartesiano onde a bomba se encontra, no eixo 'y'.
void insere_arvore(Arvore segmentos_ativos, Segmento s, double bx, double by);

/// @brief 
/// @param segmentos_ativos É o ponteiro para a árvore que armazena e organiza todos os segmentos ativos.
/// @param s É o segmento, que por não está mais ativo, deixará de fazer parte da árvore.
/// @param bx É a posição no plano cartesiano onde a bomba se encontra, no eixo 'x'.
/// @param by É a posição no plano cartesiano onde a bomba se encontra, no eixo 'y'.
void remove_arvore(Arvore segmentos_ativos, Segmento s, double bx, double by);

/// @brief É a função que vai liberar a memória que foi alocada para a utilização dessa estrutura.
/// @param segmentos_ativos É o ponteiro para a árvore que armazena e organiza todos os segmentos ativos.
void libera_arvore(Arvore segmentos_ativos);

#endif