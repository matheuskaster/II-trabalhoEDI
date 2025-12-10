#ifndef GEOMETRIA_H
#define GEOMETRIA_H 

#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"

typedef void* Geometria;
typedef void* Forma;

/// @brief Cria um círculo com os parâmetros informados.
/// @param tipo É um char que tem a inicial da forma, nesse caso, 'c'.
/// @param id Número inteiro positivo identificador, para saber a qual círculo ele está se referindo.
/// @param x Número real que indica a coordenada no eixo x no qual o centro do círculo se encontra.
/// @param y Número real que indica a coordenada no eixo y no qual o centro do círculo se encontra.
/// @param r Número real que indica o tamanho do raio do círculo.
/// @param corb É uma string de caracteres que represetam a cor da borda do círculo, no padrão SVG, RGB que a cada dois caracteres no sistema hexadecimal são a intensidade de cada uma das três cores (ex.: #00FF00).
/// @param corp É uma string de caracteres que represetam a cor de preenchimento do círculo, no padrão SVG, RGB que a cada dois caracteres no sistema hexadecimal são a intensidade de cada uma das três cores (ex.: #00FF00).
/// @return Retorna a forma com o tipo e um círculo criado com os parâmetros.
Geometria cria_forma_circulo (char tipo, int id, double x, double y, double r, char *corb, char *corp);

/// @brief Cria um retângulo com os parâmetros informados.
/// @param tipo É um char que tem a inicial da forma, nesse caso, 'r'.
/// @param id Número inteiro e positivo identificador para saber a qual retângulo ele está se referindo.
/// @param x É a coordenada no eixo x no qual a âncora do retângulo se encontra (o vértice do canto inferior esquerdo).
/// @param y É a coordenada no eixo y no qual a âncora do retângulo se encontra (o vértice do canto inferior esquerdo).
/// @param w É um número real correspondente a largura do retângulo.
/// @param h É um número real correspondente a altura do retângulo.
/// @param corb Indica a cor da borda do retângulo.
/// @param corp Indica a cor de preenchimento do retângulo.
/// @return Retorna a forma com o tipo e um retângulo criado com os parâmetros.
Geometria cria_forma_retangulo (char tipo, int id, double x, double y, double w, double h, char *corb, char *corp);

/// @brief Cria um linha com os parâmetros informados.
/// @param tipo É um char que tem a inicial da forma, nesse caso, 'l'.
/// @param id Número inteiro identificador para saber a qual linha ele está se referindo.
/// @param x1 É o menor valor onde uma das extremidades da linha se encontra no eixo x (referente ao vértice inferior esquerdo), indicando a sua posição no plano.
/// @param y1 É o menor valor onde uma das extremidades da linha se encontra no eixo y (referente ao vértice inferior esquerdo), indicando a sua posição no plano.
/// @param x2 É o maior valor onde uma das extremidades da linha se encontra no eixo x (referente ao vértice superior direito), indicando a sua posição no plano.
/// @param y2 É o maior valor onde uma das extremidades da linha se encontra no eixo y (referente ao vértice superior direito), indicando a sua posição no plano.
/// @param cor Indica a cor da linha.
/// @return Retorna a forma com o tipo e um linha criado com os parâmetros.
Geometria cria_forma_linha (char tipo, int id, double x1, double y1, double x2, double y2, char *cor);

/// @brief Cria um texto com as informaçoes relacionadas a cada um dos parâmetros.
/// @param tipo É um char que tem a inicial da forma, nesse caso, 't'.
/// @param id É o identificador, para saber como se referir a esse texto em específico.
/// @param x É a posicao no eixo x, na qual esta localizada a âncora do texto.
/// @param y É a posicao no eixo y, na qual esta localizada a âncora do texto.
/// @param corb É a cor da borda de cada um dos caracteres do texto.
/// @param corp É a cor de preenchimento de cada um dos caracteres do texto.
/// @param a É um char, feito para poder identificar sobre qual parte do texto ele se refere (começo, meio, ou fim).
/// @param txto É o texto que estará escrito no arquivo .svg da forma texto.
/// @param ts É o estilo do texto.
/// @return Retorna a forma com o tipo e um texto criado com os parâmetros.
Geometria cria_forma_texto (char tipo, int id, double x, double y, char *corb, char *corp, char a, char *txto, Estilo ts);

/// @brief Por meio de um ponteiro a forma, ele passa especificamente a forma que está la dentro. 
/// @param g É um ponteiro que aponta para a implementação da forma.
/// @return Retorna um void* apontado para a forma específica (ex.: retorna Circulo, Retangulo, Linha, Texto).
Forma get_info_forma (Geometria g);

