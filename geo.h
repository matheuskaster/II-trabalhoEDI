#ifndef GEO_H
#define GEO_H
#include <stdio.h>
#include "geometria.h"


/// @brief É um TAD que utiliza funções de arquivo pra poder ler o .geo, criar as formas que estão no arquivo de entrada as colocar no plano cartesiano.
/// @param plano É o plano cartesiano do projeto, onde as formas ficam ao serem criadas.
/// @param arq_geo É o arquivo de entrada, do tipo .geo.
void geo (void *plano, FILE* arq_geo);

#endif