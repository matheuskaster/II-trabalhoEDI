#ifndef SOBREPOSICAO_H
#define SOBREPOSICAO_H
#include <stdbool.h>
#include "anteparo.h"

/// @brief A função descobre onde que essa linha cruza o segmento que vai ser atingido, ao lançar o raio da varredura no ângulo que se encontra o 
/// anteparo, em relação a bomba. Através de uma função interna que é chamada, que pega a porcentagem de duas retas finitas, descobre em qual ponto do
/// segmento o raio da bomba irá atingir. O objetivo final é encontrar quem seriam os biombos
/// @param x_bomba É a coordenada no eixo 'x' da posição do plano cartesiano, local onde a bomba caiu.
/// @param y_bomba É a coordenada no eixo 'y' da posição do plano cartesiano, local onde a bomba caiu.
/// @param angulo Para saber qual direção, em radianos, o raio da varredura precisa estar olhando para encontrar o ponto do biombo.
/// @param s É o ponteiro para o segmento que a função quer verificar se vai cruzar, ou seja, fazer com que o segmento se torne ativo.
/// @return Retorna um ponto, com coordenadas double, dentro do intervalo dos dois extremos do segmento, que representa o ponto de intersecção.
Ponto interseccao_raio_segmento (double x_bomba, double y_bomba, double angulo, Segmento s);

/// @brief A função calcula o quadrado da distancia de dois pontos, utilizando pitágoras, mas como o objetivo não é descobrir a distância real, mas
/// calcular uma distância para comparar com outra, não é necessário obter a raiz dessa soma de quadrados, e calcular a raiz exige mais do computador.
/// @param x1 É o valor no eixo 'x' do primeiro ponto que será utilizado para calcular a distância.
/// @param y1 É o valor no eixo 'y' do primeiro ponto que será utilizado para calcular a distância.
/// @param x2 É o valor no eixo 'x' do segundo ponto que será utilizado para calcular a distância.
/// @param y2 É o valor no eixo 'y' do segundo ponto que será utilizado para calcular a distância.
/// @return Retorna o valor da distância elevada ao quadrado entre os dois pontos passados por parâmetro.
double distancia_ao_quadrado(double x1, double y1, double x2, double y2);

/// @brief Recebe os 4 pontos para delimitar uma bounding box, pega eles e os atribui para uma estrutura feita para guardar uma bounding box.
/// @param xmin É o valor mínimo necessário no eixo 'x' para não estar completamente a esquerda da bounding box.
/// @param ymin É o valor mínimo necessário no eixo 'y' para não estar completamente abaixo da bounding box.
/// @param xmax É o valor máximo possível no eixo 'y' para não estar completamente a direita da bounding box.
/// @param ymax É o valor máximo possível no eixo 'y' para não estar completamente acima da bounding box.
/// @return Retorna a bounding box certinha de um polígono genérico.
///bounding_box limite_poligono(double xmin, double ymin, double xmax, double ymax);

#endif

