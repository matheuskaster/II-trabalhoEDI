#ifndef ANTEPARO__H
#define ANTEPARO_H
#include "geometria.h"

typedef void* Segmento;

/// @brief Recebe uma geometria, identifica a que forma ela se refere, e retorna os segmentos da forma transformada em anteparo.
/// @param x1 É a coordenada no eixo 'x' do primeiro ponto do segmento.
/// @param y1 É a coordenada no eixo 'y' do primeiro ponto do segmento.
/// @param x2 É a coordenada no eixo 'x' do segundo ponto do segmento.
/// @param y2 É a coordenada no eixo 'x' do segundo ponto do segmento.
/// @param g É um ponteiro que aponta para qual é a geometria que originou os segmentos gerados.
/// @return Retorna o segmento que acabou de ser transformado
Segmento transforma_anteparo(double x1, double y1, double x2, double y2, Geometria g);

#endif

