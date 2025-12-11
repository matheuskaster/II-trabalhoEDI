#ifndef BOMBA_H
#define BOMBA_H
#include <stdio.h>
#include "lista.h"
#include "anteparo.h"
#include "vetor.h"

/// @brief Função responsável por realizar o comando 'a' do .qry, está sendo feita em um módulo separado por questão de organização.
/// @param i É o primeiro id do intervalo das formas que serão transformadas em anteparos.
/// @param j É o último id do intervalo das formas que serão transformadas em anteparos.
/// @param direcao É um char para dizer qual o sentido do segmento, caso um círculo seja tranformadao em anteparo, (horizontal 'h' ou vertical 'v'). 
/// @param chao É a lista onde todas as geometrias se encontram
/// @param file_txt É um arquivo do tipo .txt para reportar id e tipo da figura original, além do id e extremos dos segmentos produzidos.
/// @param vet É um vetor de anteparos, onde ponteiros para os segmentos são guardados, para melhorar na hora de ordená-los e para separar os
/// anteparos das outras formas do jogo.
void a(int i, int j, char direcao, Lista chao, FILE *file_txt, Vetor vet);

/// @brief Cria quatro limites (segmentos) para formar uma "caixa infinita" usada pelo algoritmo da bomba.
/// @param vet Vetor onde serão inseridos os segmentos-limite.
void cria_caixa_infinita(Vetor vet);

/// @brief Faz o processo da bomba de destruição.
/// @param x A posição no eixo 'x' em que a bomba caiu.
/// @param y A posição no eixo 'y' em que a bomba caiu.
/// @param sfx É o sufixo do nome, que tem que ser diferente do original, do novo nome do arquivo final .svg, da região de visibilidade da bomba.
/// @param chao É o local onde todas as formas geradas pelo .geo se encontram.
/// @param txt É o arquivo final de saída .txt, ele vai anotar as principais informações dos resultados da bomba.
/// @param svg É o arquivo de saída .svg, que vai ilustrar o que aconteceu com as formas.
/// @param vet É o vetor que guarda todos os anteparos.
/// @param path_svg_qry É o nome base para montar o nome do arquivo .svg.
/// @param tipo_ordenacao É o tipo de ordenação, podendo ser 'q', para a utilização do qsort, ou 'm' para utilizar o merge sort e insertion sort.
/// @param menos_i É o parâmetro que diz qual tamanho é suficientemente pequeno, para que ele pare de fazer o merge sort e comece a utilizar o insertion sort.
void d(double x, double y, char *sfx, Lista chao, FILE *txt, FILE *svg, Vetor vet, char *path_svg_qry, char tipo_ordenacao, int menos_i);

/// @brief Faz o processo da bomba de pintura.
/// @param x A posição no eixo 'x' em que a bomba caiu.
/// @param y A posição no eixo 'y' em que a bomba caiu.
/// @param cor É a cor no padrão RGB do svg, que vai ser pintada todas as formas dentro da região de visibilidade do polígono.
/// @param sfx É o sufixo do nome, que tem que ser diferente do original, do novo nome do arquivo final .svg, da região de visibilidade da bomba.
/// @param chao É o local onde todas as formas geradas pelo .geo se encontram.
/// @param txt É o arquivo final de saída .txt, ele vai anotar as principais informações dos resultados da bomba.
/// @param svg É o arquivo de saída .svg, que vai ilustrar o que aconteceu com as formas.
/// @param vet É o vetor que guarda todos os anteparos.
/// @param path_svg_qry É o nome base para montar o nome do arquivo .svg.
/// @param tipo_ordenacao É o tipo de ordenação, podendo ser 'q', para a utilização do qsort, ou 'm' para utilizar o merge sort e insertion sort.
/// @param menos_i É o parâmetro que diz qual tamanho é suficientemente pequeno, para que ele pare de fazer o merge sort e comece a utilizar o insertion sort.
void p(double x, double y, char* cor, char *sfx, Lista chao, FILE *txt, FILE *svg, Vetor vet, char *path_svg_qry, char tipo_ordenacao, int menos_i);

/// @brief Faz o processo da bomba de clonagem.
/// @param x A posição no eixo 'x' em que a bomba caiu.
/// @param y A posição no eixo 'y' em que a bomba caiu.
/// @param dx É o valor que será somado ao a posição no eixo 'x' da bomba para definir a posição do clone.
/// @param dy É o valor que será somado ao a posição no eixo 'y' da bomba para definir a posição do clone.
/// @param sfx É o sufixo do nome, que tem que ser diferente do original, do novo nome do arquivo final .svg, da região de visibilidade da bomba.
/// @param chao É o local onde todas as formas geradas pelo .geo se encontram.
/// @param txt É o arquivo final de saída .txt, ele vai anotar as principais informações dos resultados da bomba.
/// @param svg É o arquivo de saída .svg, que vai ilustrar o que aconteceu com as formas.
/// @param vet É o vetor que guarda todos os anteparos.
/// @param path_svg_qry É o nome base para montar o nome do arquivo .svg.
/// @param tipo_ordenacao É o tipo de ordenação, podendo ser 'q', para a utilização do qsort, ou 'm' para utilizar o merge sort e insertion sort.
/// @param menos_i É o parâmetro que diz qual tamanho é suficientemente pequeno, para que ele pare de fazer o merge sort e comece a utilizar o insertion sort.
void cln(double x, double y, double dx, double dy, char *sfx, Lista chao, FILE *txt, FILE *svg, Vetor vet, char *path_svg_qry, char tipo_ordenacao, int menos_i);


#endif
