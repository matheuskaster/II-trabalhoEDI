#ifndef ANTEPARO__H
#define ANTEPARO_H
#include "geometria.h"

typedef void* Ponto;
typedef void* Segmento;

/// @brief Recebe duas coordenadas e retorna um tipo Ponto, que armazena os dois. Para converter e padronizar, mais fácil de utilizar funções que usam ponto.
/// @param x É um número double que indica em qual posição do eixo 'x' estará localizado o ponto que será criado.
/// @param y É um número double que indica em qual posição do eixo 'y' estará localizado o ponto que será criado.
/// @return Retorna um ponto, nas duas coordenadas passadas por parâmetro.
Ponto transforma_ponto(double x, double y);

/// @brief Recebe uma geometria, identifica a que forma ela se refere, e retorna os segmentos da forma transformada em anteparo.
/// @param id É um número inteiro único para poder identificar um segmento específico.
/// @param x1 É a coordenada no eixo 'x' do primeiro ponto do segmento.
/// @param y1 É a coordenada no eixo 'y' do primeiro ponto do segmento.
/// @param x2 É a coordenada no eixo 'x' do segundo ponto do segmento.
/// @param y2 É a coordenada no eixo 'x' do segundo ponto do segmento.
/// @param tipo É um char que tem a letra inicial para diferenciar o tipo do anteparo, podendo ser uma das opções: limite 'l', anteparo 'a' e o de poligono 'p'. 
/// @param cor É uma string de char que representa uma cor no padrão do SVG, (red, green, blue).
/// @param g É um ponteiro que aponta para qual é a geometria que originou os segmentos gerados.
/// @return Retorna o segmento que acabou de ser transformado
Segmento transforma_anteparo(int id, double x1, double y1, double x2, double y2, char tipo, char* cor, Geometria g);

/// @brief Como na hora de dividir os segmentos, eles tem que ser diferentes, eu utilizo essa função para criar o segmento dividido.
/// @param id É um id único para o novo segmento que está sendo criado.
/// @param x É a coordenada no eixo 'x' do primeiro ponto do novo segmento.
/// @param y É a coordenada no eixo 'y' do primeiro ponto do novo segmento.
/// @param x2 É a coordenada no eixo 'x' do segundo ponto do novo segmento.
/// @param y2 É a coordenada no eixo 'y' do segundo ponto do novo segmento.
/// @param s_original É o segmento original que está sendo dividido.
/// @return Um segmento novo, que é o resultado da divisão do segmento original.
Segmento divide_segmentos(int id, double x, double y, double x2, double y2, Segmento s_original);

/// @brief Altera o valor do 'x' e do 'y' do ponto 1 de um segmento, para os passados por parâmetro.
/// @param x É o novo valor do 'x' do ponto 1.
/// @param y É o novo valor do 'y' do ponto 1.
/// @param s É o segmento que terá o ponto 1 alterado.
void set_p1_segmento(double x, double y, Segmento s);

/// @brief Altera o valor do 'x' e do 'y' do ponto 2 de um segmento, para os passados por parâmetro.
/// @param x É o novo valor do 'x' do ponto 2.
/// @param y É o novo valor do 'y' do ponto 2.
/// @param s É o segmento que terá o ponto 2 alterado.
void set_p2_segmento(double x, double y, Segmento s);

/// @brief Recebe um ponto qualquer, e retorna qual o valor do 'x' dele, onde ele se encontra no eixo 'x'.
/// @param p É um ponteiro que aponta para o ponto.
/// @return Retorna um número double com o valor do 'x'.
double get_x_ponto(Ponto p);

/// @brief Recebe um ponto qualquer, e retorna qual o valor do 'y' dele, onde ele se encontra no eixo 'y'.
/// @param p É um ponteiro que aponta para o ponto.
/// @return Retorna um número double com o valor do 'y'.
double get_y_ponto(Ponto p);

/// @brief Acessa um segmento, olha qual é o id dele e o retorna.
/// @param s É o ponteiro para o segmento que se deseja encontrar o id.
/// @return Retorna um número inteiro, que corresponde ao identificador do segmento.
int get_id_segmento(Segmento s);

/// @brief Recebe um segmento qualquer e retorna qual é o valor do x do ponto 1, qual é a posição desse ponto pertencente ao segmento, no eixo 'x'.
/// @param s É um ponteiro que aponta para o segmento.
/// @return Retorna um número double com o valor do 'x'
double get_x_p1(Segmento s);

/// @brief Recebe um segmento qualquer e retorna qual é o valor do x do ponto 2, qual é a posição desse ponto pertencente ao segmento, no eixo 'x'.
/// @param s É um ponteiro que aponta para o segmento.
/// @return Retorna um número double com o valor do 'x'
double get_x_p2(Segmento s);

/// @brief Recebe um segmento qualquer e retorna qual é o valor do x do ponto 1, qual é a posição desse ponto pertencente ao segmento, no eixo 'y'.
/// @param s É um ponteiro que aponta para o segmento.
/// @return Retorna um número double com o valor do 'y'
double get_y_p1(Segmento s);

/// @brief Recebe um segmento qualquer e retorna qual é o valor do x do ponto 2, qual é a posição desse ponto pertencente ao segmento, no eixo 'y'.
/// @param s É um ponteiro que aponta para o segmento.
/// @return Retorna um número double com o valor do 'y'
double get_y_p2(Segmento s);

/// @brief Troca a cor, colocando a cor passada por parâmtro, como a nova cor.
/// @param seg É um ponteiro que aponta para o segmento que terá sua cor trocada.
/// @param cor É a nova cor, que o segmento passará a ter.
void set_cor_segmento(Segmento seg, char *cor);

/// @brief Pega um segmento, clona ele igualziho, só que com um id único, e altera a coordenada dele.
/// @param seg É o ponteiro para o segmento.
/// @param dx É o número que será adicionado ao valor da coordenada no eixo 'x', para resultar na posição que o clone estará localizado.
/// @param dy É o número que será adicionado ao valor da coordenada no eixo 'y', para resultar na posição que o clone estará localizado.
/// @param id É o id que o segmento vai possuir
/// @return O segmento clone.
Segmento clona_segmento(Segmento seg, double dx, double dy, int id);

/// @brief Libera toda a memória referente ao segmento e a memória que ele mesmo utiliza dentro dele.
/// @param s É um ponteiro que aponta para o segmento, que toda a memória reservada relacionada a ele, será disponibilizada novamente para outras utilizações.
void libera_segmento (Segmento s);


#endif
