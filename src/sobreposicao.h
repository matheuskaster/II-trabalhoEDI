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

/// @brief Calcula o determinante de uma matriz 3x3, com o objetivo de ajudar a descobrir o lado que um ponto está em relação a um segmento.
/// @param xx É o ponto x do primeiro vetor da matriz.
/// @param xy É o ponto y do primeiro vetor da matriz.
/// @param yx É o ponto x do segundo vetor da matriz.
/// @param yy É o ponto y do segundo vetor da matriz.
/// @param zx É o ponto x do terceiro vetor da matriz.
/// @param zy É o ponto y do terceiro vetor da matriz.
/// @return Retona o valor do determinante calculado.
double calculo_determinante(double xx, double xy, double yx, double yy, double zx, double zy);

/// @brief A função calcula o quadrado da distancia de dois pontos, utilizando pitágoras, mas como o objetivo não é descobrir a distância real, mas
/// calcular uma distância para comparar com outra, não é necessário obter a raiz dessa soma de quadrados, e calcular a raiz exige mais do computador.
/// @param x1 É o valor no eixo 'x' do primeiro ponto que será utilizado para calcular a distância.
/// @param y1 É o valor no eixo 'y' do primeiro ponto que será utilizado para calcular a distância.
/// @param x2 É o valor no eixo 'x' do segundo ponto que será utilizado para calcular a distância.
/// @param y2 É o valor no eixo 'y' do segundo ponto que será utilizado para calcular a distância.
/// @return Retorna o valor da distância elevada ao quadrado entre os dois pontos passados por parâmetro.
double distancia_ao_quadrado(double x1, double y1, double x2, double y2);

/// @brief Calcula de que lado o ponto de inicio do novo segmento está em relação aos segmentos já presentes na árvore.
/// @param st O novo segmento que está sendo inserido na árvore.
/// @param sr O segmento já presente na árvore.
/// @return O valor do determinante que indica de que lado o ponto está em relação ao segmento.
double lado_ponto_relacao_segmento(Segmento st, Segmento sr);

/// @brief Calcula a interseção entre o raio de varredura e o segmento.
/// @param s É um ponteiro para o segmento que será verificado.
/// @param theta O ângulo em radianos do raio da varredura.
/// @param xSaida É o ponteiro para a variável que armazenará a coordenada 'x' do ponto de interseção.
/// @param ySaida É o ponteiro para a variável que armazenará a coordenada 'y' do ponto de interseção.
/// @param bx É a coordenada no eixo 'x' da posição do plano cartesiano, local onde a bomba caiu.
/// @param by É a coordenada no eixo 'y' da posição do plano cartesiano, local onde a bomba caiu.
/// @return Retorna 1 se houve interseção, ou 0 caso contrário.
int calcularInterseccaoRaio(Segmento s, double theta, double *xSaida, double *ySaida, double bx, double by);

#endif

double lado_ponto_relacao_segmento2(Segmento st, Segmento sr);
