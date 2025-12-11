#ifndef QRY_H
#define QRY_H
#include <stdio.h>
#include "geo.h"
#include "lista.h"
#include "geometria.h"

/// @brief É uma função feita para poder ler o arquivo de entrada qry e executar tudo o que é pedido para ser feito dentro dele.
/// @param chao É onde as formas ficam localizadas.
/// @param file_qry É o arquivo de entrada do tipo .qry.
/// @param file_svg É o arquivo de saída, com as ilustrações, depois de ter sido processado pelo qry.
/// @param file_txt É o arquivo de saída, com o relatório final, depois de ter sido processado pelo qry.
/// @param tipo_ordenacao É um caractere que possui a letra referente a forma que ele deseja que seja ordenado o qry, 'q' se for  por qsort, ou 'm' 
/// se for para ordenar utilizando o merge e insertion sort.
/// @param menos_i É um número do tipo int, para dizer quando o tamanho do vertor é suficientemente pequeno para parar com o merge sort e utilizar
/// insertion sort
///@param path_svg_qry É o caminho do arquivo svg, após as ações do qry.
void qry (Lista chao, FILE* file_qry, FILE* file_svg_qry, FILE* file_txt, char* path_svg_qry, char tipo_ordenacao, int menos_i);

#endif