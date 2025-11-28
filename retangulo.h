#ifndef RETANGULO_H
#define RETANGULO_H

typedef void *Retangulo;

/// @brief Cria um retângulo com os parâmetros informados.
/// @param id Número inteiro e positivo identificador para saber a qual retângulo ele está se referindo.
/// @param x É a coordenada no eixo x no qual a âncora do retângulo se encontra (o vértice do canto inferior esquerdo).
/// @param y É a coordenada no eixo y no qual a âncora do retângulo se encontra (o vértice do canto inferior esquerdo).
/// @param w É um número real correspondente a largura do retângulo.
/// @param h É um número real correspondente a altura do retângulo.
/// @param corb Indica a cor da borda do retângulo.
/// @param corp Indica a cor de preenchimento do retângulo.
/// @return Retorna um retângulo criado com os parâmetros.
Retangulo cria_retangulo (int id, double x, double y, double w, double h, char *corb, char *corp);

/// @brief O número inteiro passado por parâmetro na função se torna o novo identificador do retãngulo.
/// @param r É um ponteiro que aponta para o retângulo.
/// @param id É o novo identificador do retângulo.
void set_id_retangulo (Retangulo r, int id);

/// @brief Informa qual é o id do retângulo.
/// @param r É um ponteiro que aponta para o retângulo.
/// @return Retorna o id do retângulo.
int get_id_retangulo (Retangulo r);

/// @brief O número double passado por parâmetro na função indica a coordenada no eixo x onde está localizado a âncora do retângulo.
/// @param r É um ponteiro que aponta para o retângulo.
/// @param x É a coordenada no eixo x na qual a ãncora do retângulo se encontra.
void set_x_retangulo (Retangulo r, double x);

/// @brief Informa qual é a coordenada no ponto x da âncora do retângulo.
/// @param c É um ponteiro que aponta para o retângulo.
/// @return Retorna qual é a coordenada no ponto x da âncora do retângulo.
double get_x_retangulo (Retangulo r);

/// @brief O número double passado por parâmetro na função indica a coordenada no eixo y onde está localizado a âncora do retângulo.
/// @param r É um ponteiro que aponta para o retângulo.
/// @param y É a coordenada no eixo y na qual a âncora do retângulo se encontra.
void set_y_retangulo (Retangulo r, double y);

/// @brief Informa qual é a coordenada no ponto y da âncora do retângulo.
/// @param r É um ponteiro que aponta para o retângulo.
/// @return Retorna qual é a coordenada no ponto y da âncora do retângulo.
double get_y_retangulo (Retangulo r);

/// @brief O número passado por parâmetro na função, torna-se a largura do retângulo, também passado por parâmetro.
/// @param r É um ponteiro que aponta para o retângulo.
/// @param w É a largura que o retângulo possui.
void set_w_retangulo (Retangulo r, double w);

/// @brief Informa qual é a largura do retângulo.
/// @param r É um ponteiro que aponta para o retângulo.
/// @return Retorna qual é a largura do retângulo.
double get_w_retangulo (Retangulo r);

/// @brief O número passado por parâmetro na função, torna-se a altura do retângulo, também passado por parâmetro.
/// @param r É um ponteiro que aponta para o retângulo.
/// @param w É a altura que o retângulo possui.
void set_h_retangulo (Retangulo r, double w);

/// @brief Informa qual é a altura do retângulo.
/// @param r É um ponteiro que aponta para o retângulo.
/// @return Retorna qual é a altura do retângulo.
double get_h_retangulo (Retangulo r);

/// @brief O ponteiro para um char passado por parâmetro na função aponta para uma sequência de letras determinam uma cor, e essa cor, por meio da função, passa a ser a nova cor de borda do retângulo, também passado por parâmetro.
/// @param r É um ponteiro que aponta para o retângulo.
/// @param corb É a nova cor do retângulo.
void set_corb_retangulo (Retangulo r, char *corb);

/// @brief Informa qual é a cor de borda do retângulo.
/// @param r É um ponteiro que aponta para o retângulo.
/// @return Retorna a cor de borda do retângulo.
char* get_corb_retangulo (Retangulo r);

/// @brief O ponteiro para um char passado por parâmetro na funçao aponta para uma sequência de letras determinam uma cor, e essa cor, por meio da função, passa a ser a nova cor de preenchimento do retângulo, também passado por parâmetro.
/// @param r É um ponteiro que aponta para o retângulo.
/// @param corp É a nova cor do retângulo.
void set_corp_retangulo (Retangulo r, char *corp);

/// @brief Informa qual é a cor de preenchimento do retângulo.
/// @param r É um ponteiro que aponta para o retângulo.
/// @return Retorna a cor de preenchimento do retângulo.
char* get_corp_retangulo (Retangulo r);

/// @brief Calcula a area do retângulo.
/// @param r Um ponteiro que aponta para o retângulo.
/// @return Retorna um número real float, correspondente ao tamanho dessa área.
double calcula_area_retangulo (Retangulo r);

/// @brief Libera toda a memória que estava reservada ao retangulo, disponibilizando ela novamente ao uso.
/// @param r É um ponteiro para qual retângulo terá sua memória liberada.
void libera_retangulo(Retangulo r);

#endif