/// @brief Acessa a forma informada por parâmetro e informa qual é o tipo dela.
/// @param g É um ponteiro que aponta para a forma.
/// @return Retorna um char que indica qual é o tipo da forma.
char get_tipo_forma (Geometria g);

/// @brief Acessa a forma passada por parâmetro e mostra qual é o número inteiro responsável por identificar a forma.
/// @param g É um ponteiro que aponta para a forma.
/// @return Retorna um int que indica qual é o identificador id dessa forma.
int get_id_forma (Geometria g);

/// @brief O número double passado por parâmetro será a nova coordenada no eixo x da forma.
/// @param g É um ponteiro que aponta para a forma que terá sua posição no eixo x alterada.
/// @param x É a nova posição no eixo x da forma.
void set_x_forma(Geometria g, double x);

/// @brief Acessa a forma passada por parâmetro e mostra qual é a coordenada no eixo x, na qual esta localizada a forma.
/// @param g É um ponteiro que aponta para a forma.
/// @return Retorna um doble representando a coordenada do eixo x que está localizada a forma.
double get_x_forma (Geometria g);

/// @brief O número double passado por parâmetro será a nova coordenada no eixo y da forma.
/// @param g É um ponteiro que aponta para a forma que terá sua posição no eixo y alterada.
/// @param y É a nova posição no eixo y da forma.
void set_y_forma(Geometria g, double y);

/// @brief Acessa a forma passada por parâmetro e mostra qual é a coordenada no eixo y, na qual esta localizada a forma.
/// @param g É um ponteiro que aponta para a forma.
/// @return Retorna um doble representando a coordenada do eixo y que está localizada a forma.
double get_y_forma (Geometria g);

/// @brief Acessa a forma passada por parâmetro e mostra qual é a área dela.
/// @param g É um ponteiro que aponta para a forma.
/// @return Retorna um número double, que é o valor da área dessa forma.
double get_area_forma (Geometria g);

/// @brief O ponteiro para um char passado por parâmetro na função aponta para uma sequência de letras determinam uma cor, e essa cor, por meio da função, passa a ser a nova cor de borda da forma, também passada por parâmetro.
/// @param g É um ponteiro que aponta para a forma.
/// @param corb É a nova cor de borda da forma.
void set_corb_forma (Geometria g, char* corb);

/// @brief Acessa a forma passada por parâmetro e mostra qual é a cor de borda dela.
/// @param g É um ponteiro que aponta para a forma.
/// @return Retorna qual é a cor de borda da forma.
char* get_corb_forma(Geometria g);

/// @brief O ponteiro para um char passado por parâmetro na função aponta para uma sequência de letras determinam uma cor, e essa cor, por meio da função, passa a ser a nova cor de preenchimento da forma, também passada por parâmetro.
/// @param g É um ponteiro que aponta para a forma.
/// @param corp É a nova cor de borda da forma.
void set_corp_forma (Geometria g, char* corp);

/// @brief Acessa a forma passada por parâmetro e mostra qual é a cor de preenchimento dela.
/// @param g É um ponteiro que aponta para a forma.
/// @return Retorna qual é a cor de preenchimento da forma.
char* get_corp_forma(Geometria g);

/// @brief Pega o último id encontrado, entre todas as formas do geo, o declara como o ultimo id, e guarda o valor dele.
/// @param ultimo_id É o número inteiro, que corresponde ao valor do ultimo id encontrado.
void armazena_ultimo_id(int ultimo_id);

/// @brief Função responsável para possibilitar o acesso ao valor do último id para outros módulos, com a finalidade de continuar sempre fazendo identificadores únicos.
/// @return Retorna o valor inteiro correspondente ao valor do último id encontrado.
int get_ultimo_id();

/// @brief Recebe uma forma e clona ela, ou seja, faz uma cópia com os mesmos atributos, entretanto altera qual é o id da forma.
/// @param g É um ponteiro que aponta para a forma.
/// @return Retorna a forma clonada.
Geometria clona_forma(Geometria g);

/// @brief Acessa a forma passada por parâmetro e inverte as cores, ou seja, faz com que a cor de borda se torne a novamcor de preenchimento assim como a de preenchimento seja a nova cor de borda.
/// @param g É um ponteiro que aponta para a forma.
void inverte_cores_forma(Geometria g);

/// @brief Acessa a forma passada por parâmetro e libera toda a memória reservada à ela, que estava sendo ocupada e que não será mais.
/// @param g É um ponteiro que aponta para a forma.
void libera_forma(Geometria g);

#endif
