#ifndef SVG_H
#define SVG_H
#include <stdio.h>
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "geometria.h"
#include "geo.h"

/// @brief Escreve o cabeçalho do arquivo .svg, ou seja, é a declaração <?xml ...?> e a tag <svg ...> com seus atributos que 
/// definem o espaço e as regras para o desenho.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
void abre_svg (FILE* arq_svg);

/// @brief Passa as características do círculo para o svg poder o desenhar.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param c É um ponteiro que aponta para o círculo.
void desenha_circulo_svg (FILE* arq_svg, Circulo c);

/// @brief Passa as características do retângulo para o svg poder o desenhar.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param r É um ponteiro que aponta para o retângulo.
void desenha_retangulo_svg (FILE* arq_svg, Retangulo r);

/// @brief Passa as características da linha para o svg poder a desenhar.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param l É um ponteiro que aponta para a linha.
void desenha_linha_svg (FILE* arq_svg, Linha l);

/// @brief Passa as características do texto para o svg poder o escrever.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param t É um ponteiro que aponta para o texto.
void desenha_texto_svg (FILE* arq_svg, Texto t, Estilo ts);

/// @brief Passa as caracteísticas da forma para o svg poder escrever.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
/// @param f É a forma genérica que será desenhada no svg.
void desenha_forma_svg (FILE* arq_svg, Geometria g);

/// @brief Escreve o rodapé do arquivo .svg, ou seja, é a tag </svg> que fecha o arquivo svg, indicando a realização com sucesso.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
void fecha_svg (FILE* arq_svg);

/// @brief É uma função que desenha todas as formas do plano.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
/// @param chao É o local onde as formas se encontram.
void svg (FILE* arq_svg, Lista chao);

#endif