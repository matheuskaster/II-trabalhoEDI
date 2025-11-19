#ifndef QRY_H
#define QRY_H
#include "geo.h"

#include "geometria.h"

/// @brief É uma função feita para poder ler o arquivo de entrada qry e executar tudo o que é pedido para ser feito dentro dele.
/// @param plano É onde as formas ficam localizadas.
/// @param file_qry É o arquivo de entrada do tipo .qry.
/// @param file_svg É o arquivo de saída, com as ilustrações, depois de ter sido processado pelo qry.
/// @param file_txt É o arquivo de saída, com o relatório final, depois de ter sido processado pelo qry.
void qry (void* plano, FILE* file_qry, FILE* file_svg_qry, FILE* file_txt);

#endif