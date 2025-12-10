#ifndef POLIGONO_H
#define POLIGONO_H
#include <stdbool.h>
#include "anteparo.h"
#include "sobreposicao.h"

typedef void* Poligono;

Poligono cria_poligono ();

void insere_ponto_poligono (Poligono, Ponto);

void insere_segmento (Poligono, Segmento);

void get_bouding_box (bounding_box);

bool esta_dentro (Poligono, Ponto);

Ponto get_ponto (Poligono);

Segmento get_segmento (Poligono);


#endif