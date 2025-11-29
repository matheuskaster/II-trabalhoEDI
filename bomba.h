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

#endif

