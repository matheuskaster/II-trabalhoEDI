#ifndef CIRCULO_H
#define CIRCULO_H

typedef void *Circulo;

/// @brief Cria um círculo com os parâmetros informados.
/// @param id Número inteiro positivo identificador, para saber a qual círculo ele está se referindo.
/// @param x Número real que indica a coordenada no eixo x no qual o centro do círculo se encontra.
/// @param y Número real que indica a coordenada no eixo y no qual o centro do círculo se encontra.
/// @param r Número real que indica o tamanho do raio do círculo.
/// @param corb É uma string de caracteres que represetam a cor da borda do círculo, no padrão SVG, RGB que a cada dois caracteres no sistema hexadecimal são a intensidade de cada uma das três cores (ex.: #00FF00).
/// @param corp É uma string de caracteres que represetam a cor de preenchimento do círculo, no padrão SVG, RGB que a cada dois caracteres no sistema hexadecimal são a intensidade de cada uma das três cores (ex.: #00FF00).
/// @return Retorna um círculo criado com os parâmetros.
Circulo cria_circulo (int id, double x, double y, double r, char *corb, char *corp);


/// @brief O número inteiro passado por parâmetro na função passa a ser o novo identificador do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @param id Será o novo identificador do círculo.
void set_id_circulo (Circulo c, int id);


/// @brief Informa qual é o identificador do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @return Retorna o id do círculo.
int get_id_circulo (Circulo c);

/// @brief O número double passado por parâmetro na função passa a ser a nova coordenada no eixo x onde está localizado o centro do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @param x Será a nova coordenada no eixo x na qual o centro do círculo passará a se encontrar.
void set_x_circulo (Circulo c, double x);

/// @brief Informa qual é a coordenada no ponto x do centro do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @return Retorna qual é a coordenada no ponto x do centro do círculo.
double get_x_circulo (Circulo c);

/// @brief O número double passado por parâmetro na função passa a ser a nova coordenada no eixo y onde esta localizado o centro do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @param y Será a coordenada no eixo y na qual o centro do círculo se encontrará.
void set_y_circulo (Circulo c, double y);

/// @brief Informa qual é a coordenada no ponto y do centro do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @return Retorna qual é a coordenada no ponto y do centro do círculo.
double get_y_circulo (Circulo c);

/// @brief O número double passado por parâmetro na função passa a ser o novo raio do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @param r Será o novo raio do círculo.
void set_r_circulo (Circulo c, double r);

/// @brief Informa qual é o tamanho do raio do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @return Retorna o tamanho do raio do círculo.
double get_r_circulo (Circulo c);

/// @brief O ponteiro para um char passado por parametro na função aponta para uma sequência em hexadecimal determinando uma cor, e essa cor, por meio da função, passa a ser a nova cor de borda do círculo, também passado por parâmetro.
/// @param c É um ponteiro que aponta para o círculo.
/// @param corb Será a nova cor do círculo.
void set_corb_circulo (Circulo c, char *corb);

/// @brief Informa qual é a cor de borda do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @return Retorna a cor de borda do círculo.
char* get_corb_circulo (Circulo c);

/// @brief O ponteiro para um char passado por parametro na função aponta para uma sequência em hexadecimal determinando uma cor, e essa cor, por meio da função, passa a ser a nova cor de preenchimento do círculo, também passado por parâmetro.
/// @param c É um ponteiro que aponta para o círculo.
/// @param corp Será a nova cor do círculo.
void set_corp_circulo (Circulo c, char *corp);

/// @brief Informa qual é a cor de preenchimento do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @return Retorna a cor de preenchimento do círculo.
char* get_corp_circulo (Circulo c);

/// @brief Calcula a área do círculo.
/// @param c É um ponteiro que aponta para o círculo.
/// @return Retorna um número real float, correspondente ao tamanho dessa área.
double calcula_area_circulo (Circulo c);

/// @brief Libera toda a memória alocada utilizada pelo círculo novamente disponível para uso.
/// @param c É um ponteiro que aponta para o círculo que terá sua memória liberadaa.
void libera_circulo(Circulo c);

#endif
